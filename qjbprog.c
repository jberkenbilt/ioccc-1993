extern void *malloc(int);

char *m0 = "Usage: %s [+|-]n\n\tn != 0, -128 < n < 127\n";
char *m1 = "move ring %d from stack %d to stack %d\n";

char *bits;
signed char len;

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
    {
	if (args[3])
	{
	    char c, t;
	    c = (args[1] + args[2] == 3) ? 3 : (args[1] + args[2] == 4) ? 2 : 1;
	    if (args[0] != 1) {
		(args[0])--; t = args[2]; args[2] = c; main(argc, argv); c = args[2]; args[2] = t; (args[0])++;
	    }
	    printf(m1, args[0], args[1], args[2]);
	    if (args[0] != 1) {
		(args[0])--; t = args[1]; args[1] = c; main(argc, argv); c = args[1]; args[1] = t; (args[0])++;
	    }
	}
	else
	{
	    switch (- 1 + (-(args[0])) - 1)
	    {
	      case 0:
		puts(bits, bits[- len - (1 + ((args[1] & 1) ^ 1))] = args[1]);
		puts(bits, bits[- len - (1 + (args[1] & 1))] = args[1]);
		break;
	      case -1:
		puts(bits, bits[- len - 1] = args[1]);
		break;
	      default:
		args[0] += 1 + ((args[1] & 1) ^ 1);
		main(argc, argv);
		args[0] -= 1 + ((args[1] & 1) ^ 1);
		if (args[1] & 1) {
		    (args[0])+=2; (args[1]) ^= 1; main(argc, argv); (args[1]) ^= 1; (args[0])-=2;
		}
		puts(bits, bits[args[0] - len] = args[1]);
		if (!(args[1] & 1)) {
		    (args[0])+=2; (args[1]) ^= 1; main(argc, argv); (args[1]) ^= 1; (args[0])-=2;
		}
		args[0] += 1 + (args[1] & 1);
		main(argc, argv);
		args[0] -= 1 + (args[1] & 1);
	    }
	}
    }
    return 0;
}
