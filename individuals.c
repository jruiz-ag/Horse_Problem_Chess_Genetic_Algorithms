/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_indiv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <confidentjaime@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:21:50 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/06/11 16:21:50 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horse_problem.h"

static int *gen_chromosome(int len)
{
	int *sol;
	int	cont;
	int	*remain;
	int	actual;
	int actual_len;

	sol = ft_calloc(len, sizeof(int));
	if (!sol)
		return (NULL);
	cont = 0;
	remain = ft_generate_list_int(len);
	actual_len = len;
	if (!remain)
	{
		free(sol);
		return (NULL);
	}
	while(cont < len)
	{
		actual = (int)(ft_random() * actual_len);
		sol[cont++] = (ft_value(len, remain, actual)); 
		actual_len = ft_extract(len, remain, actual);
	}
	free(remain);
	return (sol);
}

t_indiv *build_indiv(int width)
{
	t_indiv *node;

	node = ft_calloc(1, sizeof(t_indiv));
	if (!node) 
		return (NULL);
	node -> chromosome = gen_chromosome(width * width);
	if (!(node -> chromosome))
	{
		free(node);
		return (NULL);
	}
	node -> len_chromosome = width * width;
	node -> fitness = 0.0;
	return (node);
}

void	show_gen(t_indiv *indiv)
{
	int	len;
	int	cont;

	len = indiv->len_chromosome;
	cont = 0;
	ft_printf("Valores del individuo: ");
	while (cont < (len - 1))
		ft_printf("%d, ", indiv -> chromosome[cont++]);
	ft_printf("%d. ", indiv -> chromosome[cont++]);
	ft_printf("Su fitness es de: %g\n", indiv -> fitness);
}

void	free_indiv(t_indiv **indiv)
{
	if (!indiv || !*indiv)
		return ;
	if ((*indiv)->chromosome)
		free((*indiv)->chromosome);
	free(*indiv);
}