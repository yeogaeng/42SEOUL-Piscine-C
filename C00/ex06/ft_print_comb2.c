/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:21:05 by yokko             #+#    #+#             */
/*   Updated: 2023/09/05 12:15:06 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_ab(char *a, char *b)
{
	write(1, &a[0], 1);
	write(1, &a[1], 1);
	write(1, " ", 1);
	write(1, &b[0], 1);
	write(1, &b[1], 1);
	b[1]++;
	if (a[0] == '9' && a[1] == '8')
	{
		return ;
	}
	write(1, ", ", 2);
}

void	condition_ab(char *a, char *b)
{
	while (b[0] <= '9')
	{
		while (b[1] <= '9')
		{
			write_ab(a, b);
		}
		b[0]++;
		b[1] = '0';
	}
	if (a[1] == '9')
	{
		a[0]++;
		a[1] = '0';
	}
	else
	{
		a[1]++;
	}
}

void	ft_print_comb2(void)
{
	char	a[2];
	char	b[2];

	a[0] = '0';
	a[1] = '0';
	while (a[0] <= '9')
	{
		if (a[1] != '9')
		{
			b[0] = a[0];
			b[1] = a[1] + 1;
		}
		else
		{
			b[0] = a[0] +1;
			b[1] = '0';
		}
		condition_ab(a, b);
	}
}
