#include <cstdio>
#include <algorithm>

using namespace std;

bool used[16];
int unit[16];

bool cmp(const int& a, const int &b)
{
	return a > b;
}

int main5()
{
	int N;
	//freopen("input5.txt", "r", stdin);

	scanf("%d", &N);

	int maxx = 0;
	int K, D;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &unit[i]);
		maxx += unit[i];
	}

	scanf("%d", &D);

	K = maxx / D;
	if (K*D != maxx)
	{
		printf("False\n");
		return 0;
	}

	sort(unit, unit + N, cmp);
	for (int i = 0; i < D; i++)
	{
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			if (K < unit[j])
			{
				printf("False\n");
				return 0;
			}
			if (sum + unit[j] <= K && !used[j])
			{
				used[j] = true;
				sum += unit[j];
			}
		}

		if (sum != K)
		{
			printf("False\n");
			return 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if(!used[i])
		{
			printf("False\n");
			return 0;
		}
	}
	
	printf("True\n");
	return 0;
}
