#include <unistd.h>
#include <stdio.h>
int tab[8][8];

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_print_tab(void)
{
	extern int tab[8][8];
	int i;
	int j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			ft_putchar(tab[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	ft_putchar('\n');
}

void		set_tab(void)
{
	extern int tab[8][8];
	int i;
	int j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			tab[i][j] = 0;
			j++;
		}
	i++;
	}
	tab[1][0] = 1;
	tab[3][1] = 1;
	tab[5][2] = 1;
	tab[7][3] = 1;
	tab[2][4] = 1;
	tab[0][6] = 1;
	tab[6][6] = 1;
	tab[4][7] = 1;
}

int		is_possible(int i, int j)
{
	extern int tab[8][8];
	int n;
	int m;

	n = 0;
	while (n < 8)
	{
		if (tab[n][j] == 1)
		{
			if (n != i)
				return (0);
		}
		n++;
	}
	n = 0;
	while (n < 8)
	{
		if (tab[i][n] == 1)
		{
			if (n != j)
				return (0);
		}
		n++;
	}

	n = i;
	m = j;
	while (i > 0 && j > 0)
	{
		i--;
		j--;
	}
	while (i < 8 && j < 8)
	{
		if (tab[i][j] == 1)
		{
			if (i != n && j !=m)
				return (0);
		}
		i++;
		j++;
	}

	i = n;
	j = m;
	while (i > 0 && j < 7)
	{
		i--;
		j++;
	}
	while (i < 8 && j >= 0)
	{
		if (tab[i][j] == 1)
		{
			if (i != n && j != m)
				return (0);
		}
		i++;
		j--;
	}
	return (1);
}

int		valid_comb(void)
{
	extern int tab[8][8];
	int i;
	int j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (tab[i][j] == 1)
			{
				if (!is_possible(i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int main()
{
	set_tab();
	printf("%d", valid_comb());
	return (0);
}
