#include <demos/lv_demos.h>
#include <hardware/spi.h>
#include <lvgl.h>
#include <pico/binary_info.h>
#include <pico/stdlib.h>
#include <sfe_pico.h>
#include <stdio.h>
#include <drivers/lcd.h>
#include <tusb.h>

int main(void)
{
    stdio_init_all();

    while (!tud_cdc_connected())
        ;

    sleep_ms(500);

    printf("Using PICO SDK v%d.%d.%d\n", PICO_SDK_VERSION_MAJOR, PICO_SDK_VERSION_MINOR, PICO_SDK_VERSION_REVISION);

    const size_t psram_size = sfe_setup_psram(SFE_RP2350_XIP_CSI_PIN);
    if (psram_size) {
        printf("PSRAM setup complete. PSRAM size 0x%lX\n", psram_size);
    } else {
        printf("PSRAM not detected\n");
    }

    spi_init(SPI_LCD, 20 * 1000 * 1000);

    gpio_set_function(PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_SPI_SCK_PIN, PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI));

    printf("Using LVGL v%d.%d.%d\n", lv_version_major(), lv_version_minor(), lv_version_patch());

    lv_init();
    lv_tick_set_cb(time_us_32);

    ayo_lcd_init();

    lv_obj_t *scr = lv_screen_active();
    lv_obj_set_style_bg_color(scr, lv_color_white(), 0);
    lv_obj_set_style_bg_opa(scr, LV_OPA_100, 0);

    lv_demo_widgets();

    while (true) {
        lv_task_handler();

        sleep_ms(5);
    }

    return 0;
}
