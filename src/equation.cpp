#include <equation.hpp>

Equation::Equation() : equation("")
{}

Equation::Equation(const std::string &equation) : equation(equation), equation_reduced("")
{
	this->left_terms.clear();
	this->right_terms.clear();

	this->solution_x1 = 0;
	this->solution_x2 = 0;

	this->max_power = -1;
	
}

Equation::Equation(const Equation &other)
{
	this->equation.assign(other.equation);
}

Equation::~Equation()
{}

double Equation::find_term_in_left_terms_by_power(int power)
{
	for (auto it = this->left_terms.begin(); it != this->left_terms.end(); it++)
	{
		if (power == (*it).power)
			return (*it).term;
	}
	return 0;
}