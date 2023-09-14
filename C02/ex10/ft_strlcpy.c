/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:59:39 by yokko             #+#    #+#             */
/*   Updated: 2023/09/05 09:32:25 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		return (i);
	}
	while (i < size - 1)
	{
		if (src[i] == '\0')
		{
			dest[i] = '\0';
			return (i);
		}
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
