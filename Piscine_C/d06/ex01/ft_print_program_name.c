/*
//Header cutre
*/

void ft_putchar(char c);

int main(int gc, char **gv)
{
	int i;

	i = 0;
	while (gv[0][i])
	{
		ft_putchar(gv[0][i]);
		i++;
	}
	return(0);
}
