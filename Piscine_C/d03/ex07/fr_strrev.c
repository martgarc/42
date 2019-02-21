char		*ft_strrev(char *str)
{
	int a;
	int b;
	int swap;

	a = 0;
	b = 0;
	while (str[b])
		b++;
	b--;
	while (a < b)
	{
		swap = str[a];
		str[a] = str[b];
		str[b] = swap;
		a++;
		b--;
	}
	return (str);
}
