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
	double answer = Calculation::returnAnswer(request);
	if (answer == floor(answer)) {
		return std::to_string(int(answer));
	}
	return std::to_string(answer);
};