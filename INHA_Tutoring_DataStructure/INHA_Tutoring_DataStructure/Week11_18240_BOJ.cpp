/* 백준 18240번 이진 탐색 트리 복원하기
*
* Input: 수열의 길이 N (2 <= N <= 300,000)
*		 A_2부터 A_N까지 순서대로 삽입할 때마다 삽입된 노드의 깊이가 공백으로 구분하여 주어짐.
*		 이때 노드의 깊이는 1이상 N 미만의 자연수이다.
*
* Output: 가능한 수열이 있다면 첫째 줄에 A_1..A_N의 값을 공백으로 구분하여 출력 (스페셜 저지)
*		  가능한 수열이 없으면 -1 출력
*
* 스페셜 저지이므로 형태에 얽매일 필요가 없다.
* 들어오는 높이의 수대로 각 레벨을 왼쪽부터 채운 형태라고 생각하면 쉽다.
* 만약 1이 1개 밖에 없는데 2가 3개 이상 들어온다거나
* 1이 2개인데 2가 5개 이상 들어온다면 아예 불가능하다.
* 이 과정은 어렵지 않다. 다만, 번호를 매기는 과정이 어렵기 때문에
* 우리는 BST가 중위 순회를 하면 오름차순으로 정리됨을 이용한다.
* 
* 
* 최대 높이는 n-1이다.
* 배열로 만들 경우 매우 큰 배열이 필요하다. 만약 왼쪽 편향일 경우, 2^29999 - 1 개의 배열이 필요하게 된다.
* 배열로 BST를 만드는 것은 좋지 못하다.
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int index;
    vector<Node*> children;

    Node(int idx) {
        index = idx;
    }
};

vector<vector<Node*>> tree(300001, vector<Node*>());
int result[300001];


int idx = 1;
void Inorder(Node* _root) {
    if (_root->children.size() > 0) {
        // 왼쪽 자식 존재
        Inorder(_root->children[0]);
    }
    result[_root->index] = idx++;
    if (_root->children.size() > 1) {
        // 오른쪽 자식 존재
        Inorder(_root->children[1]);
    }
}

int main() {
    // 노드의 깊이(depth)는 2^depth개 만큼만 나올 수 있다

    int N; cin >> N;

    int index = 0;
    Node* head = new Node(++index);

    tree[0].push_back(head);

    for (int i = 0; i < N - 1; i++) {
        int level;
        cin >> level;

        Node* tmp = new Node(++index);

        int insertIdx = tree[level].size();
        if (tree[level - 1].size() < (insertIdx / 2) + 1)
        {
            cout << -1;
            return 0;
        }
        tree[level].push_back(tmp);
        tree[level - 1][insertIdx / 2]->children.push_back(tmp);
    }

    Inorder(head);

    for (int i = 1; i < N + 1; i++)
    {
        cout << result[i] << " ";
    }
}