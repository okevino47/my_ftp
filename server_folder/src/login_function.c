/*
** EPITECH PROJECT, 2018
** login_function
** File description:
** login_function.hpp login_function.cpp
*/

#include "../includes/server.h"
//#include "server.h"

/*!
* Ask to the client, by writing on his "fd",
* to give his username. If its empty launch an
* error code "530", otherwise greeting him by
* "331" code.
* @param [in] cmd
* @param [in] data
* @param [out] info
* @return "SUCCESS" code in any case
*/
int	user_cmd(char **cmd, const t_clt_data *data, t_clt_info *info)
{
	if (check_is_empty(cmd[1]) == FAILURE || info->connected == TRUE)
	{
		write(data->fd, CODE530, strlen(CODE530));
	} else {
		info->user = cmd[1];
		write(data->fd, CODE331, strlen(CODE331));
	}
	return (SUCCESS);
}

/*!
* Ask to the client, by writing on his "fd",
* to give password to connect him. If its empty
* launch an error code "503", otherwise greeting
* him by "331" code.
* @param [in] cmd
* @param [in] data
* @param [out] info
* @return "SUCCESS" code in any case
*/
int	pass_cmd(char **cmd, const t_clt_data *data, t_clt_info *info)
{

	if (info->user == NULL)
		write(data->fd, CODE503, strlen(CODE503));
	else {
		info->pass = cmd[1];
		info->connected = TRUE;
		write(data->fd, CODE230, strlen(CODE230));
	}
	return (SUCCESS);
}