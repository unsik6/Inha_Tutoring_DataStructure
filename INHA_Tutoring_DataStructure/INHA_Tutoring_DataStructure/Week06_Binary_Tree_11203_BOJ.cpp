/* 백준 11203번 Numbers On a Tree

input : 트리의 높이 H (1 <= H <= 30)
		문자열 (L, R) (0 <= 문자열의 길이 <= 30)

		** Perfect Binary Tree의 라벨링이 우측 하단부터 좌상으로 1씩 증가

output: 루트부터 주어진 문자열의 이동을 진행한 후 최종 노드의 번호
*/

// binary tree의 속성을 이용하는 문제입니다.
// 실제로 tree를 구현할 경우, 제한 시간 내에 못 풀기 때문에
// tree 구현 연습은 다른 문제에서 진행합니다.

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