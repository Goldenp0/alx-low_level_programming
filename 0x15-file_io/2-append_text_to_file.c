#include  "main.h"

/**
  * append_text_to_file - Appends the text at the end of a file function
  * @filename: A pointer to the name of the file appended
  * @text_content: The string is to add to the end of the file
  *
  * Return: if the function fails or if the filename is NULL - -1
  *     If the file doesn't exist then the user lacks written permission - -1
  *     Otherwise - 1
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, x, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	x = write(o, text_content, len);

	if (o == -1 || x == -1)
		return (-1);

	close(o);

	return (1);
}
