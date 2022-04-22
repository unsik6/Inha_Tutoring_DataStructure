/*
Vector
���� �迭�� ���͸� ȯ�� �迭�� �����϶�. �̶�, ������ ���� ��ɾ���� ������ �� �־�� �Ѵ�.
�����ڰ� ���͸� ������ �� ���ο� �����ϴ� ������ ũ��(�뷮)�� N�̶�� �ϰ�, ����ڰ� �ν��ϴ� ũ�⸦ n�̶�� ����.
�迭�� Ȯ���� ���� �׻� ���� ����� Ȱ���Ѵ�.
�迭�� ����� ���� N�� n/2���� �۰ų� ���� ���(��, N�� 2���� �۾����� �ʴ´�) ����Ѵ�.
������ ù �뷮�� 2�̴�.
1)	at(i): i��° ���� ����Ѵ�. ���� �ش��ϴ� �ε��� ���� ���� ���(��� �ִ� ��� ����) -1�� ����Ѵ�.
2)	set(i, x): i��° ���� x�� �ٲ۴�. �̶� �ش��ϴ� �ε��� ���� ���� ���(��� �ִ� ��� ����) -1�� ����Ѵ�.
3)	insert(i, x): i��° ���� x�� �ִ´�. i�� [0, n]�� �������� �־�����. �̶�, ���Ͱ� ����ִ� ��� -1�� ����Ѵ�.
4)	remove(i): i��° ���� �����Ѵ�. �̶� �ش��ϴ� �ε��� ���� ���� ���(��� �ִ� ��� ����) -1�� ����Ѵ�.
5)	push_back(x): �迭�� �� �ڿ� x�� �߰��Ѵ�.
6)	GetSize(): ����ڰ� �ν��ϴ� �迭�� ũ�� n�� ����Ѵ�.
7)	empty(): �����迭�� ����ִ��� Ȯ���Ѵ�. ��� ���� ��� 1��, �ƴϸ� 0�� ����Ѵ�.
8)	print(): �迭�� ��� ���Ҹ� ���������� ����Ѵ�. ��� ���� ��� -1�� ����Ѵ�.
* �Է�
���� ù �ٿ��� ��ɾ� �Է��� �� N�� �־�����. N�� ������ [0, 10,000]�̴�.
�� �ٸ��� ��ɾ �־�����, �Ű������� �ʿ��� ��� �������� �����Ͽ� �־�����.
�̶�, ������ ���ҷ� �־����� ���� x�� [0, 1,000] ������ �����̴�.
*/

#include<iostream>
using namespace std;

class Vector
{
private:
	int* m_arr;
	int m_capacity;
	int m_size;
	int m_fIdx, m_rIdx;	// fIdx: �迭�� ù��° ����, rIdx: �迭�� ������ ������ ��

public:
	Vector() : m_capacity(2), m_size(0), m_fIdx(0), m_rIdx(0)
	{
		m_arr = new int[2];
	}
	~Vector() { delete[] m_arr; }

	bool empty()
	{
		return !m_size;
	}

	int at(int _idx)
	{
		if (empty() || _idx >= m_size)
			return -1;
		else
			return m_arr[(m_fIdx + _idx) % m_capacity];
	}

	void set(int _idx, int _x)
	{
		if (empty() || _idx >= m_size)
			cout << -1 << '\n';
		else
		{
			m_arr[(m_fIdx + _idx) % m_capacity] = _x;
		}
	}

	void doublingUp()
	{
		int* newArr = new int[m_capacity * 2];
		for (int i = 0; i < m_capacity; i++)
		{
			newArr[i] = m_arr[(m_fIdx + i) % m_capacity];
		}
		m_capacity *= 2;
		m_fIdx = 0;
		m_rIdx = m_size;
		delete[] m_arr;
		m_arr = newArr;
	}

	void doublingDown()
	{
		int* newArr = new int[m_capacity / 2];
		for (int i = 0; i < m_size; i++)
		{
			newArr[i] = m_arr[(m_fIdx + i) % m_capacity];
		}

		m_capacity /= 2;
		m_fIdx = 0;
		m_rIdx = m_size;
		delete[] m_arr;
		m_arr = newArr;
	}

	void insert(int _idx, int _x)
	{
		if (m_size == m_capacity)
			this->doublingUp();
		for (int i = m_size; i > _idx; i--)
		{
			m_arr[(m_fIdx + i) % m_capacity] = m_arr[(m_fIdx + i - 1) % m_capacity];
		}
		m_arr[(m_fIdx + _idx) % m_capacity] = _x;
		m_size++;
		m_rIdx = (m_rIdx + 1) % m_capacity;
	}

	void remove(int _idx)
	{
		if (empty() || _idx >= m_size)
			cout << -1 << '\n';
		else
		{
			cout << m_arr[(m_fIdx + _idx) % m_capacity] << '\n';

			for (int i = _idx; i < m_size - 1; i++)
			{
				m_arr[(m_fIdx + i) % m_capacity] = m_arr[(m_fIdx + i + 1) % m_capacity];
			}
			m_size--;
			if (m_rIdx == 0) m_rIdx = m_capacity;
			m_rIdx = (m_rIdx - 1) % m_capacity;

			if (m_size <= m_capacity / 2 && m_capacity > 2)
				this->doublingDown();
		}
	}

	void push_back(int _x)
	{
		if (m_size == m_capacity)
			this->doublingUp();
		m_arr[(m_rIdx++) % m_capacity] = _x;
		m_size++;
	}

	int getSize() { return m_size; }
	void print()
	{
		if (empty())
		{
			cout << -1 << '\n';
			return;
		}
		for (int i = 0; i < m_size; i++)
		{
			cout << m_arr[(m_fIdx + i) % m_capacity] << ' ';
		}
		cout << '\n';
	}
};

int main()
{
	int N;
	cin >> N;

	Vector vec;
	for (int n = 0; n < N; n++)
	{
		string command;
		cin >> command;
		if (command == "at")
		{
			int param;
			cin >> param;
			cout << vec.at(param) << '\n';
		}
		else if (command == "set")
		{
			int param1, param2;
			cin >> param1 >> param2;
			vec.set(param1, param2);
		}
		else if (command == "insert")
		{
			int param1, param2;
			cin >> param1 >> param2;
			vec.insert(param1, param2);
		}
		else if (command == "remove")
		{
			int param;
			cin >> param;
			vec.remove(param);
		}
		else if (command == "push_back")
		{
			int param;
			cin >> param;
			vec.push_back(param);
		}
		else if (command == "getSize")
		{
			cout << vec.getSize() << '\n';
		}
		else if (command == "empty")
		{
			cout << vec.empty() << '\n';
		}
		else if (command == "print")
		{
			vec.print();
		}
	}
	return 0;
}