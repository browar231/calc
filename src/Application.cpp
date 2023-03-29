#include "Application.h"
#include "Calculation.h"
#include "Common.h"
namespace Application {
std::string getInputFromConsole()
{
	std::string input;
	std::cout << "Request: ";
	std::getline(std::cin >> std::ws, input);
	return input;
}
std::string parseRequest(std::string request)
{
	double answer = Calculation::returnAnswer(request);
	if (answer == floor(answer)) {
		return std::to_string(int(answer));
	}
	return std::to_string(answer);
};
}