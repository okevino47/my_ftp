/*
** EPITECH PROJECT, 2018
** passif_transfert
** File description:
** passif_transfert.hpp passif_transfert.cpp
*/

//#include "server.h"
#include "../includes/server.h"

/*!
* Initialize a new socket to enable the functions
* transfert which will use the new fd stored in
* the struct.
* @param [] cmd
* @param [] data
* @param [] info
* @return "SUCCESS" code in any case
*/
int	pasv_cmd(char **cmd, const t_clt_data *data, \
	t_clt_info *info)
{
	(void)cmd;
	struct	sockaddr_in	transf_struct;
	t_clt_data		pasv_data;
	t_co_head		connec;
	int 		port;

	port = init_passiv_port();
	init_passv_transfert_connexion(&transf_struct, (uint16_t)port , \
	&connec);
	assign_socket_addr(&connec, transf_struct);
	listen_multiple_connexions(connec);
	store_and_print_pasv_infos(pasv_data, data);
	accept_transfert_connection(&connec, info);
	return (SUCCESS);
}

/*!
* Choose a random value between all the port which
* should be available between "1024" and "65535".
* @return the port number calculated.
*/
int	init_passiv_port(void)
{
	int	i;

	srand(time(NULL));
	i = rand() % (MY_RAND_MIN - MY_RAND_MAX) + MY_RAND_MAX;
	printf("%d\n", i);
	return (i);
}

/*!
* Launche all the socket initialisation function
* for the new connection.
* @param [out] transf_struct
* @param [in] port
* @param [out] connec
*/
void	init_passv_transfert_connexion(struct sockaddr_in *transf_struct, \
	uint16_t port, t_co_head *connec)
{
	init_sockaddr_struct(transf_struct, port);
	fill_protoent_struct(connec);
	create_socket(connec);
}

/*!
* Wait that the client ask a connection with the
* information launched on the message fd.
* @param [out] connec
* @param [in] info
*/
void	accept_transfert_connection(t_co_head *connec, t_clt_info *info)
{
	struct sockaddr_in	client_struct;
	int			accepted;
	socklen_t		clt_size = sizeof(client_struct);

	accepted = accept(connec->fd, (struct sockaddr *)&client_struct, \
	&clt_size);
	if (accepted == -1)
		return;
	info->sock_transf = accepted;
}

/*!
* Write on the client output the data that he
* need to connect with the new port.
* @param [in] pasv_data
* @param [in] data
*/
void	store_and_print_pasv_infos(t_clt_data pasv_data, \
	const t_clt_data *data)
{
	char		*str;
	int		i = 0;

	str = malloc(sizeof(char) * 70);
	if (!str)
		return;
	sprintf(str, "%s,%d,%d", data->ip, pasv_data.port >> 8, \
	pasv_data.port & 0xFF);
	while (str[i]) {
		if (str[i] == '.')
			str[i] = ',';
		i += 1;
	}
	write(data->fd, CODE227A, strlen(CODE227A));
	write(data->fd, str, strlen(str));
	write(data->fd, CODE227B, strlen(CODE227B));
}
