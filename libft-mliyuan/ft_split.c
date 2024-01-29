/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 06:08:00 by mliyuan           #+#    #+#             */
/*   Updated: 2023/12/27 16:03:32 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcounts(char *str, char c)
{
	int	word_count;

	word_count = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			word_count++;
			while (*str != c && *str != '\0')
				str++;
			if (*str == '\0')
				return (word_count);
		}
		str++;
	}
	return (word_count);
}

static void	ft_allocstr(char **sp, char const *s, char sep)
{
	char		**tab_sp;
	char const	*tmp;

	tmp = s;
	tab_sp = sp;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			*tab_sp = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tab_sp;
		}
	}
	*tab_sp = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**str;

	word_count = 0;
	if (s == NULL)
		return (NULL);
	word_count = ft_wordcounts((char *) s, c);
	str = malloc(sizeof(char **) * (word_count + 1));
	if (str == NULL)
		return (NULL);
	ft_allocstr(str, (char *)s, c);
	return (str);
}
