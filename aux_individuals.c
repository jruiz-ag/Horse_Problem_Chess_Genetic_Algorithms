/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_individuals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <confidentjaime@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:35:31 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/06/11 16:35:31 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horse_problem.h"

static t_indiv	*ft_assign_same(t_indiv **dest, t_indiv *src)
{
	int	cont;

	(*dest)->len_chromosome = src->len_chromosome;
	(*dest)->fitness = src->fitness;
	(*dest)->chromosome = ft_calloc((*dest)->len_chromosome, sizeof(int));
	if (!(*dest)->chromosome)
	{
		free(*dest);
		return(NULL);
	}
	cont = 0;
	while(cont < (*dest)->len_chromosome)
	{
		(*dest)->chromosome[cont] = src->chromosome[cont];
		++cont;
	}
	return (*dest);
}

t_indiv *ft_cpy_best(t_indiv **population)
{
	int		best;
	int		cont;
	int		best_idx;
	t_indiv *res;

	cont = 0;
	best = -1;
	while(cont < INDIV)
	{
		if (population[cont]->fitness > best)
		{
			best = population[cont]->fitness;
			best_idx = cont;
		}
		++cont;
	}
	res = ft_calloc(1, sizeof(t_indiv));
	if (!ft_assign_same(&res, population[best_idx]))
		return (NULL);
	return (res);
}

int	*ft_generate_list_int(int len)
{
	int	*list;
	int	cont;

	list = ft_calloc(len, sizeof(int));
	if (!list)
		return (NULL);
	cont = 0;
	while(cont < len)
	{
		list[cont] = cont;
		++cont;
	}
	return (list);
}

int	ft_value(int len, int *list, int pos)
{
	int	idx;
	int	cont_values;
	
	cont_values = 0;
	idx = 0;
	while(idx < len)
	{
		if ((cont_values == pos) && (list[idx] != -1))
			return (list[idx]);
		if (list[idx] != -1)
			++cont_values;
		++idx;
	}
	return (-1);
}

int	ft_extract(int len, int *list, int pos)
{
	int idx;
	int	cont_values;
	int	changed;

	cont_values = 0;
	idx = 0;
	changed = 0;
	while(idx < len)
	{
		if ((cont_values == pos) && (list[idx] != -1) && !changed)
		{
			list[idx] = -1;
			changed = 1;
		}
		if (list[idx] != -1)
			++cont_values;
		++idx;
	}
	return (cont_values);
}
