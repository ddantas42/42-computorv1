#include <iostream>
#include "equation.hpp"
#include <cmath>
#include <complex>

static void solve_degree_2(Equation &Eq)
{
	double a = Eq.left_terms[0].term;
	double b = Eq.left_terms[1].term;
	double c = Eq.left_terms[2].term;
	double delta = b * b - 4 * a * c;

	Eq.solution_x1 = (-b + std::sqrt(delta)) / (2 * a);
	Eq.solution_x2 = (-b - std::sqrt(delta)) / (2 * a);

	if (delta > 0)
	{
		std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;

		Eq.solution_x1 = (-b + std::sqrt(delta)) / (2 * a);
		Eq.solution_x2 = (-b - std::sqrt(delta)) / (2 * a);
		
		std::cout << Eq.solution_x1 << std::endl;
		std::cout << Eq.solution_x2 << std::endl;
	}
	else if (delta == 0)
	{
		std::cout << "Discriminant is zero, the solution is:" << std::endl;

		// Eq.solution_x1 = Eq.solution_x2 = -b / (2 * a);
		
		std::cout << Eq.solution_x1 << std::endl;

	}
	else 
	{
		std::cout << "Discriminant is strictly negative, the two complex solutions are:" << std::endl;

		// Eq.solution_x1 = -b / 2*a;
		// Eq.solution_x1.imaginary = std::sqrt(std::abs(delta)) / 2*a;


		// Eq.solution_x2 = -b / 2*a;
		// Eq.solution_x2.imaginary = -1 * std::sqrt(std::abs(delta)) / 2*a;
		
		std::cout << Eq.solution_x1 << std::endl;

	}
}

void solve(Equation &Eq)
{
	if (Eq.max_power > 2)
	{
		std::cout << "The polynomial degree is stricly greater than 2, I can't solve." << std::endl;
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
}