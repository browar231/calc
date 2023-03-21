#include "Application.h"
#include "Common.h"
int main()
{
    bool running{true};
    std::cout << "Please type your request, allowed operations: +-*/" << std::endl;
    std::cout << "Currently works only for digits" << std::endl;
    std::cout << "Type exit to close" << std::endl;
    while (running)
    {
        Application app;
        std::string input = app.getInputFromConsole();
        std::string_view answer = app.parseRequest(input);
        std::cout << "Answer: " << answer << std::endl;
        running = app.isFinished();
    }
    return 0;
}