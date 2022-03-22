// ���� 1021�� ȸ���ϴ� ť

// Input: 0 < N <= 50 = ť�� ����, 0 < M <= N ���ϴ� ������ ��ġ
//		  ������ �ϴ� ��ġ��

// condition: ����� ȸ��ť
//			  ���� ����: pop, �·� �̵�, ��� �̵�

// ������ �̵��ؼ� �� ��� i - 1
// �ڷ� �̵��ؼ� �� ��� N - i + 1
// �� ���� ���ؼ� �� ���� ������ ���� �ȴ�.
// �׸��� ������ �� ���ڵ��� ���ο� ť(ũ�� N - i)������ ��ġ ���ڷ� �ٲ��ָ� �ȴ�.

#include<iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int* arr = new int[M];
	for (int i = 0; i < M; i++)
		cin >> arr[i];
	int cnt = 0;

	for(int i = 0; i < M; i++)
	{
		cnt += (N - arr[i] + 1 > arr[i] - 1 ? arr[i] - 1 : N - arr[i] + 1);

		for (int f = i+1; f < M; f++)
			arr[f] = (arr[i] <= arr[f] ? arr[f] - arr[i] : arr[f] + N - arr[i]);
		N--;
	}
	cout << cnt;
	return 0;
}