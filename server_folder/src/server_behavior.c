/*
** EPITECH PROJECT, 2018
** server_behavior
** File description:
** server_behavior.hpp server_behavior.cpp
*/

//#include "my_ftp.h"
#include "../includes/server.h"

/*!
* Launch the listen function and check the return
* of the function.
* @param [in] connec
*/
void	listen_multiple_connexions(t_co_head connec)
{
	if (listen(connec.fd, CONNEC_MAX_NB) == FAILURE)
	{
		if (close(connec.fd))
		{
			perror(PB_CLS_LSTN);
			exit(ERROR);
		}
		perror(PB_LSTN);
		exit(ERROR);
	}
}

/*!
* Loop to create a structure that regroup all client
* data and to accept every client request. Print error
* message if a problem occur, loop continue until the
* "SINGINT" signal catch.
* @param [in] connec
* @param [in] server
*/
void	server_loop(t_co_head *connec)
{
	t_clt_data	clt_data;
	int		accepted;
	pid_t		pid;

	accepted = accept_new_client(connec, &clt_data);
	if (accepted == SUCCESS)
	{
		pid = fork();
		if (pid == ERROR_FORK)
			perror(PB_FORK_EXEC);
		else if (pid == CLIENT)
			client_handle(&clt_data, (*connec));
	}
	close(clt_data.fd);
}

/*!
* Accept a new connexion and fill the structure relative
* to the client.
* @param [in] connec
* @param [in/out] clt_data
* @return the structure filled with the client info. Structure
* 	   will be set to "NULL" if a problem occur.
*/
int	accept_new_client(t_co_head *connec, t_clt_data *clt_data)
{
	int			fd_client;
	struct sockaddr_in	client_struct;
	socklen_t		client_size = sizeof(client_struct);

	fd_client = accept(connec->fd, (struct sockaddr *)&client_struct, \
	&client_size);
	if (fd_client == -1)
	{
		perror(PB_FD_CLT);
		return (FAILURE);
	}
	fill_client_struct(clt_data, client_struct, fd_client);
	return (SUCCESS);
}

/*!
* Little function which role is just to assign the client
* data.
* @param [out] clt_data
* @param [in] client_struct
* @param [in] fd_client
*/
void	fill_client_struct(t_clt_data *client_data, \
	const struct sockaddr_in client_struct, const int fd_client)
{
	client_data->fd		= fd_client;
	client_data->ip		= inet_ntoa(client_struct.sin_addr);
	client_data->port	= (int)ntohs(client_struct.sin_port);
}