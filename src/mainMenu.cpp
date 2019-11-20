#include "../include/include.h"

void Game::mainMenu()
{
    WindowClear();
    // Start(this->windowWidth, this->windowHeight);
    // std::cout << this->windowWidth << " " << this->windowHeight << std::endl;
    Background(255, 255, 255);
    Image(0, 0, this->windowWidth, this->windowHeight + 100, "/home/pi/Desktop/RecGameOpenVG/assets/mainMenu.jpg");
    End();
}
