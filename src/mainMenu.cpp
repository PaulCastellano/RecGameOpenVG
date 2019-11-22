#include "../include/include.h"

void Game::mainMenu()
{
    WindowClear();
    // Start(this->windowWidth, this->windowHeight);
    // std::cout << this->windowWidth << " " << this->windowHeight << std::endl;
    Background(255, 255, 255);
    Image(0, 100, this->windowWidth, this->windowHeight, "/home/pi/Desktop/RecGame/assets/mainMenu.jpg");
    End();
}
