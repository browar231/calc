#include "Calculation.h"
#include "Common.h"
#include <algorithm>
#include <ctype.h>

Calculation::Calculation(const std::string &expression) {
	m_expression = expression;
	parseTokensFromRequest();
	produceRPNStack();
};
double Calculation::returnAnswer() { return evaluateRPN(); };
void Calculation::parseTokensFromRequest() {
	for (std::string::size_type i = 0; i < m_expression.size(); i++) {
		char character = m_expression[i];
		if (isdigit(character)) {
			double value = character - '0';
			if (!m_tokenStack.empty() && isdigit(m_expression[i - 1])) {
				double previousValue = m_expression[i - 1] - '0';
				previousValue *= 10;
				previousValue += value;
				m_tokenStack.pop_back();
				m_tokenStack.push_back(CalculationToken{
					CalculationToken::TokenType::c_number, previousValue});
			} else {
				m_tokenStack.push_back(CalculationToken{
					CalculationToken::TokenType::c_number, value});
			}
		}
		if (isCharAnOperator(character)) {
			m_tokenStack.push_back(CalculationToken{
				CalculationToken::TokenType::c_operator,
				returnOperatorPrecedence(character), m_expression[i]});
		}
	}
};
void Calculation::produceRPNStack() {
	for (CalculationToken token : m_tokenStack) {
		if (token.m_type == CalculationToken::TokenType::c_number) {
			m_outputQueue.push_back(token);
		}
		if (token.m_type == CalculationToken::TokenType::c_operator) {
			while (!m_operatorStack.empty() &&
				   m_operatorStack.top().m_precedence >= token.m_precedence) {
				m_outputQueue.push_back(m_operatorStack.top());
				m_operatorStack.pop();
			}
			m_operatorStack.push(token);
		}
	}
	while (!m_operatorStack.empty()) {
		m_outputQueue.push_back(m_operatorStack.top());
		m_operatorStack.pop();
	}
}
double Calculation::evaluateRPN() {
	std::stack<CalculationToken> evalStack;
	for (CalculationToken token : m_outputQueue) {
		switch (token.m_type) {
		case CalculationToken::TokenType::c_number:
			evalStack.push(token);
			break;
		case CalculationToken::TokenType::c_operator:
			double a{evalStack.top().m_value};
			evalStack.pop();
			double b{evalStack.top().m_value};
			evalStack.pop();
			double result =
				Calculation::performMathOperation(token.m_operator, a, b);
			evalStack.push(CalculationToken{
				CalculationToken::TokenType::c_number, result});
			break;
		}
	};
	return evalStack.top().m_value;
}
double Calculation::performMathOperation(char mathOperator, double b,
										 double a) {
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
bool Calculation::isCharAnOperator(char c) {
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
char Calculation::returnOperatorPrecedence(char op) {
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