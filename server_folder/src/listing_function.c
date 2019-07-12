/*
** EPITECH PROJECT, 2018
** listing_function
** File description:
** listing_function.hpp listing_function.cpp
*/

//#include "server.h"
#include "../includes/server.h"

/*!
* Print the current working directory.
* @param [in] cmd
* @param [in] data
* @param [in] info
* @return
*/
int	pwd_cmd(char **cmd, const t_clt_data *data, t_clt_info *info)
{
	char	*path = malloc(sizeof(char) * 1024);

	(void)cmd;
	if (info->connected == SUCCESS)
		write(data->fd, CODE530, strlen(CODE530));
	else
	{
		if (getcwd(path, 1024) == NULL)
		{
			write(data->fd, CODE257A, strlen(CODE257A));
			free(path);
			return (SUCCESS);
		}
		write(data->fd, CODE257A, strlen(CODE257A));
		write(data->fd, path, strlen(path));
		write(data->fd, CODE257B, strlen(CODE257B));
	}
	free(path);
	return (SUCCESS);
}