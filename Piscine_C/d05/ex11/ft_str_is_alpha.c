int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	if (*str == '\0')
		return (1);
	while (str[i])
	{
		if ((str[i] > 96 && str[i] < 123)
		|| (str[i] > 64 && str[i] < 91))
			i++;
		else
			return (0);
	}
	return (1);
}
