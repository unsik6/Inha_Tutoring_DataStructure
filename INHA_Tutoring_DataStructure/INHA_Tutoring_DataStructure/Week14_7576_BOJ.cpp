// 백준 7576번 토마토

// input: M * N 매트릭스 (2 <= M, N <= 1,000)
//		  상자에 담긴 토마토의 정보 입력: 1 = 익음, 0 = 익지 않음, -1 = 토마토 없음
// 
// condition: 익은 토마토와 인접한 토마토는 하루 후에 익는다.
//			  며칠이 지나야 모두 익는가?

// 아이디어 도출
// 처음에 입력받은 익은 토마토들이 모두 BFS의 시작점이라고 생각한다.
// 모든 익은 토마토들에 대해서 BFS를 진행하고, lvl을 부여한다.
// 이때 처음에 입력받은 익은 토마토들에 따라 레벨이 다를 수 있으므로 가장 낮은 레벨을 부여한다.
// 레벨을 부여하면서 레벨의 최대값을 찾는다.
// BFS는 O(N * M)이기 때문에 총 실행은 O((N * M)^2)이며 초당 1억번의 실행을 한다고 하면 10000초가 소모된다.
// 
// 이를 줄이려면 첫번째 외의 BFS에서 제한을 걸면 된다.
// 첫번째에는 일반적인 BFS를 진행한다.
// 두번째부터는 BFS를 진행할 때, 어떤 정점이 기존의 레벨보다 높거나 같다면,
// 그 정점을 기준으로는 더 진행하지 않아도 된다.
// 왜냐하면 해당 정점보다 더 깊은 정점은 무조건 기존의 레벨보다 높기 때문이다.
// 그러면 결국 탐색시 겹치는 토마토가 급격하게 줄어들며, 겹치는 경우가 가장 많은 최악의 경우에는 O(N*M /2)이므로
// O(N*M)시간에 수행할 수 있다.

// 계속된 시간초과...
// 처음에 레벨을 계산하는 방식은 현재 레벨, 현재 레벨의 정점 수,
// 다음 레벨의 정점을 각각의 변수로 구성했다.
// 그래서 처음에 익어있는 토마토별로 BFS를 구성해야 했고, 시간초과가 났다.
// 그러나 레벨을 각 정점별로 저장하면 현재 레벨에 +1만 하면 됐고,
// 처음에 익어있는 토마토도 그냥 큐에 넣어 돌리면 될 뿐이었다..

#include <iostream>
#include <queue>
using namespace std;

int NeverExplored = 10000001;
int pmR[4] = { -1, 1, 0, 0 };
int pmC[4] = { 0, 0, 1, -1 };

int main()
{
	int N, M;
	cin >> N >> M;

	queue<int> explored;

	int** mat = new int* [M];
	int** lvlMat = new int* [M];
	for (int i = 0; i < M; i++)
	{
		mat[i] = new int[N] {-1};
		lvlMat[i] = new int[N];

		for (int f = 0; f < N; f++)
		{
			cin >> mat[i][f];
			if (mat[i][f] == 1)
				explored.push(i * N + f);

			if (mat[i][f] == 1) lvlMat[i][f] = 0;
			else if (mat[i][f] == -1) lvlMat[i][f] = -1;
			else lvlMat[i][f] = NeverExplored;
		}
	}

	// start BFS to all firstRipen
	while (!explored.empty())
	{
		int cur = explored.front();
		int curCol = cur % N;
		int curRow = (cur - curCol) / N;
		explored.pop();
		for (int i = 0; i < 4; i++)
		{
			int tarRow = curRow + pmR[i];
			int tarCol = curCol + pmC[i];
			if (tarRow >= 0 && tarRow < M && tarCol >= 0 && tarCol < N)
			{
				if (mat[tarRow][tarCol] == 0
					&& lvlMat[tarRow][tarCol] > lvlMat[curRow][curCol] + 1)
				{
					explored.push(tarRow * N + tarCol);
					lvlMat[tarRow][tarCol] = lvlMat[curRow][curCol] + 1;
				}
			}
		}
	}
	

	int max = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			/*cout << lvlMat[i][j] << ' ';*/
			if (lvlMat[i][j] == NeverExplored)
			{
				max = -1;
				break;
			}
			if (max < lvlMat[i][j]) max = lvlMat[i][j];
		}
		if (max == -1) break;
		/*cout << endl;*/
	}

	cout << max;

	for (int i = 0; i < M; i++)
	{
		delete[] mat[i];
		delete[] lvlMat[i];
	}
	delete[] mat;
	delete[] lvlMat;
}