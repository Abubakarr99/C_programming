#include <stdio.h>
#include "sum.h"
#define PI 3.142



int main(int argc, char* argv[])
{
	int ret;
	float c;
	float a,b;
	a=PI;
	ret = sscanf(argv[1], "%f", &b);
	if (ret == 1)
	{
		c=sum(a, b);
		printf("%f + %f = %f\n", a, b, c);
	}

	return 0;
}
