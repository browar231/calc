#pragma once
#include <string>
class Application
{
public:
    std::string parseRequest(std::string request);
    bool isFinished();

private:
    bool m_shouldTerminate = false;
};