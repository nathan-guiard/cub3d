/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:21:50 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/04 17:27:01 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	check_arguments(int ac, char **av)
{
	int	fd;

	if (check_arguments2(ac, av) == -1)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Invald file\n");
		return (-1);
	}
	if (ac > 2)
	{
		printf("Too many arguements\n");
		return (-1);
	}
	return (fd);
}

int	check_arguments2(int ac, char **av)
{
	if (ac == 1)
	{
		printf("Please enter map as arguement\n");
		return (-1);
	}
	if (ft_strlen(av[1]) == 0)
	{
		printf("Empty args\n");
		return (-1);
	}
	if (check_file_ext(av[1]) == -1)
	{
		printf("Not a .cub file\n");
		return (-1);
	}
	return (0);
}

int	check_file_ext(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i > 4)
		i = i - 4;
	else
		return (-1);
	if (ft_strncmp(file + i, ".cub", 4) == 0)
		return (1);
	else
		return (-1);
}
