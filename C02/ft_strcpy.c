#include <stdio.h>
char *strcpy(char *dest, char *src)
{
	int i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

int main()
{
	char des[10];
	char src[] = "rimahanna";
	char *dest = strcpy(des, src);
	printf("%s", dest);
	return 0;

}
