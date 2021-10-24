/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:37:20 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/24 14:44:52 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRAS_HPP
#define EXTRAS_HPP

# include <iostream>
# include <memory>
# include <functional>
# include <limits>
# include <utility>
# include <map>
# include <stack>
# include <vector>
# include <iterator>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
#include <string>
#include <deque>
#include <stdlib.h>

# include "./random_access_iterator.hpp"
# include "./MapIterators.hpp"
# include "../vector.hpp"
# include "../map.hpp"
# include "../stack.hpp"

void	vector_tests(void);
void	map_tests(void);
void	subject_tests(int argc, char** argv);
#endif