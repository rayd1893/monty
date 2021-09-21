#include "monty.h"
/**
 *
 */
char *_strconcat(char *str1, char *str2)
{
	char *str_result;
	int i = 0;

	while (*str1)
	{
		str_result[i] = *str1;
		i++;
		str1++;
	}

	while (*str2)
	{
		str_result[i] = *str2;
		i++;
		str2++;
	}

	str_result[i] = '\0';

	return(str_result);
}
