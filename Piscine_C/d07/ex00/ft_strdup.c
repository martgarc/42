#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	ft_strcpy(src, str);
	return (str);
}
