#pragma once
#include <string>
#include <vector>
#include <stack>
#include <deque>

struct CalculationToken
{
public:
    enum class TokenType
    {
        c_none,
        c_number,
        c_operator
    };
    CalculationToken(std::string string, TokenType type, char precedence) : m_string(string), m_type(type), m_precedence(precedence){};
    std::string m_string;
    TokenType m_type;
    char m_precedence;
};
class Calculation
{
    // implementation of Shuning yard algorithm
public:
    Calculation(std::string);
    std::string giveAnswer();

private:
    void parseTokens();
    void assignTokens();
    char returnOperatorPrecedence(char);
    char returnHighestPrecedenceInOperatorStack();
    bool isCharAnOperator(char);
    std::deque<CalculationToken> m_tokenStack;
    std::string m_expression;
    std::deque<CalculationToken> m_outputQueue;
    std::stack<CalculationToken> m_operatorStack;
    // debug
public:
    void debugInfo();
    void debugOutput();
};