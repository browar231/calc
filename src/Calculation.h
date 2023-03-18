#pragma once
#include <string>
#include <vector>

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
    void debugInfo();

private:
    void parseTokens();
    char returnOperatorPrecedence(char);
    bool isCharAnOperator(char);
    std::vector<CalculationToken> m_tokenStack;
    std::string m_expression;
    std::vector<CalculationToken> m_numberQueue;
    std::vector<CalculationToken> m_operatorQueue;
};