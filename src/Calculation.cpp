#include <string>
#include <vector>
// to be deleted
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include "Calculation.h"

#define DEBUG_INFO

#ifdef DEBUG_INFO
#define DEBUG(x) std::cout << x;
#endif
#ifndef DEBUG_INFO
#define DEBUG(x)
#endif

Calculation::Calculation(std::string expression)
{
    m_expression = expression;
};
std::string Calculation::giveAnswer()
{
    parseTokens();
#ifdef DEBUG_INFO
    debugInfo();
#endif
    return "Answer";
};
char Calculation::returnOperatorPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    };
};
void Calculation::parseTokens()
{
    for (char &character : m_expression)
    {
        // TODO: currently works only for digits
        if (isdigit(character))
        {
            m_tokenStack.push_back(CalculationToken{std::string(1, character), CalculationToken::TokenType::c_number, 0});
        }
        if (isCharAnOperator(character))
        {
            m_tokenStack.push_back(CalculationToken{std::string(1, character), CalculationToken::TokenType::c_operator, returnOperatorPrecedence(character)});
        }
    }
};
bool Calculation::isCharAnOperator(char c)
{
    if (c == '+')
        return true;
    if (c == '-')
        return true;
    if (c == '/')
        return true;
    if (c == '*')
        return true;
    return false;
}
void Calculation::debugInfo()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Tokens:" << std::endl;
    std::cout << '\t';
    for (CalculationToken i : m_tokenStack)
    {
        std::cout << i.m_string << '(' << +i.m_precedence << ')' << ' ';
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
};