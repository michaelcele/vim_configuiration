#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "holberton.h"

/**
* _printf - print all that received
*@format: arguments received
*/
int _printf(const char *format, ...)
{
	struct nodo *new;
	struct nodo *prev = NULL;
	struct nodo *first = NULL;
	int i = 0;
	int j = 0;
	int last = 0, len = 0;
	char *str_before;
	va_list list_arg;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j++;
			len = (i - 1) - last;
			str_before = malloc(sizeof(char) * len);
			if (str_before)
			{
				_strncpy(str_before, format, len, last);
				new = malloc(sizeof(nodo *));
				if (new)
				{
					new->str = malloc(sizeof(char) * len);
					new->len = len;
					new->type = 'z';
					if (new->str)
					{
						new->str = str_before;
					}
					new->next = NULL;
					if (!first)
					{
						first = new;
						prev = new;
					}
					else
					{
						prev->next = new;
						prev = new;
					}
				}
			}

/*--------------------------------*/

			new = malloc(sizeof(nodo *));
			if (new)
			{
				new->str = NULL;
				new->len = 1;
				new->type = format[i + 1];
				new->next = NULL;
				if (!first)
				{
					first = new;
					prev = new;
				}
				else
				{
					prev->next = new;
					prev = new;
				}
			}

/*--------------------------------*/

			last = i + 2;
		}

		i++;
	}

	if (format[i] == '\0' && format[i - 2] != '%')
	{
		len = i - last;
		str_before = malloc(sizeof(char) * len);
		if (str_before)
		{
			_strncpy(str_before, format, len, last);
			new = malloc(sizeof(nodo *));
			if (new)
			{
				new->str = malloc(sizeof(char) * len);
				new->len = len;
				if (new->str)
				{
					new->str = str_before;
				}
				new->next = NULL;
				if (!first)
				{
					first = new;
					prev = new;
				}
				else
				{
					prev->next = new;
					prev = new;
				}
			}
		}
	}

	new = first;

	va_start(list_arg, format);

	while (new != NULL)
	{
		if (new->type == 'c')
		{
			char temp = va_arg(list_arg, int);

			write(1, &temp, 1);
		}

		if (new->type == 's')
		{
			char *temp2 = va_arg(list_arg, char *);
			unsigned int bytes = _strlen(temp2);

			write(1, temp2, bytes);
		}

		if (new->type == 'z')
		{
			write(1, new->str, new->len);
			write(1, " ", 1);
		}
		new = new->next;
	}

	write(1, "\n", 1);
	return (i);
}

int main(void)
{
	char c = 'a';
	char s[] = "String Hola";
	char j = 'a';

	_printf("Contar cadena %c algo %s mas %c", c, s, j);
	return (0);
}
