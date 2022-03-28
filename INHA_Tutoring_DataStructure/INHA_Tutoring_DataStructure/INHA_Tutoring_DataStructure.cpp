#include <iostream>
using namespace std;


// 해야되는 작업 1번: 공백 찍기, 2번 별찍기
// 
// b = 각 경우에 공백이 찍히는 횟수
//     b--;
// s = 각 경우에 별이 찍히는 횟수
//     s++;
// b + s = n
// 
// s = n - b
// 우리한테 필요한거: b, n

void starByBlanck(int _n, int _b)
{
	if (_b < 0) return;

	for (int i = 0; i < _b; i++) cout << ' ';
	for (int i = 0; i < _n - _b; i++) cout << '*';
	cout << endl;

	starByBlanck(_n, _b - 1);
}


int main()
{
	int N;
	cin >> N;

	starByBlanck(N, N-1);
}