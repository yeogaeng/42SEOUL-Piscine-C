/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:13:59 by yokko             #+#    #+#             */
/*   Updated: 2023/09/13 23:23:30 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*arr;
	long	len;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	i = 0;
	len = (long)max - (long)min;
	arr = (int *)malloc(sizeof(int) * (len));
	if (!arr)
		return (-1);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	range[0] = arr;
	return (len);
}
