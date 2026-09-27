#include <iostream>
#include "equation.hpp"
#include <sstream>

void create_reduce_string(Equation &Eq)
{
	bool any_element_printed = false;

	for (auto it = Eq.left_terms.begin() ; it != Eq.left_terms.end() ; it++)
	{
		if ((*it).term == 0) // Don't print the zeros
			continue ;
		
		std::ostringstream term, power;

		term << (*it).term;
		power << (*it).power;

		if ((*it).term >= 0 && any_element_printed != false)
			Eq.equation_reduced += "+ ";

		Eq.equation_reduced += term.str() + " * X^" + power.str() + " ";
		any_element_printed = true;
	}

	if (any_element_printed == false)
		Eq.equation_reduced += "0";
		
	Eq.equation_reduced += "= 0";
}