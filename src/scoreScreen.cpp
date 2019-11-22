#include "../include/include.h"

void Game::scoreScreen()
{
	std::string str;
	char *s;
	int i;

	WindowClear();
	// Start(this->windowWidth, this->windowHeight);
	Background(255, 255, 255);
	if (this->zone == 1)
		str = "Zona: 1";
	else if (this->zone == 2)
		str = "Zona: 2";
	else
		str = "Zona: 3";
	s = (char *)malloc(sizeof(char) * str.length() + 1);
	i = -1;
	while (++i < str.length())
		s[i] = str[i];
	s[i] = '\0';
	//Text(this->windowWidth / 150, this->windowHeight - 10 - this->windowWidth / 50, s, SerifTypeface, this->windowWidth / 40);
	free(s);

	if (this->mode == 1)
		str = "Nivel: Usor";
	else if (this->mode == 2)
		str = "Nivel: Mediu";
	else
		str = "Nivel: Greu";
	s = (char *)malloc(sizeof(char) * str.length() + 1);
	i = -1;
	while (++i < str.length())
		s[i] = str[i];
	s[i] = '\0';
	//Text(this->windowWidth / 150, this->windowHeight - 10 - 2 * TextHeight(SerifTypeface, this->windowWidth / 50), s, SerifTypeface, this->windowWidth / 40);
	free(s);

	if (this->colorMode == 1)
		str = "Culoare:";
	else
		str = "Culoare:";
	s = (char *)malloc(sizeof(char) * str.length() + 1);
	i = -1;
	while (++i < str.length())
		s[i] = str[i];
	s[i] = '\0';
	//Text(this->windowWidth / 150, this->windowHeight - 10 - 3 * TextHeight(SerifTypeface, this->windowWidth / 50), s, SerifTypeface, this->windowWidth / 40);
	//Fill(255, 0, 0, 1);
	//Rect(TextWidth(s, SerifTypeface, this->windowWidth / 40) + 2, this->windowHeight - 10 - 3 * TextHeight(SerifTypeface, this->windowWidth / 40), this->windowWidth / 24, TextHeight(SerifTypeface, this->windowWidth / 40));
	if (this->colorMode == 2)
	{
		Fill(0, 0, 255, 1);

		Rect(TextWidth(s, SerifTypeface, this->windowWidth / 40) + 2 + this->windowWidth / 24, this->windowHeight - 10 - 3 * TextHeight(SerifTypeface, this->windowWidth / 40), this->windowWidth / 24, TextHeight(SerifTypeface, this->windowWidth / 40));

		Fill(0, 0, 0, 1);
		//TO DO!!!
		// Line(...);
	}
	free(s);

	if (this->time == 2)
		str = "Timp: 2 min";
	else if (this->time == 3)
		str = "Timp: 3 min";
	else
		str = "Timp: 5 min";
	s = (char *)malloc(sizeof(char) * str.length() + 1);
	i = -1;
	while (++i < str.length())
		s[i] = str[i];
	s[i] = '\0';
	//Text(this->windowWidth / 150, this->windowHeight - 10 - 4 * TextHeight(SerifTypeface, this->windowWidth / 40), s, SerifTypeface, this->windowWidth / 40);
	free(s);

	if (this->timerCount < 10)
		str = "TIMP:00";
	else if (this->timerCount < 100)
		str = "TIMP:0";
	else
		str = "TIMP:";
	str += std::to_string(this->timerCount);
	s = (char *)malloc(sizeof(char) * str.length() + 1);
	i = -1;
	while (++i < str.length())
		s[i] = str[i];
	s[i] = '\0';
	//Text(this->windowWidth / 7, this->windowHeight - 50, s, SerifTypeface, this->windowWidth / 10);
	free(s);

	if (abs(this->score) < 10)
		if (this->score < 0)
			str = "SCOR:-00";
		else
			str = "SCOR:00";
	else if (abs(this->score) < 100)
		if (this->score < 0)
			str = "SCOR:-0";
		else
			str = "SCOR:0";
	else if (this->score < 0)
		str = "SCOR:-";
	else
		str = "SCOR:";
	str += std::to_string(abs(this->score));
	s = (char *)malloc(sizeof(char) * str.length() + 1);
	i = -1;
	while (++i < str.length())
		s[i] = str[i];
	s[i] = '\0';
	//TO DO!!!
	Text(this->windowWidth / 6, this->windowHeight / 5, s, SerifTypeface, this->windowWidth / 10);
	free(s);
	str = "\0";
	End();
}
