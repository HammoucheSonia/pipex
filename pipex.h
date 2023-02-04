/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:53:44 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/27 21:54:53 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

void	ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		count_words(char *str, char c);
void	child_one(int *pipefd, int *fd, char **av, char **envp);
void	child_two(int *pipefd, int *fd, char **av, char **envp);
void	end(char *m);
void	free_split(char **tab);
char	*ft_path(char *cmd, char **env);
void	cmd_not_found(char **cmd);
char	*return_path(char **env);
int		char_in_str(char *str, char c);

#endif
