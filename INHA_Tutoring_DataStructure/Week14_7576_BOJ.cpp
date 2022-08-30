// ���� 7576�� �丶��

// input: M * N ��Ʈ���� (2 <= M, N <= 1,000)
//		  ���ڿ� ��� �丶���� ���� �Է�: 1 = ����, 0 = ���� ����, -1 = �丶�� ����
// 
// condition: ���� �丶��� ������ �丶��� �Ϸ� �Ŀ� �ʹ´�.
//			  ��ĥ�� ������ ��� �ʹ°�?

// ���̵�� ����
// ó���� �Է¹��� ���� �丶����� ��� BFS�� �������̶�� �����Ѵ�.
// ��� ���� �丶��鿡 ���ؼ� BFS�� �����ϰ�, lvl�� �ο��Ѵ�.
// �̶� ó���� �Է¹��� ���� �丶��鿡 ���� ������ �ٸ� �� �����Ƿ� ���� ���� ������ �ο��Ѵ�.
// ������ �ο��ϸ鼭 ������ �ִ밪�� ã�´�.
// BFS�� O(N * M)�̱� ������ �� ������ O((N * M)^2)�̸� �ʴ� 1����� ������ �Ѵٰ� �ϸ� 10000�ʰ� �Ҹ�ȴ�.
// 
// �̸� ���̷��� ù��° ���� BFS���� ������ �ɸ� �ȴ�.
// ù��°���� �Ϲ����� BFS�� �����Ѵ�.
// �ι�°���ʹ� BFS�� ������ ��, � ������ ������ �������� ���ų� ���ٸ�,
// �� ������ �������δ� �� �������� �ʾƵ� �ȴ�.
// �ֳ��ϸ� �ش� �������� �� ���� ������ ������ ������ �������� ���� �����̴�.
// �׷��� �ᱹ Ž���� ��ġ�� �丶�䰡 �ް��ϰ� �پ���, ��ġ�� ��찡 ���� ���� �־��� ��쿡�� O(N*M /2)�̹Ƿ�
// O(N*M)�ð��� ������ �� �ִ�.

// ��ӵ� �ð��ʰ�...
// ó���� ������ ����ϴ� ����� ���� ����, ���� ������ ���� ��,
// ���� ������ ������ ������ ������ �����ߴ�.
// �׷��� ó���� �;��ִ� �丶�亰�� BFS�� �����ؾ� �߰�, �ð��ʰ��� ����.
// �׷��� ������ �� �������� �����ϸ� ���� ������ +1�� �ϸ� �ư�,
// ó���� �;��ִ� �丶�䵵 �׳� ť�� �־� ������ �� ���̾���..

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