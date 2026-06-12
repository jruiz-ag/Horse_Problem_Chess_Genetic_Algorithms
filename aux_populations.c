/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_populations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <confidentjaime@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:02:10 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/06/12 01:02:10 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horse_problem.h"

static void	mutate(t_indiv	**indiv, int width)
{
	int	cont;
	int	idx_swap;
	int	swap;

	cont = 0;
	while(cont < (*indiv)->len_chromosome)
	{
		if (ft_random() > MUTATE_PRC)
		{
			idx_swap = (int)(ft_random() * (width * width));
			swap = (*indiv)->chromosome[idx_swap];
			(*indiv)->chromosome[idx_swap] = (*indiv)->chromosome[cont];
			(*indiv)->chromosome[cont] = swap;
		}
		++cont;
	}
}

static t_indiv	*ft_cpy_node(t_indiv *src)
{
	t_indiv *dest;

	dest = ft_calloc(1, sizeof(t_indiv));
	if (!dest)
		return (NULL);
	ft_assign_same(&dest, src);
	if (!(dest->chromosome))
		return(free(dest), NULL);
	return(dest);
}

void	show_pop(t_indiv **population)
{
	int	cont;

	cont = 0;
	while(cont < INDIV)
	{
		show_gen(population[cont]);
		++cont;
	}
}

static int	preserve_parents(t_indiv ***population, t_indiv **parents)
{
	t_indiv	*parent;
	t_indiv	*new_indiv;
	int		cont;

	cont = 0;
	while (cont < K_SELECT)
	{
		parent = parents[cont];
		new_indiv = ft_cpy_node(parent);
		if (!new_indiv)
			return (free_population(population, cont), -1);		
		(*population)[cont] = new_indiv;
		++cont;
	}	
	return (0);
}

t_indiv	**next_populations(int width, t_indiv **parents)
{
	t_indiv	**population;
	t_indiv	*parent;
	t_indiv	*new_indiv;
	int		idx_parent;
	int		cont;

	population = ft_calloc(INDIV, sizeof(t_indiv *));
	if (!population)
		return (NULL);
	if (preserve_parents(&population, parents) == -1)
		return (NULL);
	cont = K_SELECT;
	while (cont < INDIV)
	{		
		idx_parent = (int)(ft_random() * (K_SELECT));
		parent = parents[idx_parent];
		new_indiv = ft_cpy_node(parent);
		if (!new_indiv)
			return (free_population(&population, cont), NULL);
		mutate(&new_indiv, width);
		population[cont] = new_indiv;
		++cont;
	}
	eval_population(&population);
	return (population);
}
