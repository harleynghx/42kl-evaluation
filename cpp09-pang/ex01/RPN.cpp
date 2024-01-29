#include "RPN.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

RPN::RPN() { RPN(""); }

RPN::RPN(std::string numbers) : _Status(false)
{
	for (std::string::iterator it = numbers.begin(); it < numbers.end(); it++)
	{
		std::string::iterator tmpIt = std::find(it, numbers.end(), ' ');
		if (it == tmpIt)
			continue;

		std::string tmp(it, tmpIt);
		_Notations.push(tmp);
		it = tmpIt;
	}
}

RPN::~RPN() {}

RPN::RPN(const RPN& rpn) : _Notations(rpn._Notations) {}

RPN& RPN::operator=(const RPN& rpn)
{
	_Notations = rpn._Notations;
	return *this;
}

bool RPN::ValidateNumber(std::string num) const
{
	for (std::string::iterator it = num.begin(); it < num.end(); it++)
	{
		if (*it < '0' || *it > '9')
			return false;
	}

	return true;
}

int RPN::ThrowError(std::string msg, bool showIndex)
{
	std::cout << "Error: " << msg;
	if (showIndex)
	{
		std::cout << " at index " << _Notations.size() - 1;
		std::cout << ": " << _Notations.top();
	}
	std::cout << std::endl;
	_Status = false;
	return 0;
}

int RPN::GetNumber()
{
	if (_Notations.size() <= 0)
		return ThrowError("Input ended abruptly", false);

	int num = 0;
	if (_Notations.top().size() == 1 && (_Notations.top()[0] < '0' || _Notations.top()[0] > '9'))
		return CalculateNumbers();

	if (!ValidateNumber(_Notations.top()))
		return ThrowError("Bad number");

	std::stringstream ss(_Notations.top());
	ss >> num;

	_Notations.pop();
	return num;
}

int RPN::CalculateNumbers()
{
	RPN::Operator type;

	_Status = true; // set this to false if something didn't work

	if (_Notations.top().size() != 1)
		return ThrowError("Invalid operator");

	switch (_Notations.top()[0])
	{
		case '+':
			type = OP_PLUS;
			break;

		case '-':
			type = OP_MINUS;
			break;

		case '*':
			type = OP_MULT;
			break;

		case '/':
			type = OP_DIV;
			break;

		default:
			return ThrowError("Invalid operator");
	}
	_Notations.pop();

	int lhs, rhs;

	rhs = GetNumber();
	if (!GetStatus())
		return 0;

	lhs = GetNumber();
	if (!GetStatus())
		return 0;

	switch (type)
	{
		case OP_PLUS:
			return lhs + rhs;

		case OP_MINUS:
			return lhs - rhs;

		case OP_MULT:
			return lhs * rhs;

		case OP_DIV:
			return lhs / rhs;

		default:
			return ThrowError("Something went wrong");
	}
}

bool RPN::GetStatus() const
{
	return _Status;
}
