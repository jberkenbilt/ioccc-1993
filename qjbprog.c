extern void *malloc(int);

char *m0 = "Usage: %s [+|-]n\n\tn != 0, -128 < n < 127\n";
char *m1 = "move ring %d from stack %d to stack %d\n";

char *bits;
signed char len;

void move(char n, char a, char b, char f)
{
    if (f)
    {
	char c;
	c = (a + b == 3) ? 3 : (a + b == 4) ? 2 : 1;
	(n == 1) ?0: move(n - 1, a, c, 1);
	printf(m1, n, a, b);
	(n == 1) ?0: move(n - 1, c, b, 1);
    }
    else
    {
	switch (- 1 + (-n) - 1)
	{
	  case 0:
	    puts(bits, bits[- len - (1 + ((a & 1) ^ 1))] = a);
	    puts(bits, bits[- len - (1 + (a & 1))] = a);
	    break;
	  case -1:
	    puts(bits, bits[- len - 1] = a);
	    break;
	  default:
	    move(n + 1 + ((a & 1) ^ 1), a, 0, 0);
	    (a & 1) ? move(n + 1 + 1, a ^ 1, 0, 0):0;
	    puts(bits, bits[n - len] = a);
	    (a & 1) ?0: move(n + 1 + 1, a ^ 1, 0, 0);
	    move(n + 1 + (a & 1), a, 0, 0);
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
	move(args[0], args[1], args[2], args[3]);

    return 0;
}
