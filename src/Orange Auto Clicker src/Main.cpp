#include "Definitions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> 
#include <future>
#include <functional>
#include <chrono>
#define OrangeTyper

void cite() {
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	HANDLE hConsolec = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsolec, 3);
	std::cout << "Copyright: Comyar D,Void-Overflow" << std::endl << "@https://OrangeTyper.netlify.app";
}

namespace utility {
	void clear() {
		COORD topLeft = { 0, 0 };
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;

		GetConsoleScreenBufferInfo(console, &screen);
		FillConsoleOutputCharacterA(
			console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
		FillConsoleOutputAttribute(
			console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
			screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
		SetConsoleCursorPosition(console, topLeft);
	}

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;

	void setAxis(int x, int y) {
		CursorPosition.X = x;
		CursorPosition.Y = y;
		SetConsoleCursorPosition(console, CursorPosition);
	}
	int endOnKeyState() {
		while (GetAsyncKeyState(VK_END)) {
			return 0;
		}
	}
}

int main() {
	long double gap;
	std::cout << "Please enter how much of a time gap you would like inbetween each click. Please enter the time in seconds." << std::endl;
	std::cin >> gap;
	unsigned int unassignedSlots = 0;

	while (GetAsyncKeyState(VK_ESCAPE))
		return 0;

	utility::clear();
	for (int i = 10; i > 0; i--) {
		std::cout << "Starting in " << i << " seconds...";
		Sleep(1000);
		utility::clear();
	}
	utility::clear();
	std::cout << "Time:" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "  " << std::endl;
	std::cout << "------------------------" << std::endl;
	cite();
	while (true) {
		auto countDownThread = std::async(std::launch::async, Time::countDown, gap);
		utility::setAxis(0,2);
	}
	return 0;
}