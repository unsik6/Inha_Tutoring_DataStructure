/* 백준 5525번 IOIOI
* 
* 50점 목표 - 해시 테이블용
*
* Input: 'O'의 개수 N (1 <= N <= 1,000,000)
*		 문자열의 길이 M (2N+1 <= M <= 1,000,000,000)
*		'I'와 'O'로만 이루어진 문자열 S (길이 = M)
*
* Output: 'I'와 'O'가 번갈아 가며 나타나고, N+1개의 'I'와 N개의 'O'를 갖는 문자열 P에 대하여
*		  S에서 P가 나타나는 회수를 출력한다.
* 
* 실제로 Rabin-Karp라는 string matching 알고리즘은 해시를 이용해서 매칭을 진행한다.
* 매칭을 진행할 문자열 패턴 P의 모든 문자들을 더하여 생성한 해시값을 h_p라고 하자.
* 매칭을 진행할 문자열 S의 S[0]~S[|S|-|P|]에서 시작하고 P와 동일한 길이를 같는 부분 문자열 S[0..|P| - 1] ~ S[|S| - |P|, |S| - 1]에 대하여
* 동일한 방식으로 각각의 해시값을 구한 서열 hashArr (크기는 |S| - |P| + 1)를 탐색하면서 hashArr[i] == h_p인 경우
* 해당 부분 문자열이 실제로 패턴 P와 동일한지 검사한다.
* 
* 이는 문자열에서 실제로 패턴이 나타나는 부분이 매우 적을 것이라는 전제로 만들어진 알고리즘이다.
* hashArr[i] == h_p인 경우는 2가지이다.
*  (1) S[i..|P| + i - 1] == P인 경우, 실제로 P가 나타나는 것이다.
*  (2) S[i..|P| + i - 1] != P인 경우, 우리가 자료구조 수업에서 배웠던 해시 충돌이 일어나는 경우이다.
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
