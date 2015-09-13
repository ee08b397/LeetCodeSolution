/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 9ms
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p,*s;
        p=new ListNode(0);
        p->next=head;
        head=p;
        while(p->next!=NULL && p->next->next!=NULL){
            s=p->next->next;
            p->next->next=s->next;
            s->next=p->next;
            p->next=s;
            p=s->next;
        }
        return head->next;
    }
};
