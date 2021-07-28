#include "holberton.h"

/**
 *_strncpy - Copy a string
 *@dest: String final
 *@src: String to copy
 *@n: bytes to copy
 *@first: Position to begin a copy
 *Description: Function for copies a string from a starting position
 *Return: A pointer to string copied
 *
 **/

char *_strncpy(char *dest, const char *src, int n, int first)
{
        int i;

        i = 0;
        while ((src[first + i] != '\0') && (i < n))
        {
                dest[i] = src[first + i];
                i++;
        }
        
        return (dest);
}