/*
** EPITECH PROJECT, 2018
** connexion_destruction
** File description:
** connexion_destruction.hpp connexion_destruction.cpp
*/

#include "../includes/server.h"

/*!
* Close corectly by closing the "fd".
* @param [in] connec
* @return "FAILURE" code i
*/
int	close_connexion(t_co_head *connec)
{
	if (close(connec->fd) == FAILURE)
	{
		perror(PB_CLS_FD);
		return (FAILURE);
	}
	connec->fd = -2;
	return (SUCCESS);
}