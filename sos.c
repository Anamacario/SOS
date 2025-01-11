#include "pico/stdlib.h"

// Definições de pinos e tempos
#define led_pin 13           // GPIO onde o LED externo está conectado
#define tempo_ponto 200      // Tempo para um ponto (0,2 segundos)
#define tempo_traco 800      // Tempo para um traço (0,8 segundos)
#define tempo_gap 125        // Intervalo entre pontos/traços (0,125 segundos)
#define tempo_letra 250      // Intervalo entre letras (0,25 segundos)
#define tempo_ciclo 3000     // Intervalo entre ciclos de SOS (3 segundos)

// Função para ponto (.)
void dot() {
    gpio_put(led_pin, true);
    sleep_ms(tempo_ponto);
    gpio_put(led_pin, false);
    sleep_ms(tempo_gap);
}

// Função para traço (-)
void dash() {
    gpio_put(led_pin, true);
    sleep_ms(tempo_traco);
    gpio_put(led_pin, false);
    sleep_ms(tempo_gap);
}

// Função para enviar SOS
void sendSOS() {
    // Envia "S" (três pontos)
    dot(); dot(); dot();
    sleep_ms(tempo_letra);

    // Envia "O" (três traços)
    dash(); dash(); dash();
    sleep_ms(tempo_letra);

    // Envia "S" (três pontos)
    dot(); dot(); dot();
}

int main() {
    // Configuração inicial do GPIO
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    // Loop principal
    while (true) {
        sendSOS();           // Envia o sinal SOS
        sleep_ms(tempo_ciclo); // Aguarda 3 segundos antes de reiniciar o ciclo
    }

    return 0; // Opcional, não será alcançado no loop infinito
}
