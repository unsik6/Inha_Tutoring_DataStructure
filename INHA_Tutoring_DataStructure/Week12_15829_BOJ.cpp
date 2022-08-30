/* 백준 15829번 Hashing
*
* Input: 문자열의 길이 L (1 <= L <= 50)
* 
* Output: sum(all char * pow(r, i) mod M
*		  r = 31, M = 1234567891
*/

#include <iostream>
using namespace std;

#define R 31
#define M 1234567891

long long  hashing(char* _str, int _size)
{
	long long hashValue = 0;
	for (int i = 0; i < _size; i++)
	{
		long long charValue = _str[i] - 'a' + 1;
		for (int f = 0; f < i; f++)
		{
			charValue = charValue * R % M;
		}
		hashValue = (hashValue + charValue) % M;
	}

	return hashValue;
}

int main()
{
	int l;
	cin >> l;
	char* str = new char[l + 1];
	cin.ignore();
	cin.clear();
	cin.getline(str, l + 1);
	cout << hashing(str, l);

	delete[] str;
}