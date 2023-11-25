#include "shell.h"

/**
 * f_strcpy - this copies the required string
 * @dest: required destination
 * @src: source
 *
 * Return: the pointer to destination
 */
char *f_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * f_strcat - will concatenate strings
 * @dest: destination
 * @src: source
 *
 * Return: pointer to destination buffer
 */
char *f_strcat(char *dest, const char *src)
{
	char *r = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (r);
}

/**
 * f_strdup - this will duplicate a given string
 * @str: required string to be duplicated
 *
 * Return: pointer to the duplicated string
 */
char *f_strdup(const char *str)
{
	int length = 0;
	char *r;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	r = malloc(sizeof(char) * (length + 1));
	if (!r)
		return (NULL);
	for (length++; length--;)
		r[length] = *--str;
	return (r);
}

/**
 *_putchar - this writes characters to stdout
 * @c: requuired character to be printed
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * f_strspn - Gets the length of a prefix substring
 *
 * @s: pointer input
 * @accept: the required substring prefix
 *
 * Return: the number of bytes in the initial segment
 */
unsigned int f_strspn(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
				break;
		}
		if (!accept[j])
			return (i);
	}

	return (i);
}
