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
 Or for more detailed help please visit the website for this software at -- https://OrangeTyper.netlify.app
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
#define OrangeTyper

void cite() {

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	HANDLE hConsolec = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsolec, 3);
std::cout << "Copyright: Comyar D,Void-Overflow" << std::endl << "@https://OrangeAutoTyper.netlify.app";
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

	void setAxis(int x, int y, std::string path, std::string prefixPath) {
		if (prefixPath == "") {
			CursorPosition.X = path.length() + 12;
		}
		else {
			CursorPosition.X = path.length() + prefixPath.length() + 16;
		}
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
	std::cout << "Please enter how much of a time gap you would like inbetween each command. Please enter the time in seconds." << std::endl;
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

	std::cout << std::endl << std::endl << unassignedSlots << " out of 20 command slots free." << std::endl;
	cite();
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
					std::string rootOneAsString = root["empty1"]["command"].asString();
					std::string prefixOneAsString = root["empty1"]["prefix"].asString();
					if (root["empty1"]["prefix"] == "")
						utility::setAxis(18, 3, rootOneAsString,prefixOneAsString);
					else
						utility::setAxis(27, 3, rootOneAsString, prefixOneAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootOneAsString, root["empty1"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty1"]["prefix"] == "")
						utility::setAxis(18, 3, rootOneAsString, prefixOneAsString);
					else
						utility::setAxis(27, 3, rootOneAsString, prefixOneAsString);
				}

				if (i == 2 && root["empty2"]["command"] != "") {
					std::string rootTwoAsString = root["empty2"]["command"].asString();
					std::string prefixTwoAsString = root["empty2"]["prefix"].asString();
					if (root["empty2"]["prefix"] == "")
						utility::setAxis(18, 5, rootTwoAsString, prefixTwoAsString);
					else
						utility::setAxis(27, 5, rootTwoAsString, prefixTwoAsString);
					auto countDownThread2 = std::async(std::launch::async, Time::countDown, gap, rootTwoAsString, root["empty2"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty2"]["prefix"] == "")
						utility::setAxis(18, 5, rootTwoAsString, prefixTwoAsString);
					else
						utility::setAxis(27, 5, rootTwoAsString, prefixTwoAsString);

				}
				
				if (i == 3 && root["empty3"]["command"] != "") {
					std::string rootThreeAsString = root["empty3"]["command"].asString();
					std::string prefixThreeAsString = root["empty3"]["prefix"].asString();
					if (root["empty3"]["prefix"] == "")
						utility::setAxis(18, 7, rootThreeAsString, prefixThreeAsString);
					else
						utility::setAxis(27, 7, rootThreeAsString, prefixThreeAsString);
					auto countDownThread3 = std::async(std::launch::async, Time::countDown, gap, rootThreeAsString, root["empty3"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty3"]["prefix"] == "")
						utility::setAxis(18, 7, rootThreeAsString, prefixThreeAsString);
					else
						utility::setAxis(27, 7, rootThreeAsString, prefixThreeAsString);
				}
				if (i == 4 && root["empty4"]["command"] != "") {
					std::string rootFourAsString = root["empty4"]["command"].asString();
					std::string prefixFourAsString = root["empty4"]["prefix"].asString();
					if (root["empty4"]["prefix"] == "")
						utility::setAxis(18, 9, rootFourAsString, prefixFourAsString);
					else
						utility::setAxis(27, 9, rootFourAsString, prefixFourAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootFourAsString, root["empty4"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty4"]["prefix"] == "")
						utility::setAxis(18, 9, rootFourAsString, prefixFourAsString);
					else
						utility::setAxis(27, 9, rootFourAsString, prefixFourAsString);
				}
				if (i == 5 && root["empty5"]["command"] != "") {
					std::string rootFiveAsString = root["empty5"]["command"].asString();
					std::string prefixFiveAsString = root["empty5"]["prefix"].asString();
					if (root["empty5"]["prefix"] == "")
						utility::setAxis(18, 11, rootFiveAsString, prefixFiveAsString);
					else
						utility::setAxis(27, 11, rootFiveAsString, prefixFiveAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootFiveAsString, root["empty5"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty5"]["prefix"] == "")
						utility::setAxis(18, 11, rootFiveAsString, prefixFiveAsString);
					else
						utility::setAxis(27, 11, rootFiveAsString, prefixFiveAsString);
				}
				if (i == 6 && root["empty6"]["command"] != "") {
					std::string rootSixAsString = root["empty6"]["command"].asString();
					std::string prefixSixAsString = root["empty6"]["prefix"].asString();
					if (root["empty6"]["prefix"] == "")
						utility::setAxis(18, 13, rootSixAsString, prefixSixAsString);
					else
						utility::setAxis(27, 13, rootSixAsString, prefixSixAsString);
					auto countDownThreada = std::async(std::launch::async, Time::countDown, gap, rootSixAsString, root["empty6"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty6"]["prefix"] == "")
						utility::setAxis(18, 13, rootSixAsString, prefixSixAsString);
					else
						utility::setAxis(27, 13, rootSixAsString, prefixSixAsString);
				}
				if (i == 7 && root["empty7"]["command"] != "") {
					std::string rootSevenAsString = root["empty7"]["command"].asString();
					std::string prefixSevenAsString = root["empty7"]["prefix"].asString();
					if (root["empty7"]["prefix"] == "")
						utility::setAxis(18, 15, rootSevenAsString, prefixSevenAsString);
					else
						utility::setAxis(27, 15 , rootSevenAsString, prefixSevenAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootSevenAsString, root["empty7"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty7"]["prefix"] == "")
						utility::setAxis(18, 15, rootSevenAsString, prefixSevenAsString);
					else
						utility::setAxis(27, 15, rootSevenAsString, prefixSevenAsString);
				}
				if (i == 8 && root["empty8"]["command"] != "") {
					std::string rootEightAsString = root["empty8"]["command"].asString();
					std::string prefixEightAsString = root["empty8"]["prefix"].asString();
					if (root["empty6"]["prefix"] == "")
						utility::setAxis(18, 17, rootEightAsString, prefixEightAsString);
					else
						utility::setAxis(27, 17, rootEightAsString, prefixEightAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootEightAsString, root["empty8"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty8"]["prefix"] == "")
						utility::setAxis(18, 17, rootEightAsString, prefixEightAsString);
					else
						utility::setAxis(27, 17, rootEightAsString, prefixEightAsString);
				}
				if (i == 9 && root["empty9"]["command"] != "") {
					std::string rootNineAsString = root["empty9"]["command"].asString();
					std::string prefixNineAsString = root["empty9"]["prefix"].asString();
					if (root["empty9"]["prefix"] == "")
						utility::setAxis(18, 19, rootNineAsString, prefixNineAsString);
					else
						utility::setAxis(27, 19, rootNineAsString, prefixNineAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootNineAsString, root["empty9"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty9"]["prefix"] == "")
						utility::setAxis(18, 19, rootNineAsString, prefixNineAsString);
					else
						utility::setAxis(27, 19, rootNineAsString, prefixNineAsString);
				}
				if (i == 10 && root["empty10"]["command"] != "") {
					std::string rootTenAsString = root["empty10"]["command"].asString();
					std::string prefixTenAsString = root["empty10"]["prefix"].asString();
					if (root["empty10"]["prefix"] == "")
						utility::setAxis(18, 21, rootTenAsString, prefixTenAsString);
					else
						utility::setAxis(27, 21, rootTenAsString, prefixTenAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootTenAsString, root["empty10"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty10"]["prefix"] == "")
						utility::setAxis(18, 21, rootTenAsString, prefixTenAsString);
					else
						utility::setAxis(27, 21, rootTenAsString, prefixTenAsString);
				}
				if (i == 11 && root["empty11"]["command"] != "") {
					std::string rootElevenAsString = root["empty11"]["command"].asString();
					std::string prefixElevenAsString = root["empty11"]["prefix"].asString();
					if (root["empty11"]["prefix"] == "")
						utility::setAxis(18, 23, rootElevenAsString, prefixElevenAsString);
					else
						utility::setAxis(27, 23, rootElevenAsString, prefixElevenAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootElevenAsString, root["empty11"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty11"]["prefix"] == "")
						utility::setAxis(18, 23, rootElevenAsString, prefixElevenAsString);
					else
						utility::setAxis(27, 23, rootElevenAsString, prefixElevenAsString);
				}
				if (i == 12 && root["empty12"]["command"] != "") {
					std::string rootTwelveAsString = root["empty12"]["command"].asString();
					std::string prefixTwelveAsString = root["empty12"]["prefix"].asString();
					if (root["empty12"]["prefix"] == "")
						utility::setAxis(18, 25, rootTwelveAsString, prefixTwelveAsString);
					else
						utility::setAxis(27, 25, rootTwelveAsString, prefixTwelveAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootTwelveAsString, root["empty12"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty12"]["prefix"] == "")
						utility::setAxis(18, 25, rootTwelveAsString, prefixTwelveAsString);
					else
						utility::setAxis(27, 25, rootTwelveAsString, prefixTwelveAsString);
				}
				if (i == 13 && root["empty13"]["command"] != "") {
					std::string rootThirteenAsString = root["empty13"]["command"].asString();
					std::string prefixThirteenAsString = root["empty13"]["prefix"].asString();
					if (root["empty13"]["prefix"] == "")
						utility::setAxis(18, 27, rootThirteenAsString, prefixThirteenAsString);
					else
						utility::setAxis(27, 27, rootThirteenAsString, prefixThirteenAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootThirteenAsString, root["empty13"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty13"]["prefix"] == "")
						utility::setAxis(18, 27, rootThirteenAsString, prefixThirteenAsString);
					else
						utility::setAxis(27, 27, rootThirteenAsString, prefixThirteenAsString);
				}
				if (i == 14 && root["empty14"]["command"] != "") {
					std::string rootFourteeAsString = root["empty14"]["command"].asString();
					std::string prefixFourteeAsString = root["empty14"]["prefix"].asString();
					if (root["empty14"]["prefix"] == "")
						utility::setAxis(18, 29, rootFourteeAsString, prefixFourteeAsString);
					else
						utility::setAxis(27, 29, rootFourteeAsString, prefixFourteeAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootFourteeAsString, root["empty14"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty14"]["prefix"] == "")
						utility::setAxis(18, 29, rootFourteeAsString, prefixFourteeAsString);
					else
						utility::setAxis(27, 29, rootFourteeAsString, prefixFourteeAsString);
				}
				if (i == 15 && root["empty15"]["command"] != "") {
					std::string rootFifteenAsString = root["empty15"]["command"].asString();
					std::string prefixFifteenAsString = root["empty15"]["prefix"].asString();
					if (root["empty15"]["prefix"] == "")
						utility::setAxis(18, 31, rootFifteenAsString, prefixFifteenAsString);
					else
						utility::setAxis(27, 31, rootFifteenAsString, prefixFifteenAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootFifteenAsString, root["empty15"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty15"]["prefix"] == "")
						utility::setAxis(18, 31, rootFifteenAsString, prefixFifteenAsString);
					else
						utility::setAxis(27, 31, rootFifteenAsString, prefixFifteenAsString);
				}
				if (i == 16 && root["empty16"]["command"] != "") {
					std::string rootSixteenAsString = root["empty16"]["command"].asString();
					std::string prefixSixteenAsString = root["empty16"]["prefix"].asString();
					if (root["empty16"]["prefix"] == "")
						utility::setAxis(18, 33, rootSixteenAsString, prefixSixteenAsString);
					else
						utility::setAxis(27, 33, rootSixteenAsString, prefixSixteenAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootSixteenAsString, root["empty16"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty16"]["prefix"] == "")
						utility::setAxis(18, 33, rootSixteenAsString, prefixSixteenAsString);
					else
						utility::setAxis(27,33, rootSixteenAsString, prefixSixteenAsString);
				}
				if (i == 17 && root["empty17"]["command"] != "") {
					std::string rootSeventeenAsString = root["empty17"]["command"].asString();
					std::string prefixSeventeenAsString = root["empty17"]["prefix"].asString();
					if (root["empty17"]["prefix"] == "")
						utility::setAxis(18, 35, rootSeventeenAsString, prefixSeventeenAsString);
					else
						utility::setAxis(27, 35, rootSeventeenAsString, prefixSeventeenAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootSeventeenAsString, root["empty17"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty17"]["prefix"] == "")
						utility::setAxis(18, 35, rootSeventeenAsString, prefixSeventeenAsString);
					else
						utility::setAxis(27, 35, rootSeventeenAsString, prefixSeventeenAsString);
				}
				if (i == 18 && root["empty18"]["command"] != "") {
					std::string rootEighteenAsString = root["empty18"]["command"].asString();
					std::string prefixEighteenAsString = root["empty18"]["prefix"].asString();
					if (root["empty18"]["prefix"] == "")
						utility::setAxis(18, 37, rootEighteenAsString, prefixEighteenAsString);
					else
						utility::setAxis(27, 37, rootEighteenAsString, prefixEighteenAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootEighteenAsString, root["empty18"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty18"]["prefix"] == "")
						utility::setAxis(18, 37, rootEighteenAsString, prefixEighteenAsString);
					else
						utility::setAxis(27, 37, rootEighteenAsString, prefixEighteenAsString);
				}
				if (i == 19 && root["empty19"]["command"] != "") {
					std::string rootNineteenAsString = root["empty19"]["command"].asString();
					std::string prefixNineteenAsString = root["empty19"]["prefix"].asString();
					if (root["empty19"]["prefix"] == "")
						utility::setAxis(18, 39, rootNineteenAsString, prefixNineteenAsString);
					else
						utility::setAxis(27, 39, rootNineteenAsString, prefixNineteenAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootNineteenAsString, root["empty19"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty19"]["prefix"] == "")
						utility::setAxis(18, 39, rootNineteenAsString, prefixNineteenAsString);
					else
						utility::setAxis(27, 39, rootNineteenAsString, prefixNineteenAsString);
				}
				if (i == 20 && root["empty20"]["command"] != "") {
					std::string rootTwentyAsString = root["empty20"]["command"].asString();
					std::string prefixTwentyAsString = root["empty20"]["prefix"].asString();
					if (root["empty20"]["prefix"] == "")
						utility::setAxis(18, 41, rootTwentyAsString, prefixTwentyAsString);
					else
						utility::setAxis(27, 41, rootTwentyAsString, prefixTwentyAsString);
					auto countDownThread = std::async(std::launch::async, Time::countDown, gap, rootTwentyAsString, root["empty20"]["prefix"]);
					utility::endOnKeyState();
					if (root["empty20"]["prefix"] == "")
						utility::setAxis(18, 41, rootTwentyAsString, prefixTwentyAsString);
					else
						utility::setAxis(27, 41, rootTwentyAsString, prefixTwentyAsString);
				}
			}
		}
		if (rotateInt == 0) 
			rotateInt = tempRotateInt;				
	}
		return 0;
}
