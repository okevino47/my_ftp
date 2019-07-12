/*
** EPITECH PROJECT, 2018
** my_str_to_wordtab
** File description:
** my_str_to_wordtab.hpp my_str_to_wordtab.cpp
*/

//#include "my_ftp.h"
#include "../includes/server.h"

/*!
* Function which parse the entire command by
* creating a tab in which each line correspond
* a specific word of the client instruction.
* @param [in] buff
* @return The tab containing all the word
* 	   which compose the client command
*/
char	**parse_command(char *buff)
{
	char	*word;
	char	**tab = NULL;

	word = strtok(buff, " ");
	for (int line = 0; word; line += 1)
	{
		tab = realloc(tab, sizeof(char *) * (line + 2));
		tab[line] = strdup(word);
		tab[line + 1] = NULL;
		word = strtok(NULL, " ");
	}
	for (int line = 0; tab[line] != NULL; line += 1)
		epur_str(&tab[line]);
	return (tab);
}

/*!
* Remove the '\r' and '\n' in the string given
* in parameter.
* @param [out] str
*/
void	epur_str(char **str)
{
	for (int i = 0; (*str)[i] != '\0'; i += 1)
	{
		if ((*str)[i] == '\r' || (*str)[i] == '\n')
			(*str)[i] = '\0';
	}
}