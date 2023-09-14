/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:22:01 by yokko             #+#    #+#             */
/*   Updated: 2023/09/05 09:39:16 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	go_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + 32;
		str++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	go_lowercase(str);
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
				continue ;
			else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				continue ;
			else if (str[i - 1] >= '0' && str[i - 1] <= '9')
				continue ;
			else
				str[i] = str[i] - 32;
		}
	}
	return (str);
}
