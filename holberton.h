#ifndef HOLBERTON_H
#define HOLBERTON_H
typedef struct nodo
{
        char *str;
        int len;
        char type;
        struct nodo *next;
}nodo;
char *_strncpy(char *dest, const char *src, int n, int first);
int _strlen(char *s);

#endif