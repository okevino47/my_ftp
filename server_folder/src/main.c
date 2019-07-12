/*
** EPITECH PROJECT, 2018
** main
** File description:
** main.hpp main.cpp
*/

//#include "my_ftp.h"
#include "../includes/server.h"

/*!
* Mother function of calling everything in the program.
* @param [in] ac
* @param [in] av
* @return
*/
int	main(int ac, char **av)
{
	t_co_head		connec;
	uint16_t 		port;
	struct sockaddr_in	server_struct;

	preliminary_check(ac, (const char **)av, &port);
	init_connexion_struct(&connec, &server_struct, port);
	assign_socket_addr(&connec, server_struct);
	listen_multiple_connexions(connec);
	while (1)
		server_loop(&connec);
	return (SUCCESS);
}
