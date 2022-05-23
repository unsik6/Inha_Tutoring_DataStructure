// 백준 1927번 최소 힙

// input: 1 <= N = 연산의 개수 <= 100,000
//		  x: 자연수인 경우, 배열에 값을 추가 // 0인 경우, 가장 작은 값 출력 및 제거 < 2^31

// condition: 가치 합의 최대값

#include<iostream>
using namespace std;

void intSwap(int& _a, int& _b)
{
	_a ^= _b ^= _a ^= _b;
}

class MinHeap
{
private:
	int* m_arr;
	int m_size;
	int m_capacity;

public:
	MinHeap(int _cap = 0) : m_size(0), m_capacity(_cap)
	{
		m_arr = new int[_cap];
	}
	~MinHeap() { delete m_arr; }

	void upHeap()
	{
		int curIdx = m_size;
		while (curIdx / 2 > 0)
		{
			if (m_arr[curIdx] < m_arr[curIdx / 2])
			{
				intSwap(m_arr[curIdx], m_arr[curIdx / 2]);
			}
			else break;

			curIdx /= 2;
		}
	}

	void downHeap()
	{
		int curIdx = 1;
		while (curIdx * 2 <= m_size)
		{
			int min = m_arr[curIdx];
			int tarIdx = curIdx;
			if (min > m_arr[curIdx * 2])
			{
				min = m_arr[curIdx * 2];
				tarIdx = curIdx * 2;
			}
			if (curIdx * 2 + 1 <= m_size
				&& min > m_arr[curIdx * 2 + 1])
			{
				min = m_arr[curIdx * 2 + 1];
				tarIdx = curIdx * 2 + 1;
			}

			if (tarIdx == curIdx) break;
			else
			{
				intSwap(m_arr[curIdx], m_arr[tarIdx]);
				curIdx = tarIdx;
			}
		}
	}

	void insert(int _e)
	{
		if (m_size >= m_capacity)
		{
			cerr << "Full Exception\n";
			return;
		}
		m_arr[++m_size] = _e;
		this->upHeap();
	}

	int removeMin()
	{
		if (m_size < 1)
		{
			return 0;
			// cerr << "Empty Exception\n";
			// return;
		}
		int result = m_arr[1];
		m_arr[1] = m_arr[m_size--];
		this->downHeap();

		return result;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	MinHeap* heap = new MinHeap(N + 1);
	for (int n = 0; n < N; n++)
	{
		int input;
		cin >> input;

		if (input == 0)
			cout << heap->removeMin() << '\n';
		else
			heap->insert(input);
	}
	

	delete heap;
}