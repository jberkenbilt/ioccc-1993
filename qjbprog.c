extern void *malloc(int);

char *v0 = "Usage: %s [+|-]n\n\tn != 0, -128 < n < 127\n";
char *v1 = "move ring %d from stack %d to stack %d\n";

char *bits;
signed char len;

int main(int v2, char *v3[])
{
    char *v4 = (char *)(v3 + 2);
    
    if ((! v3[0]) || (! v3[1]))
	return printf(v0, v3[0]), 1;
    else if (v3[2] && (v2 != 2))
	return printf(v0, v3[0]), 1;
    else if (!v3[2])
    {
	if ((atoi(v3[1]) < -128) || (atoi(v3[1]) > 127) ||
	    ((len = atoi(v3[1])) == 0))
	    return printf(v0, v3[0]), 1;
	if (len > -len)
	{
	    v4[0] = len;
	    v4[1] = 1;
	    v4[2] = 2;
	    v4[3] = 1;
	}
	else if (len < 0)
	{
	    bits = malloc(-len);
	    memset(bits, '1', -len);
	    puts(bits);
	    v4[0] = len;
	    v4[1] = '0';
	    v4[2] = 0;
	    v4[3] = 0;
	}
	return main(v2, v3);
    }
    else
    {
	if (v4[3])
	{
	    char c, t;
	    c = (v4[1] + v4[2] == 3) ? 3 : (v4[1] + v4[2] == 4) ? 2 : 1;
	    if (v4[0] != 1) {
		(v4[0])--; t = v4[2]; v4[2] = c; main(v2, v3); c = v4[2]; v4[2] = t; (v4[0])++;
	    }
	    printf(v1, v4[0], v4[1], v4[2]);
	    if (v4[0] != 1) {
		(v4[0])--; t = v4[1]; v4[1] = c; main(v2, v3); c = v4[1]; v4[1] = t; (v4[0])++;
	    }
	}
	else
	{
	    switch (- 1 + (-(v4[0])) - 1)
	    {
	      case 0:
		puts(bits, bits[- len - (1 + ((v4[1] & 1) ^ 1))] = v4[1]);
		puts(bits, bits[- len - (1 + (v4[1] & 1))] = v4[1]);
		break;
	      case -1:
		puts(bits, bits[- len - 1] = v4[1]);
		break;
	      default:
		v4[0] += 1 + ((v4[1] & 1) ^ 1);
		main(v2, v3);
		v4[0] -= 1 + ((v4[1] & 1) ^ 1);
		if (v4[1] & 1) {
		    (v4[0])+=2; (v4[1]) ^= 1; main(v2, v3); (v4[1]) ^= 1; (v4[0])-=2;
		}
		puts(bits, bits[v4[0] - len] = v4[1]);
		if (!(v4[1] & 1)) {
		    (v4[0])+=2; (v4[1]) ^= 1; main(v2, v3); (v4[1]) ^= 1; (v4[0])-=2;
		}
		v4[0] += 1 + (v4[1] & 1);
		main(v2, v3);
		v4[0] -= 1 + (v4[1] & 1);
	    }
	}
    }
    return 0;
}
