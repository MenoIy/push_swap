#include <stdlib.h>
#include <stdio.h>

int get_bit(unsigned int value, int pos)
{
	    int c = value & (1 << pos);
			    return c;
}

int main(int argc, char **argv)
{
	   unsigned int input1 = atoi(argv[1]);
	      int input2 = atoi(argv[2]);
		     
		     printf("%d", get_bit(input1, input2)); 
			    return (0);
}
