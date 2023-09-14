/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:29:33 by yokko             #+#    #+#             */
/*   Updated: 2023/09/14 05:26:05 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ischarset(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	*save_word(char *str, char *charset, int *i, int str_len)
{
	char	*ptr;
	char	*toss;

	ptr = (char *)malloc(sizeof(char) * str_len + 1);
	toss = ptr;
	if (!ptr)
		return (ptr);
	while (!ischarset(str[*i], charset) && str[*i] != '\0')
	{
		*ptr = str[*i];
		(*i)++;
		ptr++;
	}
	*ptr = '\0';
	return (toss);
}

int	count_word(char *str, char *charset, int *str_len)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!ischarset(str[i], charset) && flag == 0)
			flag = 1;
		else if (ischarset(str[i], charset) && flag == 1)
		{
			flag = 0;
			count++;
		}
		i++;
	}
	*str_len = i;
	if (flag == 1)
		count++;
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		c_word;
	int		str_len;
	int		i;
	char	**s;
	char	**toss;

	c_word = count_word(str, charset, &str_len);
	s = (char **)malloc(sizeof(char *) * c_word + 1);
	toss = s;
	i = 0;
	while (str[i] != '\0')
	{
		if (!ischarset(str[i], charset))
		{
			*s = save_word(str, charset, &i, str_len);
			if (!(*s))
				return (NULL);
			s++;
		}
		else
			i++;
	}
	*s = 0;
	return (toss);
}
