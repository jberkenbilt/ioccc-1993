char *a = "invalid";
char *b = "move ring %d from stack %d to stack %d\n";

char *bits;
signed char len;

int main(int d, char *e[])
{
    char *q = ((char *)(e + 2));
    if ((! e[0]) || (! e[1]))
	return puts(a), 1;
    else if (e[2] && (d != 2))
	return puts(a), 1;
    else if (!e[2])
    {
	if ((atoi(e[1]) < -128) || (atoi(e[1]) > 127) ||
	    ((len = atoi(e[1])) == 0))
	    return puts(a), 1;
	if (len > -len)
	{
	    q[0] = len;
	    q[1] = 1;
	    q[2] = 2;
	    q[3] = 1;
	}
	else if (len < 0)
	{
	    bits = (char *)malloc(-len);
	    memset(bits, '1', -len);
	    puts(bits);
	    q[0] = len;
	    q[1] = '0';
	    q[2] = 0;
	    q[3] = 0;
	}
	return main(d, e);
    }
    else
    {
	if (q[3])
	{
	    char c, t;
	    c = (q[1] + q[2] == 3) ? 3 : (q[1] + q[2] == 4) ? 2 : 1;
	    if (q[0] != 1) {
		(q[0])--;
		t = q[2];
		q[2] = c;
		main(d, e);
		c = q[2];
		q[2] = t;
		(q[0])++;
	    }
	    printf(b, q[0], q[1], q[2]);
	    if (q[0] != 1) {
		(q[0])--;
		t = q[1];
		q[1] = c;
		main(d, e);
		c = q[1];
		q[1] = t;
		(q[0])++;
	    }
	}
	else
	{
	    switch (- 1 + (-(q[0])) - 1)
	    {
	      case 0:
		puts(bits, bits[- len - (1 + ((q[1] & 1) ^ 1))] = q[1]);
		puts(bits, bits[- len - (1 + (q[1] & 1))] = q[1]);
		break;
	      case -1:
		puts(bits, bits[- len - 1] = q[1]);
		break;
	      default:
		q[0] += 1 + ((q[1] & 1) ^ 1);
		main(d, e);
		q[0] -= 1 + ((q[1] & 1) ^ 1);
		if (q[1] & 1) {
		    (q[0])+=2;
		    (q[1]) ^= 1;
		    main(d, e);
		    (q[1]) ^= 1;
		    (q[0])-=2;
		}
		puts(bits, bits[q[0] - len] = q[1]);
		if (!(q[1] & 1)) {
		    (q[0])+=2;
		    (q[1]) ^= 1;
		    main(d, e);
		    (q[1]) ^= 1;
		    (q[0])-=2;
		}
		q[0] += 1 + (q[1] & 1);
		main(d, e);
		q[0] -= 1 + (q[1] & 1);
	    }
	}
    }
    return 0;
}
