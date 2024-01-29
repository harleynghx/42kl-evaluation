#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
public:
	RPN();
	RPN(std::string numbers);
	~RPN();
	RPN(const RPN& rpn);
	RPN& operator=(const RPN& rpn);

	int CalculateNumbers();
	bool GetStatus() const;

	enum Operator
	{
		OP_PLUS,
		OP_MINUS,
		OP_MULT,
		OP_DIV,
	};

private:
	std::stack<std::string> _Notations;
	bool _Status;

	bool ValidateNumber(std::string num) const;
	int ThrowError(std::string msg, bool showIndex=true);
	int GetNumber();
};

#endif