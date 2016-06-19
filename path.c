#include <stdio.h>

int path(int n, int m)
{
	static int cache[20][20];
	if (n == 1 || m == 1)
		return 1;
	if (cache[n][m] != 0)
		return cache[n][m];
	else
		return cache[n][m] = path(n - 1, m) + path(n, m - 1);
}

int main(void)
{
	int n, m;
	int target;
	int result;

	scanf("%d %d", &n, &m);
	scanf("%d", &target);

	if (target != 0)
	{
		int y, x;

		if (target % m == 0)
		{
			y = target / m;
			x = m;
		}
		else
		{
			y = target / m + 1;
			x = target % m;
		}

		result = path(y, x);
		result *= path(n - y + 1, m - x + 1);
	}
	else
		result = path(n, m);

	printf("%d \n", result);
	return 0;
}
