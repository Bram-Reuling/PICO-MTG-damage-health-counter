#include "drivers/st7789/st7789.hpp"
#include "drivers/rgbled/rgbled.hpp"
#include "drivers/button/button.hpp"
#include "libraries/pico_vector/pico_vector.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "libraries/pico_display/pico_display.hpp"
#include "libraries/bitmap_fonts/font8_data.hpp"

pimoroni::ST7789 st7789(pimoroni::PicoDisplay::WIDTH, pimoroni::PicoDisplay::HEIGHT, pimoroni::ROTATE_0, false, pimoroni::get_spi_pins(pimoroni::BG_SPI_FRONT));

pimoroni::PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);

pimoroni::RGBLED led(pimoroni::PicoDisplay::LED_R, pimoroni::PicoDisplay::LED_G, pimoroni::PicoDisplay::LED_B);

pimoroni::Button button_a(pimoroni::PicoDisplay::A, pimoroni::Polarity::ACTIVE_LOW, 300);
pimoroni::Button button_b(pimoroni::PicoDisplay::B, pimoroni::Polarity::ACTIVE_LOW, 300);
pimoroni::Button button_x(pimoroni::PicoDisplay::X, pimoroni::Polarity::ACTIVE_LOW, 300);
pimoroni::Button button_y(pimoroni::PicoDisplay::Y, pimoroni::Polarity::ACTIVE_LOW, 300);

void setup()
{
    graphics.set_font(&font8);
    st7789.set_backlight(200);
    led.set_brightness(1);
}

void checkButtons(int& damage, int& health)
{
    if (button_a.read())
      damage++;
    
    if (button_b.read())
      damage--;

    if (button_x.read())
      health++;
    
    if (button_y.read())
      health--;
}

pimoroni::Point centerText(const std::string& message, float scale)
{
    int32_t width = graphics.measure_text(message, scale);
    int32_t height = 1;

    if (graphics.bitmap_font)
    {
      height = graphics.bitmap_font->height * scale;
    }

    return {(pimoroni::PicoDisplay::WIDTH / 2) - (width / 2), (pimoroni::PicoDisplay::HEIGHT / 2) - (height / 2)};
}

int main()
{
    setup();

    int damageCounter = 0;
    int healthCounter = 0;

  while(true)
  {
    checkButtons(damageCounter, healthCounter);

    graphics.set_pen(30, 40, 50);

    graphics.clear();

    graphics.set_pen(10, 20, 30);
    pimoroni::Rect text_rect(0, 0, pimoroni::PicoDisplay::WIDTH, pimoroni::PicoDisplay::HEIGHT);
    graphics.rectangle(text_rect);

    text_rect.deflate(10);
    graphics.set_pen(110, 120, 130);

    std::string message = std::to_string(damageCounter) + std::string("/") + std::to_string(healthCounter);

    float scale = 6.f;

    graphics.text(message, centerText(message, scale), text_rect.w, scale);

    st7789.update(&graphics);
  }

  return 0;
}