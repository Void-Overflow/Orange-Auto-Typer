/*******************************************************
This file is for all the definitions related to the Main.cpp c++ file
I also added some features such as namespace Time
for the clock here as well.

For more information about this software,
read the README file in the folder of this application.
*********************************************************/
#ifndef DEFINE
#define DEFINE

#ifndef DEFINITION
#define DEFINITION

	#include <Windows.h>
        #include <iostream>
        #include <String>
	#include <Time.h>
	#include <future>
	#include <functional>
	#include <chrono>
	#include "json/json.h"

	namespace keyVal {
		#ifndef VAL
		#define VAL
			static const char add() {
				static const char add = VK_ADD;
				return add;
			}
			static const char subtract() {
				static const char subtract = VK_SUBTRACT;
				return subtract;
			}
			static const char multiply() {
				static const char multiply = VK_MULTIPLY;
				return multiply;
			}
			static const char divide() {
				static const char divide = VK_DIVIDE;
				return divide;
			}
			


			static const char right() {
				static const char right = VK_RIGHT;
				return right;
			}
			static const char left() {
				static const char left = VK_LEFT;
				return left;
			}
			static const char up() {
				static const char up = VK_UP;
				return up;
			}
			static const char down() {
				static const char down = VK_DOWN;
				return down;
			}
			


			static const char space() {
				static const char space = VK_SPACE;
				return space;
			}
			static const char enter() {
				static const char enter = VK_RETURN;
				return enter;
			}
			static const char escape() {
				static const char escape = VK_ESCAPE;
				return escape;
			}
			static const char control() {
				static const char ctrl = VK_CONTROL;
				return ctrl;
			}
			static const char shift() {
				static const char shift = VK_SHIFT;
				return shift;
			}			
			static const char capslock() {
				static const char capLock = VK_CAPITAL;
				return capLock;
			}
			static const char backspace() {
				static const char backspace = VK_BACK;
				return backspace;
			}
			static const char tab() {
				static const char tab = VK_TAB;
				return tab;
			}
			static const char pause() {
				static const char pause = VK_PAUSE;
				return pause;
			}



			static const char zero() {
				static const char zero = 0x30;
				return zero;
			}
			static const char one() {
				static const char one = 0x31;
				return one;
			}
			static const char two() {
				static const char two = 0x32;
				return two;
			}
			static const char three() {
				static const char three = 0x33;
				return three;
			}
			static const char four() {
				static const char four = 0x34;
				return four;
			}
			static const char five() {
				static const char five = 0x35;
				return five;
			}
			 static const char six() {
				static const char six = 0x36;
				return six;
			}
			static const char seven() {
				static const char seven = 0x37;
				return seven;
			}
			static const char eight() {
				static const char eight = 0x38;
				return eight;
			}
			static const char nine() {
				static const char nine = 0x39;
				return nine;
			}
		
			

			static const  char a() {
				static const char a = 0x41;
				return a;
			}
			static const char b() {
				static const char b = 0x42;
				return b;
			}
			static const char c() {
				static const char c = 0x43;
				return c;
			}
			static const char d() {
				static const char d = 0x44;
				return d;
			}
			static const char e() {
				static const char e = 0x45;
				return e;
			}
			static const char f() {
				static const char f = 0x46;
				return f;
			}
			static const char g() {
				static const char g = 0x47;
				return g;
			}
			static const char h() {
				static const char h = 0x48;
				return h;
			}
			static const char i() {
				static const char i = 0x49;
				return i;
			}
			static const char j() {
				static const char j = 0x4A;
				return j;
			}
			static const char k() {
				static const char k = 0x4B;
				return k;
			}
			static const char l() {
				static const char l = 0x4C;
			}
			static const char m() {
				static const char m = 0x4D;
				return m;
			}
			static const char n() {
				static const char n = 0x4E;
				return n;
			}
			static const char o() {
				static const char o = 0x4F;
				return o;
			}
			static const char p() {
				static const char p = 0x50;
				return p;
			}
			static const char q() {
				static const char q = 0x51;
				return q;
			}
			static const char r() {
				static const char r = 0x52;
				return r;
			}
			static const char s() {
				static const char s = 0x53;
				return s;
			}
			static const char t() {
				static const char t = 0x54;
				return t;
			}
			static const char u() {
				static const char u = 0x55;
				return u;
			}
			static const char v() {
				static const char v = 0x56;
				return v;
			}
			static const char w() {
				static const char w = 0x57;
				return w;
			}
			static const char x() {
				static const char x = 0x58;
				return x;
			}
			static const char y() {
				static const char y = 0x59;
				return y;
			}
			static const char z() {
				static const char z = 0x5A;
				return z;
			}

	#endif
  }

  namespace Keys {
	#ifndef SENDKEYS
	#define SENDKEYS
	  bool keyPressed(int key) {
		  return GetAsyncKeyState(key) == -32767;
	  }
	  bool keyHeld(int key) {
		  return GetAsyncKeyState(key) & 0x8000;
	  }
	  void sendKeyPress(int key) {
		  static INPUT ip;
		  ip.type = INPUT_KEYBOARD;
		  ip.ki.wScan = 0;
		  ip.ki.time = 0;
		  ip.ki.dwExtraInfo = 0;
		  ip.ki.dwFlags = 0;
		  ip.ki.wVk = key;
		  SendInput(1, &ip, sizeof(INPUT));
		  ip.ki.dwFlags = KEYEVENTF_KEYUP;
		  SendInput(1, &ip, sizeof(INPUT));
	  }
	  void sendKeyRelease(int key)  {
		  static INPUT ip;
		  ip.type = INPUT_KEYBOARD;
		  ip.ki.wScan = 0;
		  ip.ki.time = 0;
		  ip.ki.dwExtraInfo = 0;
		  ip.ki.dwFlags = 0;
		  ip.ki.wVk = key;
		  ip.ki.dwFlags = KEYEVENTF_KEYUP;
		  SendInput(1, &ip, sizeof(INPUT));
	  }
	  void SendKeys (const std::string& str)  {
		  for (char c : str){
			  int key;
			  if (c == ' ')
				  key = VK_SPACE;
			  else if (!std::isdigit(c) && !std::isalpha(c))
				  continue;
			  else
				  key = std::toupper(c);
			  sendKeyPress(key);
		  }
	  }
	#endif
  }

  namespace backLine{
	  void backLine(long double gap) {
		  if (gap < 9 && gap >= 1) {
			  std::cout << '\b';
			  for (int i = 0; i < 20; i++) {
				  std::cout << '\b';
			  }
		  }
		  if (gap == 9) {
			  for (int i = 0; i < 2; i++) {
				  std::cout << '\b';
			  }
			  for (int i = 0; i < 20; i++) {
				  std::cout << '\b';
			  }
		  }
		  else if (gap < 99 && gap >= 10) {
			  for (int i = 0; i < 2; i++) {
				  std::cout << '\b';
			  }
			  for (int i = 0; i < 20; i++) {
				  std::cout << '\b';
			  }
		  }
		  if (gap == 99) {
			  for (int i = 0; i < 3; i++) {
				  std::cout << '\b';
			  }
			  for (int i = 0; i < 20; i++) {
				  std::cout << '\b';
			  }
		  }
		  else if (gap >= 100 && gap < 999) {
			  for (int i = 0; i < 3; i++) {
				  std::cout << '\b';
			  }
			  for (int i = 0; i < 20; i++) {
				  std::cout << '\b';
			  }
		  }
		  if (gap == 999) {
			  for (int i = 0; i < 4; i++) {
				  std::cout << '\b';
			  }
			  for (int i = 0; i < 20; i++) {
				  std::cout << '\b';
			  }
		  }
		  else if (gap >= 1000 && gap < 9999) {
			  for (int i = 0; i < 4; i++) {
				  std::cout << '\b';
			  }
			  for (int i = 0; i < 20; i++) {
				  std::cout << '\b';
			  }
		  }
		  if (gap == 9999) {
			  for (int i = 0; i < 5; i++) {
				  std::cout << '\b';
			  }
			  for (int i = 0; i < 20; i++) {
				  std::cout << '\b';
			  }
		  }
		  else if (gap >= 10000 && gap < 86400) {
			  for (int i = 0; i < 5; i++) {
				  std::cout << '\b';
			  }
			  for (int i = 0; i < 20; i++) {
				  std::cout << '\b';
			  }
		  }
		  else if (gap > 86400) {
			  std::cout << "You entered too big of a number. The limit is 86,400 seconds, or 1 day. Try closing restarting this application and entering a smaller value";
		  }
	  }
  }

  namespace Time {
	#ifndef TIME
	#define TIME
		#define lineSkip "                                                                       "
		#define enterEraseLine "                    "
		#define seperationLine  "------------------------"
		#define seperationEraseLine	

		void delay(int seconds) {
		  std::this_thread::sleep_for(std::chrono::milliseconds(200));
		  int milli_seconds = 1000 * seconds;
		  clock_t start_time = clock();
		  while (clock() < start_time + milli_seconds);
		 }
		 
	  int countDown(long double gap, std::string keys, Json::Value prefixAddress) {
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
				  gap--;
				  backLine::backLine(gap);
			  }
		  }
		  if (gap == 0) {
			  backLine::backLine(gapInterval);
			  HANDLE hConsoleTwo = GetStdHandle(STD_OUTPUT_HANDLE);
			  SetConsoleTextAttribute(hConsoleTwo, 2);
			  std::string entering = "Entering...";
			  std::cout << entering;
			  Keys::SendKeys(keys);
			  if (prefixAddress != "") {
				  if (prefixAddress == "{enter}") {
					  keybd_event(VK_RETURN, 0, 0, 0);
					  keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
				  }
				  if (prefixAddress == "{tab}") {
					  keybd_event(VK_TAB, 0, 0, 0);
					  keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
				  }
				   if (prefixAddress == "{space}") {
					  keybd_event(VK_SPACE, 0, 0, 0);
					  keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
				  }
				  if (prefixAddress == "{ctrl}") {
					  keybd_event(VK_CONTROL, 0, 0, 0);
					  keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
				  }
				  if (prefixAddress == "{shift}") {
					  keybd_event(VK_SHIFT, 0, 0, 0);
					  keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
				  }
				  if (prefixAddress != "{shift}" && prefixAddress != "{ctrl}" && prefixAddress != "{space}" && prefixAddress != "{tab}" && prefixAddress != "{enter}") {
					  keybd_event(VK_SPACE, 0, 0, 0);
					  keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
					  Keys::SendKeys("Failed to find prefix");
				  }
			  }
		  }
		  Time::delay(1);
		  for (int i = 0; i < 11; i++) {
			  std::cout << "\b";
		  }
		  HANDLE hConsoleThree = GetStdHandle(STD_OUTPUT_HANDLE);
		  SetConsoleTextAttribute(hConsoleThree, 14);
		  std::cout << "Awaiting Entry...";
		  gap = gapInterval;
	  }
	#endif 
  }     
#endif
#endif
