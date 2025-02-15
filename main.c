#include <stdio.h>
#include "pico/stdlib.h"

#include "notas.h"
#include "musicas.h"

#include "hardware/pwm.h"
#include "hardware/clocks.h"




// Configuração do pino do buzzer
#define BUZZER_PIN 21

// Definição de uma função para inicializar o PWM no pino do buzzer
void pwm_init_buzzer(uint pin, uint BUZZER_FREQUENCY) {
    // Configurar o pino como saída de PWM
    gpio_set_function(pin, GPIO_FUNC_PWM);

    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o PWM com frequência desejada
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (BUZZER_FREQUENCY * 4096)); // Divisor de clock
    pwm_init(slice_num, &config, true);

    // Iniciar o PWM no nível baixo
    pwm_set_gpio_level(pin, 0);
}

// Definição de uma função para emitir um beep com duração especificada
void beep(uint pin, uint duration_ms) {
    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o duty cycle para 50% (ativo)
    pwm_set_gpio_level(pin, 2048);

    // Temporização
    sleep_ms(duration_ms);

    // Desativar o sinal PWM (duty cycle 0)
    pwm_set_gpio_level(pin, 0);

    // Pausa entre os beeps
    sleep_ms(100); // Pausa de 100ms
}

int main() {
    // Configuração do GPIO para o botão A
    const uint BUTTON_PIN_A = 5;  // Pino do botão A
    gpio_init(BUTTON_PIN_A);
    gpio_set_dir(BUTTON_PIN_A, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_A);

    // Configuração do GPIO para o botão B
    const uint BUTTON_PIN_B = 6;  // Pino do botão B
    gpio_init(BUTTON_PIN_B);
    gpio_set_dir(BUTTON_PIN_B, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_B);
    
    
    // Configuração do GPIO para o buzzer como saída
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

   

    while (true) {
        // Verifica o estado do botão
        if (gpio_get(BUTTON_PIN_A) == 0) {  // Botão pressionado (nível lógico baixo)
            int tamanho = sizeof(brilhaBrilha) / sizeof(brilhaBrilha[0]);

            for (int i = 0; i < tamanho; i++) {     
                pwm_init_buzzer(BUZZER_PIN,brilhaBrilha[i].frequencia);// Inicializar o PWM no pino do buzzer
                beep(BUZZER_PIN, parabens[i].tempo); // Bipe de 500ms  // Liga o buzzer
            }
        }else if(gpio_get(BUTTON_PIN_B) ==  0){
            int tamanho = sizeof(parabens) / sizeof(parabens[0]);

            for (int i = 0; i < tamanho; i++) {     
                pwm_init_buzzer(BUZZER_PIN,parabens[i].frequencia);// Inicializar o PWM no pino do buzzer
                beep(BUZZER_PIN, parabens[i].tempo); // Bipe de 500ms  // Liga o buzzer

            }
        }
    }

    return 0;
}
