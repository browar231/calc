#include <string>
#include "Application.h"

std::string Application::parseRequest(std::string request)
{
    if (request.compare("exit") == 0)
    {
        m_shouldTerminate = true;
        return "Terminating";
    };
    return "Request: " + request;
};
bool Application::isFinished()
{
    return !m_shouldTerminate;
}