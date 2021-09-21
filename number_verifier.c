#include "monty.h"
/**
 * get_op_cases - Function converts numbers to char.
 * Return: Void.
 * @format: Sting being searched for %
 * @i: holds the place in which % was found in the string
 **/
int number_verifier(char *string)
{
	if (*string == '\0')
	{
		return(1);
	}
	if ((*string >= '1' && *string <= '9') || *string == '-')
	{
		return(number_verifier(string + 1));
	}
	return(0);
}
