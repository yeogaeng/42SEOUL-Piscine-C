/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:14:23 by yokko             #+#    #+#             */
/*   Updated: 2023/09/13 15:03:40 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_return(char *str, int i, int minus)
{
	int	intstr;

	intstr = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		intstr = intstr * 10 + (str[i] - '0');
		i++;
	}
	return (minus * intstr);
}

int	check_white(char *str, int i)
{
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			break ;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus;

	i = 0;
	minus = 1;
	i = check_white(str, i);
	while ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
	{
		if (str[i] == '-')
			minus = minus * (-1);
		i++;
	}
	return (ft_atoi_return(str, i, minus));
}
