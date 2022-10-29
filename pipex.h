/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:58:46 by aivanyan          #+#    #+#             */
/*   Updated: 2022/10/29 16:02:42 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

extern char	**g_envp;

//pipex
int					main(int argc, char **argv, char **envp);
void				forking(int *pipefd, int *filefd, char **argv);
void				process(int *pipefd, int fd, char *cmd, int is_first);
void				execute(char *cmd);

//utils
char				*get_environment(char **env, char *name);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin3(char *str1, char *str2, char *str3);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

//split
static int			ft_count(char const *s, char c);
static char const	*ft_start(char const *s, char c);
static char const	*ft_end(char const *s, char c);
static int			ft_check_alloc(char **split, char *str, int index);
char				**ft_split(char const *s, char c);

//split_utils
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);

#endif
