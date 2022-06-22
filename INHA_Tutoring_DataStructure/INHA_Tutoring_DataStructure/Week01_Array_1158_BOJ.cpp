// ���� 1158�� �似Ǫ�� ����

// input: ����� �� N, ���� ���� K (1 <= K <= N <= 5,000)
// 
// condition: K������� K��° ����� �����Ѵ�. �� ����� ���ŵǸ� ���� ����鵵 �̷���� ���� ���� ���
//			  ��� ���� ������ ����ϰ�, ���� ������� ���

// using array
#include <iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	bool* arr = new bool[N]{false};		// if arr[i] is killed then arr[i] is true.
	int curIdx = -1, killCnt = 0;
	
	cout << '<';
	while (killCnt < N)
	{
		for (int i = 0; i < K; i++)
		{
			curIdx = (curIdx + 1) % N;
			if (arr[curIdx])
				i--;
		}
		arr[curIdx] = true;
		cout << curIdx + 1
			<< (killCnt == N - 1 ? ">" : ", ");

		killCnt++;
	}


	delete[] arr;
	
	return 0;
}