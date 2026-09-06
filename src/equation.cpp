#include <equation.hpp>
#include <bits/stdc++.h>



Equation::Equation() : equation("")
{
}

Equation::Equation(const std::string &equation) : equation(equation)
{

}

Equation::Equation(const Equation &other)
{
	this->equation.assign(equation);
}

Equation::~Equation()
{
}