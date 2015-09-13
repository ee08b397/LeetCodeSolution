/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 46ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<stdio.h>
#include<stdlib.h>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int high = (l1->val+l2->val)/10;
       struct ListNode* head = new ListNode((l1->val+l2->val)%10);
       head->next=NULL;
       struct ListNode* p;
       p=head;
       l1=l1->next;l2=l2->next;
       while(l1!=NULL || l2!=NULL){
           int a = l1==NULL?0:l1->val;
           int b = l2==NULL?0:l2->val;
           struct ListNode* s = new ListNode((a+b+high)%10);
           s->next=NULL;
           p->next=s;
           p=s;
           high = (a+b+high)/10;
           l1 = l1==NULL?NULL:l1->next;
           l2 = l2==NULL?NULL:l2->next;
       }
       if(high){
           struct ListNode* s = new ListNode(high);
           s->next=NULL;
           p->next=s;
       }
       return head;
    }
};
