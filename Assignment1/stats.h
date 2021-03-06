/*
* Auther Name  -> Sakshama Ghoslya
* Email        -> ghoslya@iith.ac.in
* Date         -> 01/11/2020
* Ststs.h file  includes  all function's prototypes which 
* are well defined in the stats.c file.
*/




#ifndef STATS_H
#define STATS_H


/*
* print_statistics  prints output of the othr different
* functions used in the main() function.
*/
void print_statistics(unsigned int median, unsigned int mean, unsigned char max, unsigned char min);

/*
* print_array takes the length and data of array and print 
* it.
*/
void print_array(int len, unsigned char *a);


/*
* this function takes given array and find the median of 
* all given data in array and return it.
*/
unsigned int find_median(int len, unsigned char *a);

/*
* Function takes given array and find the mean of 
* all given data in array and return it.
*/
unsigned int find_mean(int len, unsigned char *a);

/*
* Function takes given array and find the maximum value of 
* all given data in array and return it.
*/
unsigned char find_maximum(int len, unsigned char *a);

/*
* Function takes given array and find the minimum value  of 
* all given data in array and return it.
*/
unsigned char find_minimum(int len, unsigned char *a);

/*
* This function return the sorted array of a given array.
*/
unsigned char sort_array(int len, unsigned char *a);
#endif
