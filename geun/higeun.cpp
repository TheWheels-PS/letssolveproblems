#include <stdio.h>
#include <stdlib.h>

const int ANS_LEN = 100; // 가능한 경로에 대해 블랙노드의 개수를 담을 배열 크기 상수

typedef struct node
{
    struct node *parent;
    struct node *left;
    struct node *right;
    int data;
    int color;
} node;

typedef struct rbtree
{
    node *root;
    node *NIL;
} rbtree;

node *new_node(int data)
{
    node *n = (node*) malloc(sizeof(node));

    n->parent = NULL;
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    n->color = 1;

    return n;
}

rbtree *new_rbtree()
{
    rbtree *t = (rbtree*)malloc(sizeof(rbtree));
    node *nil_node = (node*)malloc(sizeof(node));

    nil_node->parent = NULL;
    nil_node->left = NULL;
    nil_node->right = NULL;
    nil_node->data = 0;
    nil_node->color = 0;
    t->NIL = nil_node;
    t->root = t->NIL;

    return t;
}

void left_rotation(rbtree *t, node *x)
{
    // x의 오른쪽 자식 노드 y 선언
    node *y = x->right;

    // y의 왼쪽 자식 노드를 x의 오른쪽 자식 노드로 변경
    x->right = y->left;

    // y의 왼쪽 자식 노드가 NIL 노드가 아니면 y의 왼쪽 자식 노드의 부모 노드를 x로 변경
    if (y->left != t->NIL)
        y->left->parent = x;

    // y의 부모 노드를 x의 부모 노드로 변경
    y->parent = x->parent;

    // x의 부모 노드가 NIL 노드이면 트리의 루트 노드를 y로 변경
    if (x->parent == t->NIL)
        t->root = y;
    // x가 부모 노드의 왼쪽 자식 노드이면 x의 부모 노드의 왼쪽 자식 노드를 y로 변경
    else if (x == x->parent->left)
        x->parent->left = y;
    // x가 부모 노드의 오른쪽 자식 노드이면 x의 부모 노드의 오른쪽 자식 노드를 y로 변경
    else
        x->parent->right = y;

    // y의 왼쪽 자식 노드를 x로 변경
    y->left = x;
    // x의 부모 노드를 y로 변경
    x->parent = y;
}

void right_rotation(rbtree *t, node *x)
{
    // x의 왼쪽 자식 노드 y 선언
    node *y = x->left;

    // y의 오른쪽 자식 노드를 x의 왼쪽 자식 노드로 변경
    x->left = y->right;

    // y의 오른쪽 자식 노드가 NIL 노드가 아니면 y의 오른쪽 자식 노드의 부모 노드를 x로 변경
    if (y->right != t->NIL)
        y->right->parent = x;

    // y의 부모 노드를 x의 부모 노드로 변경
    y->parent = x->parent;

    // x의 부모 노드가 NIL 노드이면 트리의 루트 노드를 y로 변경
    if (x->parent == t->NIL)
        t->root = y;
    // x가 x의 부모 노드의 왼쪽 자식 노드이면 x의 부모 노드의 왼쪽 자식 노드를 y로 변경
    else if (x == x->parent->left)
        x->parent->left = y;
    // x가 x의 부모 노드의 오른쪽 자식 노드이면 x의 부모 노드의 오른쪽 자식 노드를 y로 변경
    else
        x->parent->right = y;

    // y의 오른쪽 자식 노드를 x로 변경
    y->right = x;
    // x의 부모 노드를 y로 변경
    x->parent = y;
}

