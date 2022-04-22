// 백준 2750번 수 정렬하기 2

// input: 1 <= N = 정수 개수 <= 1,000,000
//		  |x| <= 1,000,000 (중복 안됨)

// using Heap Sort Algorithms

#include <iostream>
using namespace std;


class MinHeap
{
private:
	int* m_arr;
	
	int m_capacity;
	int m_heapSize;

	int m_lastIdx;

public:
	MinHeap(int _size = 0)
	{
		this->m_capacity = _size;
		this->m_heapSize = 0;
		this->m_lastIdx = 0;
		this->m_arr = new int[_size];
		for (int i = 0; i < m_capacity; i++)
		{
			m_arr[i] = -1000001;
		}
	}
	~MinHeap() { delete[] this->m_arr; }

	bool isEmpty()
	{
		return this->m_heapSize == 0;
	}

	int getCapacity()
	{
		return this->m_capacity;
	}

	int getHeapSize()
	{
		return this->m_heapSize;
	}

	void upHeap()
	{
		int tempIdx = this->m_lastIdx;
		while (tempIdx / 2 > 0)
		{
			if (this->m_arr[tempIdx] < this->m_arr[tempIdx / 2])
			{
				int temp = this->m_arr[tempIdx];
				this->m_arr[tempIdx] = this->m_arr[tempIdx / 2];
				this->m_arr[tempIdx / 2] = temp;

				tempIdx /= 2;
			}
			else break;
		}
	}

	void downHeap()
	{
		int tempIdx = 1;
		while (tempIdx * 2 <= this->m_heapSize)
		{
			int minIdx = tempIdx;
			if (this->m_arr[tempIdx] > this->m_arr[tempIdx * 2])
			{
				minIdx = tempIdx * 2;
			}
			if (tempIdx * 2 + 1 <= this->m_heapSize && this->m_arr[minIdx] > this->m_arr[tempIdx * 2 + 1])
			{
				minIdx = tempIdx * 2 + 1;
			}

			if (minIdx == tempIdx) return;
			else
			{
				int temp = this->m_arr[tempIdx];
				this->m_arr[tempIdx] = this->m_arr[minIdx];
				this->m_arr[minIdx] = temp;
			}
			tempIdx = minIdx;
		}
	}

	void insertHeap(int _e)
	{
		// check for isFull
		if (this->m_heapSize >= this->m_capacity)
		{
			return;
		}
		else
		{
			this->m_arr[++this->m_lastIdx] = _e;
			this->upHeap();
			this->m_heapSize++;
		}
	}

	int removeMin()
	{
		if (isEmpty())
		{
			return -1000001;
		}
		else
		{
			int min = this->m_arr[1];
			this->m_arr[1] = this->m_arr[this->m_lastIdx--];
			this->m_heapSize--;
			this->downHeap();		

			return min;
		}
	}

	void printAll()
	{
		for (int i = 1; i <= m_heapSize; i++)
		{
			cout << this->m_arr[i] << ' ';
		}
		cout << '\n';
	}
};

int main()
{
	int N;
	cin >> N;
	MinHeap* heap = new MinHeap(1000000);
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		heap->insertHeap(e);
	}
	for (int i = 0; i < N; i++)
	{
		cout << heap->removeMin() << '\n';
	}
}




// using Merge Sort Algorithm

//#include<iostream>
//using namespace std;
//
//void merge(int* arr, int* arr1, int* arr2, int size1, int size2)
//{
//	int i = 0, i1 = 0, i2 = 0;
//	while (i < size1 + size2)
//	{
//		if (i2 >= size2)
//		{
//			arr[i] = arr1[i1];
//			i++;
//			i1++;
//			continue;
//		}
//		else if (i1 >= size1)
//		{
//			arr[i] = arr2[i2];
//			i++;
//			i2++;
//			continue;
//		}
//		if (arr1[i1] >= arr2[i2])
//		{
//			arr[i] = arr2[i2];
//			i2++;
//		}
//		else
//		{
//			arr[i] = arr1[i1];
//			i1++;
//		}
//		i++;
//	}
//}
//
//void mergeSort(int* arr, int size)
//{
//	if (size == 1) return;
//
//	int size1 = size / 2;
//	int* arr1 = new int[size1];
//	int size2 = size - size1;
//	int* arr2 = new int[size2];
//	for (int i = 0; i < size; i++)
//	{
//		if (i < size1) arr1[i] = arr[i];
//		else arr2[i - size1] = arr[i];
//	}
//	mergeSort(arr1, size1);
//	mergeSort(arr2, size2);
//	merge(arr, arr1, arr2, size1, size2);
//}
//
//int main()
//{
//	int N;
//	cin >> N;
//	int* arr = new int[N];
//	for (int i = 0; i < N; i++) cin >> arr[i];
//	mergeSort(arr, N);
//	for (int i = 0; i < N; i++) cout << arr[i] << '\n';
//}