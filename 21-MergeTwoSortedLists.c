// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=problem-list-v2&envId=0ac4eqo2
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
        int val;
        struct ListNode* next;
    }L;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
int main(){
    int arr1[3]={1,2,4};
    int arr2[3] ={1,3,4};
    
    // 錯誤的
    // L* list1 = &arr1;
    // L* list2 = &arr2;
    L dummy = {0, NULL};
    L *list1 = &dummy;
    for(int i=0; i<3; i++){
        L* a1 = malloc(sizeof(L));
        a1 ->val = arr1[i];
        a1 ->next=NULL;
        list1->next = a1;
        list1 = list1->next;
    }
    L dummy2 = {0, NULL};
    L *list2 = &dummy2;
    for(int i=0; i<3; i++){
        L* a2 = malloc(sizeof(L));
        a2 ->val = arr2[i];
        a2 ->next=NULL;
        list2->next = a2;
        list2 = list2->next;
    }

    L* ans = mergeTwoLists(dummy.next, dummy2.next);
    // 印出：移動的是 p
    for (L* p = ans; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }

    // 釋放：ans 還在開頭
    while (ans != NULL) {
        L* temp = ans;
        ans = ans->next;
        free(temp);
    }
    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode* head = &dummy;
    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            head->next = list1;
            list1 = list1->next;
            head = head->next;
        }
        else{
            head->next = list2;
            list2=list2->next;
            head = head->next;
        }
    }
    head->next = (list1 != NULL)? list1:list2;
return dummy.next;
}

