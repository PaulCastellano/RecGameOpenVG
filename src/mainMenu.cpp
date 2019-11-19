#include "../include/include.h"

void    Game::mainMenu() {
    Start(this->windowWidth, this->windowHeight);
    Background(255, 255, 255);
    Image(0, 0, this->windowWidth, this->windowHeight, "/home/pi/Desktop/RecGameOpenVG/assets/download.jpeg");
    End();
}
