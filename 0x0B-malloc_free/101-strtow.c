#include <stdio.h>
#include <stdlib.h>

int str_len(char *str);
int word_count(char *str);
char *_strncpy(char *dest, char *src, int n);

/**
 * strtow - Entry point
 *
 *  * @str: string
 *
 * Description: Function that splits a string into words.
 *
 * Prototype: char **strtow(char *str);
 *
 * The function returns a pointer to an array of strings (words)
 *
 * Each element of this array should contain a single word,
 * null-terminated
 *
 * Each argument should be followed by a \n in the new string
 *
 * Words are separated by spaces
 *
 * Returns NULL if str == NULL or str == ""
 *
 * If your function fails, it should return NULL
 *
 * Return: A pointer to an array of strings (words)
 *
 */

char **strtow(char *str)
{
	int i;
	int wordStart = 0;
	int wordIndex = 0;

	int strLen = str_len(str);
	int wordsCount = word_count(str);
	char **strArray;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	strArray = malloc((wordsCount + 1) * sizeof(char *));

	if (strArray == NULL)
		return (NULL);


	for (i = 0; i <= strLen; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (wordStart < i)
			{
				int wordLen = i - wordStart;

				strArray[wordIndex] = malloc((wordLen + 1) * sizeof(char));

				if (strArray[wordIndex] == NULL)
				{
					int j;

					for (j = 0; j < wordLen; j++)
					{
						free(strArray[j]);
					}

					free(strArray);
					return (NULL);
				}

				_strncpy(strArray[wordIndex], str + wordStart, wordLen);
				strArray[wordIndex][wordLen] = '\0';
				wordIndex++;
			}

			wordStart = i + 1;
		}
	}

	strArray[wordIndex] = NULL;

	return (strArray);
}

/**
 * str_len - Entry point
 *
 *  * @str: pointer to the string
 *
 * Description: Helper Function that calculate the length of a string
 *
 * Return: The length of a string
 *
 *
 */

int str_len(char *str)
{
	if (!*str)
		return (0);

	return (1 + str_len(str + 1));
}


/**
 * word_count - Entry point
 *
 *  * @str: pointer to the string
 *
 * Description: Helper Function that calculate the number of words
 * in a string
 *
 * Return: The number of words
 *
 *
 */

int word_count(char *str)
{
	int wordCount = 0, i, inWord = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && !inWord)
		{
			inWord = 1;
			wordCount++;

		}
		else
			inWord = 0;

	}

	return (wordCount);
}


/**
 * _strncpy - Entry point
 *
 *  * @dest: pointer to the to the destination array where
 *  *         the content is to be copied.
 *  * @src: pointer to  the string to be copied.
 *  * @n:  represents The number of characters to be copied from source.
 *
 * Description: Function that copies up to n characters from
 * the string pointed to, by src to dest. In a case where
 * the length of src is less than that of n, the remainder
 * of dest will be padded with null bytes.
 *
 * Prototype: char *_strncpy(char *dest, char *src, int n);
 *
 *
 *
 * Return: the pointer to the copied string.
 *
 *
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
