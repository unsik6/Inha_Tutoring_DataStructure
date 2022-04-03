#include <iostream>
using namespace std;

void change(int* arrint, int size)
{
	arrint[size - 1] = arrint[0];
}

int main()
{
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		arr[i] = i;


	cout << arr << endl;
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	cout << endl;

	change(arr, N);

	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	cout << endl;
	
}