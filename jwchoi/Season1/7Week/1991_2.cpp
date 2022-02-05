#include <iostream>

using namespace std;

class Node {
private:
  char data;
  Node *left;
  Node *right;

public:
  Node() {
    data = ' ';
    left = NULL;
    right = NULL;
  }

  void SetData(char pdata) { this->data = pdata; }

  void SetLeft(Node *pleft) { this->left = pleft; }

  void SetRight(Node *pright) { this->right = pright; }

  void PreOrderTraverse(Node *rnode) {
    cout << rnode->data;

    if (rnode->left)
      PreOrderTraverse(rnode->left);

    if (rnode->right)
      PreOrderTraverse(rnode->right);
  }

  void InOrderTraverse(Node *rnode) {
    if (rnode->left)
      InOrderTraverse(rnode->left);

    cout << rnode->data;

    if (rnode->right)
      InOrderTraverse(rnode->right);
  }

  void PostOrderTraverse(Node *rnode) {
    if (rnode->left)
      PostOrderTraverse(rnode->left);

    if (rnode->right)
      PostOrderTraverse(rnode->right);

    cout << rnode->data;
  }
};

int main(void) {
  int N, idx;
  char P, L, R;

  cin >> N;

  Node *nodes = (Node *)malloc(sizeof(Node) * N);

  for (int i = 0; i < N; ++i) {
    cin >> P >> L >> R;

    idx = P - 'A';

    nodes[idx].SetData(P);

    if (L == '.')
      nodes[idx].SetLeft(NULL);
    else
      nodes[idx].SetLeft(&nodes[L - 'A']);

    if (R == '.')
      nodes[idx].SetRight(NULL);
    else
      nodes[idx].SetRight(&nodes[R - 'A']);
  }

  nodes->PreOrderTraverse(nodes);

  cout << endl;

  nodes->InOrderTraverse(nodes);

  cout << endl;

  nodes->PostOrderTraverse(nodes);

  return 0;
}
