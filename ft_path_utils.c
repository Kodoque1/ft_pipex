/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:49:11 by zaddi             #+#    #+#             */
/*   Updated: 2025/12/19 13:49:12 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_free_array(char **arr)
{
	while (*arr)
	{
		free(*arr);
		*arr = NULL;
		arr++;
	}
}

char	*ft_joinpath(char *s1, char *s2)
{
	int		size;
	char	*s;
	char	*tmp;

	size = ft_strlen(s1);
	if ((s1)[size - 1] != '/')
		tmp = ft_strjoin(s1, "/");
	else
		tmp = s1;
	s = ft_strjoin(tmp, s2);
	free(tmp);
	return (s);
}

char	*search_in_path(char *bin, char **path_env)
{
	char	*tmp;
	char	*path;

	path = NULL;
	while (*path_env)
	{
		tmp = ft_joinpath(*path_env, bin);
		if (access(tmp, X_OK) == 0)
		{
			path = tmp;
			break ;
		}
		free(tmp);
		path_env++;
	}
	return (path);
}

char	**ft_find_path_env(char **envp)
{
	char	**tmp;
	char	**path;

	path = NULL;
	tmp = NULL;
	while (*envp)
	{
		tmp = ft_strsplit(*envp, '=');
		if (ft_strcmp("PATH", tmp[0]) == 0)
		{
			path = ft_strsplit(tmp[1], ':');
		}
		envp++;
	}
	ft_free_array(tmp);
	return (path);
}

char	*get_bin_fullpath(char *bin, char **envp)
{
	char	**path_env;
	char	*full_path;

	path_env = ft_find_path_env(envp);
	if (path_env)
	{
		full_path = search_in_path(bin, path_env);
	}
	ft_free_array(path_env);
	return (full_path);
}
