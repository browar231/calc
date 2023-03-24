#pragma once
#include "Common.h"
class Application {
public:
	std::string getInputFromConsole();
	std::string parseRequest(std::string request);
	bool isFinished();

private:
	bool m_shouldTerminate = false;
};