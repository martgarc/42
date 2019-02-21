char		*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || str[i - 1] == 32 || str[i - 1] == 45
		|| str[i - 1] == 43)
		{
			if (str[i] > 96 && str[i] < 123)
				str[i] = str[i] - 32;
		}
		else
		{
			if (str[i] > 64 && str[i] < 91)
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
