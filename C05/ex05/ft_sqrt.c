/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:23:00 by yokko             #+#    #+#             */
/*   Updated: 2023/09/10 11:30:18 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int		i;
	long	pow;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 2;
	while (i <= (nb / 2))
	{
		pow = (long)i * (long)i;
		if (pow == (long)nb)
			return (i);
		else if (pow < (long)nb)
			i++;
		else
			return (0);
	}
	return (0);
}
