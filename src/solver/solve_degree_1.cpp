#include <iostream>
#include "equation.hpp"

static double find_term_in_equation_by_power(std::vector<t_element> vector, int power)
{
	for (auto it = vector.begin(); it != vector.end(); it++)
	{
		if (power == (*it).power)
			return (*it).term;
	}

	return 0;
}

void solve_degree_1(Equation &Eq)
{
	double a = 0;
	double b = 0;
	double solution;
	
	a = find_term_in_equation_by_power(Eq.left_terms, 1); // will ALWAYS exists due the max_power being checked before this function triggers
	b = find_term_in_equation_by_power(Eq.left_terms, 0);

	std::cout << "a: " << a << " | b: " << b << std::endl;

	solution = -b / a;
	Eq.solution_x1 = Eq.solution_x2 = std::complex<double>(solution);

	// Prevent std::cout printing -0
	if (solution == 0)
		solution = 0;
		
	if (solution >= 0)
		std::cout << solution << std::endl;
	else 
		std::cout << "- " << -solution << std::endl;


}