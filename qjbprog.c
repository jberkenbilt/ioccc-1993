extern void *malloc(int);

char *m = "invalid";

char *bits;
int len;

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

void addrem(int n, char c)
{
    switch (- 1 + n - 1)
    {
      case 0:
	puts(bits, bits[len - (1 + ((c & 1) ^ 1))] = c);
	puts(bits, bits[len - (1 + (c & 1))] = c);
	break;
      case -1:
	puts(bits, bits[len - 1] = c);
	break;
      default:
	addrem(n - 1 - ((c & 1) ^ 1), c);
	(c & 1) ? addrem(n - 1 - 1, c ^ 1):0;
	puts(bits, bits[len - n] = c);
	(c & 1) ?0: addrem(n - 1 - 1, c ^ 1);
	addrem(n - 1 - (c & 1), c);
    }
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
	addrem(len, '0');
    }
    else
	return 1, printf("invalid\n");

    return 0;
}
