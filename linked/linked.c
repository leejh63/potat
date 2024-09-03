#include <stdio.h>
#include <stdlib.h>

// 구조체  struct
typedef struct Node{
    int key;
    int data;
    struct Node *next;
} node;

// 노드 생성
node* createNode(int data, int key)
{
    node *newnode = (node *)malloc(sizeof(node));
    //
    newnode -> key = key;
    newnode -> data = data;
    // newnode.next = NULL; < 이것은 newnode가 포인터가 아닌 구조체여야한다.
    newnode -> next = NULL;
    return newnode;
}

//생성노드 연결

void appnode(node**head, int data, int key)
{
    node *newnode = createNode(data, key);
    if (*head == NULL){
        *head = newnode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
// key값 으로 특정 노드 찾기
void findkey(node*head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            printf("key = %d, data = %d, address = %p\n", temp->key, temp->data, temp);
            return;
        }
        temp = temp->next;
    }
    printf("없는듯\n");
}

void alldel(node*head)
{
    node *temp;
    while ( head != NULL )
    {
        temp = head;
        head = head->next;
        printf("key %d 삭제\n", temp->key);
        free(temp);
    }
}

void delkey(node**head, int key)
{
    node *temp = *head;
    node *prev = NULL;

    if (temp != NULL && temp->key == key )
    {
        *head = temp->next;
        printf("wantdel:%d  key = %d, data = %d, address = %p\n",key , temp->key, temp->data, temp);
        free(temp);
        return;
    }

    // 순서 중요하다 만약 temp가 null이면 
    // 앞서나온 temp->key != key에서 에러 발생한다.
    // 주의 할것
//  while (temp->key != key && temp != NULL)  기존 
    while (temp != NULL && temp->key != key) 
    {   
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL)
    {
        printf("we dont have key %d\n", key);
        return;
    }

    prev->next = temp->next;
    printf("wantdel:%d  key = %d, data = %d, address = %p\n",key , temp->key, temp->data, temp);
    free(temp);
}

int main(void)
{
    node *head = NULL;
    int numkey, endfor, dkey;

    printf("몇개 생성?.\n");
    scanf("%d", &endfor);

    for (int i = 1; i <= endfor; i++)
    {
        appnode(&head, i*10, i);
    }

    dkey = 1;
    while (dkey != -1)
    {   
        printf("삭제할 키를 입력하시오.\n");
        scanf("%d", &dkey);
        if (dkey == -1)
        {
            break;
        }
        delkey(&head, dkey);
    }

    numkey = 1;
    while (numkey != -1)
    {
        printf("찾을 키를 입력하시오.\n");
        scanf("%d", &numkey);
        if (numkey == -1)
        {
            break;
        }
        findkey(head, numkey);
    }

    alldel(head);

    return 0;
}