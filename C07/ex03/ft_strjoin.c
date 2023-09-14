/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:18:44 by yokko             #+#    #+#             */
/*   Updated: 2023/09/14 05:53:20 by yokko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *sep)
{
	int	len;

	len = 0;
	while (*sep != '\0')
	{
		len++;
		sep++;
	}
	return (len);
}

int	ft_strcat(char *dest, char *src)
{
	int	length;

	length = 0;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		length++;
	}
	return (length);
}

char	*make_ptr(int size, char **strs, char *sep, char *ptr)
{
	int	i;
	int	j;
	int	len;
	int	slen;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			ptr[len] = strs[i][j];
			j++;
			len++;
		}
		if (i != size - 1)
		{
			slen = ft_strcat(&ptr[len], sep);
			len += slen;
		}
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

int	slen_maker(int size, char **strs)
{
	int	i;
	int	j;
	int	strs_len;

	i = 0;
	strs_len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		strs_len += j;
		i++;
	}
	return (strs_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		l;
	char	*ptr;
	int		slen;

	l = slen_maker(size, strs);
	slen = ft_strlen(sep);
	if (size == 0)
	{
		ptr = (char *)malloc(1);
		ptr[0] = 0;
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * (l + (size - 1) * slen + 1));
	return (make_ptr(size, strs, sep, ptr));
}
