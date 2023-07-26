#include "vheadersh.h"
/**
 *_puutts - print inpuring
 *@strstr: thestro bnted
 * Return: Nohing
 */
void _puutts(char *strstr)
{
	int i = 0;

	if (!strstr)
		return;
	while (strstr[i] != '\0')
	{
		_putchar(strstr[i]);
		i++;
	}
}
/**
 * _putchar - writeharactetdout
 * @g: The charactrint
 * Return: On success 1.
 * On error, -1 is returpproely.
 */
int _putchar(char g)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (g == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (g != BUF_FLUSH)
		buf[i++] = g;
	return (1);
}
