/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_fail_on_divider.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:57:52 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/04 12:02:12 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *string, char delimiter)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	if (string[i] && string[i] != delimiter)
	{
		words++;
		i++;
	}
	while (string[i])
	{
		if (string[i] == delimiter && string[i + 1] != \
			delimiter && string[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

size_t	ft_countletters(char const *string, char delimiter)
{
	size_t	i;

	i = 0;
	while (string[i] && string[i] != (const char) delimiter)
	{
		i++;
	}
	return (i);
}

int	ft_check_double_characters(char const *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] == c)
			return 0;
		i++;
	}
	return (1);
}

char	**ft_split_fail_on_divider(char const *s, char c)
{
	char	**final;
	size_t	i;
	size_t	a;

	if (!ft_check_double_characters(s, c))
		return (NULL);
	final = (char **) malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!final)
		return (NULL);
	i = 0;
	a = 0;
	while (i < ft_countwords(s, c))
	{
		while (s[a] == (const char)c)
			a++;
		final[i] = ft_substr(s, a, ft_countletters(&s[a], c));
		a = a + ft_countletters(&s[a], c);
		i++;
	}
	final[ft_countwords(s, c)] = 0;
	return (final);
}
