#include "eadkpp.h"
#include "ui/home_screen.h"

#include <stdint.h>

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "Football";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

namespace {

void waitForKeyRelease(EADK::Keyboard::Key key) {
  while (EADK::Keyboard::scan().keyDown(key)) {
    EADK::Timing::msleep(20);
  }
}

}  // namespace

int main(int argc, char * argv[]) {
  (void)argc;
  (void)argv;

  int selectedItem = 0;
  EADK::Display::pushRectUniform(EADK::Screen::Rect, EADK::Color(0x101C23));

  while (true) {
    drawHomeScreen(selectedItem);

    EADK::Keyboard::State keyboard = EADK::Keyboard::scan();

    if (keyboard.keyDown(EADK::Keyboard::Key::Up)) {
      selectedItem = (selectedItem + kHomeMenuItemCount - 1) % kHomeMenuItemCount;
      waitForKeyRelease(EADK::Keyboard::Key::Up);
    } else if (keyboard.keyDown(EADK::Keyboard::Key::Down)) {
      selectedItem = (selectedItem + 1) % kHomeMenuItemCount;
      waitForKeyRelease(EADK::Keyboard::Key::Down);
    } else if (keyboard.keyDown(EADK::Keyboard::Key::OK)) {
      waitForKeyRelease(EADK::Keyboard::Key::OK);
      drawPlaceholderScreen(selectedItem);
      waitForBackKey();
    }

    EADK::Timing::msleep(25);
  }

  return 0;
}
