/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <confidentjaime@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:50:53 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/06/11 15:50:53 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_random(void)
{
	static unsigned long long	st = 0;
	static int					initialized = 0;
	unsigned long long			z;

	if (!initialized)
	{
		st = ((unsigned long long)time(0) << 32) ^ (unsigned long long)&st;
		initialized = 1;
	}
	st += 0x9e3779b97f4a7c15ULL;
	z = st;
	z ^= z >> 33;
	z *= 0xff51afd7ed558ccdULL;
	z ^= z >> 33;
	z *= 0xc4ceb9fe1a85ec53ULL;
	z ^= z >> 33;
	z ^= z >> 27;
	z *= 0x3c79ac492ba7b653ULL;
	z ^= z >> 33;
	return ((z >> 11) * (1.0 / (1ULL << 53)));
}
