
/*------------------------------------
 * termios.c
 * Create:  2025-07-01
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 *
 *
 *
 *
 *------------------------------------
 */

#include "..\..\0ctr.h"
#if SYS_OS_LINUX
/*================================================================*/
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
/*------------------------------------*/
static struct termios old_tio, new_tio;
void sys_init_term(void);
void sys_init_term()
{
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    int flags,ret;
    flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    flags |= O_NONBLOCK;
    ret   = fcntl(STDIN_FILENO, F_SETFL, flags);
    if(ret==-1)
    {
    	perror("fcntl F_SETFL\r\n");
    }

}
void sys_restore_term(void);
void sys_restore_term()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);

    int flags;
    flags = fcntl(STDIN_FILENO, F_GETFL);
    flags &= ~O_NONBLOCK;
    fcntl(STDIN_FILENO, F_SETFL, flags);

}
/*------------------------------------*/
static char old;
char sys_get_char(void);
char sys_get_char()
{
	char ch;
	read(STDIN_FILENO, &ch, 1);
	if(ch == old)
		return 0;
	else
		old = ch;
	return ch;
}
/*================================================================*/
#endif
/* end of termios.c */
