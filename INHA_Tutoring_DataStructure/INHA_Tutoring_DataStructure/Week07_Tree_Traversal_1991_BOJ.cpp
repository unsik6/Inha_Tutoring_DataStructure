/* ���� 1991�� Ʈ�� ��ȸ
* 
* Input: ����� ���� (1 <= N <= 26)
*		 �� ���� �� �¿� �ڽ�.
*		 �� ����� ���� A������ ���ĺ�, ���� �¿� �ڽ��� ���� ��� .�� ǥ��
*		 �׻� A ��尡 ��Ʈ
* 
* Output: ���� ��ȸ, ���� ��ȸ, ���� ��ȸ ��� ���
*/

#include <iostream>
using namespace std;

int binaryTreeIndices[26]{ 0 };

void preOrder(int _root, int _rootCharIdx)
{
	char curChar = '0';
	for (int i = _rootCharIdx; i < 26; i++)
	{
		if (binaryTreeIndices[i] == _root)
		{
			curChar = i + 'A';
			break;
		}
	}
	if (curChar == '0') return;
	cout << curChar;
	preOrder(_root * 2, curChar - 'A' + 1);
	preOrder(_root * 2 + 1, curChar - 'A' + 1);
}

void inOrder(int _root, int _rootCharIdx)
{
	char curChar = '0';
	for (int i = _rootCharIdx; i < 26; i++)
	{
		if (binaryTreeIndices[i] == _root)
		{
			curChar = i + 'A';
			break;
		}
	}
	if (curChar == '0') return;
	inOrder(_root * 2, curChar - 'A' + 1);
	cout << curChar;
	inOrder(_root * 2 + 1, curChar - 'A' + 1);
}

void postOrder(int _root, int _rootCharIdx)
{
	char curChar = '0';
	for (int i = _rootCharIdx; i < 26; i++)
	{
		if (binaryTreeIndices[i] == _root)
		{
			curChar = i + 'A';
			break;
		}
	}
	if (curChar == '0') return;
	postOrder(_root * 2, curChar - 'A' + 1);
	postOrder(_root * 2 + 1, curChar - 'A' + 1);
	cout << curChar;
}

int main()
{
	int N;
	cin >> N;

	binaryTreeIndices[0] = 1;

	for (int n = 0; n < N; n++)
	{
		char input;
		cin >> input;

		int curCharNum = input - 'A';

		cin >> input;
		if (input != '.')
		{
			int leftCharNum = input - 'A';
			binaryTreeIndices[leftCharNum] = binaryTreeIndices[curCharNum] * 2;
		}

		cin >> input;
		if (input != '.')
		{
			int rightCharNum = input - 'A';
			binaryTreeIndices[rightCharNum] = binaryTreeIndices[curCharNum] * 2 + 1;
		}
	}
	
	preOrder(1, 0);
	cout << '\n';
	inOrder(1, 0);
	cout << '\n';
	postOrder(1, 0);
}