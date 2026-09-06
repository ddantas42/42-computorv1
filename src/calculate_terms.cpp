#include "equation.hpp"
#include <iostream>
#include <string>

static bool safe_isdigit(char c)
{
	unsigned char casted = static_cast<unsigned char>(c);
	return std::isdigit(casted);
}

static void skip_spaces(std::string::iterator &it)
{
	while (*it == ' ' || *it == '\t')
		it++;
}




static int get_element_term(std::string::iterator &it, std::string equation)
{
	int sign = 1;
	std::string aux_for_number;

	if (*it == '+')
		it++;
	else if (*it == '-')
	{
		sign = 1;
		it++;
	}

	skip_spaces(it);

	for ( ; std::isdigit(static_cast<unsigned char>(*it)) && it != equation.end(); it++)
		aux_for_number += *it;

	std::cout << aux_for_number << std::endl;

	return std::stoi(aux_for_number) * sign;
}



void calculate_terms(Equation &Eq)
{
	std::vector<t_element> *current_terms = &(Eq.left_terms);
	t_element element = {0, 0};

	for (auto it = Eq.equation.begin(); it != Eq.equation.end(); )
	{
		element = {0,0};

		skip_spaces(it);

		if (*it == '=')
		{
			current_terms = &(Eq.right_terms);
			it++;
			continue;
		}

		// Parsing each term  A * X^B
		if (*it == '-' || *it == '+' || std::isdigit(static_cast<unsigned char>(*it)))
		{
			// Getting the Term A first after the sign
			element.term = get_element_term(it, Eq.equation);
			

			// After getting the Term, we skip towards a single *, and skip again to to waiting for an X (variable raised to a power B)
			skip_spaces(it);
			if (*it != '*')
				throw std::invalid_argument("No * after term number " + std::to_string(element.term));
			it++;
			skip_spaces(it);

			// Now allowing spaces in between X and ^ and B
			if (*it != 'X')
				throw std::invalid_argument("No X after " + std::to_string(element.term) + " *");
			it++;
			if (*it != '^')
				throw std::invalid_argument("No ^ after " + std::to_string(element.term) + " X*");
			it++;

			std::string aux_for_number;
			for ( ; std::isdigit(static_cast<unsigned char>(*it)) && it != Eq.equation.end(); it++)
				aux_for_number += *it;


			std::cout << aux_for_number << std::endl;
			element.power = std::stoi(aux_for_number);

			current_terms->push_back(element);
		}
		else
			throw std::invalid_argument("Not expected character");

	}
}

//!! $>./computor "5 * X^0 + 4 * X^1 = 4 * X^0"
