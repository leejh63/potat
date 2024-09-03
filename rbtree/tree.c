#include "rbtree.h"
#include <stdio.h>
#include <stdlib.h>

// 트리 구조체 생성 함수
rbtree *new_rbtree(void) {
  // 1.  rbtree구조체 생성/ root포인터, nil포인터 포함됨
  rbtree *tree = (rbtree *)calloc(1, sizeof(rbtree));

  // 2. sentinel 노드 생성
  node_t *nilnode = (node_t *)calloc(1, sizeof(node_t));

  // 3. sentinel 노드초기화
  nilnode->color = 1;
  nilnode->key = -1;
  nilnode->parent = NULL;
  nilnode->left = NULL;
  nilnode->right = NULL;

  // 4. 닐노드 포인터 지정
  tree->nil = nilnode;
  // 초기 루트노드는 닐노드임.
  tree->root = tree->nil;

//   tree->root = nilnode; 큰 차이는 없지만 때에 따라서 차이발생 할 수 있음.
  return tree;
}

// 모든 rbtree 삭제
// 후위 순회를 통해 트리삭제 진행 
void deltree(rbtree *tree, node_t *node)
{
    if (node != tree->nil)
    {
        deltree(tree, node->right);
        deltree(tree, node->left);
        free(node);
    }
    
}

void delete_rbtree(rbtree *t) 
{
  // 만약 루트 노드가 닐노드가 아니라면 트리가 존재 
  if (t->root != t->nil)
  {
      deltree(t, t->root);
  }
  
  free(t->nil);
  free(t);

}

// 왼쪽 회전 nil, root 주소 받기 위함, 로테이션을 위한 노드 주소
void Lrot(rbtree *tree, node_t*node)
{
    //현재 노드 오른쪽주소 값 변수
    node_t *nowright = node->right;

    // 오른쪽 노드의 왼쪽 노드를 현재노드의 오른쪽과 연결
    node->right = nowright->left;

    // 이때 nowright->left가 nill노드 > 신경 x
    // nill이 아닐경우 nowright->left의 부모는 현재 노드
    if (node->right != tree->nil)
    {
        nowright->left->parent = node;
    }
    // 노드들의 부모를 변경
    nowright->parent = node->parent;
    // 현재 노드의 부모의 경우 3가지 경우존재
    
    // 현재 노드부모가 nill
    if (node->parent == tree->nil)
    {// 오른쪽 노드가 root
        tree->root = nowright;

    // 현재 노드가 왼쪽 자식
    } else if (node == node->parent->left){
        //오른쪽 노드가 부모의 왼쪽자식
        node->parent->left = nowright;

    //현재 노드가 오른쪽 자식
    } else { 
        //오른쪽 노드가 부모의 오른쪽 자식
        node->parent->right = nowright;
    }
    nowright->left = node;
    node->parent = nowright;
}

void Rrot(rbtree *tree, node_t *node)
{
    node_t *nowleft = node->left;
    node->left = nowleft->right;

    if (nowleft->right != tree->nil){
        nowleft->right->parent = node;
    }

    nowleft->parent = node->parent;

    if (node->parent == tree->nil){
        tree->root = nowleft;

    }else if (node == node->parent->left){
        node->parent->left = nowleft;

    }else{
        node->parent->right = nowleft;
    }
    nowleft->right = node;
    node->parent = nowleft;
}

void insertfix(rbtree* tree, node_t* newnode)
{
    node_t *uncle;
    // newnode의 부모가 빨간색일 경우 진행
    while(newnode->parent->color == 0)
    {
        //부모가 조부모 왼쪽자식
        if (newnode->parent == newnode->parent->parent->left)
        {// 부모가 왼쪽 이므로 삼촌은 오른쪽이다.
            uncle = newnode->parent->parent->right;
            //1. uncle의 color = 0 (red)
            if (uncle->color == 0)
            {// 부모, 삼촌 color  0 > 1, 조부모 color 1 > 0
                newnode->parent->color = 1;
                uncle->color = 1;
                newnode->parent->parent->color = 0;
                // 색 변경 후 newnode중 red로 변경된 노드가 조건을 벗어나는지 확인해야한다.
                newnode = newnode->parent->parent;
                // 최악의 경우 루트 노드까지올라가게 되며
                // 이경우 while끝난 후 루트노드의 색깔을 검정으로 바꿔주면 해결된다.
            }else {// 2. uncle의 color = 1 (black), 내가 부모의 오른쪽 자식일경우
                if (newnode == newnode->parent->right)
                {// 부모를 기준으로 왼쪽 로테이션 시켜서 3. 형태로 만들어준다.
                    newnode = newnode->parent;
                    Lrot(tree, newnode);
                }// 3. uncle의 color = 1 (black), 내가 부모의 왼쪽 자식일경우
                //먼저 부모 0 > 1, 조부모 1 > 0의 색깔변경 위치이동후 색깔변경 귀찮아짐
                newnode->parent->color = 1;
                newnode->parent->parent->color = 0;
                // 조부모 기준 오른쪽 로테이션 진행
                Rrot(tree, newnode->parent->parent);
            }
        } else{// 부모가 할아버지 오른쪽자식의 경우 왼쪽과 로직 동일, 좌우만 변경
            uncle = newnode->parent->parent->left;
            //1
            if (uncle->color == 0)
            {
                newnode->parent->color = 1;
                uncle->color = 1;
                newnode->parent->parent->color = 0;
                newnode = newnode->parent->parent;
            }else {//2
                if (newnode == newnode->parent->left)
                {
                    newnode = newnode->parent;
                    Rrot(tree, newnode);
                }
                newnode->parent->color = 1;
                newnode->parent->parent->color = 0;
                Lrot(tree, newnode->parent->parent);
            }
        }
    }
    //루트 색깔 변경 잊지말자.
    tree->root->color = 1;
}

