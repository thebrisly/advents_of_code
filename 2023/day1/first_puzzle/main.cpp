/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:17:53 by lfabbian          #+#    #+#             */
/*   Updated: 2023/12/05 09:45:22 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

void count_numbers (std::string line)
{
	int				count;
	std::string		final_number;

	char 			first_digit;
    char 			last_digit;
	bool 			in_number = false;

	for (char& c : line)
	{
		if (std::isdigit(c))
		{
			if (!in_number)
            {
                first_digit = c;
				last_digit = c
                in_number = true;
            }
            last_digit = c;
		}
	}

	int num = (first_digit - '0') * 10 + (last_digit - '0');
    tab_of_numbers.push_back(num);
}

int final_sum(const std::vector<int>& tab)
{
    int sum = std::accumulate(tab.begin(), tab.end(), 0);
    return sum;
}

int main()
{
	std::string line;
	std::ifstream myfile ("input.txt");
	bool first_found;

	std::vector<int> tab_of_numbers;

	if (myfile.is_open())
	{
		while(getline(myfile, line))
		{
			count_numbers(line);
		}

		myfile.close();
	}

	std::cout << "The sum of all numbers is equal to : " << final_sum(tab_of_numbers) << std::endl;
}
