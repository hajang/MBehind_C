//
// Created by Ha on 16. 1. 1..
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    struct Node *next;
    void *data;
}Node;

// 구조체, 메모리 할당 후 Node * 반환
Node *createNode(void *data){
    struct Node *node = (Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// list 제일 앞에 node를 추가
void addNode(Node **head, Node *node){
    node->next = *head;
    *head = node;
}

// data를 지니는 첫번째 node를 list에서 검색
// 반환된 node를 검사하여 null인 경우는 찾지 못한 경우임
Node *findNode(Node* list, void *data){
    Node *node = list;

    // 리스트 끝까지 끝이 아니거나 data를 아직 못찾았을 경우
    while(node != NULL && node->data != data){
        node = node->next;
    }

    return node;
}

// list에서 node를 찾은 뒤 앞 뒤 연결
bool deleteNode(Node *head, Node *node) {
//    1. node 앞의 노드를 찾음
//    2. node 앞의 노드와 node 뒤의 노드를 연결(preNode->next = node->next)
//    3. node 메모리 반환
//
//    예외) 리스트에 원소가 한개이거나 리스트가 비어있는 경우

    if (head == NULL || head->next == NULL){
        if (node == head) { // 삭제하려는 node가 head인 경우
            head = NULL;
            free(node);
            return true;
        }
        else // node가 리스트에 존재하지 않음
            return false;
    }


    Node *preNode1 = head, *preNode2 = head->next;

    // 리스트의 종주, node를 찾을때까지
    while(preNode2 != NULL && preNode2 != node){
        preNode1 = preNode2;
        preNode2 = preNode2->next;
    }

    // 리스트에서 node를 찾지 못한 경우
    if(preNode2 == NULL)
        return false;

    // 리스트에서 node를 찾음 - 이 경우 preNode1이 node 앞의 노드가 된다
    preNode1->next = node->next;
    free(node);
    return true;
}

// currentNode 뒤에 newNode를 삽입
// currentNode 자체가 null인 경우 오류
bool insertNodeAfter(Node *currentNode, Node *newNode){
    if(currentNode) {
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        return true;
    }
    else
        return false;
}


// list 내용을 모두 출력
void printList(Node *list){
    Node *node = list;

    while(node != NULL){
        printf("%d - ", node->data);
        node = node->next;
    }
    printf("\n");
}


#endif //LINKEDLIST_LINKEDLIST_H
