#include "lcd.h"

#include <hardware/gpio.h>
#include <hardware/spi.h>
#include <lvgl.h>
#include <src/drivers/display/st7789/lv_st7789.h>

#define DRAW_BUF_SIZE (LCD_WIDTH * LCD_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
static uint32_t draw_buf[DRAW_BUF_SIZE / 4];

static void send_cmd(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, const uint8_t *param, size_t param_size)
{
    LV_UNUSED(disp);

    gpio_put(PIN_LCD_DC, 0);

    gpio_put(PIN_LCD_CS, 0);

    spi_write_blocking(SPI_LCD, cmd, cmd_size);

    gpio_put(PIN_LCD_DC, 1);

    if (param_size > 0)
        spi_write_blocking(SPI_LCD, param, param_size);

    gpio_put(PIN_LCD_CS, 1);
}

static void send_color(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, uint8_t *param, size_t param_size)
{
    LV_UNUSED(disp);

    gpio_put(PIN_LCD_DC, 0);

    gpio_put(PIN_LCD_CS, 0);

    spi_write_blocking(SPI_LCD, cmd, cmd_size);

    gpio_put(PIN_LCD_DC, 1);

    if (param_size > 0) {
        // switch to 16-bit writes
        hw_write_masked(&spi_get_hw(SPI_LCD)->cr0, 15 << SPI_SSPCR0_DSS_LSB, SPI_SSPCR0_DSS_BITS);

        spi_write16_blocking(SPI_LCD, (uint16_t *)param, param_size / 2);

        // switch back to 8-bit
        hw_write_masked(&spi_get_hw(SPI_LCD)->cr0, 7 << SPI_SSPCR0_DSS_LSB, SPI_SSPCR0_DSS_BITS);
    }

    gpio_put(PIN_LCD_CS, 1);

    lv_display_flush_ready(disp);
}

void ayo_lcd_init(void)
{
    gpio_init(PIN_LCD_BL);
    gpio_set_dir(PIN_LCD_BL, GPIO_OUT);
    gpio_put(PIN_LCD_BL, 1);

    gpio_init(PIN_LCD_DC);
    gpio_set_dir(PIN_LCD_DC, GPIO_OUT);

    gpio_init(PIN_LCD_CS);
    gpio_set_dir(PIN_LCD_CS, GPIO_OUT);
    gpio_put(PIN_LCD_CS, 1);

    lv_display_t *disp = lv_st7789_create(LCD_HEIGHT, LCD_WIDTH, LV_LCD_FLAG_NONE, send_cmd, send_color);
    lv_lcd_generic_mipi_set_invert(disp, true);

    lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_90);
    lv_display_set_buffers(disp, (void*)draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
}
