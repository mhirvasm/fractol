/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:47:19 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/08/16 12:34:25 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	skip_spaces_and_sign(char **str, int *sign)
{
	while (((**str) >= 9 && (**str) <= 13) || (**str) == 32)
		(*str)++;
	if ((**str) == '-' || (**str) == '+')
	{
		if ((**str) == '-')
			*sign = -1;
		(*str)++;
	}
}

int	ft_atodbl(char *str, double *output)
{
	double	n;
	double	multiplier;
	int		sign;

	sign = 1;
	n = 0;
	multiplier = 10;
	skip_spaces_and_sign(&str, &sign);
	while (*str && *str != '.' && ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str && *str != '.' && ft_isdigit(*str))
	{
		n += (*str - '0') / multiplier;
		multiplier *= 10;
		str++;
	}
	if (*str != '\0')
		return (0);
	*output = (double)(n * sign);
	return (1);
}
