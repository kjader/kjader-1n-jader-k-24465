#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	printf("hello wordl\n");
	
	for(i = 0; i < argc; i++)
	{
	if (i==0)
	{
		printf("Program name: %s\n", argv[i]);
		continue;
	}		
	printf("Arg no %d: %s\n", i, argv[i]); 
	}

		



	return 0;
}
