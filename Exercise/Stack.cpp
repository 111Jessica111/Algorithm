#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

char a[1005];
int sum, k;

stack <int> stk;

int main_38()
{
	int i = 0;
	do {
		cin >> a[i];
	} while (a[i++] != '@');

	for (int i = 0; a[i] != '@'; i++)
	{
		if (a[i] == '.')
		{
			sum = 0, k = 1;
			for (int j = i - 1; j >= 0 && a[j] >= '0' && a[j] <= '9'; j--) sum = sum + (a[j] - 48) * k, k *= 10;//转化为数字存入栈
			stk.push(sum);
			continue;
		}
		if (a[i] >= '0' && a[i] <= '9') continue;
		sum = stk.top();
		stk.pop();
		if (a[i] == '+') sum = stk.top() + sum;
		if (a[i] == '-') sum = stk.top() - sum;
		if (a[i] == '*') sum = stk.top() * sum;
		if (a[i] == '/') sum = stk.top() / sum;
		stk.pop();
		stk.push(sum);
	}
	printf("%d", stk.top());
	return 0;
}
