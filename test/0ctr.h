
/*------------------------------------
 * 0ctr.h
 * Create:  2025-06-30
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 *
 *
 *
 *
 *------------------------------------
 */


#ifndef TEST_0CTR_H_
#define TEST_0CTR_H_
/*================================================================*/
#define SYS_TEST_IN_OS	1
/*------------------------------------*/
#if SYS_TEST_IN_OS
#define SYS_TEST_IN_BM	0
#define SYS_OS_CYGWIN	1
#define SYS_OS_LINUX	0
#define SYS_OS_WINDOW	0
#else
#define SYS_TEST_IN_BM	1
#define SYS_OS_CYGWIN	0
#define SYS_OS_LINUX	0
#define SYS_OS_WINDOW	0
#endif

#if ((SYS_TEST_IN_BM+SYS_OS_CYGWIN+SYS_OS_LINUX+SYS_OS_WINDOW)!=1)
#error "Only one of four can be 1"
#endif
/*================================================================*/
#endif
/* end of 0ctr.h */
