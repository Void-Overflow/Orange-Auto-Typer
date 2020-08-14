/**********************************************************************************************************************************************
 Comyar D/Void-Overflow 2020

Description:
This auto typer is a great and simple auto typer to use! 
It is currently in ALPHA testing and will be open to new features, updates, and encancements. 
There may be bugs as this is relativly new. If you wish to use this application and/or add your own features to it feel free. 
Just note that comercial usage or redistributions of this software with my code is not allowed without approval by Comyar D/Void_Overflow.
This is a C++ native application with usage from the Windows.h library. This may not work on other platforms other than Windows.

How to Use:
When you download Orange Auto Typer, you should get a folder. Inside of that folder there should be 3 things, a folder named src, 
an application called Orange Auto Typer, and a file called commands.json. 
commands.json is the commands that will be used by the application. Open the commands.json file,
and there will be an example of how to use it demonstrated with the "beg" object. 
For help on how to use json, prefix an issue on this repository. Once you have prefixed the commands in json,
open the Orange Auto Typer application and follow the steps required.

 Cites:
 Orange Auto Typer is created and owned by Comyar D/Void_Overflow.
 To contact me for support or more information about
 this application, visit my Github repository at --
 https://github.com/Void-Overflow?tab=repositories
 Or for more detailed help please visit the website for this software at -- https://OrangeAutoTyper.netlify.app
 For more precise help methods and for beginners with no knowledge of git or github. For help please send an email
 to the correspoding email address @ -- OrangeSupport@gmail.com
 Redistribution of this software is not prohibited without approval from Comyar D/Void_Overflow.
 To assign keyslot values, go to the "commands.json" file and add the commands and  prefixes you would like.
 For more information or help about the software, please visit the corresponding Github repository
 for it at -- https://github.com/Void-Overflow/Orange-Auto-Typer and submit an issue. Or, visit my website at -- 
 https://OrangeAutoTyper.netlify.app for help on how to submit an issue and more general information


 Jsoncpp is not my software nor do I own or have any relation to the creation or management
 of the software. For more information about Jsoncpp please vitit their Github repository at --
 https://github.com/open-source-parsers/jsoncpp

 WARNING: ANY BAN,INFRACTION,PUNISHMENT,MISDEMEANOR,OR FELONY INFLICTED BY ORANGE AUTO TYPER
 IS NOT MY RESPONSIBILITY NOR THE FAULT OF MY SOFTWARE. WHAT IS DONE WITH THIS SOFTWARE IS COMPLETLY UP TO THE USER!!!
****************************************************************************************************************************************************/

#include <iostream>
#include "json/json.h"
#include <fstream>
#include <string>
#include <Windows.h> 
#include "Definitions.hpp"
#include <future>
#include <functional>
#include <chrono>

