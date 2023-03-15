#include <iostream>
#include <string>
#include "Application.h"
int main()
{
    Application app;
    bool running{true};
    std::string request;
    while (running)
    {

        std::getline(std::cin >> std::ws, request); // read a full line of text into age
        std::cout << app.parseRequest(request) << std::endl;
        running = app.isFinished();
    }

    return 0;
}