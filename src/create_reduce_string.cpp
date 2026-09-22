#include <iostream>
#include "equation.hpp"
#include <sstream>

void create_reduce_string(Equation &Eq)
{
	Eq.equation_reduced = "";

	for (auto it = Eq.left_terms.begin() ; it != Eq.left_terms.end() ; it++)
	{
		std::ostringstream term, power;
		term << (*it).term;
		power << (*it).power;
		Eq.equation_reduced += term.str() + " * X^" + power.str() + " ";

	}

	Eq.equation_reduced += "= 0";

}