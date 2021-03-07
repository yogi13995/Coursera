#ifndef __DATA_H__
#define __DATA_H__
#include"platform.h"
#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>

/* This function takes a pointer, a base and input int data.
	Intiger data is conveted into the desired base ASCII string.
	At the end the length of the string is return includding the null charecter.
*/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/*
	Function takes ASCII string as an input with a pointer and a its length.
	String is converted into the decimal integer and then returned .
*/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif
