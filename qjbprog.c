extern void *malloc(int);

char *m = "invalid";

char *bits;
int len;

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


void p_addrem(int n, char c)
{
    puts(bits, bits[len - n] = c);
}

void add(int n)
{
    if (n > 2)
    {
	add(n - 1);
	rem(n - 2);
	p_addrem(n, '1');
	add(n - 2);
    }
    else if (n == 2)
    {
	p_addrem(1, '1');
	p_addrem(2, '1');
    }
    else if (n == 1)
    {
	p_addrem(1, '1');
    }
    else
	puts(m);
}

void rem(int n)
{
    if (n > 2)
    {
	rem(n - 2);
	p_addrem(n, '0');
	add(n - 2);
	rem(n - 1);
    }
    else if (n == 2)
    {
	p_addrem(2, '0');
	p_addrem(1, '0');
    }
    else if (n == 1)
    {
	p_addrem(1, '0');
    }
    else
	puts(m);
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
