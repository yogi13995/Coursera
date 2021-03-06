/*
* Auther Name  -> Sakshama Ghoslya
* Email        ->ghoslya@iith.ac.in
* Date         -> 01/11/2020
* Ststs.c file  includes  all function's defination  in
* other words it includes body fo a function .
* 
*/

#include<stdio.h>
#include<string.h>

/*
* print_statistics  prints output of the othr different
* functions used in the main() function.
*/
void print_statistics(unsigned int median, unsigned int mean, unsigned char max, unsigned char min)
{ 
	printf("minimum = %d\n",min);
	printf("maximum = %d\n",max);
	printf("mean = %d\n",mean);
	printf("median = %d\n",median);
}


/*
* print_array takes the length and data of array and print 
* it.
*/
void print_array(int len, unsigned char *a)
{
	printf("Sorted array a[]= [");
	for(int i=0;i<len;i++)
	{
		printf("%d",a[i]);
		printf(",");
		printf(" ");
	}
	printf("]");
}



/*
* this function takes given array and find the median of 
* all given data in array and return it.
*/
unsigned char find_median(int len, unsigned char *a)
{
	unsigned int median,m;
	m = ((a[len/2] +  a[ (len/2) -1]))/2;
	median = (unsigned char)(m);/*To take th nearest integer output*/
	return median;
}


/*
* Function takes given array and find the mean of 
* all given data in array and return it.
*/
unsigned char find_mean(unsigned int len, unsigned char *a)
{
	unsigned int mean,sum,m;
	sum = 0;
	for(int i = 0;i<len;i++)
	{
		sum = sum + a[i];
	}
	m = ((sum))/len;
	mean = (unsigned char )(m);
	return mean;
}

	
	
unsigned char find_maximum(int len, unsigned char *a)
{
	unsigned char max =0;
	for(int i = 0;i<len;i++)
	{
		if(max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}
	
	
	
	
/*
* Function takes given array and find the minimum value  of 
* all given data in array and return it.
*/
unsigned char find_minimum(int len, unsigned char *a)
{
	unsigned char min = a[0];
	for(int i = 0;i<len;i++)
	{
		if(min > a[i])
		{
			min = a[i];
		}
	}
 	return min;
}


/*
* This function return the sorted array of a given array.
*/
unsigned char * sort_array(int len, unsigned char *a)
{
	unsigned char b;
	for(int i = 0;i<len;i++)
	{
	
		for(int j= i+1;j<len;j++)
		{
			if(a[i] < a[j])
			{
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
			
		}
	}
return a;

}





/*
* main() function is the starting point of the codes in c 
*/
int main()
{
	unsigned char a[40] = {34,201,190,154,8,194,2,6,114,88,45,76,123,87,25,23,200,122,150,90,92,87,177,244,201,6,12,60,8,2,5,67,   7,87,250,230,99,3,100,90};
	
	
    
	unsigned char median,mean,max,min,*b;
	int len = sizeof(a);
	
	mean = find_mean(len, a);
	max = find_maximum(len,a);
	min = find_minimum(len,a);
	b = sort_array(len,a);
	median = find_median(len,b);
	print_statistics(median,mean,max,min);
	print_array(len,b);
	return 0;
	
	
}

