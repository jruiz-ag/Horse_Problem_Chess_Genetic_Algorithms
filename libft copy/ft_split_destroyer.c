/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_destroyer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:56:46 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/06/02 16:56:46 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_destroyer(char ***matrix)
{
	int	cont;

	cont = 0;
	while ((*matrix)[cont])
	{
		free((*matrix)[cont]);
		++cont;
	}
	free(*matrix);
}
