#include "include/include.h"

Game g;
char c;

void *score(void *varg)
{
	while (g.getTimerCount() >= 0)
	{
		c = serialGetchar(fd);
		if (c == '+')
		{
			g.setScore(g.getScore() + 1);
		}
		else if (g.getColorMode() == 2 && c == '-')
		{
			g.setScore(g.getScore() - 1);
		}
		else if (c == 'R')
		{
			g.setTimerCount(-1);
		}
	}
	return (varg);
}

void *timer(void *varg)
{
	while (g.getTimerCount() >= 0)
	{
		g.setTimerCount(g.getTimerCount() - 1);
		sleep(1);
	}
	return (varg);
}

int main()
{
	bool gameStart;
	int w;
	int h;
	int fd;

	int settingsCount;

	pthread_t timerThread;
	pthread_t scoreShowThread;

	//Graphic init
	init(&w, &h);
	g.setWindowWidth(w);
	g.setWindowHeight(h);

	//Communication with Arduino
	if ((fd = serialOpen("/dev/ttyACM0", 115200)) < 0)
	{
		std::cout << "Unable to open serial device"
				  << std::endl;
		return 1;
	}
	while (1)
	{
		g.setScore(0);
		g.setZone(0);
		g.setMode(0);
		g.setTime(0);
		gameStart = false;
		settingsCount = 0;
		g.mainMenu();
		while (!gameStart)
		{
			c = serialGetchar(fd);
			if (c == 'S')
				settingsCount++;
			else if (c == '1')
			{
				g.setZone(1);
				settingsCount++;
			}
			else if (g.getZone() == 0 && c == '2')
			{
				g.setZone(2);
				settingsCount++;
			}
			else if (g.getZone() == 0 && c == '3')
			{
				g.setZone(3);
				settingsCount++;
			}
			else if (c == 'E')
			{
				g.setMode(1);
				settingsCount++;
			}
			else if (g.getMode() == 0 && c == 'M')
			{
				g.setMode(2);
				settingsCount++;
			}
			else if (c == 'H')
			{
				g.setMode(3);
				settingsCount++;
			}
			else if (c == 'M')
			{
				g.setColorMode(1);
				settingsCount++;
			}
			else if (c == 'B')
			{
				g.setColorMode(2);
				settingsCount++;
			}
			else if (c == '2')
			{
				g.setTime(2);
				settingsCount++;
			}
			else if (c == '3')
			{
				g.setTime(3);
				settingsCount++;
			}
			else if (c == '5')
			{
				g.setTime(5);
				settingsCount++;
			}

			if (settingsCount == 5)
				gameStart = true;
		}

		std::cout << g.getZone() << "  " << g.getMode() << "  " << g.getColorMode() << "  " << g.getTime() << "  " << std::endl;
		g.setTimerCount(60 * g.getTime());
		sleep(3);
		pthread_create(&timerThread, NULL, timer, NULL);
		pthread_create(&scoreShowThread, NULL, score, NULL);
		while (g.getTimerCount() >= 0)
		{
			g.scoreScreen();
		}
		pthread_cancel(timerThread);
		pthread_cancel(scoreShowThread);
		if (c != 'R')
		{
			g.resultScreen();
			sleep(5);
		}
	}
	finish();
	return (0);
}
