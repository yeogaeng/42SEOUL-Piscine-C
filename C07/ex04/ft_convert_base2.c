/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:26:56 by yokko             #+#    #+#             */
/*   Updated: 2023/09/14 17:55:53 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base, int base_size);
int	ft_strlen(char *base);

void	ft_putnbr(int nb, int base_t_size, char *ptr, char *base_to)
{
	long	nbnb;
	int		arr[50];
	int		i;
	int		j;

	nbnb = (long)nb;
	i = 0;
	j = 0;
	if (nbnb < 0)
	{
		ptr[0] = '-';
		nbnb = -nbnb;
		j = 1;
	}
	while (1)
	{
		arr[i] = nbnb % (long)base_t_size;
		if (nbnb / (long)base_t_size == 0)
			break ;
		i++;
		nbnb = nbnb / (long)base_t_size;
	}
	while (i >= 0)
		ptr[j++] = base_to[arr[i--]];
	ptr[j] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*ptr;
	int		base_f_size;
	int		base_t_size;
	int		atoi_result;

	base_f_size = ft_strlen(base_from);
	base_t_size = ft_strlen(base_to);
	if (base_t_size <= 1 || base_f_size <= 1)
		return (0);
	if (!check_base(base_from, base_f_size)
		|| !check_base(base_to, base_t_size))
		return (NULL);
	atoi_result = ft_atoi_base(nbr, base_from);
	ptr = (char *)malloc(34);
	if (!ptr)
		return (NULL);
	ft_putnbr(atoi_result, base_t_size, ptr, base_to);
	return (ptr);
}
