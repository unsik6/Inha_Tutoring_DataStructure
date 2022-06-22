// 백준 1158번 요세푸스 문제

// input: 사람의 수 N, 제거 간격 K (1 <= K <= N <= 5,000)
// 
// condition: K순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들도 이루어진 원을 따라 계속
//			  모두 죽을 때까지 계속하고, 죽은 순서대로 출력

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