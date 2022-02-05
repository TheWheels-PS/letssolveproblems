#include <iostream>

using namespace std;

struct Node {
  char data;
  Node *left;
  Node *right;
};

void PreorderTraverse(Node *nodes) {
  cout << nodes->data;

  if (nodes->left)
    PreorderTraverse(nodes->left);

  if (nodes->right)
    PreorderTraverse(nodes->right);
}

void InorderTraverse(Node *nodes) {

  if (nodes->left)
    InorderTraverse(nodes->left);

  cout << nodes->data;

  if (nodes->right)
    InorderTraverse(nodes->right);
}

void PostorderTraverse(Node *nodes) {
  if (nodes->left)
    PostorderTraverse(nodes->left);

  if (nodes->right)
    PostorderTraverse(nodes->right);

  cout << nodes->data;
}

int main(void) {
  int N, idx;
  char P, L, R;

  cin >> N;

  Node *nodes = (Node *)malloc(sizeof(Node) * N);

  for (int i = 0; i < N; ++i) {
    cin >> P >> L >> R;

    idx = P - 'A';

    nodes[idx].data = P;

    if (L == '.')
      nodes[idx].left = NULL;
    else
      nodes[idx].left = &nodes[L - 'A'];

    if (R == '.')
      nodes[idx].right = NULL;
    else
      nodes[idx].right = &nodes[R - 'A'];
  }

  PreorderTraverse(nodes);

  cout << endl;

  InorderTraverse(nodes);

  cout << endl;

  PostorderTraverse(nodes);

  return 0;
}
