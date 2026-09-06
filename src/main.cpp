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
		std::cin >> equation;

	return equation;
}

int main(int argc, char **argv)
{
	std::string equation_string = get_equation_from_arg(argc, argv);

	if (equation_string == "")
		return 1;

	std::cout << "Equation: " << equation_string << std::endl;

	try {
		Equation equation(equation_string);
		// equation.calculate_terms();

	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}



	
	return 0;
}