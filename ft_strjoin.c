/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:54:08 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/27 21:54:11 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = -1;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	while (i++, s1[i])
	{
		dest[j] = s1[i];
		j++;
	}
	i = 0;
	dest[j] = '/';
	j++;
	while (s2[i])
	{
		dest [j] = s2[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
