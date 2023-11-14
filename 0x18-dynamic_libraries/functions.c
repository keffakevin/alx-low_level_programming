#include <stdio.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, returns the written character. On error, returns -1.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _islower - Checks if a character is a lowercase letter.
 * @c: The character to be checked.
 *
 * Return: 1 if the character is a lowercase letter, 0 otherwise.
 */
int _islower(int c)
{
    return (c >= 'a' && c <= 'z');
}

/**
 * _isalpha - Checks if a character is an alphabetic character.
 * @c: The character to be checked.
 *
 * Return: 1 if the character is an alphabetic character, 0 otherwise.
 */
int _isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _abs - Computes the absolute value of an integer.
 * @n: The integer to compute the absolute value of.
 *
 * Return: The absolute value of the integer.
 */
int _abs(int n)
{
    return (n < 0) ? -n : n;
}

/**
 * _isupper - Checks if a character is an uppercase letter.
 * @c: The character to be checked.
 *
 * Return: 1 if the character is an uppercase letter, 0 otherwise.
 */
int _isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

/**
 * _isdigit - Checks if a character is a digit.
 * @c: The character to be checked.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

/**
 * _strlen - Computes the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
    int length = 0;

    while (*s != '\0')
    {
        length++;
        s++;
    }

    return length;
}

/**
 * _puts - Writes a string to stdout.
 * @s: The string to be written.
 */
void _puts(char *s)
{
    while (*s != '\0')
    {
        _putchar(*s);
        s++;
    }
}

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
    char *originalDest = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';  // Null-terminate the destination string
    return originalDest;
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
    int result = 0;
    int sign = 1;

    if (*s == '-')
    {
        sign = -1;
        s++;
    }

    while (*s >= '0' && *s <= '9')
    {
        result = result * 10 + (*s - '0');
        s++;
    }

    return sign * result;
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strcat(char *dest, char *src)
{
    char *originalDest = dest;

    while (*dest != '\0')
    {
        dest++;
    }

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';  // Null-terminate the concatenated string
    return originalDest;
}

/**
 * _strncat - Concatenates n characters from one string to another.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The number of characters to concatenate.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
    char *originalDest = dest;

    while (*dest != '\0')
    {
        dest++;
    }

    while (*src != '\0' && n > 0)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    *dest = '\0';  // Null-terminate the concatenated string
    return originalDest;
}

/**
 * _strncpy - Copies up to n characters from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of characters to copy.
 *
 * Return: A pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
    char *originalDest = dest;

    while (*src != '\0' && n > 0)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    // Fill the remaining characters with null bytes if needed
    while (n > 0)
    {
        *dest = '\0';
        dest++;
        n--;
    }

    return originalDest;
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if the strings are equal, a negative value if s1 is less than s2,
 *         and a positive value if s1 is greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    return (*s1 - *s2);
}

/**
 * _memset - Fills the first n bytes of a memory area with a constant byte.
 * @s: The memory area to be filled.
 * @b: The constant byte.
 * @n: The number of bytes to be filled.
 *
 * Return: A pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
    while (n > 0)
    {
        *s = b;
        s++;
        n--;
    }

    return s;
}

/**
 * _memcpy - Copies n bytes from source to destination.
 * @dest: The destination memory area.
 * @src: The source memory area.
 * @n: The number of bytes to be copied.
 *
 * Return: A pointer to the destination memory area.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
    while (n > 0)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    return dest;
}

/**
 * _strchr - Locates the first occurrence of a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: A pointer to the first occurrence of the character c in the string s,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
        {
            return s;
        }
        s++;
    }

    return NULL;
}

/**
 * _strspn - Calculates the length of the initial segment of a string
 *           consisting of only characters from another string.
 * @s: The input string.
 * @accept: The string containing the characters to match.
 *
 * Return: The number of characters in the initial segment of s that match
 *         any character in accept.
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;

    while (*s != '\0' && *accept != '\0' && *s == *accept)
    {
        count++;
        s++;
        accept++;
    }

    return count;
}

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: The string to be searched.
 * @accept: The set of characters to search for.
 *
 * Return: A pointer to the first occurrence in s of any character in accept,
 *         or NULL if no such character is found.
 */
char *_strpbrk(char *s, char *accept)
{
    while (*s != '\0')
    {
        char *currentAccept = accept;
        while (*currentAccept != '\0')
        {
            if (*s == *currentAccept)
            {
                return s;
            }
            currentAccept++;
        }
        s++;
    }

    return NULL;
}

/**
 * _strstr - Locates a substring within a string.
 * @haystack: The string to be searched.
 * @needle: The substring to search for.
 *
 * Return: A pointer to the first occurrence of the substring needle in the
 *         string haystack, or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
    while (*haystack != '\0')
    {
        char *h = haystack;
        char *n = needle;
        while (*n != '\0' && *h == *n)
        {
            h++;
            n++;
        }
        if (*n == '\0')
        {
            return haystack;
        }
        haystack++;
    }

    return NULL;
}