//EXAMPLE PRINT FUNCTIONS
//void beg() {	
//	keybd_event(0x50, 0, 0, 0);
//	keybd_event(0x50, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x4C, 0, 0, 0);
//	keybd_event(0x4C, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x53, 0, 0, 0);
//	keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(VK_SPACE, 0, 0, 0);
//	keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x42, 0, 0, 0);
//	keybd_event(0x42, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x45, 0, 0, 0);
//	keybd_event(0x45, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x47, 0, 0, 0);
//	keybd_event(0x47, 0, KEYEVENTF_KEYUP, 0);
//}
//
//void deposit() {
//	keybd_event(0x50, 0, 0, 0);
//	keybd_event(0x50, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x4C, 0, 0, 0);
//	keybd_event(0x4C, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x53, 0, 0, 0);
//	keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(VK_SPACE, 0, 0, 0);
//	keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x44, 0, 0, 0);
//	keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x45, 0, 0, 0);
//	keybd_event(0x45, 0, KEYEVENTF_KEYUP, 0);
//	
//	keybd_event(0x50, 0, 0, 0);
//	keybd_event(0x50, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(VK_SPACE, 0, 0, 0);
//	keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x41, 0, 0, 0);
//	keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x4C, 0, 0, 0);
//	keybd_event(0x4C, 0, KEYEVENTF_KEYUP, 0);
//
//	keybd_event(0x4C, 0, 0, 0);
//	keybd_event(0x4C, 0, KEYEVENTF_KEYUP, 0);
//}

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
	std::ifstream file_input("commands.json");

	Json::CharReaderBuilder builder;
	Json::Value root;
	JSONCPP_STRING errs;

	if (!parseFromStream(builder, file_input, &root, &errs)) {
		std::cout << errs << std::endl;
		return EXIT_FAILURE;
	}

	long double gap;
	std::cout << "Please enter the amount of time space you would like inbetween each command. Please enter the time in seconds." << std::endl;
	std::cin >> gap;
	unsigned int unassignedSlots = 0;

	while (GetAsyncKeyState(VK_ESCAPE))
		return 0;

	std::cout << "Starting in 10 seconds...";
	//Sleep(10000);
	utility::clear();

	if (root["empty1"]["command"] == "") {
		unassignedSlots++;
	}
	if (root["empty2"]["command"] == "") {
		unassignedSlots++;
	}
	if (root["empty3"]["command"] == "") {
		unassignedSlots++;
	}
	if (root["empty4"]["command"] == "") {
		unassignedSlots++;
	}
	if (root["empty5"]["command"] == "") {
		unassignedSlots++;
	}
	if (root["empty6"]["command"] == "") {
		unassignedSlots++;
	}
	if (root["empty7"]["command"] == "") {
		unassignedSlots++;
	}
	if (root["empty8"]["command"] == "") {
		unassignedSlots++;
	}
	if (root["empty9"]["command"] == "") {
		unassignedSlots++;
	}
	if (root["empty10"]["command"] == "") {
		unassignedSlots++;
	}
	if (root["empty11"]["command"] == "") {
		unassignedSlots++;
	}

	if (root["empty12"]["command"] == "") {
		unassignedSlots++;
	}

	if (root["empty13"]["command"] == "") {
		unassignedSlots++;
	}

	if (root["empty14"]["command"] == "") {
		unassignedSlots++;
	}

	if (root["empty15"]["command"] == "") {
		unassignedSlots++;
	}

	if (root["empty16"]["command"] == "") {
		unassignedSlots++;
	}

	if (root["empty17"]["command"] == "") {
		unassignedSlots++;
	}

	if (root["empty18"]["command"] == "") {
		unassignedSlots++;
	}

	if (root["empty19"]["command"] == "") {
		unassignedSlots++;
	}

	if (root["empty20"]["command"] == "") {
		unassignedSlots++;
	}


	std::cout << "Commands:" << "||" << "Prefixs: || Time: ||" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "------------------------" << std::endl;


	if (root["empty1"]["command"] != "") {
			std::cout << "Slot 1" << ": " << root["empty1"]["command"] << "||"; 

			if (root["empty1"]["prefix"] != "") 
				std::cout << root["empty1"]["prefix"] << "||";	

			std::cout << "Awaiting Entry..." << std::endl;
			std::cout << "------------------------" << std::endl;
	}

	if (root["empty2"]["command"] != "") {
		std::cout << "Slot 2" << ": " << root["empty2"]["command"] << "||";

		if (root["empty2"]["prefix"] != "")
			std::cout << root["empty2"]["prefix"] << "||"; 

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty3"]["command"] != "") {
		std::cout << "Slot 3" << ": " << root["empty3"]["command"] << "||";

		if (root["empty3"]["prefix"] != "")
			std::cout << root["empty3"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty4"]["command"] != "") {
		std::cout << "Slot 4" << ": " << root["empty4"]["command"] << "||";

		if (root["empty4"]["prefix"] != "")
			std::cout << root["empty4"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty5"]["command"] != "") {
		std::cout << "Slot 5" << ": " << root["empty5"]["command"] << "||";

		if (root["empty5"]["prefix"] != "")
			std::cout << root["empty5"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty6"]["command"] != "") {
		std::cout << "Slot 6" << ": " << root["empty6"]["command"] << "||";

		if (root["empty6"]["prefix"] != "")
			std::cout << root["empty6"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty7"]["command"] != "") {
		std::cout << "Slot 7" << ": " << root["empty7"]["command"] << "||";

		if (root["empty7"]["prefix"] != "")
			std::cout << root["empty7"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty8"]["command"] != "") {
		std::cout << "Slot 8" << ": " << root["empty8"]["command"] << "||";

		if (root["empty8"]["prefix"] != "")
			std::cout << root["empty8"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty9"]["command"] != "") {
		std::cout << "Slot 9" << ": " << root["empty9"]["command"] << "||";

		if (root["empty9"]["prefix"] != "")
			std::cout << root["empty9"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty10"]["command"] != "") {
		std::cout << "Slot 10" << ": " << root["empty10"]["command"] << "||";

		if (root["empty10"]["prefix"] != "")
			std::cout << root["empty10"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty11"]["command"] != "") {
		std::cout << "Slot 11" << ": " << root["empty11"]["command"] << "||";

		if (root["empty11"]["prefix"] != "")
			std::cout << root["empty11"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty12"]["command"] != "") {
		std::cout << "Slot 12" << ": " << root["empty12"]["command"] << "||";

		if (root["empty12"]["prefix"] != "")
			std::cout << root["empty12"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty13"]["command"] != "") {
		std::cout << "Slot 13" << ": " << root["empty13"]["command"] << "||";

		if (root["empty13"]["prefix"] != "")
			std::cout << root["empty13"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty14"]["command"] != "") {
		std::cout << "Slot 14" << ": " << root["empty14"]["command"] << "||";

		if (root["empty14"]["prefix"] != "")
			std::cout << root["empty14"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty15"]["command"] != "") {
		std::cout << "Slot 15" << ": " << root["empty15"]["command"] << "||";

		if (root["empty15"]["prefix"] != "")
			std::cout << root["empty15"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}


	if (root["empty16"]["command"] != "") {
		std::cout << "Slot 16" << ": " << root["empty16"]["command"] << "||";

		if (root["empty16"]["prefix"] != "")
			std::cout << root["empty16"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty17"]["command"] != "") {
		std::cout << "Slot 17" << ": " << root["empty17"]["command"] << "||";

		if (root["empty17"]["prefix"] != "")
			std::cout << root["empty17"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty18"]["command"] != "") {
		std::cout << "Slot 18" << ": " << root["empty18"]["command"] << "||";

		if (root["empty18"]["prefix"] != "")
			std::cout << root["empty18"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty19"]["command"] != "") {
		std::cout << "Slot 19" << ": " << root["empty19"]["command"] << "||";

		if (root["empty19"]["prefix"] != "")
			std::cout << root["empty19"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	if (root["empty20"]["command"] != "") {
		std::cout << "Slot 20" << ": " << root["empty20"]["command"] << "||";

		if (root["empty20"]["prefix"] != "")
			std::cout << root["empty20"]["prefix"] << "||";

		std::cout << "Awaiting Entry..." << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	std::cout << std::endl << std::endl << "The rest of your command slots are empty. To assign a command to a slot, open the 'commands.json' file in your application folder You have: " << unassignedSlots << " out of 20 command slots free to use. For help "
		"setting up the commands please visit the official website at -- https://OrangeAutoTyper.netlify.app " << std::endl;
	int rotateInt = 21;
	const int tempRotateInt = rotateInt;
	while (1) {
		const int rotateIntInterval = rotateInt;
		utility::endOnKeyState();
		if (rotateInt != 0) {
			for (int i = 0; i < rotateIntInterval; i++) {
				utility::endOnKeyState();
				rotateInt--;
				if (i == 1 && root["empty1"]["command"] != "") {
					if (root["empty1"]["prefix"] == "")
						utility::setAxis(18, 3);
					else
						utility::setAxis(27, 3);
					std::string rootOneAsString = root["empty1"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty1"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty1"]["prefix"] == "")
						utility::setAxis(18, 3);
					else
						utility::setAxis(27, 3);
				}

				if (i == 2 && root["empty2"]["command"] != "") {
					if (root["empty2"]["prefix"] == "")
						utility::setAxis(18, 5);
					else
						utility::setAxis(27,5);
					std::string rootTwoAsString = root["empty2"]["command"].asString();
					auto countDownThread2 = std::async(std::launch::async, Time::countDown, gap, rootTwoAsString, root["empty2"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty2"]["prefix"] == "")
						utility::setAxis(18, 5);
					else
						utility::setAxis(27, 5);

				}
				if (i == 3 && root["empty3"]["command"] != "") {
					if (root["empty3"]["prefix"] == "")
						utility::setAxis(18, 7);
					else
						utility::setAxis(27, 7);
					std::string rootThreeAsString = root["empty3"]["command"].asString();
					auto countDownThread3 = std::async(std::launch::async, Time::countDown, gap, rootThreeAsString, root["empty3"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty3"]["prefix"] == "")
						utility::setAxis(18, 7);
					else
						utility::setAxis(27, 7);
				}
				if (i == 4 && root["empty4"]["command"] != "") {
					if (root["empty4"]["prefix"] == "")
						utility::setAxis(18, 9);
					else
						utility::setAxis(27, 9);
					std::string rootOneAsString = root["empty4"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty4"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty4"]["prefix"] == "")
						utility::setAxis(18, 9);
					else
						utility::setAxis(27, 9);
				}
				if (i == 5 && root["empty5"]["command"] != "") {
					if (root["empty5"]["prefix"] == "")
						utility::setAxis(18, 11);
					else
						utility::setAxis(27, 11);
					std::string rootOneAsString = root["empty5"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty5"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty5"]["prefix"] == "")
						utility::setAxis(18, 11);
					else
						utility::setAxis(27, 11);
				}
				if (i == 6 && root["empty6"]["command"] != "") {
					if (root["empty6"]["prefix"] == "")
						utility::setAxis(18, 13);
					else
						utility::setAxis(27, 13);
					std::string rootOneAsString = root["empty6"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty6"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty6"]["prefix"] == "")
						utility::setAxis(18, 13);
					else
						utility::setAxis(27, 13);
				}
				if (i == 7 && root["empty7"]["command"] != "") {
					if (root["empty7"]["prefix"] == "")
						utility::setAxis(18, 15);
					else
						utility::setAxis(27, 15);
					std::string rootOneAsString = root["empty7"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty7"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty7"]["prefix"] == "")
						utility::setAxis(18, 15);
					else
						utility::setAxis(27, 15);
				}
				if (i == 8 && root["empty8"]["command"] != "") {
					if (root["empty6"]["prefix"] == "")
						utility::setAxis(18, 17);
					else
						utility::setAxis(27, 17);
					std::string rootOneAsString = root["empty8"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty8"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty8"]["prefix"] == "")
						utility::setAxis(18, 17);
					else
						utility::setAxis(27, 17);
				}
				if (i == 9 && root["empty9"]["command"] != "") {
					if (root["empty9"]["prefix"] == "")
						utility::setAxis(18, 19);
					else
						utility::setAxis(27, 19);
					std::string rootOneAsString = root["empty9"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty9"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty9"]["prefix"] == "")
						utility::setAxis(18, 19);
					else
						utility::setAxis(27, 19);
				}
				if (i == 10 && root["empty10"]["command"] != "") {
					if (root["empty10"]["prefix"] == "")
						utility::setAxis(18, 21);
					else
						utility::setAxis(27, 21);
					std::string rootOneAsString = root["empty10"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty10"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty10"]["prefix"] == "")
						utility::setAxis(18, 21);
					else
						utility::setAxis(27, 21);
				}
				if (i == 11 && root["empty11"]["command"] != "") {
					if (root["empty11"]["prefix"] == "")
						utility::setAxis(18, 23);
					else
						utility::setAxis(27, 23);
					std::string rootOneAsString = root["empty11"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty11"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty11"]["prefix"] == "")
						utility::setAxis(18, 23);
					else
						utility::setAxis(27, 23);
				}
				if (i == 12 && root["empty12"]["command"] != "") {
					if (root["empty12"]["prefix"] == "")
						utility::setAxis(18, 25);
					else
						utility::setAxis(27, 25);
					std::string rootOneAsString = root["empty12"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty12"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty12"]["prefix"] == "")
						utility::setAxis(18, 25);
					else
						utility::setAxis(27, 25);
				}
				if (i == 13 && root["empty13"]["command"] != "") {
					if (root["empty13"]["prefix"] == "")
						utility::setAxis(18, 27);
					else
						utility::setAxis(27, 27);
					std::string rootOneAsString = root["empty13"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty13"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty13"]["prefix"] == "")
						utility::setAxis(18, 27);
					else
						utility::setAxis(27, 27);
				}
				if (i == 14 && root["empty14"]["command"] != "") {
					if (root["empty14"]["prefix"] == "")
						utility::setAxis(18, 29);
					else
						utility::setAxis(27, 29);
					std::string rootOneAsString = root["empty14"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty14"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty14"]["prefix"] == "")
						utility::setAxis(18, 29);
					else
						utility::setAxis(27, 29);
				}
				if (i == 15 && root["empty15"]["command"] != "") {
					if (root["empty15"]["prefix"] == "")
						utility::setAxis(18, 31);
					else
						utility::setAxis(27, 31);
					std::string rootOneAsString = root["empty15"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty15"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty15"]["prefix"] == "")
						utility::setAxis(18, 31);
					else
						utility::setAxis(27, 31);
				}
				if (i == 16 && root["empty16"]["command"] != "") {
					if (root["empty16"]["prefix"] == "")
						utility::setAxis(18, 33);
					else
						utility::setAxis(27, 33);
					std::string rootOneAsString = root["empty16"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty16"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty16"]["prefix"] == "")
						utility::setAxis(18, 33);
					else
						utility::setAxis(27,33);
				}
				if (i == 17 && root["empty17"]["command"] != "") {
					if (root["empty17"]["prefix"] == "")
						utility::setAxis(18, 35);
					else
						utility::setAxis(27, 35);
					std::string rootOneAsString = root["empty17"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty17"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty17"]["prefix"] == "")
						utility::setAxis(18, 35);
					else
						utility::setAxis(27, 35);
				}
				if (i == 18 && root["empty18"]["command"] != "") {
					if (root["empty18"]["prefix"] == "")
						utility::setAxis(18, 37);
					else
						utility::setAxis(27, 37);
					std::string rootOneAsString = root["empty18"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty18"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty18"]["prefix"] == "")
						utility::setAxis(18, 37);
					else
						utility::setAxis(27, 37);
				}
				if (i == 19 && root["empty19"]["command"] != "") {
					if (root["empty19"]["prefix"] == "")
						utility::setAxis(18, 39);
					else
						utility::setAxis(27, 39);
					std::string rootOneAsString = root["empty19"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty19"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty19"]["prefix"] == "")
						utility::setAxis(18, 39);
					else
						utility::setAxis(27, 39);
				}
				if (i == 20 && root["empty20"]["command"] != "") {
					if (root["empty20"]["prefix"] == "")
						utility::setAxis(18, 41);
					else
						utility::setAxis(27, 41);
					std::string rootOneAsString = root["empty20"]["command"].asString();
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty20"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty20"]["prefix"] == "")
						utility::setAxis(18, 41);
					else
						utility::setAxis(27, 41);
				}
			}

		}
		if (rotateInt == 0) 
			rotateInt = tempRotateInt;				
	}
		return 0;
}