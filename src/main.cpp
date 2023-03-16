#include <iostream>
#include <string>
#include "Application.h"

//test comment for educational purposes
int main()
{
    Application app;
    bool running{true};
    std::string request;
    while (running)
    {
        std::cout << "Request: ";
        std::getline(std::cin >> std::ws, request);
        std::cout << "Answer: " << app.parseRequest(request) << std::endl;
        running = app.isFinished();
    }

    return 0;
}