#include <pico/stdlib.h>
#include <sfe_pico.h>
#include <stdio.h>

int main(void)
{
    stdio_init_all();

    sleep_ms(2000);

    const size_t psram_size = sfe_setup_psram(SFE_RP2350_XIP_CSI_PIN);
    if (psram_size) {
        printf("PSRAM setup complete. PSRAM size 0x%lX\n", psram_size);
    } else {
        printf("PSRAM not detected\n");
    }

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }

    return 0;
}
