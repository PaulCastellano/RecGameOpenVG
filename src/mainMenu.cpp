#include "../include/include.h"

void Game::mainMenu()
{
    WindowClear();
    Start(this->windowWidth, this->windowHeight);
    // std::cout << this->windowWidth << " " << this->windowHeight << std::endl;
    Image(0, 0, 100, 100, "/home/pi/Desktop/RecGameOpenVG/assets/mainMenu.jpeg");
    End();
}
