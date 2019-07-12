/*
** EPITECH PROJECT, 2018
** init_function
** File description:
** init_function.hpp init_function.cpp
*/

//#include "my_ftp.h"
#include <asm/errno.h>
#include "../includes/server.h"

/*!
* Initialise to "NULL" or "FALSE" every variable
* that info structure contain.
* @param [in] info
*/
void	init_info_struct(t_clt_info *info)
{
	info->sock_transf	= -1;
	info->user 		= NULL;
	info->pass		= NULL;
	info->connected		= FALSE;
	info->transfering	= FALSE;
}