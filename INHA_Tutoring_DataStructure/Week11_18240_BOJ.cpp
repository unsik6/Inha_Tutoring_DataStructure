/* ���� 18240�� ���� Ž�� Ʈ�� �����ϱ�
*
* Input: ������ ���� N (2 <= N <= 300,000)
*		 A_2���� A_N���� ������� ������ ������ ���Ե� ����� ���̰� �������� �����Ͽ� �־���.
*		 �̶� ����� ���̴� 1�̻� N �̸��� �ڿ����̴�.
*
* Output: ������ ������ �ִٸ� ù° �ٿ� A_1..A_N�� ���� �������� �����Ͽ� ��� (����� ����)
*		  ������ ������ ������ -1 ���
*
* ����� �����̹Ƿ� ���¿� ������ �ʿ䰡 ����.
* ������ ������ ����� �� ������ ���ʺ��� ä�� ���¶�� �����ϸ� ����.
* ���� 1�� 1�� �ۿ� ���µ� 2�� 3�� �̻� ���´ٰų�
* 1�� 2���ε� 2�� 5�� �̻� ���´ٸ� �ƿ� �Ұ����ϴ�.
* �� ������ ����� �ʴ�. �ٸ�, ��ȣ�� �ű�� ������ ��Ʊ� ������
* �츮�� BST�� ���� ��ȸ�� �ϸ� ������������ �������� �̿��Ѵ�.
* 
* 
* �ִ� ���̴� n-1�̴�.
* �迭�� ���� ��� �ſ� ū �迭�� �ʿ��ϴ�. ���� ���� ������ ���, 2^29999 - 1 ���� �迭�� �ʿ��ϰ� �ȴ�.
* �迭�� BST�� ����� ���� ���� ���ϴ�.
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
        // ���� �ڽ� ����
        Inorder(_root->children[0]);
    }
    result[_root->index] = idx++;
    if (_root->children.size() > 1) {
        // ������ �ڽ� ����
        Inorder(_root->children[1]);
    }
}

int main() {
    // ����� ����(depth)�� 2^depth�� ��ŭ�� ���� �� �ִ�

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