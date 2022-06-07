/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:55:58 by afelicia          #+#    #+#             */
/*   Updated: 2022/05/27 22:40:56 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*snew;
	size_t	i;
	size_t	j;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	snew = malloc(sizeof(char) * (len + 1));
	if (snew == NULL)
		return (NULL);
	i = 0;
	while (i < strlen(s1))
	{
		snew[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < strlen(s2))
	{
		snew[i + j] = s2[j];
		j++;
	}
	snew[i + j] = '\0';
	return (snew);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (const char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (const char)c)
		return (&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		j;
	char	*dest;

	dest = malloc(sizeof(char) * (strlen(s) + 1));
	if (!(dest))
		return (NULL);
	j = 0;
	while (s[j])
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

void	ft_free(char *str, char **str2, char **str3)
{
	if (str)
		free(str);
	if (*str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (*str3)
		free(*str);
	return (NULL);
}
