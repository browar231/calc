#include "Application.h"
#include "Calculation.h"
#include "Common.h"
std::string Application::getInputFromConsole() {
	std::string input;
	std::cout << "Request: ";
	std::getline(std::cin >> std::ws, input);
	return input;
}
std::string Application::parseRequest(std::string request) {
	if (request.compare("exit") == 0) {
		m_shouldTerminate = true;
		return "Terminating";
	};
	Calculation calculation(request);
	double answer = calculation.returnAnswer();
	if (answer == floor(answer)) {
		return std::to_string(int(answer));
	}
	return std::to_string(answer);
};
bool Application::isFinished() { return !m_shouldTerminate; }