// 백준 2606번 바이러스

// input: 컴퓨터의 개수 (1 <= com <= 100)
//		  간선의 개수 (net)
//		  net개 동안 간선이 연결하는 두 정점의 번호가 주어진다.
// condition: 컴퓨터가 연결되어 있으면 바이러스가 퍼진다. 1번컴퓨터가 바이러스에 걸렸다.

// We just need to search all vertices of a graph including vertex1.

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int com, net;
	cin >> com >> net;
	int** graph = new int* [com + 1];
	for (int i = 0; i < com + 1; i++)
	{
		graph[i] = new int[com + 1]{ 0 };
	}
	for (int i = 0; i < net; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s][e]++;
		graph[e][s]++;
	}

	// answer
	int cnt = 0;

	// BFS
	bool* isExplored = new bool[com + 1]{ false };
	queue<int> lvlVertices;
	lvlVertices.push(1);
	isExplored[1] = true;
	while (!lvlVertices.empty())
	{
		int curV = lvlVertices.front();
		lvlVertices.pop();
		cnt++;

		for (int i = 1; i < com + 1; i++)
		{
			if (graph[curV][i] > 0 && !isExplored[i])
			{
				isExplored[i] = true;
				lvlVertices.push(i);
			}
		}
	}
	
	cout << --cnt;

	for (int i = 0; i < com + 1; i++)
	{
		delete[] graph[i];
	}
	delete[] graph;
}