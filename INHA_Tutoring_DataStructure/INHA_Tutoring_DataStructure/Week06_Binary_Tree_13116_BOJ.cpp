/* 13116 30��
input : ��ǥ ��� a, b (1 <= a, b <= 1023, a!=b)


output: ��Ʈ���� a, b������ ��� �� ��ġ�� �� �� ���� ū �� * 10
*/

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int a, b;
		cin >> a >> b;
		int ancestorOfa[11]{ 0 };
		int ancestorOfb[11]{ 0 };
		ancestorOfa[0] = a;
		ancestorOfb[0] = b;
		int curIdx = 1;
		while (a > 1)
		{
			if (a % 2 == 1)
			{
				a = (a - 1) / 2;
			}
			else
				a /= 2;
			ancestorOfa[curIdx] = a;
			curIdx++;
		}
		curIdx = 1;
		while (b > 1)
		{
			if (b % 2 == 1)
			{
				b = (b - 1) / 2;
			}
			else
				b /= 2;
			ancestorOfb[curIdx] = b;
			curIdx++;
		}

		int max = 1;
		for (int i = 0; i < 10; i++)
		{
			for (int f = 0; f < 10; f++)
			{
				if (ancestorOfa[i] == ancestorOfb[f])
				{
					max = (max < ancestorOfa[i] ? ancestorOfa[i] : max);
					break;
				}
				else if (ancestorOfa[i] == 0 || ancestorOfb[f] == 0)
					break;
			}
		}

		cout << max * 10 << '\n';
	}

	return 0;
}