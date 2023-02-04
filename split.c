/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:52:36 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/27 21:52:43 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"

static size_t	nombre(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_words(char *str, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (*str)
	{
		if (*str != c && k == 0)
		{
			k = 1;
			i++;
		}
		else if (*str == c)
			k = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (i++, i <= nombre(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == nombre(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
	}
	split[j] = 0;
	return (split);
}
