#include <iostream>
#include <string>
#include <cstdlib>
#include <sys/time.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

#include <wiringSerial.h>
#include <wiringPi.h>

#include <pthread.h>

//#include "../assets/DejaVuSansMono.inc"
#include "VG/openvg.h"
#include "VG/vgu.h"
#include "shapes.h"
#include "fontinfo.h"

class Game
{
private:
    int windowWidth;
    int windowHeight;
    int score;
    int mode;
    int zone;
    int colorMode;
    int time;
    int timerCount;
    //Fontinfo DejaFont;
public:
    //Setters
    void setWindowWidth(int windowWidth);
    void setWindowHeight(int windowHeight);
    void setScore(int score);
    void setMode(int mode);
    void setZone(int zone);
    void setColorMode(int colorMode);
    void setTime(int time);
    void setTimerCount(int timerCount);
    //Getters
    int getWindowWidth();
    int getWindowHeight();
    int getScore();
    int getMode();
    int getZone();
    int getColorMode();
    int getTime();
    int getTimerCount();
    //Screens
    void mainMenu();
    void scoreScreen();
    void resultScreen();
};
