#include "shell.h"
#include <stdio.h>

/**
 * f_strlen - This returns the required length of the string.
 * @s: the string to be checked.
 *
 * Return: The required length of the string.
 */
int f_strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * f_strcmp - This Compares two strings.
 * @s1: First string.
 * @s2: Second string.
 * Return: 0 if @s1 and @s2 are equal.
 * negative value if @s1 is less than @s2.
 * positive value if @s1 is greater than @s2.
 */
int f_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return ((int) (*s1) - (*s2));
}

/**
 * f_strncmp - this compares two required strings.
 * @s1: First string.
 * @s2: the required second string.
 * @n: The maximum number of characters read.
 *
 * Return: 0, else a positive value.
 */
int f_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char c1, c2;

	while (n-- > 0)
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;

		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			break;
	}

	return (0);
}

/**
 * f_strstr - checks for the start of the needle
 * @haystack: Required string that will be searched
 * @needle: the alternative string
 *
 * Return: The address of next char else NULL
 */
char *f_strstr(char *haystack, char *needle)
{
	int i;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			int j;

			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
			}

			if (needle[j] == '\0')
			{
				return (&haystack[i]);
			}
		}
	}
	return (NULL);
}

/**
 * f_strchr - the function that locates the required character.
 *
 * @s: the pointer to the array of string.
 * @c: the character to locate.
 *
 * Return: first charatcer else null
 */

char *f_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	/**
	 * if c is '\0', you should return
	 * the pointer to the '\0' of the
	 * string s
	*/
	if (*s == c)
		return (s);
	/*return null if not found*/
	return (NULL);
}
