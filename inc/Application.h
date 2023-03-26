#pragma once
#include "Common.h"
class Application {
public:
	std::string getInputFromConsole();
	std::string parseRequest(std::string);

private:
	bool m_shouldTerminate = false;
};