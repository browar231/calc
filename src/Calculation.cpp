#include "Calculation.h"
#include "Common.h"
#include <algorithm>
#include <ctype.h>

double Calculation::returnAnswer(const std::string& expression)
{
	std::deque<CalculationToken> parsedTokens = parseTokensFromRequest(expression);
	parsedTokens = organizeNumbers(parsedTokens);
	std::deque<CalculationToken> RPNQueue = produceRPNQueue(parsedTokens);
	return evaluateRPN(RPNQueue);
};
std::deque<CalculationToken>
Calculation::parseTokensFromRequest(const std::string& expression)
{
	std::deque<CalculationToken> parsedTokens;
	for (std::string::size_type i = 0; i < expression.size(); i++) {
		char character = expression[i];
		if (isdigit(character)) {
			double value = character - '0';
			parsedTokens.push_back(CalculationToken {
				CalculationToken::TokenType::typeNumber, value });
		}
		if (isCharAnOperator(character)) {
			parsedTokens.push_back(CalculationToken {
				CalculationToken::TokenType::typeOperator,
				returnOperatorPrecedence(character), expression[i] });
		}
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
std::deque<CalculationToken> Calculation::organizeNumbers(std::deque<CalculationToken> tokens)
{
	// find consecutive digits and turn them into one number
	// thought that moving it to separate function improved readability;
	std::deque<CalculationToken> newTokens;
	for (CalculationToken token : tokens) {
		if (!newTokens.empty() && token.tokenType == CalculationToken::TokenType::typeNumber && newTokens.back().tokenType == CalculationToken::TokenType::typeNumber) {
			double previousValue = newTokens.back().tokenValue;
			previousValue *= 10;
			previousValue += token.tokenValue;
			newTokens.pop_back();
			newTokens.push_back(CalculationToken {
				CalculationToken::TokenType::typeNumber, previousValue });
		} else {
			newTokens.push_back(token);
		}
	}
	return newTokens;
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