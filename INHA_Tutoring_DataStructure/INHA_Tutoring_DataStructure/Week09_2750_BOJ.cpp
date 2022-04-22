// 백준 2750번 수 정렬하기

// input: 1 <= N = 정수 개수 <= 1,000
//		  |x| <= 1,000 (중복 안됨)

// bubble sort

//#include<iostream>
//using namespace std;
//int main()
//{
//	// input N is the size of array.
//	int N;
//	cin >> N;
//
//	// initialize new array whose size is N.
//	int* arr = new int[N];
//	for (int i = 0; i < N; i++)
//		cin >> arr[i];
//
//	for (int i = 0; i < N - 1; i++)
//	{
//		for (int j = 0; j < N - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
// 
// // print output.
//	for (int k = 0; k < N; k++) cout << arr[k] << '\n';
//
//	delete[] arr;
//}

// insertion sort

//#include<iostream>
//using namespace std;
//int main()
//{
//	// input N is the size of array.
//	int N;
//	cin >> N;
//
//	// initialize new array whose size is N.
//	int* arr = new int[N];
//	for (int i = 0; i < N; i++)
//		cin >> arr[i];
//
//	for (int i = 1; i < N; i++)
//	{
//		int key = arr[i];
//		for (int j = i - 1; j >= 0; j--)
//		{
//			if (key < arr[j])
//			{
//				arr[j + 1] = arr[j];
//				arr[j] = key;
//			}
//			else
//				break;
//		}
//	}
//
//	// print output.
//	for (int k = 0; k < N; k++) cout << arr[k] << '\n';
//
//	delete[] arr;
//}

// selection sort

#include<iostream>
using namespace std;
int main()
{
	// input N is the size of array.
	int N;
	cin >> N;

	// initialize new array whose size is N.
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N - 1; i++)
	{
		int minIdx = i;
		for (int j = i + 1 ; j < N; j++)
		{
			minIdx = (arr[minIdx] > arr[j] ? j : minIdx);
		}
		if (minIdx == i) continue;

		int temp = arr[minIdx];
		arr[minIdx] = arr[i];
		arr[i] = temp;		
	}

	// print output.
	for (int k = 0; k < N; k++) cout << arr[k] << '\n';

	delete[] arr;
}