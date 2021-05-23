#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

/*
**	Codingame Puzzle
*/

typedef struct	s_index
{
	int			l;
	int			i;
}				t_i;

int	ft_ps(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

void	ft_pt(int tab)
{
	while (tab > 0)
	{
		write(1, "\t", 1);
		tab--;
	}
}

t_i	ft_quote(int N, char cgxline[N][1001], t_i i)
{
	write(1, "\'", 1);
	i.i++;
	while (i.l < N && cgxline[i.l])
	{
		while (cgxline[i.l][i.i] && cgxline[i.l][i.i] != '\'')
		{
			write(1, &cgxline[i.l][i.i], 1);
			i.i++;
		}
		if (cgxline[i.l][i.i] == '\'')
		{
			write(1, "\'", 1);
			return (i);
		}
		i.i = 0;
		i.l++;
	}
	return (i);
}

int main()
{
    int N;
    scanf("%d", &N); fgetc(stdin);
    char cgxline[N][1001];
    for (int i = 0; i < N; i++) {
        scanf("%[^\n]", cgxline[i]); fgetc(stdin);
    }
	t_i	i;
	int	t;

	i.l = 0;
	t = 0;
	while (i.l < N && cgxline[i.l])
	{
		i.i = 0;
		while (cgxline[i.l][i.i])
		{
			while (cgxline[i.l][i.i] == ' ' || cgxline[i.l][i.i] == '\t' || cgxline[i.l][i.i] == '\n')
				i.i++;
			if (cgxline[i.l][i.i] == '(')
			{
				t++;
				ft_ps("(\n");
				ft_pt(t);
			}
			else if (cgxline[i.l][i.i] == ')')
			{
				t--;
				ft_ps("\n");
				ft_pt(t);
				ft_ps(")");
				if (cgxline[i.l][i.i + 1] && cgxline[i.l][i.i + 1] == ';')
				{
					i.i++;
					ft_ps(";\n");
				}
				else
					ft_ps("\n");
				ft_pt(t);
			}
			else if (cgxline[i.l][i.i] == ';')
			{
				ft_ps(";\n");
				ft_pt(t);
			}
			else if (cgxline[i.l][i.i] == '\'')
				i = ft_quote(N, cgxline, i);
			else
				write(1, &cgxline[i.l][i.i], 1);
			i.i++;
		}
		i.l++;
	}
    return 0;
}