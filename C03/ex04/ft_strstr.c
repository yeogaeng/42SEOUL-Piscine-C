/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:57:49 by yokko             #+#    #+#             */
/*   Updated: 2023/09/11 18:26:41 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_right_func(char *str, char *to_find, int i)
{
	int	j;

	j = 0;
	while (to_find[j] != '\0')
	{
		if (str[i] != to_find[j])
			return (0);
		j++;
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0' && to_find[0] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (is_right_func (str, to_find, i) == 1)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
