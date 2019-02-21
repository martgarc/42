#include <stdlib.h>

void	ft_print_words_tables(char **tab);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
		while (str[i])
			i++;
	return (i);
}

int		ft_custom_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != 32 && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}

int		ft_count_words(char *str)
{
	int i;
	int words;

	i = 1;
	words = 0;
	while (str[i - 1] != '\0')
	{
		if (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
			if (str[i - 1] != 32 && str[i - 1] != '\t' && str[i - 1] != '\n')
				words++;
		i++;
	}
	return (words);
}

char	*ft_almost_strdup(char *str)
{
	char	*dup;
	int		i;

	i = 0;
	if (!(dup = (char *)malloc(sizeof(char) * (ft_custom_strlen(str) + 1))))
		return (NULL);
	while (str[i] != '\0' && str[i] != 32 && str[i] != '\t' && str[i] != '\n')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split_whitespaces(char *str)
 {
	char	**tab;
	int		words;
	int		i;

	words = ft_count_words(str);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*str == 32 || *str == '\n' || *str == '\t')
			str++;
		tab[i] = ft_almost_strdup(str);
		while (*str != 32 && *str != '\n' && *str != '\t' && *str != '\0')
			str++;
		i++;
	}
	tab[i] = 0;
	return (tab);
 }

 int main(int argc, char **argv)
 {
	ft_print_words_tables(ft_split_whitespaces(argv[1]));
	return (0);
 }
