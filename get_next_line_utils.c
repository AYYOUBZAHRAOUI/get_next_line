/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:22:43 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/05/02 06:24:49 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fndnln(char *str, int n)
{
	int	indx;

	indx = 0;
	while (str && str[indx] && indx < n)
	{
		if (str[indx] == '\n')
			return (indx);
		indx++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	if (s)
	{
		while (s[l])
			l++;
	}
	return (l);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*x;
	unsigned char	*y;
	size_t			i;

	x = (unsigned char *)dst;
	y = (unsigned char *)src;
	i = 0;
	if (x == NULL)
		return (NULL);
	while (i < len)
	{
		*(x + i) = *(y + i);
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*p;

	i = ft_strlen(s1);
	j = 0;
	p = (char *)malloc(i + 1);
	if (p == NULL)
		return (NULL);
	while (j < i)
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = '\0';
	return (free(s1), s1 = NULL, p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i1;
	int		i2;

	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (NULL);
		else if (s1)
			return (ft_strdup(s1));
		else
			return (ft_strdup(s2));
	}
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	p = (char *)malloc(i1 + i2 + 1);
	if (p == NULL)
		return (NULL);
	p[i1 + i2] = 0;
	ft_memcpy(p, s1, i1);
	ft_memcpy(p + i1, s2, i2 + 1);
	return (free(s1), free(s2), p);
}
