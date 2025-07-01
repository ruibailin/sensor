/*
 * log_hex.c
 *
 *  Created on: Jan 9, 2024
 *      Author: steve rui
 */



/*================================================================*/
#include <stdio.h>
#include <stdlib.h>
/*------------------------------------*/
static void print_ascii(unsigned char c);
static void print_ascii(unsigned char c)
{
	if(c <' ')
	{
		printf("%c ", '.');
		return;
	}
	if(c<127)
	{
		printf("%c ", c);
		return;
	}
	printf("%c ", '.');
}

static void print_hex_ascii(unsigned char*buf,int size);
static void print_hex_ascii(unsigned char*buf,int size)
{
	int i,j;
	int line,row;
	line=size/16;
	row=size%16;
	j=0;
	printf("\r\n|-------------------------------------------------|\r\n");
	printf("\r\n");
	for(j=0; j<line; j++)
	{
		for(i=0;i<16;i++)
			printf("%02X ", buf[j*16+i]);
		printf("  |    ");
		for(i=0;i<16;i++)
		{
			print_ascii(buf[j*16+i]);
		}
		printf("\r\n");
	}

	if(row == 0)
	{
		printf("\r\n");
		printf("\r\n|-------------------------------------------------|\r\n");
		return;
	}

	for(i=0;i<row;i++)
	{
		printf("%02X ", buf[j*16+i]);
	}

	for(i=row;i<16;i++)
	{
		printf("   ");
	}
	printf("  |    ");
	for(i=0;i<row;i++)
	{
		print_ascii(buf[j*16+i]);
	}
	printf("\r\n");
	printf("\r\n");
	printf("\r\n|-------------------------------------------------|\r\n");
}
/*------------------------------------*/
void rbl_log_hex(unsigned char *data, int size);
void rbl_log_hex(unsigned char *data, int size)
{
	print_hex_ascii((unsigned char *)data,size);
}
/*================================================================*/
/* end of log_hex.c */
