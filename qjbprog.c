extern void *malloc(int);

char *a = "Usage: %s [+|-]n\n\tn != 0, -128 < n < 127\n";
char *b = "move ring %d from stack %d to stack %d\n";

char *bits;
signed char len;

int main(int d, char *e[])
{
    if ((! e[0]) || (! e[1]))
	return printf(a, e[0]), 1;
    else if (e[2] && (d != 2))
	return printf(a, e[0]), 1;
    else if (!e[2])
    {
	if ((atoi(e[1]) < -128) || (atoi(e[1]) > 127) ||
	    ((len = atoi(e[1])) == 0))
	    return printf(a, e[0]), 1;
	if (len > -len)
	{
	    *(((char *)(e + 2))) = len;
	    *(((char *)(e + 2))+1) = 1;
	    *(((char *)(e + 2))+2) = 2;
	    *(((char *)(e + 2))+3) = 1;
	}
	else if (len < 0)
	{
	    bits = malloc(-len);
	    memset(bits, '1', -len);
	    puts(bits);
	    *(((char *)(e + 2))) = len;
	    *(((char *)(e + 2))+1) = '0';
	    *(((char *)(e + 2))+2) = 0;
	    *(((char *)(e + 2))+3) = 0;
	}
	return main(d, e);
    }
    else
    {
	if (*(((char *)(e + 2))+3))
	{
	    char c, t;
	    c = (*(((char *)(e + 2))+1) + *(((char *)(e + 2))+2) == 3) ? 3 : (*(((char *)(e + 2))+1) + *(((char *)(e + 2))+2) == 4) ? 2 : 1;
	    if (*(((char *)(e + 2))) != 1) {
		(*(((char *)(e + 2))))--;
		t = *(((char *)(e + 2))+2);
		*(((char *)(e + 2))+2) = c;
		main(d, e);
		c = *(((char *)(e + 2))+2);
		*(((char *)(e + 2))+2) = t;
		(*(((char *)(e + 2))))++;
	    }
	    printf(b, *(((char *)(e + 2))), *(((char *)(e + 2))+1), *(((char *)(e + 2))+2));
	    if (*(((char *)(e + 2))) != 1) {
		(*(((char *)(e + 2))))--;
		t = *(((char *)(e + 2))+1);
		*(((char *)(e + 2))+1) = c;
		main(d, e);
		c = *(((char *)(e + 2))+1);
		*(((char *)(e + 2))+1) = t;
		(*(((char *)(e + 2))))++;
	    }
	}
	else
	{
	    switch (- 1 + (-(*(((char *)(e + 2))))) - 1)
	    {
	      case 0:
		puts(bits, bits[- len - (1 + ((*(((char *)(e + 2))+1) & 1) ^ 1))] = *(((char *)(e + 2))+1));
		puts(bits, bits[- len - (1 + (*(((char *)(e + 2))+1) & 1))] = *(((char *)(e + 2))+1));
		break;
	      case -1:
		puts(bits, bits[- len - 1] = *(((char *)(e + 2))+1));
		break;
	      default:
		*(((char *)(e + 2))) += 1 + ((*(((char *)(e + 2))+1) & 1) ^ 1);
		main(d, e);
		*(((char *)(e + 2))) -= 1 + ((*(((char *)(e + 2))+1) & 1) ^ 1);
		if (*(((char *)(e + 2))+1) & 1) {
		    (*(((char *)(e + 2))))+=2;
		    (*(((char *)(e + 2))+1)) ^= 1;
		    main(d, e);
		    (*(((char *)(e + 2))+1)) ^= 1;
		    (*(((char *)(e + 2))))-=2;
		}
		puts(bits, bits[*(((char *)(e + 2))) - len] = *(((char *)(e + 2))+1));
		if (!(*(((char *)(e + 2))+1) & 1)) {
		    (*(((char *)(e + 2))))+=2;
		    (*(((char *)(e + 2))+1)) ^= 1;
		    main(d, e);
		    (*(((char *)(e + 2))+1)) ^= 1;
		    (*(((char *)(e + 2))))-=2;
		}
		*(((char *)(e + 2))) += 1 + (*(((char *)(e + 2))+1) & 1);
		main(d, e);
		*(((char *)(e + 2))) -= 1 + (*(((char *)(e + 2))+1) & 1);
	    }
	}
    }
    return 0;
}
