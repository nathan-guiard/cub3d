/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:37:30 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/09 12:44:08 by nguiard          ###   ########.fr       */
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
	argv[1] = ft_strjoin("maps/", ft_lstindex(lst, index)->content);
	argv[2] = NULL;
	ft_printf("\033[1mexecuting %s %s\033[m\n", res, argv[1]);
	if (fork() == 0)
		exit(execve(res, argv, NULL));
	free_tabtab(argv);
	free(res);
	free(path);
	return (0);
}