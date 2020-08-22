#include <iostream>
#include <String>
#include <Windows.h>
#include "Definitions.hpp"
typedef std::string(*FNPTR)(std::string);

namespace DLLReference {
	class Base {
	public:
		HINSTANCE CSharpInterface;
		FNPTR pressKey;
		int loadDLL() {
			CSharpInterface = LoadLibrary(L"C:\\Users\\dehla\\Desktop\\Visual Studio Projects\\C++\\DiscordTyperCpp\\OrangeAutoTyper.dll");
			if (!CSharpInterface) {
				std::cout << "\nFailed to open DLL" << std::endl;
				return EXIT_FAILURE;
			}
			pressKey = (FNPTR)GetProcAddress(CSharpInterface, "getKeys");
			if (!pressKey) {
				std::cout << "\nCould not locate the function" << std::endl;
				return EXIT_FAILURE;
			}
			return EXIT_SUCCESS;
		}
	};
	class Derived : public Base {
	public:
		std::string SendKeysReference(std::string key) {
			Base baseInstance;
			baseInstance.loadDLL();
			pressKey(key);
			FreeLibrary(CSharpInterface);
			return key;
		}
	};
}
	std::string SendKeys(std::string key) {
		DLLReference::Derived derivedInstance;
		derivedInstance.SendKeysReference(key);
		return key;
	}
