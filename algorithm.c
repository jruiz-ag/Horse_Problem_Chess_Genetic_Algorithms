/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <confidentjaime@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:47:04 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/06/12 00:47:04 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horse_problem.h"

t_indiv	**first_selection(int width)
{
	t_indiv **population;
	t_indiv	**parents;
	t_indiv *best;
	int		cont;

	parents = ft_calloc(K_SELECT, sizeof(t_indiv *));
	if (!parents)
		return (NULL);
	population = first_population(width);
	if (!population)
		return (NULL);
	cont = 0;
	while(cont < K_SELECT)
	{
		best = ft_cpy_best(&population);
		if (!best)
		{
			free_population(&parents, K_SELECT);
			return (free_population(&population, INDIV), NULL);
		}
		parents[cont] = best;
		++cont;
	}
	free_population(&population, INDIV);
	return (parents);
}

t_indiv	**next_selections(t_indiv ***population)
{
	t_indiv	**parents;
	t_indiv *best;
	int		cont;

	parents = ft_calloc(K_SELECT, sizeof(t_indiv *));
	if (!parents)
		return (NULL);
	if (!population || !*population)
		return (NULL);
	cont = 0;
	while(cont < K_SELECT)
	{
		best = ft_cpy_best(population);		
		if (!best)
		{
			free_population(&parents, K_SELECT);
			return (free_population(population, INDIV), NULL);
		}				
		parents[cont] = best;		
		++cont;
	}		
	free_population(population, INDIV);
	return (parents);
}

int	algorithm(int width)
{
	t_indiv **population;
	t_indiv	**parents;
	int		gen;
	int		cont_parents;

	gen = 1;
	parents = first_selection(width);
	while(gen < NGEN)
	{
		ft_printf("\n --- GENERACION %d --- \n", gen);
		cont_parents = 0;
		while(cont_parents < 1)
			show_gen(parents[cont_parents++]);
		population = next_populations(width, parents);
		free_population(&parents, K_SELECT);
		if (!population)
			return (-1);
		parents = next_selections(&population);	
		++gen;
	}	
	show_gen(parents[0]);
	free_population(&parents, K_SELECT);		
	return (0);
}