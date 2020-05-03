//
// Created by yuyunhao on 2020/5/3.
//

#ifndef SEQLIST_SEQLIST_H
#define SEQLIST_SEQLIST_H

#include <stdio.h>
#include <assert.h>


#define SQLLIST_INI_SIZE 10
#define INC_SIZE 3
typedef int ElemType;

typedef struct SeqList{
    ElemType *base;
    int capacity;
    int size;
}SeqList;

void InitSeqList(SeqList *list);

void push_back(SeqList *list,ElemType x);
void show_list(SeqList *list);
void push_front(SeqList *list,ElemType x);
void pop_back(SeqList *list);
void pop_front(SeqList *list);
void insert_pos(SeqList *list,int pos, ElemType x);
int find(SeqList *list, ElemType x);
int length(SeqList *list);
void delete_pos(SeqList *list, int pos);
void delete_val(SeqList *list, ElemType item);
void sort(SeqList *list);
void reverse(SeqList *list);
void clear(SeqList *list);
void destroy(SeqList *list);
bool resize(SeqList *list);
void merge(SeqList *targetList, SeqList *list1, SeqList *list2);

#endif //SEQLIST_SEQLIST_H
