#include <cstdio>

int primes[10001];

int main3()
{
	int N;

	//freopen("input2.txt", "r", stdin);
	scanf("%d", &N);
	
	int cnt = 0;
	for (int j = N; j >= 2; j--)
	{
		int n = j;
		for (int i = 2; i*i <= j; i++)
		{
			while (n%i == 0)
			{
				primes[i]++;
				n /= i;
			}
		}

		if (n > 1)
		{
			primes[n]++;
		}
	}
	
	for (int i = 2; i <= N; i++)
	{
		if (primes[i] != 0)
			cnt++;
	}

	for (int i = 2; i <= N; i++)
	{
		if (primes[i] > 0)
		{
			printf("%d^%d", i, primes[i]);
			cnt--;
			if (cnt > 0)
				printf("*");
		}
	}
	printf("\n");
	return 0;
}
