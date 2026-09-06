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
	int sign = 0;
	std::string aux_for_number;

	if (*it == '-')
		sign = -1;
	else
		sign = 1;
	
	it++;

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

		else if (*it == '-' || *it == '+' || std::isdigit(static_cast<unsigned char>(*it)))
		{
			element.term = get_element_term(it, Eq.equation);
			current_terms->push_back(element);

			skip_spaces(it);

			if (*it != '*')
				throw std::invalid_argument("No * after term number " + std::to_string(element.term));


		}
	}
}

//!! $>./computor "5 * X^0 + 4 * X^1 = 4 * X^0"
