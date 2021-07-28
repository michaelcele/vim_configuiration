#include "holberton.h"
/**
 * _strlen  - Return length of a string
 *
 * @s: String
 *
 * Return: i
 */
int _strlen(char *s)
{
	int i = 0;
	char c = s[0];

	while (c != '\0')
	{
		c = s[++i];
	}

	return (i);
}
