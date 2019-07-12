/*
** EPITECH PROJECT, 2018
** my_ftp
** File description:
** my_ftp.hpp my_ftp.cpp
*/

#ifndef MY_FTP_H_
#define MY_FTP_H_

#include <time.h>
#include <netdb.h>
#include <zconf.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "../../commons/includes/common.h"

#define	CONNEC_MAX_NB	(10)
#define MY_RAND_MIN	(1025)
#define MY_RAND_MAX	(65535)

/*!
* 	Regroup all the information relative to the
* 	server.
*/
typedef struct	s_connexion_header
{
	int			fd;
	int			protocol;
	struct protoent		pe;
}		t_co_head;

/*!
*	Regroup all the client data.
*/
typedef struct	s_client_data
{
	int	fd;
	int	port;
	char	*ip;
}		t_clt_data;

/*!
*	Gard every important information
*	about the client command enterred
*/
typedef struct	s_clt_info
{
	int	sock_transf;
	char	*user;
	char	*pass;
	bool	connected;
	bool	transfering;
}		t_clt_info;

/*
**	Functions in "connexion_creation.c"
*/

void	create_socket(t_co_head *connec);
void	fill_protoent_struct(t_co_head *connec);
void	init_sockaddr_struct(struct sockaddr_in *server_struct, \
	uint16_t port);
void	assign_socket_addr(t_co_head *connec, \
	struct sockaddr_in server_struct);
void	init_connexion_struct(t_co_head *connec, \
	struct sockaddr_in *server_struct, uint16_t port);

/*
**	Functions in "connexion_destruction.c"
*/

int	close_connexion(t_co_head *connec);

/*
**	Functions in "server_behavior.c"
*/

void		listen_multiple_connexions(t_co_head connec);
void		server_loop(t_co_head *connec);
void		fill_client_struct(t_clt_data *clt_data, \
		struct sockaddr_in client_struct, int fd_client);
int		accept_new_client(t_co_head *connec, t_clt_data *clt_data);

/*
**	Functions in "client_handle.c"
*/

void 	welcome_client(const t_clt_data *clt_data);
void 	read_client_request(const t_clt_data *clt_data);
void	client_handle(const t_clt_data *clt_data, t_co_head connec);
void	launch_and_check_command(char **cmd, const t_clt_data *data, \
	t_clt_info *info);
int 	check_existing_command(const char *buff);

/*
**	Functions in "check_error.c"
*/

int 	preliminary_check(const int ac, const char **av, uint16_t *port);
int	check_number_arg(const int ac, const char **av);
int	check_arg_consistence(const int ac, const char **av, uint16_t *port);
int	check_if_existing_path(const char *path);

/*
**	Functions in "display_help.c"
*/

void 	display_help(void);
int	help_cmd(char **cmd, const t_clt_data *data, t_clt_info *info);

/*
**	Functions in "various_check.c"
*/

int	check_is_empty(const char *str);
int	check_buff_end(const char *buff);

/*
**	Functions in "init_function.c"
*/

void	init_info_struct(t_clt_info *info);

/*
**	Functions in "init_function.c"
*/

void	free_tab_cmd(char **tab);

/*
**	Functions in "my_str_to_wordtab.c"
*/

void	epur_str(char **str);
char	**parse_command(char *buff);

/*
**	Functions in "login_function.c"
*/

int	user_cmd(char **cmd, const t_clt_data *data, t_clt_info *info);
int	pass_cmd(char **cmd, const t_clt_data *data, t_clt_info *info);

/*
**	Functions in "noop_function.c"
*/

int 	noop_cmd(char **cmd, const t_clt_data *data, t_clt_info *info);

/*
**	Functions in "displace_function.c"
*/

int	cwd_cmd(char **cmd, const t_clt_data *data, t_clt_info *info);
int	cdup_cmd(char **cmd, const t_clt_data *data, t_clt_info *info);

/*
**	Functions in "listing_function.c"
*/

int	pwd_cmd(char **cmd, const t_clt_data *data, t_clt_info *info);

/*
**	Functions in "quit_function.c"
*/

int	quit_cmd(char **cmd, const t_clt_data *data, t_clt_info *info);

/*
**	Functions in "delete_function.c"
*/

int	dele_cmd(char **cmd, const t_clt_data *data, t_clt_info *info);

/*
**	Functions in "store_function.c"
*/

int 	stor_cmd(char **cmd, const t_clt_data *data, t_clt_info *info);

/*
**	Functions in "passif_function.c"
*/

void	init_passv_transfert_connexion(struct sockaddr_in *transf_struct, \
	uint16_t port, t_co_head *connec);
void	accept_transfert_connection(t_co_head *connec, t_clt_info *info);

void	store_and_print_pasv_infos(t_clt_data pasv_data, \
	const t_clt_data *data);
int	init_passiv_port(void);
int	pasv_cmd(char **cmd, const t_clt_data *data, \
	t_clt_info *info);

#endif /* !MY_FTP_H_ */