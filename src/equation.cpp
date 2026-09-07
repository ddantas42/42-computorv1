#include <equation.hpp>

Equation::Equation() : equation("")
{
}

Equation::Equation(const std::string &equation) : equation(equation)
{

}

Equation::Equation(const Equation &other)
{
	this->equation.assign(other.equation);
}

Equation::~Equation()
{
}