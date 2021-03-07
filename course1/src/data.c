#include"data.h"
#include"platform.h"
/* This function takes a pointer, a base and input int data.
	Intiger data is conveted into the desired base ASCII string.
	At the end the length of the string is return includding the null charecter.
*/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	int32_t dev = data;
	int32_t rem;
	int8_t count = 0;
	int8_t size = 0;

	
	if(dev<0)
	{
	*ptr = (char)(45);
	dev = (~(dev)) +1;
	count = count +1;
	}
	int32_t dev1 = dev;
	
	while((dev1 != 0))
	{
		dev1 = dev1 / base;
		count = count +1;
		size = size +1;
		
	}
	
	*(ptr + count) = '\0';
	//printf("%d",count);
	
	while((dev != 0))
	{
	 	count = count - 1;	
		rem = dev % base;
		dev = dev / base;
		*(ptr + count) = (char)(rem + 48);	
	}
	//printf("data1 is %s\n",ptr);
	//printf("%s\n",ptr);
	return (size +1);	
}

/*
	Function takes ASCII string as an input with a pointer and a its length.
	String is converted into the decimal integer and then returned .
*/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int32_t value = 0;
	int8_t count = 0;
	int8_t flag =0;
	if(*ptr == '-')
	{
	 flag = 1;
	 count = count +1;
	}
	
	
	while(*(ptr + count) != '\0')
	{
		value  = value*base + (int)(*(ptr + count) -48);
		count = count+1;
	}
	if(flag == 1)
	{
		value = (~(value) +1);
	}
	//printf("data2 is%d\n",value);
	return value;
}
