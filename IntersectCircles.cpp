#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Circle
{
	int id;
	float x;
	float y;
	float r;
}Circle;

Circle circles[10001];
vector<pair<int, int> > ret;

int main1()
{
	int N;

	//freopen("input1.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %f %f %f", &circles[i].id, &circles[i].x, &circles[i].y, &circles[i].r);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;

			if ((circles[i].r + circles[j].r) * (circles[i].r + circles[j].r) >
				(circles[i].x - circles[j].x) * (circles[i].x - circles[j].x) + (circles[i].y - circles[j].y) * (circles[i].y - circles[j].y))
			{
				if (circles[i].id < circles[j].id)
					ret.push_back(make_pair(circles[i].id, circles[j].id));
			}
		}
	}

	stable_sort(ret.begin(), ret.end());

	for (int i = 0; i < ret.size(); i++)
		printf("%d %d\n", ret[i].first, ret[i].second);
	return 0;
}
