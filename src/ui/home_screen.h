#ifndef FOOTBALLNW_HOME_SCREEN_H
#define FOOTBALLNW_HOME_SCREEN_H

enum { kHomeMenuItemCount = 4 };

void drawHomeScreen(int selectedItem);
void drawPlaceholderScreen(int selectedItem);
void waitForBackKey();

#endif
