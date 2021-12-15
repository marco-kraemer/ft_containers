/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/12/15 13:11:57 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.hpp"	

int	main(int argc, char **argv)
{
	std::cout << "**********************************************" << std::endl;
	std::cout << "*                                            *" << std::endl;
	std::cout << "*                                            *" << std::endl;
	std::cout << "*            FT_CONTAINER TESTS              *" << std::endl;
	std::cout << "*                                            *" << std::endl;
	std::cout << "*                                            *" << std::endl;
	std::cout << "**********************************************" << std::endl;
	vector_tests();
	map_tests();
	stack_tests();
	subject_tests(argc, argv);
	return 0;
}