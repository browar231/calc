#include "Application.h"
#include "Common.h"

int main()
{
	bool running { true };
	std::cout << "Please type your request without spaces, allowed operations: +-*/^"
			  << std::endl;
	std::cout << "Use dot for fractions ie. 10.32+12" << std::endl;
	std::cout << "Type exit to close" << std::endl;
	while (running) {
		std::string input = Application::getInputFromConsole();
		if (input == "exit") {
			running = false;
			break;
		}
		try {
			std::string answer = Application::parseRequest(input);
			std::cout << "Answer: " << answer << std::endl;
		} catch (std::runtime_error& error) {
			std::cout << error.what() << std::endl;
		}
	}
	return 0;
}