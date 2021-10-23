/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24:Lexicographic_permutations.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:57:03 by adelille          #+#    #+#             */
/*   Updated: 2021/10/23 13:56:14 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define TRUE	1
#define	FALSE	0

#define SIZE	11

static void	ft_swap(char n[SIZE], int x, int y)
{
	char	tmp;

	tmp = n[x];
	n[x] = n[y];
	n[y] = tmp;
}

static int	ft_is_dec(char n[SIZE], int i)
{
	while (i < SIZE - 1)
	{
		if (n[i] < n[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	ft_smallest_after(char n[SIZE], int i)
{
	int	s;
	int	index;

	s = SIZE;
	index = 0;
	while (i < SIZE)
	{
		if (n[i] - 48 < s)
		{
			s = n[i] - 48;
			index = i;
		}
		i++;
	}
	return (index);
}

static void	ft_permute(char n[SIZE], int i)
{
	int	size;

	size = SIZE - 2;
	while (i < size)
	{
		ft_swap(n, i, size);
		i++;
		size--;
	}
}

static void	ft_permutation(char n[SIZE])
{
	int	i;
	int	x;

	i = 0;
	while (i < SIZE && ft_is_dec(n, i) == FALSE)
		i++;
	x = i - 1;
	i = ft_smallest_after(n, i - 1);
	ft_swap(n, x, i);
	ft_permute(n, x + 1);
}

int	main(void)
{
	char	n[SIZE] = {"0123456798"};
	int		i;

	i = 1;
	while (i == 1000000 || i < 20)
	{
		ft_permutation(n);
		i++;
	}
	printf("%s\n", n);
	return (0);
}
