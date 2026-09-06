#include "equation.hpp"
#include <iostream>
#include <string>

// Get's the first number from where the iterator is, and returns it, having advanced the iterator
static int string_to_first_number(std::string::iterator &it, std::string string)
{
	std::string aux_for_number;
	for ( ; std::isdigit(static_cast<unsigned char>(*it)) && it != string.end(); it++)
		aux_for_number += *it;

	std::cout << aux_for_number << std::endl;
	return std::stoi(aux_for_number);
}

static void skip_spaces(std::string::iterator &it)
{
	while (*it == ' ' || *it == '\t')
		it++;
}

static int get_element_term(std::string::iterator &it, std::string equation)
{
	int sign = 1;

	if (*it == '+')
		it++;
	else if (*it == '-')
	{
		sign = -1;
		it++;
	}

	skip_spaces(it);
	
	return string_to_first_number(it, equation) * sign;
}

// Given the Term A * X^B, This functions make sure we get to B checking everything in between
static void checks_between_A_and_B(std::string::iterator &it, int term)
{
	// Skips spaces towards *
	skip_spaces(it);
	if (*it != '*')
		throw std::invalid_argument("No * after term number " + std::to_string(term));
	it++;

	// Skips spaces towards X after *
	skip_spaces(it);
	
	// Not allowing spaces in between X and ^ and B
	if (*it != 'X')
		throw std::invalid_argument("No X after " + std::to_string(term) + " *");
	it++;
	if (*it != '^')
		throw std::invalid_argument("No ^ after " + std::to_string(term) + " * X");
	it++;
	if (*it == '-') // Invalid Negative Power
		throw std::invalid_argument("- after  " + std::to_string(term) + " * X^");
		
	// Finished checking, now B is on the iterator, we can resume getting B
}


void calculate_terms(Equation &Eq)
{
	std::vector<t_element> *current_terms = &(Eq.left_terms);
	t_element element = {0, 0};

	for (auto it = Eq.equation.begin(); it != Eq.equation.end(); )
	{

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
			element = {0,0};

			// Getting the Term A first after the sign
			element.term = get_element_term(it, Eq.equation);
			
			// After getting the Term, we skip towards a B, checking between so check for invalid characters
			checks_between_A_and_B(it, element.term);
			
			element.power = string_to_first_number(it, Eq.equation);

			current_terms->push_back(element);
		}
		else
			throw std::invalid_argument("Not expected character");

	}
}

//!! $>./computor "5 * X^0 + 4 * X^1 = 4 * X^0"
