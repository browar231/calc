#include "Application.h"
#include "Calculation.h"
#include "Common.h"
std::string Application::getInputFromConsole()
{
	std::string input;
	std::cout << "Request: ";
	std::getline(std::cin >> std::ws, input);
	return input;
}
std::string Application::parseRequest(std::string request)
{
	if (request.compare("exit") == 0)
	{
		m_shouldTerminate = true;
		return "Terminating";
	};
	Calculation calculation(request);
	return calculation.returnAnswer();
};
bool Application::isFinished()
{
	return !m_shouldTerminate;
}