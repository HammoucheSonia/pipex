/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:53:12 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/27 21:53:15 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], fd);
		i++;
	}
}

void	end(char *m)
{
	ft_putstr("Error\n", 2);
	perror(m);
	exit(EXIT_FAILURE);
}

void	free_split(char **tab)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (tab[n])
		n++;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ft_path(char *cmd, char **env)
{
	char	**tab_path;
	int		i;
	char	*bin;
	int		j;

	i = 0;
	j = count_words(return_path(env), ':');
	tab_path = ft_split(return_path(env), ':');
	while (i < j)
	{
		bin = ft_strjoin(tab_path[i], cmd);
		if (access(bin, F_OK) == 0)
		{
			return (bin);
		}
		free(bin);
		i++;
	}
	free_split(tab_path);
	return (cmd);
}

void	cmd_not_found(char **cmd)
{
	ft_putstr(cmd[0], 2);
	ft_putstr(": command not found\n", 2);
	exit(EXIT_FAILURE);
}
