extern void *malloc(int);

char *m0 = "Usage: %s [+|-]n\n\tn != 0, -128 < n < 127\n";
char *m1 = "move ring %d from stack %d to stack %d\n";

char *bits;
signed char len;

void move(char *args)
{
    char *n, *a, *b, *f;
    n = args;
    a = args + 1;
    b = args + 2;
    f = args + 3;

    if (*f)
    {
	char c, t;
	c = (*a + *b == 3) ? 3 : (*a + *b == 4) ? 2 : 1;
	if (*n != 1) {
	    (*n)--; t = *b; *b = c; move(args); c = *b; *b = t; (*n)++;
	}
	printf(m1, *n, *a, *b);
	if (*n != 1) {
	    (*n)--; t = *a; *a = c; move(args); c = *a; *a = t; (*n)++;
	}
    }
    else
    {
	switch (- 1 + (-(*n)) - 1)
	{
	  case 0:
	    puts(bits, bits[- len - (1 + ((*a & 1) ^ 1))] = *a);
	    puts(bits, bits[- len - (1 + (*a & 1))] = *a);
	    break;
	  case -1:
	    puts(bits, bits[- len - 1] = *a);
	    break;
	  default:
	    *n += 1 + ((*a & 1) ^ 1);
	    move(args);
	    *n -= 1 + ((*a & 1) ^ 1);
	    if (*a & 1) {
		(*n)++; (*n)++; (*a) ^= 1; move(args); (*a) ^= 1; (*n)--; (*n)--;
	    }
	    puts(bits, bits[*n - len] = *a);
	    if (!(*a & 1)) {
		(*n)++; (*n)++; (*a) ^= 1; move(args); (*a) ^= 1; (*n)--; (*n)--;
	    }
	    *n += 1 + (*a & 1);
	    move(args);
	    *n -= 1 + (*a & 1);
	}
    }
}


int main(int argc, char *argv[])
{
    char *args = (char *)(argv + 2);

    if ((! argv[0]) || (! argv[1]))
	return printf(m0, argv[0]), 1;
    else if (argv[2] && (argc != 2))
	return printf(m0, argv[0]), 1;
    else if (!argv[2])
    {
	if ((atoi(argv[1]) < -128) || (atoi(argv[1]) > 127) ||
	    ((len = atoi(argv[1])) == 0))
	    return printf(m0, argv[0]), 1;
	if (len > -len)
	{
	    args[0] = len;
	    args[1] = 1;
	    args[2] = 2;
	    args[3] = 1;
	}
	else if (len < 0)
	{
	    bits = malloc(-len);
	    memset(bits, '1', -len);
	    puts(bits);
	    args[0] = len;
	    args[1] = '0';
	    args[2] = 0;
	    args[3] = 0;
	}
	return main(argc, argv);
    }
    else
	move(args);

    return 0;
}
