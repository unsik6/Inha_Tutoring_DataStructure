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
* 실제로 Rabin-Karp라는 string matching 알고리즘은 해쉬를 이용해서 매칭을 진행한다.
* 매칭을 진행할 문자열 패턴 P의 모든 문자들을 더하여 생성한 해쉬값을 h_p라고 하자.
* 매칭을 진행할 문자열 S의 S[0]~S[|S|-|P|]에서 시작하고 P와 동일한 길이를 같는 부분 문자열 S[0..|P| - 1] ~ S[|S| - |P|, |S| - 1]에 대하여
* 동일한 방식으로 각각의 해쉬값을 구한 서열 hashArr (크기는 |S| - |P| + 1)를 탐색하면서 hashArr[i] == h_p인 경우
* 해당 부분 문자열이 실제로 패턴 P와 동일한지 검사한다.
* 
* 이는 문자열에서 실제로 패턴이 나타나는 부분이 매우 적을 것이라는 전제로 만들어진 알고리즘이다.
* hashArr[i] == h_p인 경우는 2가지이다.
*  (1) S[i..|P| + i - 1] == P인 경우, 실제로 P가 나타나는 것이다.
*  (2) S[i..|P| + i - 1] != P인 경우, 우리가 자료구조 수업에서 배웠던 해쉬 충돌이 일어나는 경우이다.
*/


#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	char* str = new char[m + 1];
	cin.ignore();
	cin.clear();
	cin.getline(str, m + 1);

	int cnt = 0;
	bool onI = false;
	bool OI = true;
	bool onMatching = false;
	int numberOfO = 0;
	for (int i = 0; i < m; i++)
	{
		if (str[i] == 'I')
		{
			if (!onI)
			{
				onI = true;
			}
			else
			{
				if (!OI)
				{
					if (onMatching)
					{
						cnt++;
					}
					else
					{
						numberOfO++;
						if (numberOfO == n)
						{
							cnt++;
							onMatching = true;
						}
					}
					OI = true;
				}
				else
				{
					onI = true;
					OI = true;
					onMatching = false;
					numberOfO = 0;
				}
			}
		}
		else
		{
			if (onI)
			{
				if (!OI)
				{
					onI = false;
					OI = true;
					onMatching = false;
					numberOfO = 0;
				}
				else OI = false;
			}
		}
	}

	cout << cnt;

	delete[] str;
}