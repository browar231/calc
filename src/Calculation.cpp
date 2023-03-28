#include "Calculation.h"
#include "Common.h"
#include <algorithm>
#include <ctype.h>

double Calculation::returnAnswer(const std::string& expression)
{
	std::deque<CalculationToken> parsedTokens = parseTokensFromRequest(expression);
	std::deque<CalculationToken> RPNQueue = produceRPNQueue(parsedTokens);
	return evaluateRPN(RPNQueue);
};
std::deque<CalculationToken>
Calculation::parseTokensFromRequest(const std::string& expression)
{
	std::string buffer = "";
	std::deque<CalculationToken> parsedTokens;
	for (std::string::size_type i = 0; i < expression.size(); i++) {
		char character = expression[i];

		if (isdigit(character) || character == '.') {
			buffer += character;
		}
		if (buffer.empty() && character == '-') {
			buffer += character;
		}
		if (isCharAnOperator(character)) {
			if (!buffer.empty()) {
				parsedTokens.push_back(CalculationToken {
					CalculationToken::TokenType::typeNumber, stod(buffer) });
				buffer.erase();
			}
			parsedTokens.push_back(CalculationToken {
				CalculationToken::TokenType::typeOperator,
				returnOperatorPrecedence(character), character });
		}
	}
	if (!buffer.empty()) {
		parsedTokens.push_back(CalculationToken {
			CalculationToken::TokenType::typeNumber, stod(buffer) });
		buffer.erase();
	}

	return parsedTokens;
};
std::deque<CalculationToken>
Calculation::produceRPNQueue(std::deque<CalculationToken> tokensQueue)
{
	std::deque<CalculationToken> outputQueue;
	std::stack<CalculationToken> operatorStack;
	for (CalculationToken token : tokensQueue) {
		if (token.tokenType == CalculationToken::TokenType::typeNumber) {
			outputQueue.push_back(token);
		}
		if (token.tokenType == CalculationToken::TokenType::typeOperator) {
			while (!operatorStack.empty() && operatorStack.top().tokenPrecedence >= token.tokenPrecedence) {
				outputQueue.push_back(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.push(token);
		}
	}
	while (!operatorStack.empty()) {
		outputQueue.push_back(operatorStack.top());
		operatorStack.pop();
	}
	return outputQueue;
}
double Calculation::evaluateRPN(std::deque<CalculationToken> RPNQueue)
{
	std::stack<CalculationToken> evalStack;
	for (CalculationToken token : RPNQueue) {
		switch (token.tokenType) {
		case CalculationToken::TokenType::typeNumber:
			evalStack.push(token);
			break;
		case CalculationToken::TokenType::typeOperator:
			double a { evalStack.top().tokenValue };
			evalStack.pop();
			double b { evalStack.top().tokenValue };
			evalStack.pop();
			double result = Calculation::performMathOperation(token.tokenOperator, a, b);
			evalStack.push(CalculationToken {
				CalculationToken::TokenType::typeNumber, result });
			break;
		}
	};
	return evalStack.top().tokenValue;
}
double Calculation::performMathOperation(char mathOperator, double b,
	double a)
{
	switch (mathOperator) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			return 0; // to figure out later :)
		return a / b;
	default:
		return 0;
	}
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
char Calculation::returnOperatorPrecedence(char op)
{
	switch (op) {
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
int Calculation::returnOrderOfMagnitude(int x)
{
	int orders { 1 };
	while (x >= 10) {
		orders++;
		x /= 10;
	}
	return orders;
};