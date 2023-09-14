/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:29:44 by yokko             #+#    #+#             */
/*   Updated: 2023/09/14 11:44:42 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	promising(char *map, int q)
{
	int	j;

	j = 0;
	while (j < q)
	{	
		if (map[q] == map[j] || abs(q - j) == abs(map[q] - map[j]))
			return (0);
		j++;
	}
	return (1);
}

void	find_queens(char *map, int q, int *count)
{
	int		i;
	char	temp;

	i = 0;
	if (q == 10)
	{
		q = 0;
		while (q < 10)
		{
			temp = map[q] + '0';
			write(1, &temp, 1);
			q++;
		}
		write(1, "\n", 1);
		(*count)++;
		return ;
	}
	while (i < 10)
	{
		map[q] = i;
		if (promising(map, q))
			find_queens(map, q + 1, count);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	map[11];
	int		q;
	int		count;

	q = 0;
	count = 0;
	find_queens(map, q, &count);
	return (count);
}
