#include "include/include.h"

Game g;

int main()
{
    bool        gamestart;
    int		w;
    int		h;
    char        c;
    int         fd;

	int			settingsCount;

    //Graphic init
    init(&w, &h);
    g.setWindowWidth(w);
    g.setWindowHeight(h);

	//Communication with Arduino
	/*if((fd=serialOpen("/dev/ttyACM0", 115200)) < 0){
		std::cout << "Unable to open serial device\n" << std::endl;
		return 1;
	}*/

		g.setScore(1);
		g.setZone(2);
		g.setMode(0);
		g.setTime(0);
		gamestart = false;
		settingsCount = 0;
		g.scoreScreen();
    sleep(2);
    finish();
    return (0);
}
