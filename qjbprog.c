/* 
 * $Id: qjbprog.c,v 1.3 1993-03-08 04:29:27 qjb Exp $
 * $Source: /tmp/ioccc-1993/ioccc-1993/qjbprog.c,v $
 * $Author: qjb $
 *
 * This program sovles the "patience puzzle" also known as the Chinese
 * ring puzzle and other names.
 *
 * Obfuscation ideas:  Implement the whole program as main.
 * modify argv[1]; use argv[2] as sign bit.
 * have a = b == c somewhere
 * use macros to manipulate bits
 */

#if !defined(lint) && !defined(CODECENTER) || defined(RCS_HDRS)
static char *rcsid = "$Id: qjbprog.c,v 1.3 1993-03-08 04:29:27 qjb Exp $";
#endif /* !lint && !CODECENTER || RCS_HDRS */

static char *bits;
static int len;

void add(int);
void rem(int);

void p_add(int n)
{
    bits[len - n] = '1';
    puts(bits);
}

void p_rem(int n)
{
    bits[len - n] = '0';
    puts(bits);
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
	p_add(1);
	p_add(2);
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
    len = atoi(argv[1]);
    if (len > 0)
    {
	bits = malloc(len);
	memset(bits, '1', len);
	puts(bits);
	rem(len);
    }
    else
    {
	printf("invalid\n");
    }

    return 0;
}
