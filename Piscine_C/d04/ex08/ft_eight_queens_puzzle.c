#include <unistd.h>
#include <stdio.h>
int tab[8][8];

void		ft_putchar(char c)
{
	write(1, &c, 1);
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
			if (i == 0)
				tab [i][j] = 1;
			else
				tab[i][j] = 0;
			j++;
		}
	i++;
	}
}

int		last_comb(void)
{
	extern int tab[8][8];
	int j;

	j = 0;
	while (tab[7][j] == 1)
	{
		if (j == 7)
			return (1);
		j++;
	}
	return (0);
}

int		is_possible(int i, int j)
{
	extern int tab[8][8];
	int n;
	int m;

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

void	add_one(int j)
{
	extern int tab[8][8];
	int i;

	i = 0;
	while (tab[i][j] == 0)
		i++;
	if (i < 7)
	{
		tab[i][j] = 0;
		tab[i + 1][j] = 1;
	}
	else
	{
		tab[i][j] = 0;
		tab[0][j] = 1;
		add_one(j - 1);
	}
}

int		ft_eight_queens_puzzle(void)
{
	extern int tab[8][8];
	int comb;

	comb = 0;
	set_tab();
	while (!last_comb())
	{
		if (valid_comb())
			comb++;
		add_one(7);
	}
	return (comb);
}

int main()
{
	printf("%d", ft_eight_queens_puzzle());
	return (0);
}
