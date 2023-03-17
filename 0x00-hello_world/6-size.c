#include <stdio.h>
/**
 * * main - This is a prograam print a line with puts function
 * * Return: 0 (Success)
 * */
int main(void)
{
	printf("Size of char:%zu byte(s)", sizeof(char));
	printf("Size of int:%zu byte(s)", sizeof(int));
	printf("Size of long int:%zu byte(s)", sizeof(long int));
	printf("Size of long long int:%zu byte(s)", sizeof(long long int));
	printf("Size of float:%zu byte(s)", sizeof(float));
	return (0);
}
