/*
** EPITECH PROJECT, 2018
** common
** File description:
** common.hpp common.cpp
*/

#ifndef COMMON_H_
#define COMMON_H_

enum	e_return_values
{
	SUCCESS = 0,
	FAILURE	= -1,
	ERROR	= 84
};

enum 	e_pid_values
{
	CLIENT	= 0,
	ERROR_FORK = -1
};

/*!
* 	Error macro messages
*/
#define WRG_FD		("Problem occured during the fd creation")
#define PB_CLS_FD	("Error, occured during the fd closure")
#define PB_PROTO	("Error, occured during the proto struct creation")
#define PB_BIND		("Error, at the binding process")
#define PB_CLS_BIND	("Error, occured during the binding closure process")
#define	PB_LSTN		("Error, occured during the listen launching")
#define PB_CLS_LSTN	("Error occured during the listening closure process")
#define PB_FD_CLT	("Error, occured during the client acceptation")
#define PB_FORK_EXEC	("Error, occured during the fork execution")
#define PB_STAT		("Error, occured during the stat process")
#define ARG_ERRA	("Error, the number of argument is incorrect, type ")
#define ARG_ERRB	("\"./server -help\" for usage information.")
#define	WRG_ARGA	("Error one or more of your argument is invalid, ")
#define	WRG_ARGB	("please type \"./server -help\" for ")
#define	WRG_ARGC	("usage information.")
#define NOT_DIR		("Error, the pathname given is not a directory.")

/*!
* 	Mandatory reply codes
*/
#define	CODE120		("120 Service ready in nnn minutes.\r\n")
#define	CODE125		("125 Data connection already open; transfer starting.\r\n")
#define	CODE150		("150 File status okay; about to open data connection.\n")
#define	CODE200		("200 Command okay.\n")
#define	CODE214A	("214 Help message.\nOn how to use the server or the ")
#define	CODE214B	("meaning of a particular\nnon-standard command.  ")
#define	CODE214C	("This reply is useful only to the\nhuman user.\n")
#define	CODE214D	("The following commands are recognized.\n")
#define	CODE214E	("USER PASS CWD CDUP HELP QUIT NOOP\n")
#define	CODE214F	("214 Help OK.\r\n")
#define	CODE220		("220 Service ready for new user.\r\n")
#define	CODE221A	("221 Service closing control connection.\nLogged out ")
#define	CODE221B	("if appropriate.\r\n")
#define	CODE226A	("226 Closing data connection.\nRequested file action ")
#define	CODE226B	("successful (for example, file\ntransfer or file ")
#define	CODE226C	("abort).\r\n")
#define	CODE227A	("227 Entering Passive Mode (")
#define	CODE227B	(")\r\n")
#define	CODE230		("230 User logged in, proceed.\r\n")
#define	CODE250		("250 Requested file action okay, completed.\r\n")
#define	CODE257A	("257 \"")
#define	CODE257B	("\" created.\r\n")
#define	CODE331		("331 User name okay, need password.\r\n")
#define	CODE332		("332 Need account for login.\r\n")
#define	CODE500		("500 Unknow command.\r\n")
#define	CODE503		("503 Login with USER first.\r\n")
#define	CODE530		("530 Permission denied.\r\n")
#define	CODE550		("550 Failed to change directory.\r\n")

/*!
* 	Help messages
*/
#define FIRST_LINE	("USAGE: ./server port path")
#define SECOND_LINEA	("\tport  is the port number  on which the server ")
#define SECOND_LINEB	("socket listens")
#define THIRD_LINEA	("\tpath  is the pathto the home directory for ")
#define THIRD_LINEB	("the Anonymous user")

#endif /* !COMMON_H_ */
