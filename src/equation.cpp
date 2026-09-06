#include <equation.hpp>

Equation::Equation()
{
	this->equation = "";
}

Equation::Equation(const std::string &equation) : equation(equation)
{

}

Equation::Equation(const Equation &other)
{
	this->equation = other.equation;
}

Equation::~Equation()
{
}

const std::string &Equation::getEquation() const
{
	return this->equation;
}

void Equation::setEquation(const std::string &equation)
{
	this->equation = equation;
}
