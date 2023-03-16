#include <iostream>
#include <string>
#include "Application.h"

//test comment for educational purposes
int main()
{
    Application app;
    bool running{true};
    std::string request;
    std::cout<< "Please type your request, allowed characters: numbers/+/*"<<std::endl;
    std::cout<< "Type exit to close"<<std::endl;
    while (running)
    {
        std::cout << "Request: ";
        std::getline(std::cin >> std::ws, request);
        std::cout << "Answer: " << app.parseRequest(request) << std::endl;
        running = app.isFinished();
    }

    return 0;
}