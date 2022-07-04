/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:37:30 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/04 15:00:07 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	exec_map(t_list *lst, int index)
{
	char	*path;
	char	*res;
	char	**argv;

	if (index < 0 || index >= ft_lstsize(lst))
		return (ERROR);
	path = malloc(10000);
	argv = malloc(sizeof(char *) * 3);
	if (!path)
		return (ERROR);
	path = getcwd(path, 9999);
	res = ft_strjoin(path, "/cub3d");
	argv[0] = ft_strdup("./cub3d");
	argv[1] = ft_strdup(ft_lstindex(lst, index)->content);
	argv[2] = NULL;
	if (fork() == 0)
	{
		execve(res, argv, NULL);
		exit(-1);
	}
	free_tabtab(argv);
	free(res);
	free(path);
	return (0);
}