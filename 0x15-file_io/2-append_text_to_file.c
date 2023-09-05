#include "main.h"

/**
 * append_text_to_file - Appends text by the file end
 * @text_content: Str to add at the end file
 * @filename: Pointer to the name file
 *
 * Return: if the func fails or filename NULL --1
 *     If the file does not exist the user lacks write permission --1
 *     Otherwise -1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int r, m, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	r = open(filename, O_WRONLY | O_APPEND);
	m = write(r, text_content, len);

	if (r == -1 || m == -1)
		return (-1);

	close(0);

	return (1);
}
