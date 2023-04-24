#include "Calculation.h"
#include <algorithm>
#include <ctype.h>
#include <deque>
#include <math.h>
#include <stack>
#include <stdexcept>
#include <string>
#include <variant>

namespace Calculation {
double returnAnswer(const std::string& expression)
{
	if (expression.empty()) {
		throw std::runtime_error("Invalid expression");
	}
	std::deque<CalculationToken> parsedTokens = parseTokensFromRequest(expression);
	if (parsedTokens.empty()) {
		throw std::runtime_error("Invalid expression");
	}
	std::deque<CalculationToken> RPNQueue = produceRPNQueue(parsedTokens);
	return evaluateRPN(RPNQueue);
};
std::deque<CalculationToken>
parseTokensFromRequest(const std::string& expression)
{
	std::string buffer = "";
	std::deque<CalculationToken> parsedTokens;
	for (std::string::size_type i = 0; i < expression.size(); i++) {
		char character = expression[i];

		if (isdigit(character) || character == '.') {
			buffer += character;
			continue;
		}
		if (character == ',') {
			buffer += '.';
			continue;
		}
		if (buffer.empty() && character == '-') {
			buffer += character;
			continue;
		}
		if (isCharAnOperator(character)) {
			if (!buffer.empty()) {
				parsedTokens.emplace_back(TokenType::typeNumber, stod(buffer));
				buffer.erase();
			}
			parsedTokens.emplace_back(TokenType::typeOperator, character);
		}
	}
	if (!buffer.empty()) {
		parsedTokens.emplace_back(
			TokenType::typeNumber, stod(buffer));
		buffer.erase();
	}

	return parsedTokens;
};
std::deque<CalculationToken>
produceRPNQueue(std::deque<CalculationToken> tokensQueue)
{
	std::deque<CalculationToken> outputQueue;
	std::stack<CalculationToken> operatorStack;
	for (CalculationToken token : tokensQueue) {
		if (token.tokenType == TokenType::typeNumber) {
			outputQueue.push_back(token);
		}
		if (token.tokenType == TokenType::typeOperator) {
			while (!operatorStack.empty() && returnOperatorPrecedence(operatorStack.top()) >= returnOperatorPrecedence(token)) {
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
double evaluateRPN(std::deque<CalculationToken> RPNQueue)
{
	std::stack<CalculationToken> evalStack;
	for (CalculationToken token : RPNQueue) {
		switch (token.tokenType) {
		case TokenType::typeNumber:
			evalStack.push(token);
			break;
		case TokenType::typeOperator:
			double a { std::get<double>(evalStack.top().tokenValue) };
			evalStack.pop();
			double b { std::get<double>(evalStack.top().tokenValue) };
			evalStack.pop();
			double result = performMathOperation(token.tokenOperator, a, b);
			evalStack.emplace(
				TokenType::typeNumber, result);
			break;
		}
	};
	return std::get<double>(evalStack.top().tokenValue);
}
double performMathOperation(char mathOperator, double b,
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
			throw std::runtime_error("Dividing by zero");
		return a / b;
	case '^':
		return pow(a, b);
	default:
		return 0;
	}
}
bool isCharAnOperator(char c)
{
	if (c == '+')
		return true;
	if (c == '-')
		return true;
	if (c == '/')
		return true;
	if (c == '*')
		return true;
	if (c == '^')
		return true;
	return false;
}
char returnOperatorPrecedence(char op)
{
	switch (op) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	};
};

char returnOperatorPrecedence(CalculationToken& token)
{
	return returnOperatorPrecedence(std::get<char>(token.tokenValue));
};
}