/*
** EPITECH PROJECT, 2018
** deplacement_function
** File description:
** deplacement_function.hpp deplacement_function.cpp
*/

//#include "server.h"
#include "../includes/server.h"

/*!
* Change the actual working directory to the new
* path given by the client as argument after the
* "CWD" command.
* @param [in] cmd
* @param [in] data
* @param [in] info
* @return Only the "SUCCESS" code.
*/
int	cwd_cmd(char **cmd, const t_clt_data *data, t_clt_info *info)
{
	if (info->connected != TRUE)
	{
		write(data->fd, CODE530, strlen(CODE530));
		return (SUCCESS);
	}
	if (chdir((const char *)cmd[1]) == SUCCESS && \
	(cmd[2] == NULL || cmd[2][0] != '\0'))
		write(data->fd, CODE250, strlen(CODE250));
	else
		write(data->fd, CODE550, strlen(CODE550));
	return (SUCCESS);
}

/*!
* Change the actual working directory to the direct
* parent directory.
* @param [in] cmd
* @param [in] data
* @param [in] info
* @return Only the "SUCCESS" code.
*/
int	cdup_cmd(char **cmd, const t_clt_data *data, t_clt_info *info)
{
	if (info->connected != TRUE)
	{
		write(data->fd, CODE530, strlen(CODE530));
		return (SUCCESS);
	}
	if (chdir("../") == SUCCESS && \
	(cmd[1] == NULL || cmd[1][0] != '\0'))
		write(data->fd, CODE250, strlen(CODE250));
	return (SUCCESS);
}