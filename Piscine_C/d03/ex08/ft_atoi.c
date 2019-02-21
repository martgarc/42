int		ft_atoi(char *str)
{
	int nbr;
	int sign;

	nbr = 0;
	sign = 1;
	while (*str == '\t' || *str == '\v' || *str == '\n' || *str == '\r'
		|| *str =='\f' || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		if (*++str == '-' || *++str == '+')
			return (0);
		str--;
	}
		while (*str)
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}
