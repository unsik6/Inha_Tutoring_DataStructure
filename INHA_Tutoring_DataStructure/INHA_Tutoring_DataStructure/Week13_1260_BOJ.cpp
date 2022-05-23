// 백준 1260번 DFS와 BFS

// input: 정점의 개수 (1 <= N <= 1,000)
//		  간선의 개수 (1 <= M <= 10,000)
//		  탐색 시작할 정점의 번호 V (1 <= V <= N)
//		  M개 동안 간선이 연결하는 두 정점의 번호가 주어진다.
// condition: 가장 돈을 적게 쓰면서 끝까지 가는 경우


#include <iostream>
#include <queue>
using namespace std;


void DFS(int _v, int** _inciMat, int _N, bool* _isEx)
{
	_isEx[_v] = true;
	cout << _v << ' ';
	for (int i = 0; i < _N; i++)
	{
		if (_inciMat[_v][i] > 0 && !_isEx[i])
		{
			DFS(i, _inciMat, _N, _isEx);
		}
	}
}



int main()
{
	int N, M, V;
	cin >> N >> M >> V;
	int** incidentArr = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		incidentArr[i] = new int[N + 1];
		for (int f = 0; f < N + 1; f++) incidentArr[i][f] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		incidentArr[s][e]++;
		incidentArr[e][s]++;
	}

	// DFS
	bool* isExplored = new bool[N + 1]{ false };
	// recursion
	/*DFS(V, incidentArr, N + 1, isExplored);*/

	// iteration
	// stack needs O(N^2) space
	// so in some case, recursion needs less space.
	// and in iteration implementation, vector is better than static stack.
	int stackSize = N * N + 1;
	int* stack = new int[stackSize]{0};
	int top = 0;
	stack[++top] = V;
	while (top > 0)
	{
		int cur = stack[top--];
		if (isExplored[cur]) continue;
		isExplored[cur] = true;
		cout << cur << ' ';
		for (int j = N; j > 0; j--)
		{
			if (incidentArr[cur][j] > 0 && !isExplored[j])
			{
				stack[++top] = j;
			}
		}

		/*cout << "\n top = " << top << "stack : ";
		for (int i = 0; i <= top; i++)
			cout << stack[i] << ' ';
		cout << '\n';*/
	}

	cout << '\n';

	// BFS
	queue<int> lvls;
	lvls.push(V);
	while (!lvls.empty())
	{
		int curV = lvls.front();
		lvls.pop();
		cout << curV << ' ';
		for (int i = 1; i < N + 1; i++)
		{
			if (incidentArr[curV][i] > 0 && incidentArr[i][i] == 0)
			{
				// check explored
				incidentArr[i][i] = 1;
				incidentArr[curV][i] = 0;
				incidentArr[i][curV] = 0;
				lvls.push(i);
			}
		}
	}
}