/*
** EPITECH PROJECT, 2018
** display
** File description:
** display.hpp display.cpp
*/

//#include "my_ftp.h"
#include "../includes/server.h"

/*!
* Dislplay the usage of the server.
*/
void	display_help(void)
{
	printf("%s\n%s%s\n%s%s\n", FIRST_LINE, SECOND_LINEA, SECOND_LINEB, \
		THIRD_LINEA, THIRD_LINEB);
	exit(SUCCESS);
}

/*!
* Display the mandatory message and moreover
* all the function that the client is able to
* use.
* @param [in] cmd
* @param [in] data
* @param [in] info
* @return Only "SUCCESS" code.
*/
int	help_cmd(char **cmd, const t_clt_data *data, t_clt_info *info)
{
	(void)cmd;
	if (info->connected != TRUE)
		write(data->fd, CODE530, strlen(CODE530));
	else
	{
		write(data->fd, CODE214A, strlen(CODE214A));
		write(data->fd, CODE214B, strlen(CODE214B));
		write(data->fd, CODE214C, strlen(CODE214C));
		write(data->fd, CODE214D, strlen(CODE214D));
		write(data->fd, CODE214E, strlen(CODE214E));
		write(data->fd, CODE214F, strlen(CODE214F));
	}
	return (SUCCESS);
}