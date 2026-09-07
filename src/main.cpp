#include <iostream>
#include <string>
#include <equation.hpp>

static std::string get_equation_from_arg(int argc, char **argv)
{
	std::string equation = "";

	if (argc > 2)
		std::cerr << "Use: ./computor or ./computor \"EQUATION\"" << std::endl;
	else if (argc == 2)
		return equation = std::string(argv[1]);
	else
		std::getline(std::cin, equation);

	return equation;
}

static void print_terms(const std::string &name, const std::vector<t_element> &terms)
{
	std::cout << name << ":";
	if (terms.empty())
	{
		std::cout << " (none)" << std::endl;
		return;
	}

	for (const t_element &element : terms)
		std::cout << " (term: " << element.term << ", power: " << element.power << ")";
		
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	std::string equation_string = get_equation_from_arg(argc, argv);

	if (equation_string == "")
		return 1;
		
	std::cout << "Equation: " << equation_string << std::endl;
		
	try {
		Equation equation(equation_string);

		calculate_terms(equation);

		print_terms("Left terms", equation.left_terms);
		print_terms("Right terms", equation.right_terms);

		reduce_equation(equation.right_terms, equation.left_terms);

		create_reduce_string(equation);
		std::cout << "Reduced: " << equation.equation_reduced << std::endl;
		
		print_terms("Left terms", equation.left_terms);
		print_terms("Right terms", equation.right_terms);


	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}