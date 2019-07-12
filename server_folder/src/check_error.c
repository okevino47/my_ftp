/*
** EPITECH PROJECT, 2018
** check_error
** File description:
** check_error.hpp check_error.cpp
*/

//#include "my_ftp.h"
#include "../includes/server.h"

/*!
* Make all preliminary check at the beginning of the program.
* @param [in] ac
* @param [in] av
* @param [out] port
* @return Only a "SUCCESS" code, if an error occur in the
* 	   sub-functions the exit function is calling with
* 	   the appropriate code.
*/
int 	preliminary_check(const int ac, const char **av, uint16_t *port)
{
	check_number_arg(ac, av);
	check_arg_consistence(ac, av, port);
	return (SUCCESS);
}

/*!
* Check the number of the argument, in case of an amount
* of 2 argument, check the second argument value to find
* a "-help" content. In this case print the help and exit
* with a "SUCCESS" code. If not exit with "ERROR" code.
* @param [in] ac
* @param [in] av
* @return "SUCCESS" if any error occur during the process
* 	   otherwise, exit with a "SUCCESS" or "ERROR" code
*/
int	check_number_arg(const int ac, const char **av)
{
	if (ac == 3)
		return (SUCCESS);
	else if (ac == 2)
	{
		if (strcmp(av[1], "-help") == 0)
			display_help();
		else
			fprintf(stderr, "%s%s%s\n", WRG_ARGA, WRG_ARGB, \
			WRG_ARGC);
		exit(ERROR);
	}
	else
	{
		fprintf(stderr, "%s%s\n", ARG_ERRA, ARG_ERRB);
		exit(ERROR);
	}
}

/*!
* Check all argument value if an error occur during
* the process the "exit" function with the appropriate
* code is called. If the "port" argument fill the
* corresponding variable.
* @param [in] ac
* @param [in] av
* @return only a "SUCCESS" code, otherwise the "exit"
* 	   function is called.
*/
int	check_arg_consistence(const int ac, const char **av, uint16_t *port)
{
	char *port_rest = NULL;
	(void)ac;

	(*port) = (uint16_t)(strtol(av[1], &port_rest, 10));
	if (port_rest[0] != '\0')
	{
		fprintf(stderr, "%s%s%s\n", WRG_ARGA, WRG_ARGB, WRG_ARGC);
		exit(ERROR);
	}
	check_if_existing_path(av[2]);
	return (SUCCESS);
}

/*!
* Check if the path given if a correct directory.
* @param [in] path
* @return Only a "SUCCESS" code if the program
* 	   work well, exit with the "ERROR" code
* 	   if an error occur.
*/
int	check_if_existing_path(const char *path)
{
	struct stat	stat_struct;

	if (stat(path, &stat_struct) != SUCCESS)
	{
		perror(PB_STAT);
		exit(ERROR);
	}
	else {
		if (S_ISDIR(stat_struct.st_mode))
			return (SUCCESS);
		else
		{
			fprintf(stderr, "%s\n", NOT_DIR);
			exit(ERROR);
		}
	}
}
