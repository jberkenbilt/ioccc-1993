char a[] = {0x69, 110, 118, 97, 108, 105, 0x64, 1-1, 0x6d, 111, 118, 101,
1<<1<<1<<1<<1<<1, 114, 105, 0x6e, 103, 32, 'o'/3, 100, 32, 102, 114, 111,
0x6d, 32, 115, 116, 97, 100-001, 107, 32, 37, 2*'2', 32, 116, '%'+'%'+'%',
'w'-'W', 115, 0x74, 97, 3*'!', 107, 'q'-'Q', 37, 10*'\n', 10, 0}; char *b = a
+ (1<<1<<1<<1);

char *w;
signed char x;

int main(int d, char *e[])
{
    char *q = ((char *)(e + 1+1));
    if ((! e[0]) || (! e[1]))
	return puts(a), 1;
    else if (e[1<<1] && d != 1<<1)
	return puts(a), 1;
    else if (!e[1- -1])
    {
	if (atoi(e[1]) < -0200 || atoi(e[1]) > 0x7f || (x = atoi(e[1])) == 0)
	    return puts(a), 1;
	if (x > -x)
	{
	    q[0] = x;
	    q[1] = 1;
	    q[2] = 2;
	    q[3] = 1;
	}
	else if (x < 0)
	{
	    w = (char *)malloc(-x);
	    memset(w, '1', -x);
	    puts(w);
	    q[0] = x;
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
		puts(w, w[- x - 1 - (q[1] & 1 ^ 1)] = q[1]);
		puts(w, w[- x - 1 - (q[1] & 1)] = q[1]);
		break;
	      case -1:
		puts(w, w[- x - 1] = q[1]);
		break;
	      default:
		q[0] += 1 + (q[1] & 1 ^ 1);
		main(d, e);
		q[0] -= 1 + (q[1] & 1 ^ 1);
		if (q[1] & 1) {
		    q[0]+=1+1;
		    q[1]^=1;
		    main(d, e);
		    q[1]^=1;
		    q[0]-=1+1;
		}
		puts(w, w[q[0] - x] = q[1]);
		if (!(q[1] & 1)) {
		    q[0]+=1+1;
		    q[1]^=1;
		    main(d, e);
		    q[1]^=1;
		    q[0]-=1+1;
		}
		q[0] += 1 + (q[1] & 1);
		main(d, e);
		q[0] -= 1 + (q[1] & 1);
	    }
	}
    }
    return 0;
}
