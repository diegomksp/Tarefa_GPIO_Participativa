// Bibliotecas que serão usadas no projeto
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

#define LED_RED_PIN 13   // Pino para o led vermelho
#define LED_GREEN_PIN 11 // Pino para o led verde
#define LED_BLUE_PIN 12  // Pino para o led azul
#define BUZZER_PIN 21    // Pino para o buzzer

// Definição das funções que serão usadas no projeto
void initialize_gpio();
void control_components(char command);
void buzzer_beep();
void menu();
void leds();

// Função principal
int main()
{
    // Inicializa o UART e os GPIOs
    stdio_init_all();
    initialize_gpio();
    getchar();
    printf("Sistema iniciado. Aguardando comandos...\n");
    menu();

    // Loop para pegar os comandos do terminal
    while (1)
    {
        
        char command; // Guarda o comando vindo do teminal

        if (scanf("%c", &command))
        {
            control_components(command); // Faz a placa executar uma açao
        }
    }
    return 0;
} // Fim main

// Função para inicializar os pinos GPIO
void initialize_gpio()
{
    // Pinos para o led vermelho
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);

    // Pinos para o led verde
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    // Pinos para o led azul
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);

    // Pinos para o buzzer
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
} // Fim initialize_gpio

// Função para controlar os componentes da placa usando comandos do terminal
void control_components(char command)
{
    switch (command)
    {
    case '1':
        gpio_put(LED_GREEN_PIN,1);
        printf("Luz verde acesa!\n");
        break;
    case '2':
        gpio_put(LED_BLUE_PIN,1);
        printf("Luz azul acesa!\n");
        break;
    case '3': 
        gpio_put(LED_RED_PIN,1);
        printf("Luz vermelha acesa!\n");
        break;
    case '4':
        printf("Todas as luzes acesas!\n");
        leds(true);
        break;
    case '5':
        printf("Todas as luzes apagadas!\n");
        leds(false);
        break;
    case '6':
        // Comando para o buzzer fazer barulho
        buzzer_beep();
        break;
    case '7':
        printf("Entrando no modo BOOTSEL...");
        sleep_ms(1000);
        reset_usb_boot(0,0);
        break;
    default:
        printf("Comando inválido!\n");
        break;
    }
}

// Função para fazer o buzzer emitir um barulho
void buzzer_beep()
{
    int contB;

    for (contB = 0; contB < 10000; contB++)
    {
        gpio_put(BUZZER_PIN, 1);
        sleep_us(50);
        gpio_put(BUZZER_PIN, 0);
        sleep_us(50);
    }
} // Fim buzzer_beep
void leds(int a){
    gpio_put(LED_RED_PIN, a);
    gpio_put(LED_GREEN_PIN, a);
    gpio_put(LED_BLUE_PIN, a);
    gpio_put(BUZZER_PIN, false);
}
void menu(){
    printf("Entre com a opcao desejada: \n");
    printf("[1] Liga LED verde;\n");
    printf("[2] Liga LED azul;\n");
    printf("[3] Liga LED vermelho;\n");
    printf("[4] Liga os três LEDs;\n");
    printf("[5] Desliga todos os LEDs;\n");
    printf("[6] Aciona o Buzzer por 2 segundos;\n");
    printf("[7] Sai do modo execucao e entra no modo BOOTSEL\n");
}