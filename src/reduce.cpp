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



void reduce_equation(Equation &Eq)
{
	double  sum = 0;
	std::vector<t_element> 	new_vector;
	t_element	new_element = {0,0};
	Eq.max_power = calculate_max_polinomial(Eq.right_terms, Eq.left_terms);
	int		polinomio = Eq.max_power;

	while (polinomio >= 0)
	{
		// std::cout << "polinomio: " << polinomio << std::endl;
		new_element = {0 , polinomio};
		sum = 0;

		for (auto it = Eq.left_terms.begin() ; it != Eq.left_terms.end(); it++)
		{
			if ((*it).power == polinomio)
			{
				sum += (*it).term;
				// std::cout << "sum: " << sum << " | After adding " << (*it).term << std::endl;
			}

		}
		for (auto it = Eq.right_terms.begin() ; it != Eq.right_terms.end(); it++)
		{
			if ((*it).power == polinomio)
			{
				sum -= (*it).term;
				// std::cout << "sum: " << sum << " | After subtracting " << (*it).term << std::endl;
			}
		}
		new_element.term = sum;
		new_vector.push_back(new_element);

		polinomio--;
	}

	Eq.left_terms.clear();
	Eq.left_terms = new_vector;
	Eq.right_terms.clear();

}