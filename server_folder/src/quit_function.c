/*
** EPITECH PROJECT, 2018
** quit_function
** File description:
** quit_function.hpp quit_function.cpp
*/

//#include "server.h"
#include "../includes/server.h"

/*!
* Quit the client correctly by destructing all
* @param [in] cmd
* @param [in] data
* @param [in] info
* @return exit only
*/
int	quit_cmd(char **cmd, const t_clt_data *data, t_clt_info *info)
{
	(void)cmd;
	if (info->transfering == FALSE)
	{
		write(data->fd, CODE221A, strlen(CODE221A));
		write(data->fd, CODE221B, strlen(CODE221B));
	}
	close(data->fd);
	exit(SUCCESS);
}