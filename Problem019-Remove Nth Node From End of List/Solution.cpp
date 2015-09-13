/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *s,*p=new ListNode(0);
        s=head;p->next=head;
        while(n-- && s!=NULL)s=s->next;
        while(s!=NULL){
            s=s->next;
            p=p->next;
        }
        if(p->next==head){
            head=head->next;
        }else{
            p->next=p->next->next;
        }
        return head;
    }
};
