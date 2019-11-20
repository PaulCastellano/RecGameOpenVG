#include "../include/include.h"

void Game::resultScreen()
{
	std::string str;
	char *s;
	int i;
	WindowClear();
	// Start(this->windowWidth, this->windowHeight);
	Background(255, 255, 255);

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
	Text(0, 0, s, SerifTypeface, this->windowWidth / 10);
	free(s);
	str = "\0";

	End();
}
