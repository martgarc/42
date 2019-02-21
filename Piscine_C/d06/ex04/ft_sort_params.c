void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void print_params(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;

	i = 2;
	while (i < argc)
	{
		if (ft_strcmp(argv[i - 1], argv[i]) > 0)
		{
			argv[0] = argv[i - 1];
			argv[i -1] = argv[i];
			argv[i] = argv[0];
			i = 2;
		}
		else
			i++;
	}
	print_params(argc, argv);
	return (0);
}
