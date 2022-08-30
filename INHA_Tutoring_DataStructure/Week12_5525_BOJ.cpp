/* ���� 5525�� IOIOI
* 
* 50�� ��ǥ - �ؽ� ���̺��
*
* Input: 'O'�� ���� N (1 <= N <= 1,000,000)
*		 ���ڿ��� ���� M (2N+1 <= M <= 1,000,000,000)
*		'I'�� 'O'�θ� �̷���� ���ڿ� S (���� = M)
*
* Output: 'I'�� 'O'�� ������ ���� ��Ÿ����, N+1���� 'I'�� N���� 'O'�� ���� ���ڿ� P�� ���Ͽ�
*		  S���� P�� ��Ÿ���� ȸ���� ����Ѵ�.
* 
* ������ Rabin-Karp��� string matching �˰����� �ؽ��� �̿��ؼ� ��Ī�� �����Ѵ�.
* ��Ī�� ������ ���ڿ� ���� P�� ��� ���ڵ��� ���Ͽ� ������ �ؽ����� h_p��� ����.
* ��Ī�� ������ ���ڿ� S�� S[0]~S[|S|-|P|]���� �����ϰ� P�� ������ ���̸� ���� �κ� ���ڿ� S[0..|P| - 1] ~ S[|S| - |P|, |S| - 1]�� ���Ͽ�
* ������ ������� ������ �ؽ����� ���� ���� hashArr (ũ��� |S| - |P| + 1)�� Ž���ϸ鼭 hashArr[i] == h_p�� ���
* �ش� �κ� ���ڿ��� ������ ���� P�� �������� �˻��Ѵ�.
* 
* �̴� ���ڿ����� ������ ������ ��Ÿ���� �κ��� �ſ� ���� ���̶�� ������ ������� �˰����̴�.
* hashArr[i] == h_p�� ���� 2�����̴�.
*  (1) S[i..|P| + i - 1] == P�� ���, ������ P�� ��Ÿ���� ���̴�.
*  (2) S[i..|P| + i - 1] != P�� ���, �츮�� �ڷᱸ�� �������� ����� �ؽ� �浹�� �Ͼ�� ����̴�.
*/


#include <iostream>
using namespace std;

#define M 1234567891

void hashTableOfStr(char* _str, int _size, int _n, int** _hashTable)
{
	int* table = new int[_size - (2 * _n + 1) + 1];
	int sumValue = 0;
	for (int i = 0; i < (2 * _n + 1); i++)
	{
		sumValue += _str[i];
	}
	table[0] = sumValue % M;
	for (int i = 1; i < _size - (2 * _n + 1) + 1; i++)
	{
		sumValue = sumValue - _str[i - 1] + _str[i + (2 * _n)];
		table[i] = sumValue % M;
	}
	*_hashTable = table;
}

bool naiveStringMatching(char* _str1, int _startPosOfStr1, char* _str2, int _size)
{
	bool matching = true;
	for (int i = 0; i < _size; i++)
	{
		if (_str1[_startPosOfStr1 + i] != _str2[i])
		{
			matching = false;
			break;
		}
	}

	return matching;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	char* str = new char[m + 1];
	char* pattern = new char[2 * n + 1];
	for (int i = 0; i < 2 * n + 1; i++)
	{
		if (i % 2 == 0)
			pattern[i] = 'I';
		else
			pattern[i] = 'O';
	}
	/*cout << "pattern: ";
	for (int i = 0; i < 2 * n + 1; i++)
	{
		cout << pattern[i];
	}
	cout << endl;*/
	cin.ignore();
	cin.clear();
	cin.getline(str, m + 1);



	if (2 * n + 1 == m)
	{
		if (naiveStringMatching(str, 0, pattern, 2 * n + 1))
		{
			cout << 1;
		}
		else cout << 0;
	}
	else
	{
		int cnt = 0;
		int* hashTable = nullptr;
		hashTableOfStr(str, m, n, &hashTable);
		int hashValueOfP = 0;
		for (int i = 0; i < 2 * n + 1; i++)
		{
			hashValueOfP += pattern[i];
		}
		hashValueOfP %= M;

		for (int i = 0; i < m - (2 * n + 1) + 1; i++)
		{
			if (hashTable[i] == hashValueOfP)
			{
				if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I')
				{
					if (naiveStringMatching(str, i, pattern, 2 * n + 1))
					{
						cnt++;
					}
				}
			}
		}

		cout << cnt;

		delete[] hashTable;
	}
}