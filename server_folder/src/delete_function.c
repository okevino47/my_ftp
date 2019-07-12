/*
** EPITECH PROJECT, 2018
** delete_function
** File description:
** delete_function.hpp delete_function.cpp
*/

//#include "server.h"
#include "../includes/server.h"

/*!
* Delete the file given in parameter.
* @param [in] cmd
* @param [in] data
* @param [in] info
* @return "SUCCESS" code in any case
*/
int	dele_cmd(char **cmd, const t_clt_data *data, t_clt_info *info)
{
	int	removed;

	if (check_is_empty(cmd[2]) == FAILURE || info->connected == FALSE)
	{
		write(data->fd, CODE550, strlen(CODE550));
		return (SUCCESS);
	}
	removed = remove(cmd[1]);
	if (removed == SUCCESS)
		write(data->fd, CODE250, strlen(CODE250));
	else
		write(data->fd, CODE530, strlen(CODE530));
	return (SUCCESS);
}