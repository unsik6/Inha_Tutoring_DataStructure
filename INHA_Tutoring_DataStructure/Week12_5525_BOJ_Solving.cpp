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