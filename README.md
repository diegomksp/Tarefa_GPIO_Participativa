# Controle de pinos GPIO da ferramenta educacional BitDogLab.

## Descrição

O projeto consiste em utilizar a comunicação UART para enviar comandos realizados no computador para a placa BitDogLab.

## Funcionalidades

1. Ligar LED verde (GPIO 11)
2. Ligar LED azul (GPIO 12)
3. Ligar LED vermelho (GPIO 13)
4. Ligar os três LEDs (luz branca);
5. Desligar todos os LEDs;
6. Acionar o buzzer por 2 segundos – emissão de sinal sonoro;
7. Sair do modo de execução e habilitar o modo de gravação via software (reboot)

## Mapeamento das teclas

| Tecla | Função                  |
|-------|--------------------------|
| 1     | Liga LED verde           |
| 2     | Liga LED azul            |
| 3     | Liga LED vermelho        |
| 4     | Liga os três LEDs        |
| 5     | Desliga os três LEDs     |
| 6     | Aciona o Buzzer por 2 segundos |
| 7     | Sai do modo execucao e entra no modo BOOTSEL |

## Como usar

1. Conecte a placa BitDogLab via usb no modo BOOTSEL para gravar o arquivo "EmbarcaTech_GPIO_2.uf2".
2. Após a gravação, reinicie a placa.
3. Utilizando um monitor seral, pressione uma tecla para iniciar a execução do programa.

## Hardware necessário

- Raspberry Pi Pico
- LEDs(vermelho, verde, azul)
- Buzzer
- Resistores
- Cabo com coneção micro-usb

## Autores

Projeto desenvolvido por:
Bruno Costa
Caio Andrade
Diego M S Pereira
Josevaldo