/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:37:26 by yokko             #+#    #+#             */
/*   Updated: 2023/09/13 15:26:53 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_white(char *str, int i, int *minus)
{
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			break ;
	}
	*minus = 1;
	while ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
	{
		if (str[i] == '-')
			*minus = *minus * (-1);
		i++;
	}
	return (i);
}

int	findbase(char *str, char *base, int i)
{
	int	basenum;

	basenum = 0;
	while (base[basenum] != '\0')
	{
		if (str[i] == base[basenum])
			return (basenum);
		basenum++;
	}
	return (-1);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_base(char *base, int base_size)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		i++;
	}
	i = 0;
	while (i < base_size - 1)
	{
		j = i + 1;
		while (j < base_size)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	minus;
	int	base_size;
	int	basenum;

	result = 0;
	i = 0;
	base_size = ft_strlen(base);
	if (base_size <= 1)
		return (0);
	if (check_base(base, base_size) == 0)
		return (0);
	i = check_white(str, i, &minus);
	while (str[i] != '\0')
	{
		basenum = findbase(str, base, i);
		if (basenum == -1)
			return (0);
		result = result * base_size + basenum;
		i++;
	}
	return (minus * result);
}
