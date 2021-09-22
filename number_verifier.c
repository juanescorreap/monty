#include "monty.h"
/**
 * number_verifier - Function that cheks if the content of
 * a string is a number.
 * Return: 0 if it's a number or 1 if not.
 * @string: Pointer to the string to be checked
 **/
int number_verifier(char *string)
{
	if (string == NULL)
	{
		return (0);
	}
	if (*string == '\0')
	{
		return (1);
	}
	if ((*string >= '0' && *string <= '9') || *string == '-')
	{
		return (number_verifier(string + 1));
	}
	return (0);
}
