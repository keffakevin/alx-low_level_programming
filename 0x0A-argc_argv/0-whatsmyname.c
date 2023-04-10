#include <stdio.h>
#include <stdlib.h>
/**
 * main- function that print alahabetic
 * @argc:parameter description
 * @argv:parameter description
 * Return:0
 */
int main(int argc, char **argv)
{
while (argc--)
printf("%s\n", *argv++);
exit(EXIT_SUCCESS);
}
