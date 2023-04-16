#include<stdio.h>
#include"main.h"
#include <stdlib.h>
/**
* string_nconcat - Concatenates two strings, up to n bytes of the second string
* @s1: First string
* @s2: Second string
* @n: Maximum number of bytes of s2 to concatenate
* Return: Pointer to newly allocated memory with concatenated string
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
unsigned int s1_len = 0, s2_len = 0, i, j;
char *result;

if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
while (s1[s1_len])
s1_len++;
while (s2[s2_len])
s2_len++;
if (n >= s2_len)
n = s2_len;
result = malloc(sizeof(char) * (s1_len + n + 1));
if (result == NULL)
return (NULL);
for (i = 0; i < s1_len; i++)
result[i] = s1[i];
for (j = 0; j < n; j++)
result[i + j] = s2[j];
result[i + j] = '\0';
return (result);
}
