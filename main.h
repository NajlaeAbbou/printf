#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
/***task4*****/
#define BUFF_SIZE 1024

/* params task 7 11 12*/
#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16

/* size */
#define LONG 2
#define SHORT 1


/**
 * struct handlerPrint - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @handlerPrint: f specifier
 * @fn: pointer to the printing function
 */
struct handlerPrint
{
	char handlerPrint;
	int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct handlerPrint hp;


int _printf(const char *format, ...);
int get_print(const char *c, int *i,
va_list list, char buffer[], int params, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* print chars and strings task 0*/
int print_char(va_list vl, char buffer[],
	int params, int width, int precision, int size);
int print_string(va_list vl, char buffer[],
	int params, int width, int precision, int size);
int print_percent(va_list vl, char buffer[],
	int params, int width, int precision, int size);

/* print numbers task 1*/
int print_int(va_list vl, char buffer[],
	int params, int width, int precision, int size);
int print_binary(va_list vl, char buffer[],
	int params, int width, int precision, int size);
int print_unsigned(va_list vl, char buffer[],
	int params, int width, int precision, int size);
int print_octal(va_list vl, char buffer[],
	int params, int width, int precision, int size);
int print_hexadecimal_lowercase(va_list vl, char buffer[],
	int params, int width, int precision, int size);
int print_hexadecimal_uppercase(va_list vl, char buffer[],
	int params, int width, int precision, int size);

int printhexa(va_list vl, char map_to[],
char buffer[], int params, char flag_ch, int width, int precision, int size);

/* print non printable characters */
int print_UppercaseS(va_list vl, char buffer[],
	int params, int width, int precision, int size);

/* print memory address p task 6*/
int print_address(va_list vl, char buffer[],
	int params, int width, int precision, int size);

/*  handle other specifiers task  8 9 10 */
int get_params(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* print string in reverse task 13 */
int print_reverse(va_list vl, char buffer[],
	int params, int width, int precision, int size);

/* print a string in rot 13 task 14 */
int print_rot13(va_list vl, char buffer[],
	int params, int width, int precision, int size);

/* width handler */
int writechar(char c, char buffer[],
	int params, int width, int precision, int size);
int writenumber(int is_positive, int ind, char buffer[],
	int params, int width, int precision, int size);
int writenum(int ind, char bff[], int params, int width, int precision,
	int length, char padd, char extra_c);
int writeadress(char buffer[], int ind, int length,
	int width, int params, char padd, char extra_c, int padd_start);
int writeunsgnd(int ind,
char buffer[],
	int params, int width, int precision, int size);
int _isprintable(char);
int _appendhexacode(char, char[], int);
int _isdigit(char);

long int convertsizenumber(long int num, int size);
long int convertsizeunsgnd(unsigned long int num, int size);

#endif

