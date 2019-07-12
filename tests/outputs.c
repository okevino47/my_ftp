/*
** EPITECH PROJECT, 2018
** outputs
** File description:
** outputs.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include "../server_folder/includes/server.h"
#include "../commons/includes/common.h"

TestSuite(redirect, .timeout = 1);

Test(nb_arg, stdout_)
{
	cr_assert(check_number_arg(3, NULL) == SUCCESS, "\n\nechec\n\n");
}
