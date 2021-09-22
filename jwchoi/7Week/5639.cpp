
/*
EOF에 대한 이해가 필요

문제에서 제공하는 예시들만 만족하면 되는 것이 아니라, 임의의 전위 순회
결과값들을 전부 입력했을 때, 모든 경우에 해당이 되어야 함


*/

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left = NULL;
  Node *right = NULL;
};

Node *newnode(Node *node, int val) {
  if (node == NULL) {
    node = new Node();
    node->data = val;
    node->left = node->right = NULL;

    /*
    node->left = NULL;
    node->right = NULL;
    동일한 연산
    */
  } else if (val <= node->data)
    node->left = newnode(node->left, val);
  else
    node->right = newnode(node->right, val);

  return node;
}

void PostOrderTravserse(Node *pnode) {
  if (pnode->left) {
    PostOrderTravserse(pnode->left);
  }

  if (pnode->right) {
    PostOrderTravserse(pnode->right);
  }

  cout << pnode->data << endl;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int val;
  Node *rnode = NULL;

  while (true) {
    cin >> val;

    if (cin.eof())
      break;

    rnode = newnode(rnode, val);
  }

  PostOrderTravserse(rnode);

  return 0;
}
