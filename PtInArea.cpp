#include <cstdio>
#include <iostream>

using namespace std;

pair<float, float> outer[1002];
pair<float, float> inner[1002];

float crossProduct(pair<float, float> a, pair<float, float> b, pair<float, float> c)
{
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

int main2()
{
	pair<float, float> X;

	//freopen("input3.txt", "r", stdin);
	scanf("%f %f", &X.first, &X.second);

	int N, M;
	bool outerR = false; // 반시계
	bool innerR = true; // 시계

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%f %f", &outer[i].first, &outer[i].second);
	}
	outer[N].first = outer[0].first;
	outer[N].second = outer[0].second;

	if (crossProduct(outer[0], outer[1], outer[2]) < 0) // 시계방향
	{
		outerR = true;
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%f %f", &inner[i].first, &inner[i].second);
	}
	inner[M].first = inner[0].first;
	inner[M].second = inner[0].second;
	
	if (crossProduct(inner[0], inner[1], inner[2]) > 0) // 반시계방향
	{
		outerR = false;
	}

	for (int i = 0; i < N; i++)
	{
		float cross = crossProduct(outer[i], outer[i + 1], X);
		if ((!outerR && cross < 0) || (outerR && cross > 0))
		{
			printf("False\n");
			return 0;
		}
	}

	for (int i = 0; i < M; i++)
	{
		float cross = crossProduct(inner[i], inner[i + 1], X);
		if ((inner && cross > 0) || (!inner && cross < 0))
		{
			printf("True\n");
			return 0;
		}
	}

	printf("False\n");
	return 0;
}
