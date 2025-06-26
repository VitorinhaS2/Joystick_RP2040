#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

//  Vitória — Dona do Repositório / Estrutura Principal

// Definição de pinos e constantes usados no projeto todo
#define VRX_PIN 27
#define VRY_PIN 26
#define BTN_J 22
#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11
#define PWM_WRAP 24999
#define PWM_DIV 100.0
#define DEBOUNCE_TIME 200

// Variáveis globais compartilhadas
volatile bool led_green_state = false;
volatile bool pwm_enabled = true;
volatile uint32_t last_interrupt_time = 0;
float pwm_x, pwm_y;

// Protótipos das funções implementadas pelos outros desenvolvedores
void setup_gpio();
void setup_pwm();
void handle_button_press(uint gpio, uint32_t events);

int main() {
    stdio_init_all();
    adc_init();
    setup_gpio();
    setup_pwm();

    gpio_set_irq_enabled_with_callback(BTN_J, GPIO_IRQ_EDGE_FALL, true, &handle_button_press);

    while (true) {
        adc_select_input(0);   // Leitura eixo Y
        uint16_t y_value = adc_read();

        adc_select_input(1);   // Leitura eixo X
        uint16_t x_value = adc_read();

        pwm_x = 25000 - x_value * 50000 / 4095;
        pwm_y = 25000 - y_value * 50000 / 4095;

        if (fabs(pwm_x) < 1000) pwm_x = 0;
        if (fabs(pwm_y) < 1000) pwm_y = 0;

        uint slice_blue = pwm_gpio_to_slice_num(LED_BLUE);
        uint slice_red = pwm_gpio_to_slice_num(LED_RED);

        pwm_set_enabled(slice_blue, pwm_enabled);
        pwm_set_enabled(slice_red, pwm_enabled);

        pwm_set_gpio_level(LED_RED, fabs(pwm_x));
        pwm_set_gpio_level(LED_BLUE, fabs(pwm_y));
    }
}


// Laise — Configuração do PWM e Interrupção do Botão


void setup_pwm() {
    gpio_set_function(LED_BLUE, GPIO_FUNC_PWM);
    uint slice_blue = pwm_gpio_to_slice_num(LED_BLUE);
    pwm_set_clkdiv(slice_blue, PWM_DIV);
    pwm_set_wrap(slice_blue, PWM_WRAP);

    gpio_set_function(LED_RED, GPIO_FUNC_PWM);
    uint slice_red = pwm_gpio_to_slice_num(LED_RED);
    pwm_set_clkdiv(slice_red, PWM_DIV);
    pwm_set_wrap(slice_red, PWM_WRAP);

    pwm_set_enabled(slice_blue, true);
    pwm_set_enabled(slice_red, true);
}

void handle_button_press(uint gpio, uint32_t events) {
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if (current_time - last_interrupt_time > DEBOUNCE_TIME) {
        last_interrupt_time = current_time;
        if (gpio == BTN_J) {
            led_green_state = !led_green_state;
            gpio_put(LED_GREEN, led_green_state);
        }
    }
}