void insertnode(rbtree* tree, const key_t newkey)
{
    node_t *newnode = (node_t *)calloc(1, sizeof(node_t));
    newnode->color = 0;
    newnode->key = newkey;
    newnode->right = tree->nil;
    newnode->left = tree->nil;

    node_t *nownode = tree->root;
    // 만약 rbtree가 비어있다면 새로 만든 노드는 루트노드가 된다. 
    if (nownode == tree->nil){
        tree->root = newnode;
        newnode->parent = tree->nil;
        // 루트 노드는 항상 검은색이여야 한다!
        newnode->color = 1;
        return;
    }
    // rbtree에 노드 존재
    // nil 노드에 도달할때까지
    node_t *nowparent;
    while (nownode != tree->nil)
    {// 다음노드의 부모노드가 될 현재 노드 저장
        nowparent = nownode;

        // 만약 현재 노드의 key값이 새로운 노드의 key값보다 크거나 작다면
        if ( nownode->key >= newkey)
        {// 현재노드의 왼쪽노드로 넘어가라
            nownode = nownode->left;
        } else{// 현재노드의 오른쪽노드로 넘어가라
            nownode = nownode->right;
        }
    }

    // while 문이 깨지면 현재노드 nil노드에 도달 따라서 새로운 노드의 부모노드 갱신
    newnode->parent = nowparent;
    if (nowparent->key >= newkey){
        nowparent->left = newnode;
    }else{
        nowparent->right = newnode;
    }
    insertfix(tree, newnode);
}

//////////////////////////////////////////////////////////////////////////
void print_node_info(node_t *node, node_t *nil) {
    if (node == nil) {
        return;
    }

    printf("--노드 키: %d--색 %d\n", node->key, node->color);
    if (node->parent != nil) {
        printf("부모 키: %d, 색: %d \n", node->parent->key, node->parent->color);
    } else {
        printf("부모: 없음, \n");
    }

    if (node->left != nil) {
        printf("왼쪽 자식 키: %d 색: %d \n", node->left->key, node->left->color);
    } else {
        printf("왼쪽 자식: 없음, \n");
    }

    if (node->right != nil) {
        printf("오른쪽 자식 키: %d, 색: %d \n", node->right->key, node->right->color);
    } else {
        printf("오른쪽 자식: 없음\n");
    }
    printf("\n");
}

// 트리의 모든 노드를 부모, 왼쪽 자식, 오른쪽 자식 순으로 출력하는 함수
void print_tree(rbtree *tree, node_t *node) {
    if (node == tree->nil) {
        return;
    }

    // 현재 노드의 정보를 출력
    print_node_info(node, tree->nil);

    // 왼쪽 서브트리를 순회
    print_tree(tree, node->left);

    // 오른쪽 서브트리를 순회
    print_tree(tree, node->right);
}
////////////////////////////////////////////////////////////////////////

node_t* findkey(rbtree* tree, const key_t findkey)
{
    // 트리의 루트부터 시작
    node_t *nownode = tree->root;
    //1 찾는 키와 현재 노드 키값이 다를 경우 진행
    while (nownode->key != findkey)
    {
        if (nownode == tree->nil){// 닐노드의 키값을 -1로 지정함
            printf("찾는키 없음\n");
            return NULL;
        }

        // 만약 키 값 크다면 현재노드 오른쪽 노드가 다음노드
        if (nownode->key < findkey){
            nownode = nownode->right;
        }else{ // 작다면 왼쪽 노드가 다음노드
            nownode = nownode->left;
        } // 현재노드 키값과 찾는 키값이 같을 때까지 무한반복
    }
    print_node_info(nownode, tree->nil);
    return nownode;
}

node_t *rbmin(const rbtree *t, node_t* nodett) {
//   node_t* nownode = t-> root;
  node_t* nownode = nodett;
  node_t* temp;
  while(nownode != t -> nil){
    temp = nownode;
    nownode = nownode->left;
  }
  return temp;
}

// node_t *rbtree_max(const rbtree *t) {
//   // TODO: implement find
//   return t->root;
// }




int main(void){

    int numkey, keyfind;
    node_t *minnode, *corr;
    rbtree* k = new_rbtree();
    
    printf("트리 생성: 주소 %p, tree->nil %p, tree->root %p\n", k, k->nil, k->root);
    // 노드 삽입


    while (1)
    {
        printf("삽입 키 입력:\n");
        scanf("%d", &numkey);
        if (numkey == -1){
            break;
        }
        insertnode(k, numkey);
        // printf("트리의 삽입 후 노드 출력:\n");
        // print_tree(k, k->root);
    }

    printf("트리의 모든 노드 출력:\n");
    print_tree(k, k->root);

    // while(1) // 이거 실행전 findkey(k, keyfind) 함수형, 반환값 수정 필수
    // {
    //     printf("찾는 키 입력:\n");
    //     scanf("%d", &keyfind);
    //     if (keyfind == -1){
    //         break;
    //     } 
    //     findkey(k, keyfind);
    // }
    printf("test 키 입력:\n");
    scanf("%d", &keyfind);
    minnode = findkey(k, keyfind);
    corr = rbmin(k, minnode);
    printf("-----------\n");
    print_node_info(corr, k->nil);


    // 트리 삭제
    delete_rbtree(k);
}
