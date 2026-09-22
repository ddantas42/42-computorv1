#ifndef EQUATION_HPP
#define EQUATION_HPP

#include <string>
#include <vector>

typedef struct s_element
{
	double term;
	int power;
	
} t_element;

class Equation
{
	public:
		Equation();
		Equation(const std::string &equation);
		Equation(const Equation &other);
		~Equation();

		void calculate_terms();

		std::vector<t_element> left_terms;
		std::vector<t_element> right_terms;
		std::string equation;
		std::string equation_reduced;

		int max_power;
		
};

void	calculate_terms(Equation &Eq);
void	reduce_equation(Equation &Eq);
void	create_reduce_string(Equation &Eq);
void	solve(Equation &Eq);

#endif
