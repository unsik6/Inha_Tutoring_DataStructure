/* ���� 1918�� ����ǥ���
*
* Input: ���̰� 100�� ���� �ʴ� ���� ǥ���
*		 ���ĺ�(�ǿ�����)�� ��Ģ����, �Ұ�ȣ�θ� �����Ǿ� �ִ�.
*		 �ǿ����ڴ� ���ĺ� �빮�ڷ� ����, ���Ŀ� �ѹ����� ����
*		 �Ұ����� ǥ����� �־����� ����.
*
* Output: ���� ǥ���
* 
* �Ұ�ȣ�� ���� �ִ� ��� �ϳ��� �κ� ���� �����Ѵٰ� �Ǵ��� �� �ִ�.
* �׷��Ƿ� �Ұ�ȣ�� ��� ó���ϴ� ����� �ܼ��ϴ�.
* 
* *�� / ������ ��� �켱������ ���� ����. �׷��Ƿ� ǥ��Ŀ��� ���� ���� ��µǾ�� �Ѵ�.
* +�� - ������ ���� ���, ���� ������ ���� ���ݱ��� �̷�ξ��� ��� +�� - ������ ����Ѵ�.
*/

#include <iostream>
#include <stack>
using namespace std;



int main()
{
	stack<char> stk;
	string infixNotation;
	cin >> infixNotation;
	
	for (int i = 0; i < infixNotation.length(); i++)
	{
		if (infixNotation[i] >= 'A' && infixNotation[i] <= 'Z')
		{
			cout << infixNotation[i];
		}
		else
		{
			if (infixNotation[i] == '(')
				stk.push(infixNotation[i]);
			else if (infixNotation[i] == '*' || infixNotation[i] == '/')
			{
				// �� ��� �켱������ ���� ���� �����̴�.
				// �켱������ ���� �����ڰ� ������ ������ ����Ѵ�.
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
				{
					cout << stk.top();
					stk.pop();
				}
				stk.push(infixNotation[i]);
			}
			else if (infixNotation[i] == '+' || infixNotation[i] == '-')
			{
				// �� ��� �켱������ ���� ���� �����̴�. �� �� �ִ� ��� �����ڸ� ����Ѵ�.
				// ���� ���ÿ� ����� ���� �����ڵ��� ��� ����Ѵ�.
				while (!stk.empty() && stk.top() != '(')
				{
					cout << stk.top();
					stk.pop();
				}
				stk.push(infixNotation[i]);
			}
			else if (infixNotation[i] == ')')
			{
				// ��ȣ�� �����ٴ� ���� �ϳ��� �κ� ���� �Ϸ�Ǿ��ٴ� ���� �ǹ��Ѵ�.
				// '('�� ������ ������ ��� ����Ѵ�.
				while (!stk.empty() && stk.top() != '(')
				{
					cout << stk.top();
					stk.pop();
				}
				stk.pop(); // '('�� ���� ������.
			}
		}
	}
	// ��� ���� ������ ������ ���� �������� ����Ѵ�.
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}