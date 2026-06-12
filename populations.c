/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <confidentjaime@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:07:16 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/06/11 17:07:16 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horse_problem.h"

t_indiv	*free_population(t_indiv ***population, int len)
{
	int	cont;

	cont = 0;
	while (cont < len)
	{
		free_indiv(&((*population)[cont]));
		++cont;
	}
	free(*population);
	return (NULL);
}

static int	is_valid_jump(int c1, int c2, int width)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = c1 % width;
	y1 = c1 / width;
	x2 = c2 % width;
	y2 = c2 / width;
	if ((ft_abs(x1 - x2) == 2) && (ft_abs(y1 - y2) == 1))
		return (1);
	if ((ft_abs(x1 - x2) == 1) && (ft_abs(y1 - y2) == 2))
		return (1);
	return (0);
}

static int	fitness(t_indiv *indiv)
{
	int	*seq;
	int	len;
	int	fit;
	int	act;
	int	prev;

	seq = indiv->chromosome;
	len = 0;
	fit = 0;		
	while(len < (indiv->len_chromosome - 1))
	{
		act = seq[len + 1];
		prev = seq[len];
		if (is_valid_jump(prev, act, (int)ft_sqrt(indiv->len_chromosome)))
			++fit;
		++len;
	}
	return (fit);
}

void	eval_population(t_indiv ***population)
{
	int		cont;
	t_indiv *actual;

	cont = 0;
	while(cont < INDIV)
	{
		actual = (*population)[cont];
		(*population)[cont]->fitness = fitness(actual);
		++cont;
	}
}

t_indiv	**first_population(int width)
{
	int	cont;
	t_indiv	**population;
	t_indiv *indiv;

	cont = 0;
	population = ft_calloc(INDIV, sizeof(t_indiv *));
	if (!population)
		return (NULL);
	while(cont < INDIV)
	{
		indiv = build_indiv(width);
		if (!indiv)
			return (free_population(&population, cont), NULL);
		population[cont] = indiv;
		++cont;
	}
	eval_population(&population);
	return (population);
}

