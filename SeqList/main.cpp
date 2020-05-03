#include <iostream>
#include "SeqList.h"

/*
int main() {
    SeqList list1, list2, list;
    InitSeqList(&list1);
    InitSeqList(&list2);
    push_back(&list1,1);
    push_back(&list1,3);
    push_back(&list1,5);
    push_back(&list1,7);
    push_back(&list1,9);

    push_back(&list2, 2);
    push_back(&list2, 4);
    push_back(&list2, 6);
    push_back(&list2, 8);
    push_back(&list2, 10);
    push_back(&list2, 12);
    push_back(&list2, 14);

    // 合并2个顺序表
    merge(&list,&list1,&list2);

    for(int i = 0; i < list.size; i++) {
        printf("%d", list.base[i]);
        printf(" ");
    }
    printf("\n");

    return 0;
}
*/


int main() {
    SeqList mylist;
    InitSeqList(&mylist);

    ElemType item;
    int pos;
    int select = 1;
    while (select) {
        printf("******************************************\n");
        printf("* [1] push_back       [2] push_front     *\n");
        printf("* [3] show_list       [4] pop_back       *\n");
        printf("* [5] pop_front       [6] insert_pos     *\n");
        printf("* [7] find            [8] length         *\n");
        printf("* [9] delete_pos      [10] delete_val    *\n");
        printf("* [11] sort           [12] reverse       *\n");
        printf("* [13] clear          [14] destroy       *\n");
        printf("* [0] quit_system                        *\n");
        printf("******************************************\n");
        printf("请选择:>");
        scanf("%d",&select);
        if (select == 0) {
            break;
        }

        switch (select) {
            case 1:
                printf("请输入要插入的数据(以-1结束): ");
                while (scanf("%d",&item), item != -1) {
                    push_back(&mylist,item);
                }
                break;
            case 2:
                printf("请输入要插入的数据(以-1结束): ");
                while (scanf("%d",&item),item != -1) {
                    push_front(&mylist,item);
                }
                break;
            case 3:
                printf("显示数据: ");
                show_list(&mylist);
                break;
            case 4:
                pop_back(&mylist);
                break;
            case 5:
                pop_front(&mylist);
                break;

            case 6:
                printf("请输入要插入的位置: ");
                scanf("%d", &pos);
                printf("请输入要插入的数据: ");
                scanf("%d", &item);
                insert_pos(&mylist,pos,item);
                break;
            case 7:
                printf("请输入要查找的数据: ");
                scanf("%d", &item);
                pos = find(&mylist,item);
                if(pos == -1) {
                    printf("要查找的数据%d在顺序表中不存在\n",item);
                } else {
                    printf("要查找的数据 %d 在顺序表中的下标为 %d \n",item,pos);
                }
                break;

             case 8:
                 printf("顺序表的长度为 %d \n",length(&mylist));
                 break;

            case 9:
                printf("请输入要删除的位置: ");
                scanf("%d", &pos);
                delete_pos(&mylist,pos);
                break;
            case 10:
                printf("请输入要删除的数据: ");
                scanf("%d", &item);
                delete_val(&mylist,item);
                break;

            case 11:
                sort(&mylist);
                break;

            case 12:
                reverse(&mylist);
                break;
            case 13:
                clear(&mylist);
                break;
            default:
                printf("输入的数据有误，请重新输入\n");
                break;
        }
    }


    return 0;
}


