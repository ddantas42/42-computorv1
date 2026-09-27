#include <iostream>
#include "equation.hpp"

void	solve_degree_0(Equation &Eq)
{
	double a;

	a = Eq.find_term_in_left_terms_by_power(0);

	if (a == 0)
		std::cout << "Any real number is a solution." << std::endl;
	else		
		std::cout << "No solution." << std::endl;

}