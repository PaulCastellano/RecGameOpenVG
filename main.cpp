#include "include/include.h"

Game g;

void	*timer(void *varg) {
	while (g.getTime() >= 0) {
		g.setTimerCount(g.getTimerCount() - 1);
		sleep(1);
	}
	return (varg);
}

int main()
{
    bool        gamestart;

    char        c;
    int         fd;

    phtread     timerThread;
    phtread     scoreThread;

	int			settingsCount;

    //Graphic init
    init(&g.getWindowWidth(), &g.getWindowHeight());

	//Communication with Arduino
	if((fd=serialOpen("/dev/ttyACM0", 115200)) < 0){
		std::cout << "Unable to open serial device\n" << std::endl;
		return 1;
	}

    while(1) {
		g.setScore(0);
		g.setZone(0);
		g.setMode(0);
		g.setTime(0);
		gamestart = false;
		settingsCount = 0;

		g.mainMenu();

		while(!gamestart) {
			
		}
    }

    finish();
    return (0);
}