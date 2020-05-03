//
// Created by yuyunhao on 2020/5/3.
//
#include "SeqList.h"
#include <algorithm>
using namespace std;

void InitSeqList(SeqList *list) {
    list->base = (ElemType *)malloc(sizeof(ElemType)*SQLLIST_INI_SIZE);
    list->capacity = SQLLIST_INI_SIZE;
    list->size = 0;
}

bool resize(SeqList *list) {
    ElemType *newBase = (ElemType *)realloc(list->base,sizeof(ElemType)*(list->capacity+INC_SIZE));
    if(NULL == newBase) {
        printf("空间申请失败，不能插入数据");
        return false;
    }
    list->base = newBase;
    list->capacity += INC_SIZE;
    return true;
}

void push_back(SeqList *list,ElemType x) {
    if(list->size >= list->capacity && !resize(list)) {
        printf("顺序表空间已满，不能尾部插入数据\n");
        return;
    }
    list->base[list->size] = x;
    list->size++;
}

void show_list(SeqList *list) {
    for(int i = 0; i < list->size; ++i){
        printf("%d",list->base[i]);
        printf(" ");
    }
    printf("\n");
}

void push_front(SeqList *list,ElemType x) {
    if(list->size >= list->capacity  && !resize(list)) {
        printf("顺序表空间已满，不能头部插入数据\n");
        return;
    }
    for(int i = list->size; i > 0; i--) {
        list->base[i] = list->base[i-1];
    }
    list->base[0] = x;
    list->size++;
}

void pop_back(SeqList *list){
    if(list->size == 0) {
        printf("顺序表为空，不能删除\n");
        return;
    }
    list->size--;
}

void pop_front(SeqList *list) {
    if(list->size == 0) {
        printf("顺序表为空，不能删除\n");
        return;
    }
    for(int i = 0; i < list->size -1; i++) {
        list->base[i] = list->base[i+1];
    }

    list->size--;
}

void insert_pos(SeqList *list,int pos, ElemType x) {
    if(pos<0 || pos>list->size){
        printf("输入的位置不合法\n");
        return;
    }

    if(list->size>=list->capacity  && !resize(list)) {
        printf("顺序表已满，不能插入\n");
        return;
    }

    for(int i = list->size; i > pos; i--) {
        list->base[i] = list->base[i-1];
    }
    list->base[pos] = x;
    list->size++;
}

int find(SeqList *list, ElemType x) {
    for(int i = 0; i < list->size; i++){
        if(x == list->base[i]) {
            return i;
        }
    }
    return -1;
}

int length(SeqList *list) {
    return list->size;
}

void delete_pos(SeqList *list, int pos) {
    if (pos<0 || pos >= list->size) {
        printf("输入的位置不合法，请重新输入\n");
        return;
    }
    if(list->size == 0) {
        printf("顺序表已为空，不能删除\n");
        return;
    }
    for(int i = pos; i <= list->size -1; i++) {
        list->base[i] = list->base[i+1];
    }
    list->size--;
}

void delete_val(SeqList *list, ElemType item) {
    if(list->size == 0) {
        printf("顺序表已为空，不能删除\n");
        return;
    }
    int index = -1;
    for(int i = 0; i < list->size; i++) {
        if(item == list->base[i]) {
            index = i;
        }
    }

    delete_pos(list,index);
}

void sort(SeqList *list) {
    for(int i = 0; i < list->size; i++) {
        int minIndex = i;
        for(int j = i+1; j< list->size; j++) {
            if(list->base[j] < list->base[minIndex]) {
                minIndex = j;
            }
        }

        swap(list->base[minIndex],list->base[i]);
    }
}

void reverse(SeqList *list) {
    if(list->size == 0 || list->size == 1)
        return;

    ElemType temp;
    int low;
    int height = list->size -1;
    while (low < height) {
        temp = list->base[low];
        list->base[low] = list->base[height];
        list->base[height] = temp;
        low++;
        height--;
    }
}

void clear(SeqList *list) {
    list->size = 0;
}

void destroy(SeqList *list) {
    free(list->base);
    list->base = NULL;
    list->capacity = 0;
    list->size = 0;
}

void merge(SeqList *targetList, SeqList *list1, SeqList *list2) {
    targetList->capacity = list1->size + list2->size;
    ElemType *targetBase = (ElemType *)malloc(sizeof(ElemType) * targetList->capacity);
    assert(NULL != targetBase);
    targetList->base = targetBase;
    targetList->size = list1->size + list2->size;

    int targetIndex = 0;
    int index1 = 0;
    int index2 = 0;
    while (index1 < list1->size && index2 < list2->size) {
        if(list1->base[index1] < list2->base[index2]) {
            targetList->base[targetIndex++] = list1->base[index1++];

        } else {
            targetList->base[targetIndex++] = list2->base[index2++];
        }
    }

    while (index1 < list1->size){
        targetList->base[targetIndex++] = list1->base[index1++];
    }

    while (index2 < list2->size) {
        targetList->base[targetIndex++] = list2->base[index2++];
    }
}