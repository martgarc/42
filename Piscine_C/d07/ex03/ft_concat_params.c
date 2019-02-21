#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

char	*ft_strcatnl(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

char *ft_concat_params(int argc, char **argv)
 {
	char *str;
	int len;
	int i;

	len = 0;
	i = 1;
	while (argv[i])
	{
		len += ft_strlen(argv[i]) + 1;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 1;
	while (argv[i])
	{
		str = ft_strcatnl(str, argv[i]);
		i++;
	}
	return (str);
 }
