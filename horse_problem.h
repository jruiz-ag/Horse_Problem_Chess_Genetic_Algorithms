/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horse_problem.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <confidentjaime@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:11:51 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/06/11 14:11:51 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HORSE_PROBLEM_H
# define HORSE_PROBLEM_H

# define INDIV 1000
# define NGEN 1000

# include "libft/libft.h"

typedef struct s_indiv
{
	int		*chromosome;
	int		len_chromosome;
	double	fitness;
}	t_indiv;

t_indiv *build_indiv(int width);
void	show_gen(t_indiv *indiv);
void	free_indiv(t_indiv **indiv);
int		*ft_generate_list_int(int len);
int		ft_value(int len, int *list, int pos);
int		ft_extract(int len, int *list, int pos);
int		algorithm(int width);
t_indiv *ft_cpy_best(t_indiv **population);

#endif