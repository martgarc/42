void ft_putchar(char c);

void ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a <= 99)
	{
		while (b <= 99)
		{
			ft_putchar(a / 10 + '0');
			ft_putchar(a % 10 + '0');
			ft_putchar(' ');
			ft_putchar(b / 10 + '0');
			ft_putchar(b % 10 + '0');
			if (a != 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		b++;
		}
		a++;
		b = a + 1;
	}
}
