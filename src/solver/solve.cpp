#include <iostream>
#include "equation.hpp"
#include <cmath>
#include <complex>

void solve(Equation &Eq)
{
	if (Eq.max_power > 2)
	{
		std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
		return ;
	}	
	else if (Eq.max_power == 2)
	{
		std::cout << "Polynomial degree: 2" << std::endl;
		solve_degree_2(Eq);
	}
	else if (Eq.max_power == 1)
	{
		std::cout << "Polynomial degree: 1" << std::endl;
		// solve_degree_1(Eq);
	}
	else if (Eq.max_power == 0)
	{
		std::cout << "Polynomial degree: 0" << std::endl;
		// solve_degree_0(Eq);
	}
	else // Should never trigger since checked in parsing
		throw std::invalid_argument("Invalid Polynomial: " + std::to_string(Eq.max_power));
}