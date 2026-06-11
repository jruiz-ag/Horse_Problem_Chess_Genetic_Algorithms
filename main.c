/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <confidentjaime@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:11:55 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/06/11 14:11:55 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horse_problem.h"

static int	is_only_digits(char *str)
{
	while(*str)
	{
		if ((*str < '0') || ('9' < *str))
			return (0);
		++str;
	}
	return (1);
}

static int	is_valid_input(char *str)
{
	while (*str == ' ')
		++str;
	if (*str == '-')
		return (0);
	if (*str == '+')
		++str;
	while ((*str == '0') && (*(str + 1) != '\0'))
		++str;
	if (!is_only_digits(str) || (*str == '0'))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int input;

	if (argc <=  1 || argc > 2 || !(is_valid_input(argv[1])))
	{
		ft_printf("Not valid input. Please execute: ./horse_problem <positive_int>");
		return (0);
	}
	input = ft_atoi(argv[1]);
	return (0);
}