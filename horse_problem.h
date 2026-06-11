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

# include "libft/libft.h"

typedef struct	s_indiv {
	int *chromosome;
	int	len_chromosome;
	int fitness;
} t_indiv;

#endif