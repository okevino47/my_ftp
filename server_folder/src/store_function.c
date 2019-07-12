/*
** EPITECH PROJECT, 2018
** store_function
** File description:
** store_function.hpp store_function.cpp
*/

//#include "server.h"
#include "../includes/server.h"

int 	stor_cmd(char **cmd, const t_clt_data *data, t_clt_info *info)
{
	(void)cmd;
	(void)info;
	write(data->fd, CODE550, strlen(CODE550));
	return (SUCCESS);
}
