#include <iostream>
#include "equation.hpp"

int calculate_max_polinomial(std::vector<t_element> &right_terms, std::vector<t_element> &left_terms)
{
	int max_polinomio = 0;

	for (auto it = left_terms.begin() ; it != left_terms.end(); it++)
		if ((*it).power > max_polinomio)
			max_polinomio = (*it).power;

	for (auto it = right_terms.begin() ; it != right_terms.end(); it++)
		if ((*it).power > max_polinomio)
			max_polinomio = (*it).power;
	
	return max_polinomio;
}



void reduce_equation(std::vector<t_element> &right_terms, std::vector<t_element> &left_terms)
{
	double  sum = 0;
	int     max_polinomio = calculate_max_polinomial(right_terms, left_terms);
	int		polinomio = max_polinomio;
	std::vector<t_element> 	new_vector;
	t_element	new_element = {0,0};

	while (polinomio >= 0)
	{
		std::cout << "polinomio: " << polinomio << std::endl;
		new_element = {0 , polinomio};
		sum = 0;

		for (auto it = left_terms.begin() ; it != left_terms.end(); it++)
		{
			if ((*it).power == polinomio)
			{
				sum += (*it).term;
				std::cout << "sum: " << sum << " | After adding " << (*it).term << std::endl;
			}

		}
		for (auto it = right_terms.begin() ; it != right_terms.end(); it++)
		{
			if ((*it).power == polinomio)
			{
				sum -= (*it).term;
				std::cout << "sum: " << sum << " | After subtracting " << (*it).term << std::endl;
			}
		}
		new_element.term = sum;
		new_vector.push_back(new_element);

		polinomio--;
	}

	left_terms.clear();
	left_terms = new_vector;
	right_terms.clear();

}