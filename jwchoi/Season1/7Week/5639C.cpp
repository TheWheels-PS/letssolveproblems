/*
Questions
1. 채점 시간이 굉장히 오래걸린다. 정상적인 것인가?

2. 이번 코드는 클래스를 써서 만들어봤는데,
스터디 멤버들의 평가를 한 번 받아보고싶다
*/

#include <iostream>

using namespace std;

class Node {
private:
  int data;
  Node *left;
  Node *right;

public:
  Node() {
    data = 0;
    left = NULL;
    right = NULL;
  }

  Node *newNode(Node *pnode, int val) {
    if (pnode == NULL) {
      pnode = new Node();

      pnode->data = val;
      pnode->left = NULL;
      pnode->right = NULL;
    } else if (val <= pnode->data) {
      pnode->left = newNode(pnode->left, val);
    } else {
      pnode->right = newNode(pnode->right, val);
    }

    return pnode;
  }

  void PostOrderTraverse(Node *pnode) {
    if (pnode->left) {
      PostOrderTraverse(pnode->left);
    }
    if (pnode->right) {
      PostOrderTraverse(pnode->right);
    }

    cout << pnode->data << endl;
  }
};

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int val;
  Node *rnode = NULL;

  while (true) {
    cin >> val;

    if (cin.eof())
      break;

    rnode = rnode->newNode(rnode, val);
  }

  rnode->PostOrderTraverse(rnode);

  return 0;
}
