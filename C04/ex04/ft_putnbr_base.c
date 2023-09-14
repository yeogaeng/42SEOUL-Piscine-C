/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:24:27 by yokko             #+#    #+#             */
/*   Updated: 2023/09/09 15:01:09 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	basemaker(unsigned int nbr, char *base, unsigned int basesize)
{
	if (nbr < basesize)
	{
		write(1, &base[nbr], 1);
		return ;
	}
	else
	{
		basemaker((nbr / basesize), base, basesize);
		write(1, &base[nbr % basesize], 1);
	}
}

int	ft_strlen(char *base)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (base[i] != '\0')
	{
		i++;
		size++;
	}
	return (size);
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	check;
	int	base_size;

	base_size = ft_strlen(base);
	if (base_size <= 1)
		return ;
	check = check_base(base, base_size);
	if (check == 0)
		return ;
	if (nbr < 0)
	{	
		write(1, "-", 1);
		basemaker((unsigned int)nbr * (-1), base, (unsigned int)base_size);
	}
	else
		basemaker((unsigned int)nbr, base, (unsigned int)base_size);
}
