#include <algorithm>
#include <ctype.h>
#include "Calculation.h"
#include "Common.h"

Calculation::Calculation(const std::string &expression)
{
    m_expression = expression;
};
std::string Calculation::giveAnswer()
{
    parseTokens();
    assignTokens();
    return evaluateRPN();
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
void Calculation::assignTokens()
{
    for (CalculationToken token : m_tokenStack)
    {
        if (token.m_type == CalculationToken::TokenType::c_number)
        {
            m_outputQueue.push_back(token);
        }
        if (token.m_type == CalculationToken::TokenType::c_operator)
        {
            while (!m_operatorStack.empty() && m_operatorStack.top().m_precedence >= token.m_precedence)
            {
                m_outputQueue.push_back(m_operatorStack.top());
                m_operatorStack.pop();
            }
            m_operatorStack.push(token);
        }
    }
    while (!m_operatorStack.empty())
    {
        m_outputQueue.push_back(m_operatorStack.top());
        m_operatorStack.pop();
    }
}
std::string Calculation::evaluateRPN()
{
    std::stack<std::string> evalStack;
    for (CalculationToken token : m_outputQueue)
    {
        switch (token.m_type)
        {
        case CalculationToken::TokenType::c_number:
            evalStack.push(token.m_string);
            break;
        case CalculationToken::TokenType::c_operator:
            std::string a{evalStack.top()};
            evalStack.pop();
            std::string b{evalStack.top()};
            evalStack.pop();
            std::string result = Calculation::performMathOperation(token.m_string, a, b);
            evalStack.push(result);
            break;
        }
    };
    return evalStack.top();
}
std::string Calculation::performMathOperation(std::string mathOperator, std::string a, std::string b)
{
    double result{0};
    if (!mathOperator.compare("+"))
        result = std::stod(a) + std::stod(b);
    if (!mathOperator.compare("-"))
        result = std::stod(a) - std::stod(b);
    if (!mathOperator.compare("*"))
        result = std::stod(a) * std::stod(b);
    if (!mathOperator.compare("/"))
    {
        if (stoi(a) == 0)
            return 0;
        result = std::stod(b) / std::stod(a);
    }
    return std::to_string(result);
}
char Calculation::returnHighestPrecedenceInOperatorStack()
{
    char precedence = 0;
    // for (CalculationToken token : m_operatorQueue)
    // {
    //     if (token.m_precedence > precedence)
    //         precedence = token.m_precedence;
    // }
    return precedence;
}
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