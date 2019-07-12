/*
** EPITECH PROJECT, 2018
** noop_function
** File description:
** noop_function.hpp noop_function.cpp
*/

//#include "server.h"
#include "../includes/server.h"

/*!
* Write to the client the code "200" which only
* notify him that the command is correct.
* @param [in] cmd
* @param [in] data
* @param [in] info
* @return only the "SUCCESS" code.
*/
int 	noop_cmd(char **cmd, const t_clt_data *data, t_clt_info *info)
{
	(void)cmd;
	(void)info;
	if (info->connected != TRUE)
		write(data->fd, CODE530, strlen(CODE530));
	else
		write(data->fd, CODE200, strlen(CODE200));
	return (SUCCESS);
}