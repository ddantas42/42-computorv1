#ifndef EQUATION_HPP
#define EQUATION_HPP

#include <string>
#include <vector>

typedef struct s_element
{
	int term;
	int power;
} t_element;

class Equation
{
	public:
		Equation();
		Equation(const std::string &equation);
		Equation(const Equation &other);
		~Equation();

		const std::string &getEquation() const;
		void setEquation(const std::string &equation);

	private:
		std::string equation;
		std::vector<t_element> left_terms;
		std::vector<t_element> right_terms;
		std::string equation_reduced;
};

#endif
