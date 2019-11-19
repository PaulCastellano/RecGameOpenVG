#include "../include/include.h"

void	Game::scoreScreen()
{
	std::string		str;
	char			*s;
	
	int				i;
	
	Start(this->windowWidth, this->windowHeight);
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
	Text(0, this->windowHeight - this->windowWidth / 50, s, SerifTypeface, this->windowWidth / 50);
	free(s);
	
	if (this->mode == 1)
		str = "Nivel: Usor";
	else if (this->mode == 2)
		str = "Nivel: Mediu";
	else
		str = "Nivel: Hard";
	s = (char *)malloc(sizeof(char) * str.length() + 1);
	i = -1;
	while (++i < str.length())
		s[i] = str[i];
	s[i] = '\0';
	Text(0, this->windowHeight - 2 * TextHeight(SerifTypeface, this->windowWidth / 50), s, SerifTypeface, this->windowWidth / 50);
	End();
}
