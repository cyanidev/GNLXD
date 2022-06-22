/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:02:50 by afelicia          #+#    #+#             */
/*   Updated: 2022/06/22 11:51:37 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
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

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	snew = calloc((len + 1), sizeof(char));
	if (snew == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		snew[i] = s1[i];
	j = -1;
	while (s2[++j])
		snew[i + j] = s2[j];
	return (snew);
}

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		j;
	char	*dest;

	if (s == NULL)
		return (ft_strdup(""));
	dest = calloc((ft_strlen(s) + 1), sizeof(char));
	if (!(dest))
		return (NULL);
	j = 0;
	while (s[j])
	{
		dest[j] = s[j];
		j++;
	}
	return (dest);
}

void	ft_free(char **str, char **str2, char **str3)
{
	if ((str != NULL) && (*str != NULL))
	{
		free(*str);
		*str = NULL;
	}
	if ((str != NULL) && (*str != NULL))
	{
		free(*str2);
		*str2 = NULL;
	}
	if ((str != NULL) && (*str != NULL))
	{
		free(*str3);
		*str3 = NULL;
	}
}
