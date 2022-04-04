/* ���� 11203�� Numbers On a Tree

input : Ʈ���� ���� H (1 <= H <= 30)
		���ڿ� (L, R) (0 <= ���ڿ��� ���� <= 30)

		** Perfect Binary Tree�� �󺧸��� ���� �ϴܺ��� �»����� 1�� ����

output: ��Ʈ���� �־��� ���ڿ��� �̵��� ������ �� ���� ����� ��ȣ
*/

// binary tree�� �Ӽ��� �̿��ϴ� �����Դϴ�.
// ������ tree�� ������ ���, ���� �ð� ���� �� Ǯ�� ������
// tree ���� ������ �ٸ� �������� �����մϴ�.

#include <iostream>
using namespace std;

long long pow(long long _x, long long _y)
{
	long long result = 1;
	for (long long i = 0; i < _y; i++)
	{
		result *= _x;
	}
	return result;
}


int main()
{
	char order[34];
	cin.getline(order, 34, '\n');
	
	long long N = 0;
	long long curOrderIdx = 2;
	if (order[1] >= '0' && order[1] <= '9')
	{
		N = ((order[0] - '0') * 10 + (order[1] - '0'));
		curOrderIdx = 3;
	}
	else
		N = order[0] - '0';

	long long label = pow(2, N+1);

	

	if (!(order[curOrderIdx] == 'L' || order[curOrderIdx] == 'R'))
		cout << label - 1;
	else
	{
		long long curNum = 1;
		
		while (order[curOrderIdx] == 'L' || order[curOrderIdx] == 'R')
		{
			if (order[curOrderIdx] == 'L')
				curNum = curNum * 2;
			else curNum = curNum * 2 + 1;

			curOrderIdx++;
		}
		
		label -= curNum;
		
		cout << label;
	}


	return 0;
}