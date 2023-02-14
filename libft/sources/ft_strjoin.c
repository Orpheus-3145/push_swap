/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 10:59:40 by faru          #+#    #+#                 */
/*   Updated: 2023/01/30 00:34:16 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stddef.h>
#include"libft.h"
#include<stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join_str;

	if (! s1 && ! s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join_str = (char *) malloc(s1_len + s2_len + 1);
	if (! join_str)
		return (NULL);
	else
	{
		join_str[s1_len + s2_len] = '\0';
		while (s2_len--)
			join_str[s1_len + s2_len] = s2[s2_len];
		while (s1_len--)
			join_str[s1_len] = s1[s1_len];
		return (join_str);
	}
}
/*
int main()
{
	char *a, *b;
	printf("upd->sub_str: |%s|\n", ft_strjoin(a, b));
	return (0);
}
*/