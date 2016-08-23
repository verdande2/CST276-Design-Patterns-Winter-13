#include <string>
using std::string;

#include <Windows.h>

namespace ConsoleColor
{
	enum COLOR
	{
		BLACK = 0,
		DARK_BLUE = 1,
		DARK_GREEN = 2,
		DARK_AQUA = 3, DARK_CYAN = 3,
		DARK_RED = 4,
		DARK_PURPLE = 5, DARK_PINK = 5, DARK_MAGENTA = 5,
		DARK_YELLOW = 6,
		DARK_WHITE = 7,
		GRAY = 8,
		BLUE = 9,
		GREEN = 10,
		AQUA = 11, CYAN = 11,
		RED = 12,
		PURPLE = 13, PINK = 13, MAGENTA = 13,
		YELLOW = 14,
		WHITE = 15,
		NUM_COLORS = 16
	};
	const string colorNames[] = {"Black", "Dark Blue", "Dark Green", "Dark Aqua/Cyan", "Dark Red", "Dark Purple/Pink/Magenta", "Dark Yellow", "Dark White", "Gray", "Blue", "Green", "Aqua/Cyan", "Red", "Purple/Pink/Magenta", "Yellow", "White"};

	void SetTextColor(ConsoleColor::COLOR color);
	void SetBgColor(ConsoleColor::COLOR color);
	ConsoleColor::COLOR GetTextColor();
	ConsoleColor::COLOR GetBgColor();

	string ColorName(ConsoleColor::COLOR color);
};

void ConsoleColor::SetTextColor(ConsoleColor::COLOR color)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	
	ConsoleColor::COLOR bgColor = GetBgColor();

	csbi.wAttributes = bgColor << 4 | color;
	SetConsoleTextAttribute(hStdOut, csbi.wAttributes);
}

void ConsoleColor::SetBgColor(ConsoleColor::COLOR color)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	
	ConsoleColor::COLOR textColor = GetTextColor();

	csbi.wAttributes = color << 4 | textColor;
	SetConsoleTextAttribute(hStdOut, csbi.wAttributes);
}

ConsoleColor::COLOR ConsoleColor::GetTextColor()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdOut, &csbi);

	unsigned short color = csbi.wAttributes;
	return static_cast<ConsoleColor::COLOR>(color % 16);
}

ConsoleColor::COLOR ConsoleColor::GetBgColor()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdOut, &csbi);

	unsigned short color = csbi.wAttributes;
	return static_cast<ConsoleColor::COLOR>((color / 16) % 16);
}

string ConsoleColor::ColorName(ConsoleColor::COLOR color)
{
	return ConsoleColor::colorNames[color];
}