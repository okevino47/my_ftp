/*
** EPITECH PROJECT, 2018
** various_check
** File description:
** various_check.hpp various_check.cpp
*/

//#include "my_ftp.h"
#include <ctype.h>
#include "../includes/server.h"

/*!
* Check if the buffer given in parameter is
* end by a "\r\n" or not.
* @param buff
* @return "FAILURE" if the buffer is not ended
* 	   "SUCCESS" otherwise.
*/
int	check_buff_end(const char *buff)
{
	int	i = 0;

	while (buff[i++] != '\0')
	{
		if (buff[i] == '\n' && buff[i - 1] == '\r')
			return (SUCCESS);
	}
	return (FAILURE);
}

/*!
* Check if the string contain something or if it's
* a "NULL" string.
* @param [in] str
* @return "SUCCESS" if there is something in the
* 	   string, otherwise return 'FAILURE".
*/
int	check_is_empty(const char *str)
{
	if (!str || str[0] == '\0')
		return (FAILURE);
	for (int ltr = 0; str[ltr] != '\0'; ltr += 1)
		if (isprint(str[ltr]) == 0)
			return (FAILURE);
	return (SUCCESS);
}