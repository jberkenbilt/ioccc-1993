/* 
 * $Id: qjbprog.c,v 1.1 1993-03-08 03:56:27 qjb Exp $
 * $Source: /tmp/ioccc-1993/ioccc-1993/qjbprog.c,v $
 * $Author: qjb $
 *
 * This program sovles the "patience puzzle" also known as the Chinese
 * ring puzzle and other names.
 */

#if !defined(lint) && !defined(CODECENTER) || defined(RCS_HDRS)
static char *rcsid = "$Id: qjbprog.c,v 1.1 1993-03-08 03:56:27 qjb Exp $";
#endif /* !lint && !CODECENTER || RCS_HDRS */

#ifdef abs
#undef abs
#endif

#define abs(x) (((x) < 0) ? (-(x)) : (x))

void add(int);
void rem(int);

void p_add(int n)
{
    printf("+%d  ", n);
}

void p_rem(int n)
{
    printf("-%d  ", n);
}

void add(int n)
{
    if (n > 2)
    {
	add(n - 1);
	rem(n - 2);
	p_add(n);
	add(n - 2);
    }
    else if (n == 2)
    {
	p_add(2);
	p_add(1);
    }
    else if (n == 1)
    {
	p_add(1);
    }
    else
	printf("invalid\n");
}

void rem(int n)
{
    if (n > 2)
    {
	rem(n - 2);
	p_rem(n);
	add(n - 2);
	rem(n - 1);
    }
    else if (n == 2)
    {
	p_rem(2);
	p_rem(1);
    }
    else if (n == 1)
    {
	p_rem(1);
    }
    else
	printf("invalid\n");
}


int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    if (n > 0)
	rem(n);
    else
	printf("invalid");
    printf("\n");

    return 0;
}
