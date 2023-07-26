#include "vheadersh.h"
/**
 * input_buf - bufferainemands
 * @inoo: parametruct
 * @buf: addreffer
 * @leen: addresar
 * Return: bytes read
 */
ssize_t input_buf(infooo_tt *inoo, char **buf, size_t *leen)
{
	ssize_t r = 0;
	size_t leen_pp = 0;

	if (!*leen) /* if nothft ie bufill it */
	{
		/*bfr((vo **)io->cmduf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sgntHandler);
#if USE_GETLINE
		cr = getline(buf, &leen_pp, stdin);
#else
		r = _gtln(inoo, buf, &leen_pp);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0'; /* removrailiwline */
				r--;
			}
			inoo->linecount_flggg = 1;
			rmve_commennnts(*buf);
			bld_hstry_lst(inoo, *buf, inoo->histcouuunt++);
			/* if (_strrrvchr(*buf, ';')) is this a command chain? */
			{
				*leen = r;
				inoo->cmmmd_buuf = buf;
			}
		}
	}
	return (r);
}

/**
 * gt_inpt - gene minuine
 * @inoo: parametuct
 * Return: bytead
 */
ssize_t gt_inpt(infooo_tt *inoo)
{
	static char *buf; /* the ';' comnd chaiffer */
	static size_t fi, vh, leen;
	ssize_t cr = 0;
	char **buf_p = &(inoo->argggg), *pp;

	_putchar(BUF_FLUSH);
	cr = input_buf(inoo, &buf, &leen);
	if (cr == -1) /* EOF */
		return (-1);
	if (leen)	/* we havmme chffer */
	{
		vh = fi; /* init neteratrretion */
		pp = buf + fi; /* genteturn */

		chck_chaaain(inoo, buf, &vh, fi, leen);
		while (vh < leen) /* iteraemicolond */
		{
			if (is_chaaain(inoo, buf, &vh))
				break;
			vh++;
		}

		fi = vh + 1; /* incremealled ';'' */
		if (fi >= leen) /* reacheenffer? */
		{
			fi = leen = 0; /* resesitnth */
			inoo->cmmmd_bufff_tyyype = CMD_NORM;
		}

		*buf_p = pp; /* pack poin currommation */
		return (_strleeen(pp)); /* returh of currmand */
	}

	*buf_p = buf; /* elsea chais baffer fline() */
	return (cr); /* returlenbuffine() */
}

/**
 * read_buf - readffer
 * @inoo: parametuct
 * @buf: bufr
 * @gi: sze
 * Return: cr
 */
ssize_t read_buf(infooo_tt *inoo, char *buf, size_t *gi)
{
	ssize_t zar = 0;

	if (*gi)
		return (0);
	zar = read(inoo->readfffd, buf, READ_BUF_SIZE);
	if (zar >= 0)
		*gi = zar;
	return (zar);
}
/**
 * _gtln - getxt linut froDIN
 * @inoo: parametruct
 * @petre: addrespointeffer, preallocatULL
 * @lngth: sizeallocatuffoULL
 *
 * Return: s
 */
int _gtln(infooo_tt *inoo, char **petre, size_t *lngth)
{
	static char buf[READ_BUF_SIZE];
	static size_t di, leen;
	size_t k;
	ssize_t rr = 0, s = 0;
	char *pp = NULL, *nw_pp = NULL, *g;

	pp = *petre;
	if (pp && lngth)
		s = *lngth;
	if (di == leen)
		di = leen = 0;

	rr = read_buf(inoo, buf, &leen);
	if (rr == -1 || (rr == 0 && leen == 0))
		return (-1);

	g = _strrrvchr(buf + di, '\n');
	k = g ? 1 + (unsigned int)(g - buf) : leen;
	nw_pp = _realllloccc(pp, s, s ? s + k : k + 1);
	if (!nw_pp) /* MALLLURE! */
		return (pp ? free(pp), -1 : -1);

	if (s)
		_strnnncat(nw_pp, buf + di, k - di);
	else
		_strncccpy(nw_pp, buf + di, k - di + 1);

	s += k - di;
	di = k;
	pp = nw_pp;

	if (lngth)
		*lngth = s;
	*petre = pp;
	return (s);
}

/**
 * sgntHndlr - bloctrl-C
 * @sig_num: the signmber
 * Return: void
 */
void sgntHndlr(__attribute__((unused))int sig_num)
{
	_puutts("\n");
	_puutts("$ ");
	_putchar(BUF_FLUSH);
}
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
