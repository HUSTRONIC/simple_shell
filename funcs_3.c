#include "shell.h"

/**
 * f_atoi - this will Convert a string to an integer.
 * @str: Required string to be converted.
 *
 * Return: Integer of the string.
 */
int f_atoi(const char *str)
{
	int i, sign;
	unsigned int n;

	i = 0;
	sign = 1;
	n = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		else if (str[i] >= '0' && str[i] <= '9')
			n = (n * 10) + (str[i] - '0');
		else
			break;
		i++;
	}
	return (n * sign);
}

/**
 * f_memset - this is required to fill
 * memory with a constant byte
 * @s: the memory area pointer
 * @b: byte required to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *f_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * f_memcpy - copies memory area
 *
 * @dest: where to copy to
 * @src: what to copy
 * @n: n bytes of @src
 *
 * Return: Always 0 (Success)
*/

char *f_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * f_realloc - this will reallocate a memory
 * @ptr: points to malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the old block.
 */
void *f_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

/**
 * f_calloc - this allocates memory for an array using malloc
 *
 * @nmemb: array size
 * @size: element size
 *
 * Return: pointer with new allocated memory
 *         or NULL if it fails
*/

void *f_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	f_memset(p, 0, nmemb * size);

	return (p);
}
