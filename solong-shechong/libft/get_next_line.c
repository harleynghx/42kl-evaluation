/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:05:47 by shechong          #+#    #+#             */
/*   Updated: 2024/01/23 16:52:08 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*lc_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc((s1_len + s2_len + 1));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i++ < s1_len)
		str[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < s2_len)
		str[i - 1 + s1_len] = s2[i - 1];
	str[s2_len + s1_len] = '\0';
	free((char *)s1);
	return (str);
}

void	*free_ret(void *var, void *ret)
{
	free(var);
	return (ret);
}

char	*get_current_line(char *str)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new_line = malloc(i + 2);
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, str, i + 2);
	return (new_line);
}

char	*remove_current_line(char *static_buffer)
{
	int		i;
	char	*new_str;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
		return (free_ret(static_buffer, NULL));
	new_str = malloc(ft_strlen(static_buffer) - i + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, static_buffer + i + 1, ft_strlen(static_buffer));
	return (free_ret(static_buffer, new_str));
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*static_buffer;
	char		*buffer;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(static_buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_ret(buffer, NULL));
		buffer[read_bytes] = '\0';
		static_buffer = lc_strjoin(static_buffer, buffer);
	}
	ret = get_current_line(static_buffer);
	static_buffer = remove_current_line(static_buffer);
	if (ft_strlen(ret) > 0 && ret[ft_strlen(ret) - 1] == '\n' && GNL_RM_NEWLINE)
		ret = rft_substr(ret, 0, ft_strlen(ret) - 1);
	return (free_ret(buffer, ret));
}
