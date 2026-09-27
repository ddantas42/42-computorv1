#include <iostream>
#include "equation.hpp"

void solve_degree_1(Equation &Eq)
{
	double a = 0;
	double b = 0;
	double solution;
	
	a = Eq.find_term_in_left_terms_by_power(1);  // will ALWAYS exists due the max_power being checked before this function triggers
	b = Eq.find_term_in_left_terms_by_power(0);

	// std::cout << "a: " << a << " | b: " << b << std::endl;

	solution = -b / a;
	Eq.solution_x1 = Eq.solution_x2 = std::complex<double>(solution);

	// Prevent std::cout printing -0
	if (solution == 0)
		solution = 0;
		
	std::cout << solution << std::endl;


}