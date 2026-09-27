#include <iostream>
#include <complex>
#include "equation.hpp"

static void print_complex(std::complex<double> &num)
{
	double real = num.real();
	double imag = num.imag();

	// fixes std::cout printing -0 
	if (real == 0)
		real = 0;
	if (imag == 0)
		imag = 0;

	std::cout << real << " ";

	if (num.imag() >= 0)
		std::cout << "+ " << num.imag() << "i\n";
	else
		std::cout << "- " << -num.imag() << "i\n";
}

void solve_degree_2(Equation &Eq)
{
	double a = 0;
	double b = 0;
	double c = 0;
	double delta = 0;

	a = Eq.find_term_in_left_terms_by_power(2);  // will ALWAYS exists due the max_power being checked before this function triggers
	b = Eq.find_term_in_left_terms_by_power(1);
	c = Eq.find_term_in_left_terms_by_power(0);

	std::cout << "a: " << a << " | b: " << b << " | c: " << c << std::endl;

	delta = b * b - 4 * a * c;

	if (delta < 0)
	{

		Eq.solution_x1 = std::complex<double>(-b / (2 * a), std::sqrt(-delta) / (2 * a));
		Eq.solution_x2 = std::complex<double>(-b / (2 * a), -1 * (std::sqrt(-delta) / (2 * a)));

		std::cout << "Discriminant is strictly negative, the two complex solutions are:" << std::endl;

		print_complex(Eq.solution_x1);
		print_complex(Eq.solution_x2); 	

		return;
	}
	else if (delta == 0)
		std::cout << "Discriminant is zero, the solution is:" << std::endl;
	else
		std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;

	Eq.solution_x1 = (-b + std::sqrt(std::abs(delta))) / (2 * a);
	Eq.solution_x2 = (-b - std::sqrt(std::abs(delta))) / (2 * a);

	std::cout << Eq.solution_x1.real() << std::endl;
	if (delta != 0)
		std::cout << Eq.solution_x2.real() << std::endl;
}