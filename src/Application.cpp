#include <string>
#include "Application.h"

std::string Application::parseRequest(std::string request){
    return "Request: " + request;
};
bool Application::isFinished(){
    return true;
}