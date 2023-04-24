#pragma once
#include <algorithm>
#include <ctype.h>
#include <deque>
#include <math.h>
#include <stack>
#include <stdexcept>
#include <string>
#include <variant>
namespace Calculation {
// implementation of Shuning yard algorithm
enum class TokenType { typeNone,
	typeNumber,
	typeOperator,
	typeParenthesis };
struct CalculationToken {
public:
	// constructor for numbers
	CalculationToken(TokenType type, double value)
		: tokenType(type)
		, tokenValue(value) {};
	// constructor for operators
	CalculationToken(TokenType type, char mathOperator)
		: tokenType(type)
		, tokenOperator(mathOperator) {};
	std::variant<double, char> tokenValue;
	TokenType tokenType;
	char tokenOperator;
};
double returnAnswer(const std::string&);

std::deque<CalculationToken> parseTokensFromRequest(const std::string&);
std::deque<CalculationToken> produceRPNQueue(std::deque<CalculationToken>);
double evaluateRPN(std::deque<CalculationToken>);
double performMathOperation(char, double, double);
char returnOperatorPrecedence(char);
char returnOperatorPrecedence(CalculationToken& token);
bool isCharAnOperator(char);
}; // namespace Calculation