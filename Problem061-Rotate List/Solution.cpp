/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 12ms
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        ListNode *p=head,*s,*t;
        while(p!=NULL){
            p=p->next;
            len++;
        }
        if(len==0 || k%len==0)return head;
        k%=len;
        p=head;s=head;
        while(k-- && p!=NULL)p=p->next;
        while(p->next !=NULL){
            s=s->next;
            p=p->next;
        }
        t=s->next;
        s->next=NULL;
        p->next = head;
        return t;
    }
};
