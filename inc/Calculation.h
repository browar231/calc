#pragma once
#include "Common.h"
#include <deque>
#include <stack>
struct CalculationToken {
public:
	enum class TokenType { typeNone,
		typeNumber,
		typeOperator };
	// constructor for numbers
	CalculationToken(TokenType type, double value)
		: tokenType(type)
		, tokenValue(value) {};
	// constructor for operators
	CalculationToken(TokenType type, char precedence, char mathOperator)
		: tokenType(type)
		, tokenPrecedence(precedence)
		, tokenOperator(mathOperator) {};
	double tokenValue;
	TokenType tokenType;
	char tokenPrecedence;
	char tokenOperator;
};
namespace Calculation {
// implementation of Shuning yard algorithm
double returnAnswer(const std::string&);

std::deque<CalculationToken> parseTokensFromRequest(const std::string&);
std::deque<CalculationToken> produceRPNQueue(std::deque<CalculationToken>);
double evaluateRPN(std::deque<CalculationToken>);
std::deque<CalculationToken> organizeNumbers(std::deque<CalculationToken> tokens);
double performMathOperation(char, double, double);
char returnOperatorPrecedence(char);
bool isCharAnOperator(char);
}; // namespace Calculation