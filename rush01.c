/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iajeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:49:17 by iajeong           #+#    #+#             */
/*   Updated: 2023/09/03 18:26:53 by iajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int ft_atoi(char* str);
int* pick_num(char* str);
int ft_strlen(char* str);
int check(int argc, char* argv[]);
int is_building_in_row_col(int buildings[4][4], int buildingheight, int now);
int check_height_up(int map[][4], int* input, int now);
int solve_puzzle(int map[][4], int* input, int now);

int ft_atoi (char *str)
{
	int	res;
	res = 0;
	while ((*str >= '0') && (*str <='9'))
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res);
}

int *pick_num (char *str)
{
	int	*input;
	int	i;
	int j;
	input = (int *)malloc(16);
	i = -1;
	j = 0;
	while(str[++i] != '\0')
	{
		if ( str[i] >= '0' && str[i] <= '9')
		{
			input[j++] = ft_atoi(str + i);
		}
	}
	return (input);
}

int ft_strlen (char *str)
{
	int	size;
	size = 0;
	while (*str != '\0')
	{
		size++;
		str++;
	}
	return (size);
}

int check (int argc, char *argv[])
{
	if (argc != 2 || ft_strlen(argv[1]) != 31)
		return (0);
	else return (1);
}

int is_building_in_row_col (int buildings[4][4], int buildingheight, int now)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < now / 4)
    {
        if (buildings[i][now % 4] == buildingheight)
            return 0;
        i++;
    }
    while (j < now % 4)
    {
        if (buildings[now / 4][j] == buildingheight)
            return 0;
        j++;
    }
    return (1);
}

int check_height_up (int map[][4], int* input, int now)
{
    int max;
    int i;
    int count;

    i = 0;
    count = 0;
    max = 0;
    if (now / 4 == 3)
    {
        while (i < 4)
        {
            if (map[i][now % 4] > max)
            {
                max = map[i][now % 4];
                count++;
            }
            i++;
        }
        if (input[now % 4] != count)
            return (0);
    }
    return (1);
}

int solve_puzzle (int map[][4], int* input, int now)
{
    int height;
    
    height = 0;
    if (now == 16)
        return 1;
    while (++height <= 4)
    {
        if (is_building_in_row_col(map, height, now) == 1)
        {
            map[now / 4][now % 4] = height;
            if (check_height_up(map, input, now) && solve_puzzle(map, input, now + 1))
            {
                return 1;
            }
            map[now / 4][now % 4] = 0;
        }
    }
    return 0;
}

int main (int argc, char* argv[])
{
    int*    input;
    int map[4][4];
    int i;
    int j;
    char    temp;

    i = 0;
    if (check(argc, argv) != 1)
    {
        return 0;
    }
    input = pick_num(argv[1]);
    if (solve_puzzle(map, input, 0) == 1)
    {
        while (i < 4)
        {
            j = 0;
            while (j < 4)
            {
                temp = map[i][j] + '0';
                write(1, &temp, 1);
                if (j != 3)
                    write(1, " ", 1);
                j++;
            }
            write(1, "\n", 1);
            i++;
        }
    }
    else
    {
        write(1, "Error", 5);
    }
    free(input);
    return 0;
}
