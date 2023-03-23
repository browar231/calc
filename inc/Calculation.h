#pragma once
#include "Common.h"
#include <deque>
#include <stack>
struct CalculationToken {
  public:
	enum class TokenType { c_none, c_number, c_operator };
	// constructor for numbers
	CalculationToken(TokenType type, double value)
		: m_type(type), m_value(value){};
	// constructor for operators
	CalculationToken(TokenType type, char precedence, char mathOperator)
		: m_type(type), m_precedence(precedence), m_operator(mathOperator){};
	double m_value;
	TokenType m_type;
	char m_precedence;
	char m_operator;
};
class Calculation {
	// implementation of Shuning yard algorithm
  public:
	Calculation(const std::string &);
	double returnAnswer();

  private:
	void parseTokensFromRequest();
	void produceRPNStack();
	double evaluateRPN();
	double performMathOperation(char, double, double);
	char returnOperatorPrecedence(char);
	bool isCharAnOperator(char);
	std::deque<CalculationToken> m_tokenStack;
	std::string m_expression;
	std::deque<CalculationToken> m_outputQueue;
	std::stack<CalculationToken> m_operatorStack;
};