/*
** EPITECH PROJECT, 2018
** client_handle
** File description:
** client_handle.hpp client_handle.cpp
*/

//#include "my_ftp.h"
#include "../includes/server.h"

/*!
* List of the possible client command
* that can be receive.
*/
static const char	*command_list[] = {
	"USER", \
	"PASS", \
	"CWD", \
	"CDUP", \
	"QUIT", \
	"DELE", \
	"PWD", \
	"PASV", \
	"PORT", \
	"HELP", \
	"NOOP", \
	"RETR", \
	"STOR", \
	"LIST", \
	NULL
};

/*!
* Tab of function pointer with an order compliant
* with the command list above it.
*/
static int	(*func_tab[14])(char**, const t_clt_data*, t_clt_info*) = {
		(user_cmd), \
		(pass_cmd), \
		(cwd_cmd), \
		(cdup_cmd), \
		(quit_cmd), \
		(dele_cmd), \
		(pwd_cmd), \
		(pasv_cmd), \
		NULL, \
		(help_cmd), \
		(noop_cmd), \
		NULL, \
		NULL, \
		NULL
	};

/*!
* Call every function that can be call by the client.
* @param [in] clt_data
* @param [in] connec
*/
void	client_handle(const t_clt_data *clt_data, const t_co_head connec)
{
	(void)connec;
	welcome_client(clt_data);
	read_client_request(clt_data);
	return;
}

/*!
* Call the reply code "220", must be called
* at the start of a connexion.
* @param [in] clt_data
*/
void 	welcome_client(const t_clt_data *clt_data)
{
	write(clt_data->fd, CODE220, strlen(CODE220));
}

/*!
* Loop with a "read" function to listen the client
* request and traet them.
* @param [in] clt_data
*/
void 	read_client_request(const t_clt_data *clt_data)
{
	char		buff[1024];
	char 		**cmd = NULL;
	t_clt_info	info;

	init_info_struct(&info);
	while (1) {
		memset(buff, '\0', 1024);
		read(clt_data->fd, buff, 1024);
		if (check_buff_end((const char *)buff) == SUCCESS) {
			cmd = parse_command(buff);
			launch_and_check_command(cmd, clt_data, &info);
			free_tab_cmd(cmd);
		}
	}
}

/*!
* Check if the command exist in the command list
* that regroup every possible command.
* @param [in] buff
* @return "FAILURE" if the command does not exist
* 	   or "SUCCESS" otherwise.
*/
int 	check_existing_command(const char *buff)
{
	int 	line = 0;

	if (!buff)
		return (FAILURE);
	while (command_list[line] != NULL) {
		if (strcmp(buff, command_list[line]) == 0)
			return (line);
		line += 1;
	}
	return (FAILURE);
}

/*!
* If the command argument is correct, launch the
* corresponding command after the check.
* @param [in] cmd
* @param [in] data
* @param [in] info
*/
void	launch_and_check_command(char **cmd, const t_clt_data *data, \
	t_clt_info *info)
{
	int	valid;

	valid = check_existing_command((const char *)cmd[0]);
	if (info->connected == FALSE && \
	(valid != 0 && valid != 1 && valid != 4)) {
		write(data->fd, CODE530, strlen(CODE530));
		return;
	}
	if (valid != FAILURE && func_tab[valid] != NULL)
		(func_tab[valid])(cmd, data, info);
	else
		write(data->fd, CODE500, strlen(CODE500));
}
