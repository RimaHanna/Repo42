#include <stdio.h>
int ft_is_uper_case(char c)
{
	return ('A' <= c && c <= 'Z');
}
int ft_is_lower_case(char c)
{
	return ('a' <= c && c <= 'z');
}

int ft_is_alpha(char c)
{
	return (('a'<= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}
int ft_is_numeric(char c)
{
	return ('0' <= c && c <= '9');
}
char *ft_strcapitalize(char *str)
{
	int i = 0;
	if (ft_is_lower_case(str[i]))
		str[i] = str[i] - 32;
	i++;
	while (str[i])
	{
		if (ft_is_lower_case(str[i]) && !ft_is_alpha(str[i - 1]) && !ft_is_numeric(str[i -1]))
			str[i] = str[i] - 32;
		else if (ft_is_uper_case(str[i]))
			str[i] = str[i] + 32; 
		i++;
	}
	return str;
}


int main()
{
	char str[] = "salut, comment vas tu ? 42mots quarante-deux; cinquante+et+un";
	char *ret = ft_strcapitalize(str);
	printf("%s\n", ret);
	return 0;
}
