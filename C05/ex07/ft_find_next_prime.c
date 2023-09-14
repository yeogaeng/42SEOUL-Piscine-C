/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:57:13 by yokko             #+#    #+#             */
/*   Updated: 2023/09/13 20:53:31 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	while (i < (nb / i))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (nb);
}

int	ft_find_next_prime(int nb)
{
	int	prime;

	if (nb <= 2)
		return (2);
	if (nb == 3)
		return (3);
	prime = ft_is_prime(nb);
	while (prime == 0)
	{
		prime = ft_is_prime(++nb);
	}
	return (prime);
}
