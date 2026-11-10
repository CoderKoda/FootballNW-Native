#include "home_screen.h"

#include "../eadkpp.h"

namespace {

constexpr EADK::Color kBackground(0x101C23);
constexpr EADK::Color kPanel(0x1B3038);
constexpr EADK::Color kAccent(0x43D49A);
constexpr EADK::Color kPrimaryText(0xF2F7F4);
constexpr EADK::Color kMutedText(0xA8B9B3);
constexpr EADK::Color kDivider(0x30464D);

const char * const kMenuItems[kHomeMenuItemCount] = {
  "NEW MATCH",
  "TEAMS",
  "MATCH HISTORY",
  "SETTINGS"
};

const char * const kPageTitles[kHomeMenuItemCount] = {
  "NEW MATCH",
  "TEAMS",
  "MATCH HISTORY",
  "SETTINGS"
};

void drawHeader() {
  EADK::Display::drawString("FOOTBALLNW", EADK::Point(20, 18), true, kPrimaryText, kBackground);
  EADK::Display::drawString("N0120 FOOTBALL SIMULATOR", EADK::Point(20, 49), false, kMutedText, kBackground);
  EADK::Display::pushRectUniform(EADK::Rect(20, 68, 280, 2), kDivider);
}

}  // namespace

void drawHomeScreen(int selectedItem) {
  EADK::Display::pushRectUniform(EADK::Screen::Rect, kBackground);
  drawHeader();

  EADK::Display::drawString("MAIN MENU", EADK::Point(20, 82), false, kAccent, kBackground);

  for (int i = 0; i < kHomeMenuItemCount; i++) {
    const int rowY = 101 + i * 28;

    if (i == selectedItem) {
      EADK::Display::pushRectUniform(EADK::Rect(16, rowY, 288, 25), kPanel);
      EADK::Display::pushRectUniform(EADK::Rect(20, rowY + 4, 3, 17), kAccent);
    }

    const EADK::Color textColor = (i == selectedItem) ? kPrimaryText : kMutedText;
    EADK::Display::drawString(kMenuItems[i], EADK::Point(34, rowY + 8), false, textColor, (i == selectedItem) ? kPanel : kBackground);
  }

  EADK::Display::drawString("UP / DOWN  MOVE", EADK::Point(20, 222), false, kMutedText, kBackground);
  EADK::Display::drawString("OK  SELECT", EADK::Point(222, 222), false, kAccent, kBackground);
}

void drawPlaceholderScreen(int selectedItem) {
  if (selectedItem < 0 || selectedItem >= kHomeMenuItemCount) {
    selectedItem = 0;
  }

  EADK::Display::pushRectUniform(EADK::Screen::Rect, kBackground);
  drawHeader();

  EADK::Display::drawString(kPageTitles[selectedItem], EADK::Point(20, 91), true, kPrimaryText, kBackground);
  EADK::Display::pushRectUniform(EADK::Rect(20, 125, 72, 3), kAccent);

  EADK::Display::drawString("COMING SOON", EADK::Point(20, 151), false, kAccent, kBackground);
  EADK::Display::drawString("This section is part of", EADK::Point(20, 174), false, kMutedText, kBackground);
  EADK::Display::drawString("the FootballNW starter build.", EADK::Point(20, 188), false, kMutedText, kBackground);
  EADK::Display::drawString("BACK  RETURN TO MENU", EADK::Point(20, 222), false, kPrimaryText, kBackground);
}

void waitForBackKey() {
  while (true) {
    if (EADK::Keyboard::scan().keyDown(EADK::Keyboard::Key::Back)) {
      while (EADK::Keyboard::scan().keyDown(EADK::Keyboard::Key::Back)) {
        EADK::Timing::msleep(20);
      }
      return;
    }
    EADK::Timing::msleep(25);
  }
}
