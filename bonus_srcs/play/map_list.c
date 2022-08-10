/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:12:20 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/10 22:32:48 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static bool	is_a_good_map_name(char *str);

t_list	*get_map_list(void)
{
	DIR				*d;
	struct dirent	*dir;
	t_list			*res;

	res = NULL;
	d = opendir("maps");
	if (d)
	{
		dir = readdir(d);
		while (dir != NULL)
		{
			if (is_a_good_map_name(dir->d_name) == TRUE)
				ft_lstadd_back(&res, ft_lstnew(dir->d_name));
			dir = readdir(d);
		}
		closedir(d);
	}
	return (res);
}

static bool	is_a_good_map_name(char *str)
{
	int	i;

	if (!str)
		return (FALSE);
	if (str[0] == '.')
		return (FALSE);
	i = ft_strlen(str);
	if (i <= 4)
		return (FALSE);
	if (ft_strcmp(".cub", str + i - 4) != 0)
		return (FALSE);
	return (TRUE);
}

char	*treated_string(char *str)
{
	char	*res;
	char	*to_free;

	res = ft_substr(str, 0, ft_strchr(str, '.') - str);
	if (ft_strlen(res) <= MAX_STR_LEN)
		return (res);
	to_free = res;
	res = ft_substr(res, 0, MAX_STR_LEN - 1);
	free(to_free);
	to_free = res;
	res = ft_strjoin(res, ".");
	free(to_free);
	return (res);
}

void	custom_free_tabtab(char **tab)
{
	if (tab[0])
		free(tab[0]);
	if (tab[1])
		free(tab[1]);
	if (tab[2])
		free(tab[2]);
	if (tab[3])
		free(tab[3]);
	if (tab[4])
		free(tab[4]);
	free(tab);
}
