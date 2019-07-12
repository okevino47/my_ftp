/*
** EPITECH PROJECT, 2018
** connection_creation
** File description:
** connection_creation.hpp connection_creation.cpp
*/

//#include "../../commons/includes/common.h"
#include "../includes/server.h"

/*!
* Call every function needed to create and set up
* a connexion by creating a socket and filling it.
* @param [out] connec
* @param [in/out] server_struct
* @param [in] port
*/
void	init_connexion_struct(t_co_head *connec, \
	struct sockaddr_in *server_struct, uint16_t port)
{
	init_sockaddr_struct(server_struct, port);
	fill_protoent_struct(connec);
	create_socket(connec);
}

/*!
* Initialise the "sockaddr_in" structure.
* @param [out] server_struct
* @param [in] port
*/
void	init_sockaddr_struct(struct sockaddr_in *server_struct, \
	const uint16_t port)
{
	server_struct->sin_family	= AF_INET;
	server_struct->sin_port		= htons(port);
	server_struct->sin_addr.s_addr	= INADDR_ANY;
}

/*!
* Fill the "protocol" variable to avoid using the
* protoent structure along all the program execution.
* @param [out] connec
*/
void	fill_protoent_struct(t_co_head *connec)
{
	struct protoent	*pe;

	pe = getprotobyname("TCP");
	if (!pe)
		perror(PB_PROTO);
	connec->protocol = pe->p_proto;
}

/*!
* Fill the "fd" variable of the "connec" structure with the
* socket function return.
* @param [out] connec
*/
void	assign_socket_addr(t_co_head *connec, \
	struct sockaddr_in server_struct)
{
	if (bind(connec->fd, (const struct sockaddr *)&server_struct, \
	sizeof(server_struct)) == FAILURE)
	{
		if (close_connexion(connec) == FAILURE)
		{
			perror(PB_CLS_BIND);
			exit(ERROR);
		}
		perror(PB_BIND);
		exit(ERROR);
	}
}

/*!
* Call the "Socket" function and check if the
* return is correct or exit if not.
* @param [out] connec
*/
void	create_socket(t_co_head *connec)
{
	connec->fd = socket(AF_INET, SOCK_STREAM, connec->protocol);
	if (!connec->fd)
	{
		perror(WRG_FD);
		exit(ERROR);
	}
}
