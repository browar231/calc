#include <string>
#include "Application.h"
#include "Calculation.h"
std::string Application::parseRequest(std::string request)
{
    if (request.compare("exit") == 0)
    {
        m_shouldTerminate = true;
        return "Terminating";
    };
    Calculation calculation(request);
    return calculation.giveAnswer();
};
bool Application::isFinished()
{
    return !m_shouldTerminate;
}