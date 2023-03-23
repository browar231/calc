#pragma once
#include "Common.h"
#include <deque>
#include <stack>
struct CalculationToken {
  public:
	enum class TokenType { c_none, c_number, c_operator };
	CalculationToken(std::string string, TokenType type, char precedence)
		: m_string(string), m_type(type), m_precedence(precedence){};
	std::string m_string;
	TokenType m_type;
	char m_precedence;
};
class Calculation {
	// implementation of Shuning yard algorithm
  public:
	Calculation(const std::string &);
	std::string returnAnswer();

  private:
	void parseTokensFromRequest();
	void produceRPNStack();
	std::string evaluateRPN();
	std::string performMathOperation(std::string, std::string, std::string);
	char returnOperatorPrecedence(char);
	bool isCharAnOperator(char);
	std::deque<CalculationToken> m_tokenStack;
	std::string m_expression;
	std::deque<CalculationToken> m_outputQueue;
	std::stack<CalculationToken> m_operatorStack;
};