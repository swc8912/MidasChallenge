#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main4()
{
	stack<char> s;
	string input;
	//freopen("input4.txt", "r", stdin);
	cin >> input;

	if (input.size() % 2 != 0)
	{
		printf("False\n");
		return 0;
	}

	for (int i = 0; i < input.size(); i++)
	{
		if (s.size() == 0)
			s.push(input[i]);
		else if (s.top() == input[i])
		{
			s.pop();
		}
		else if (s.top() != input[i])
		{
			s.push(input[i]);
		}
	}

	if (s.size() > 0)
		printf("False\n");
	else
		printf("True\n");
	return 0;
}
