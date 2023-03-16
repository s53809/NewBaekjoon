#include <stdio.h>
#include <math.h>

int main()
{
	int i = 0, j, b = 0, c = 0, q, l, num, fin = 0;
	int a[100] = {};
	int k[100] = {};
	int r[100] = {};
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%d %d %d", &r[i], &k[i], &a[i]);
	}

	for (i = 0; i < num; i++)
	{

		b = a[i] % r[i];
		if (b == 0)
		{
			b = r[i];
		}

		c = a[i] / r[i];
		if (a[i] % r[i] != 0) {
			c += 1;
		}

		printf("%d\n", b * 100 + c);
	}


	return 0;
}
