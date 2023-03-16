#include <string>
#include <vector>
// to be deleted
#include <iostream>
#include <algorithm>
#include "Calculation.h"
std::string Calculation(std::string expression)
{
    if (expression.find("+") != std::string::npos)
    {
        std::vector<std::string> expbuffer;
        int negativeSignsAmount = std::count(expression.begin(), expression.end(), '-');
        expbuffer = splitExpression(expression, '+');
        int result = 0;
        for (auto &element : expbuffer)
        {
            result += std::stoi(Calculation(element));
        }
        result *= negativeSignsAmount * -1;
        return std::to_string(result);
    };
    if (expression.find("*") != std::string::npos)
    {
        std::vector<std::string> expbuffer;
        expbuffer = splitExpression(expression, '*');
        int result = 1;
        for (auto &element : expbuffer)
        {
            result *= std::stoi(Calculation(element));
        }
        return std::to_string(result);
    };
    return expression;
};
std::vector<std::string> splitExpression(std::string expression, char splitter)
{
    std::vector<std::string> result;
    std::string current = "";
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == splitter)
        {
            if (current != "")
            {
                result.push_back(current);
                current = "";
            }
            continue;
        }
        current += expression[i];
    }
    if (current.size() != 0)
        result.push_back(current);
    return result;
}