//
// Created by Ha on 16. 1. 2..
//

#include "LinkedList.h"

/*
 * 단일 연결 리스트가 주어졌을때 리스트의 맨 뒤에서 m번째 원소를 찾아내는 알고리즘을 만들어 보라
 * 이때 시간 및 공간 효율을 모두 고려해야 한다. 오류 조건의 처리에 주의하여 알고리즘을 구현하라.
 * 여기에서 "맨 뒤에서 m번째 원소"는 m = 0일 때 리스트의 마지막 원소를 반환하는 식으로 생각한다.
 *
 */


int main() {
    // m 입력
    int m = 9;
    printf("Enter m : ");
    scanf("%d", &m);


    // 길이 10 짜리 리스트 생성
    Node *list = createNode((void *)0);
    int i;
    for(i = 1; i< 10; i++){
        Node *newNode = createNode((void *)i);
        addNode(&list, newNode);
    }

    Node *head = list; // 리스트 head 저장

    // head로 부터 m 만큼 떨어진 곳의 포인터 저장
    Node *mBehind = head;
    for(i = 0; i < m; i ++){
        mBehind = mBehind->next;
    }

    // head와 mBehind 포인터를 동시에 종주시켜 mBehind가 리스트의 끝에 다다를때까지 진행
    // 진행 후 head의 위치는 리스트 뒤에서(마지막에서) m번째 원소가 된다.
    while(mBehind->next != NULL){
        mBehind = mBehind->next;
        head = head->next;
    }

    // 여기서 head 의 위치는 마지막에서 m번째 원소
    printf("mBehind : %d\n", head->data);


    return 0;
}