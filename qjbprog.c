/* 
 * $Id: qjbprog.c,v 1.5 1993-03-13 13:29:49 qjb Exp $
 * $Source: /tmp/ioccc-1993/ioccc-1993/qjbprog.c,v $
 * $Author: qjb $
 *
 * This program takes a single argument.  If the argument is positive,
 * it solves the tower of hanoi with argv[1] rings.  If the argument
 * is positive, it sovles the case of the "patience puzzle", also
 * known as the Chinese ring puzzle and other names, with -argv[1]
 * rings.
 *
 * Obfuscation ideas:  Implement the whole program as main.
 * modify argv[1]; use argv[2] as extra data.
 * have a = b == c somewhere
 * use macros to manipulate bits
 * use arrays of numeric characters for strings
 */

#if !defined(lint) && !defined(CODECENTER) || defined(RCS_HDRS)
static char *rcsid = "$Id: qjbprog.c,v 1.5 1993-03-13 13:29:49 qjb Exp $";
#endif /* !lint && !CODECENTER || RCS_HDRS */

extern void *malloc(int);

static char *bits;
static int len;

void add(int);
void rem(int);

move_ring(int n, int a, int b)
{
    printf("move ring %d from stack %d to stack %d\n", n, a, b);
}

void move_stack(int n, int a, int b, int c)
{
    if (n == 1)
	move_ring(n, a, b);
    else
    {
	move_stack(n - 1, a, c, b);
	move_ring(n, a, b);
	move_stack(n - 1, c, b, a);
    }
}


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
	move_stack(len, 1, 2, 3);
    }
    else if (len < 0)
    {
	len = -len;
	bits = malloc(len);
	memset(bits, '1', len);
	puts(bits);
	rem(len);
    }
    else
	return 1, printf("invalid\n");

    return 0;
}
