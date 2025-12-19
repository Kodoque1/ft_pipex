/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:49:25 by zaddi             #+#    #+#             */
/*   Updated: 2025/12/19 13:51:19 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "ft_printf.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <unistd.h>

# define FILE1 1
# define FILE2 4
# define CMD1 2
# define CMD2 3

char	*ft_joinpath(char *s1, char *s2);
char	*search_in_path(char *bin, char **path_env);
char	**ft_find_path_env(char **envp);
char	*get_bin_fullpath(char *bin, char **envp);
void	ft_free_array(char **arr);

#endif FT_PIPEX_H
