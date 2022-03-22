// 백준 1021번 회전하는 큐

// Input: 0 < N <= 50 = 큐의 길이, 0 < M <= N 원하는 원소의 위치
//		  빼고자 하는 위치들

// condition: 양방향 회전큐
//			  가능 연산: pop, 좌로 이동, 우로 이동

// 앞으로 이동해서 뺄 경우 i - 1
// 뒤로 이동해서 뺄 경우 N - i + 1
// 이 둘을 비교해서 더 적은 쪽으로 빼면 된다.
// 그리고 다음에 뺄 숫자들을 새로운 큐(크기 N - i)에서의 위치 숫자로 바꿔주면 된다.

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