/*
** EPITECH PROJECT, 2018
** destroy_ressources
** File description:
** destroy_ressources.hpp destroy_ressources.cpp
*/

//#include "server.h"
#include "../includes/server.h"

void	free_tab_cmd(char **tab)
{
	int	i = 0;

	while (tab[i] != NULL)
	{
		free(tab[i]);
		i += 1;
	}
	free(tab[i]);
	free(tab);
}