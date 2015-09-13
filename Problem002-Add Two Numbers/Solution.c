/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 16ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
#include<stdlib.h>
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int high=(l1->val+l2->val)/10;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p=head;
    struct ListNode* s;
    head->val = (l1->val+l2->val)%10;
    head->next=NULL;
    l1=l1->next;l2=l2->next;
    while(l1!=NULL || l2!=NULL){
        int a = l1==NULL?0:l1->val;
        int b = l2==NULL?0:l2->val;
       s = (struct ListNode*)malloc(sizeof(struct ListNode));
       s->val = (a+b+high)%10;
       s->next=NULL;
       p->next=s;
       p=s;
       high = (a+b+high)/10;
       l1 = l1==NULL?NULL:l1->next;
       l2 = l2==NULL?NULL:l2->next;
    }
    if(high!=0){
       s = (struct ListNode*)malloc(sizeof(struct ListNode));
       s->val = high;
       s->next=NULL;
       p->next=s;
    }
    return head;
}