void insertion_fixup(rbtree *t, node *z)
{
    // z의 부모 노드가 붉은 노드인 경우
    while (z->parent->color == 1)
    {
        // z의 부모 노드가 왼쪽 자식 노드인 경우
        if (z->parent == z->parent->parent->left)
        {
            // z의 오른쫀 삼촌 노드 y 선언
            node *y = z->parent->parent->right;

            // 삼촌 노드 y가 붉은 노드인 경우
            if (y->color == 1)
            {
                // z의 부모 노드를 검은 노드로 변환
                z->parent->color = 0;
                // z의 삼촌 노드 y를 검은 노드로 변환
                y->color = 0;
                // z의 조부모 노드를 붉은 노드로 변환
                z->parent->parent->color = 1;
                // z를 z의 조부모 노드로 변경
                z = z->parent->parent;
            }
            else
            {
                // z가 부모 노드의 오른쪽 자식인 경우
                if (z == z->parent->right)
                {
                    // z에 z의 부모 노드 저장
                    z = z->parent;
                    // 레프트 로테이션 실행
                    left_rotation(t, z);
                }
                // z의 부모 노드를 검은 노드로 변환
                z->parent->color = 0;
                // z의 조부모 노드를 붉은 노드로 변환
                z->parent->parent->color = 1;
                // 라이트 로테이션 실행
                right_rotation(t, z->parent->parent);
            }
        }
        // z의 부모 노드가 오른쪽 자식 노드인 경우
        else
        {
            // z의 왼쪽 삼촌 노드 y 선언
            node *y = z->parent->parent->left;

            if (y->color == 1)
            {
                // z의 부모 노드를 검은 노드로 변환
                z->parent->color = 0;
                // z의 삼촌 노드 y를 검은 노드로 변환
                y->color = 0;
                // z의 조부모 노드를 붉은 노드로 변환
                z->parent->parent->color = 1;
                // z를 z의 조부모 노드로 변경
                z = z->parent->parent;
            }
            else
            {
                // z가 부모 노드의 왼쪽 자식 노드인 경우
                if (z == z->parent->left)
                {
                    // z에 z의 부모 노드 저장
                    z = z->parent;
                    // 라이트 로테이션
                    right_rotation(t, z);
                }
                // z의 부모 노드를 검은 노드로 변환
                z->parent->color = 0;
                // z의 조부모 노드를 붉으 노드로 변환
                z->parent->parent->color = 1;
                // 레프트 로테이션 실행
                left_rotation(t, z->parent->parent);
            }
        }
    }
    // 트리의 루트 노드롤 검은 노드로 변환
    t->root->color = 0;
}

void insertion(rbtree *t, node *z)
{
    // 트리의 NIL인 노드 y 선언
    node *y = t->NIL;
    // 트리의 루트 노드 temp 선언
    node *temp = t->root;

    // temp가 트리의 NIL이 아니면 반복문 실행
    while (temp != t->NIL)
    {
        // y는 temp를 저장
        y = temp;
        // z의 data가 temp의 data보다 작으면 temp에 temp의 왼쪽 자식 노드 저장
        if (z->data < temp->data)
            temp = temp->left;
        // z의 data가 temp의 data보다 크면 temp에 temp의 오른쪽 자식 노드 저장
        else
            temp = temp->right;
    }

    // z의 부모 노드를 y로 변경
    z->parent = y;

    // y는 트리의 NIL이면 트리의 루트 노드를 z로 변경
    if (y == t->NIL)
        t->root = z;
    // z의 data가 y의 data보다 작으면 y의 왼쪽 자식 노드를 z로 변경
    else if (z->data < y->data)
        y->left = z;
    // z의 data가 y의 data보다 크면 y의 오른쪽 자식 노드를 z로 변경
    else
        y->right = z;

    // z의 왼쪽 자식 노드를 트리의 NIL로 변경
    z->left = t->NIL;
    // z의 오른쪽 자식 노드를 트리의 NIL로 변경
    z->right = t->NIL;
    // z의 색깔을 빨강으로 변경
    z->color = 1;

    insertion_fixup(t, z);
}

void inorder(rbtree *t, node *n)
{
    // 노드 n이 트리의 NIL이 아니면 n의 왼쪽 자식 노드를 출력 후 오른쪽 자식 노드를 출력
    if (n != t->NIL)
    {
        inorder(t, n->left);
        printf("%d \n", n->data);
        inorder(t, n->right);
    }
}
void get_height(node * now, int * answer, int * ans_cnt, int height){
	if(now == NULL){
		answer[(*ans_cnt)++] = height;
		return;
	}
	
	if(now->color == 0) height += 1;
	get_height(now->left, answer, ans_cnt, height)	;
	get_height(now->right, answer, ans_cnt, height)	;
}

int main()
{
    // 새로운 레드-블랙 트리 생성
    rbtree *t = new_rbtree();

    node *a, *b, *c, *d, *e, *f;

    a = new_node(30);
    b = new_node(20);
    c = new_node(10);
    d = new_node(40);
    e = new_node(50);
    f = new_node(60);


    insertion(t, a);
    insertion(t, b);
    insertion(t, c);
    insertion(t, d);
    insertion(t, e);
    insertion(t, f);

    inorder(t, t->root);
	
	int answer[ANS_LEN];
	int ans_cnt = 0; // 가능한 경로에 대해 블랙노드의 개수를 담을 배열 크기 변수
	get_height(t->root, answer, &ans_cnt, 0);
	for(int i = 0; i < ans_cnt; i++){
		printf("%d ", answer[i]);
	}	
	printf("\n");
    return 0;
}
