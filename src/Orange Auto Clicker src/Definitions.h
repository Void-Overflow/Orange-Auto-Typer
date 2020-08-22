#define OrangeClicker
#ifdef OrangeClicker
#ifndef AutoClicker
#define AutoClicker

#include "Definitions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> 
#include <future>
#include <functional>
#include <chrono>

namespace backLine {
	void backLine(long double gap) {
		if (gap < 1 && gap > 0) {
			std::cout << '\b';
			std::cout << '\b';
			std::cout << '\b';
			for (int i = 0; i < 22; i++) {
				std::cout << '\b';
			}
		}
		if (gap < 9 && gap >= 1) {
			std::cout << '\b';
			for (int i = 0; i < 22; i++) {
				std::cout << '\b';
			}
		}
		if (gap == 9) {
			for (int i = 0; i < 2; i++) {
				std::cout << '\b';
			}
			for (int i = 0; i < 22; i++) {
				std::cout << '\b';
			}
		}
		else if (gap < 99 && gap >= 10) {
			for (int i = 0; i < 2; i++) {
				std::cout << '\b';
			}
			for (int i = 0; i < 22; i++) {
				std::cout << '\b';
			}
		}
		if (gap == 99) {
			for (int i = 0; i < 3; i++) {
				std::cout << '\b';
			}
			for (int i = 0; i < 22; i++) {
				std::cout << '\b';
			}
		}
		else if (gap >= 100 && gap < 999) {
			for (int i = 0; i < 3; i++) {
				std::cout << '\b';
			}
			for (int i = 0; i < 22; i++) {
				std::cout << '\b';
			}
		}
		if (gap == 999) {
			for (int i = 0; i < 4; i++) {
				std::cout << '\b';
			}
			for (int i = 0; i < 22; i++) {
				std::cout << '\b';
			}
		}
		else if (gap >= 1000 && gap < 9999) {
			for (int i = 0; i < 4; i++) {
				std::cout << '\b';
			}
			for (int i = 0; i < 22; i++) {
				std::cout << '\b';
			}
		}
		if (gap == 9999) {
			for (int i = 0; i < 5; i++) {
				std::cout << '\b';
			}
			for (int i = 0; i < 22; i++) {
				std::cout << '\b';
			}
		}
		else if (gap >= 10000 && gap < 86400) {
			for (int i = 0; i < 5; i++) {
				std::cout << '\b';
			}
			for (int i = 0; i < 22; i++) {
				std::cout << '\b';
			}
		}
		else if (gap > 86400) {
			std::cout << "You entered too big of a number. The limit is 86,400 seconds, or 1 day. Try closing restarting this application and entering a smaller value";
		}
	}
}

namespace Click {
	void SendClick(long x, long y) {
		INPUT    Input = { 0 };
		::ZeroMemory(&Input, sizeof(INPUT));
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE;
		Input.mi.dx = x;
		Input.mi.dy = y;
		::SendInput(1, &Input, sizeof(INPUT));
		::ZeroMemory(&Input, sizeof(INPUT));
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE;
		Input.mi.dx = x;
		Input.mi.dy = y;
		::SendInput(1, &Input, sizeof(INPUT));
	}
}

namespace Time {
#ifndef TIME
#define TIME
#define lineSkip "                                                                       "
#define enterEraseLine "                      "
#define seperationLine  "------------------------"
#define seperationEraseLine	

	void delay(long double seconds) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		long double milliseconds = seconds * 1000;
		Sleep(milliseconds);
	}

	int countDown(long double gap) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		while (GetAsyncKeyState(VK_ESCAPE)) {
			return 0;
			return 0;
		}
		const long double gapInterval = gap;
		if (gap != 0) {
			for (int i = 0; i < gapInterval; i++) {
				if (gap <= 10) {
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
				}
				if (gap <= 20 && gap > 10) {
					HANDLE hConsoleb = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsoleb, 6);
				}
				if (gap > 20) {
					HANDLE hConsolec = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsolec, 3);
				}
				std::cout << gap << enterEraseLine;
				auto delayThread = std::async(std::launch::async, Time::delay, 1);
				if (gap == static_cast<int>(gap)) {
					gap--;
				}
				else {
					gap -= gap;
				}
				backLine::backLine(gap);
			}
		}
		if (gap == 0) {
			backLine::backLine(gapInterval);
			HANDLE hConsoleTwo = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsoleTwo, 2);
			std::string entering = "Clicking...";
			std::cout << entering;
			//keybd_event(VK_XBUTTON1, 0, 0, 0);
			//keybd_event(VK_XBUTTON1, 0, KEYEVENTF_KEYUP, 0);
			Click::SendClick(1, 2);
			for (int i = 0; i < 11; i++) {
				std::cout << "\b";
			}
			gap = gapInterval;
		}
#endif 
	}
}

#endif
#endif