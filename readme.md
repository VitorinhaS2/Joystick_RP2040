# **CONVERSORES A/D NO RP2040**

Este repositório contém o código-fonte e o diagrama referentes a parte 2 da atividade prática que consiste em utilizar o microcontrolador Raspberry Pi Pico W e um joystick para compreender o funcionamento do conversor analógico-digital (ADC) no RP2040, integrando hardware e software.

## **COMPONENTES UTILIZADOS**

Neste projeto foram utilizados os seguintes componentes:

- Microcontrolador Raspberry pi pico w;
- Joystick: Conectado às GPIOS 26 e 27.
- Botão do Joystick: Conectado à GPIO 22.
- LED RGB: Pinos conectados às GPIOs 11, 12 e 13.

## **FUNCIONALIDADES IMPLEMENTADAS**

1. Controle dos LEDs RGB via Joystick:  
- LED Azul: Brilho ajustado conforme o eixo Y do joystick.  
  - Posição central (2048): LED apagado.  
  - Movimento para cima (valores menores) ou para baixo (valores maiores): aumento gradual do brilho, atingindo o máximo nos extremos (0 e 4095).  
- LED Vermelho: Brilho ajustado conforme o eixo X do joystick.  
  - Posição central (2048): LED apagado.  
  - Movimento para esquerda (valores menores) ou direita (valores maiores): aumento gradual do brilho, atingindo o máximo nos extremos (0 e 4095).  
- Controle via PWM para variação suave da intensidade luminosa.   

2. Funcionalidades do Botão do Joystick:  
- Alternar o LED Verde a cada acionamento.    

## Organização da Equipe
- **Líder de Projeto:** [VITÓRIA CAVALCANTI] — responsável pelo gerenciamento do repositório, estrutura do código e revisão dos pull requests.
- **Desenvolvedor 1:** [LÁISA BIANCA] — responsável pela configuração dos GPIOS.
- **Desenvolvedor 2:** [LAÍSE CAFÉ] — responsável pela configuração do PWM e interrupção do botão.

---

## **VÍDEO EXPLICATIVO**
[Link do vídeo explicativo](https://www.canva.com/design/DAGrerIm0Ys/L7ECF4Yy8_C0MvmZo-GTtQ/watch?utm_content=DAGrerIm0Ys&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=h62398b5113)

## Licença
Este projeto é destinado exclusivamente para fins acadêmicos na disciplina **ELET0021 — Microcontroladores e Microprocessadores**.

---