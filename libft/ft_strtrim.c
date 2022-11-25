/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:34:20 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 10:34:48 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

/*la 1ere fonction va voir si les caracters de s1 existe dans set
elle renvoie 1 si les caracteres existent*/

/* l: 34 on est en train de voir si les caracteres existent au debut de 
// la string et les depasser (donc on aura le nombre de caractere
// de la debut de la chaine)*/

/* end > start c a d que il ya de nombre de caractere suffisant dans
// la chaine && on est en train de detecter les caractere set a la fin 
// de la chaine, "end" est par exemple 10 elle va arreter apres 2 caracteres
// donc a 8 */
int	ft_find_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	i = 0;
	start = 0;
	while (s1[start] && ft_find_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_find_char_in_set((end - 1), set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (start < end)
		str[i++] = s1[start++];
	str[start] = '\0';
	return (str);
}
/*
int main()
{
	char s1[] = "rima hanri";
	char s2[] = "r";
	char *ret = ft_strtrim(s1, s2);
	printf("%s\n", ret);
	return 0;
}*/
