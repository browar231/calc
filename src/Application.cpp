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
    return Calculation(request);
};
bool Application::isFinished()
{
    return !m_shouldTerminate;
}