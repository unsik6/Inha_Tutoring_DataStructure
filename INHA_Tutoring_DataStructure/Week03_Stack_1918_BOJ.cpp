/* 백준 1918번 후위표기식
*
* Input: 길이가 100을 넘지 않는 중위 표기식
*		 알파벳(피연산자)와 사칙연산, 소괄호로만 구성되어 있다.
*		 피연산자는 알파벳 대문자로 구성, 수식에 한번씩만 등장
*		 불가능한 표기식은 주어지지 않음.
*
* Output: 후위 표기식
* 
* 소괄호로 묶여 있는 경우 하나의 부분 식이 존재한다고 판단할 수 있다.
* 그러므로 소괄호의 경우 처리하는 방법이 단순하다.
* 
* *와 / 연산의 경우 우선순위가 제일 높다. 그러므로 표기식에서 가장 먼저 출력되어야 한다.
* +와 - 연산을 만난 경우, 절이 나눠진 경우로 지금까지 미뤄두었던 모든 +와 - 연산을 출력한다.
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
				// 이 경우 우선순위가 가장 높은 연산이다.
				// 우선순위가 낮은 연산자가 나오기 전까지 계산한다.
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
				{
					cout << stk.top();
					stk.pop();
				}
				stk.push(infixNotation[i]);
			}
			else if (infixNotation[i] == '+' || infixNotation[i] == '-')
			{
				// 이 경우 우선순위가 가장 낮은 연산이다. 할 수 있는 모든 연산자를 계산한다.
				// 현재 스택에 저장된 절의 연산자들을 모두 계산한다.
				while (!stk.empty() && stk.top() != '(')
				{
					cout << stk.top();
					stk.pop();
				}
				stk.push(infixNotation[i]);
			}
			else if (infixNotation[i] == ')')
			{
				// 괄호가 닫혔다는 것은 하나의 부분 식이 완료되었다는 것을 의미한다.
				// '('가 나오기 전까지 모두 계산한다.
				while (!stk.empty() && stk.top() != '(')
				{
					cout << stk.top();
					stk.pop();
				}
				stk.pop(); // '('도 마저 꺼낸다.
			}
		}
	}
	// 모든 내부 연산이 끝나고 남은 나머지를 출력한다.
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}