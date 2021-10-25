/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/25 14:29:49 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../container/extras/extras.hpp"	

int	main(int argc, char **argv)
{
	vector_tests();
	map_tests();
	stack_tests();
	subject_tests(argc, argv);
}