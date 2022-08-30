// 1935번 후위 표기식2

#include <iostream>
#include<math.h>
using namespace std;

int main()
{
	int N;
	string postfix;
	cin >> N >>  postfix;
	
	double* oprendTable = new double[N];
	for (int i = 0; i < N; i++) cin >> oprendTable[i];

	double* stack = new double[(int)postfix.size()]{0};
	int topIdx = -1;
	for (int i = 0; i < (int)postfix.size(); i++)
	{
		if (postfix[i] >= 'A' && postfix[i] <= 'Z')
		{
			stack[++topIdx] = oprendTable[postfix[i] - 'A'];
		}
		else
		{
			double b = stack[topIdx--];
			double a = stack[topIdx--];
			if (postfix[i] == '+')
			{
				stack[++topIdx] = a + b;
			}
			else if (postfix[i] == '-')
			{
				stack[++topIdx] = a - b;
			}
			else if (postfix[i] == '*')
			{
				stack[++topIdx] = a * b;
			}
			else if (postfix[i] == '/')
			{
				stack[++topIdx] = a / b;
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << floor(stack[topIdx] * 100) / 100;

	delete[] oprendTable;
	delete[] stack;
}