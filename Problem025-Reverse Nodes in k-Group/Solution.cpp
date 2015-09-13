/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 30ms
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *s,*p=(ListNode*)malloc(sizeof(ListNode));
        int len=k;
        p->next=head;head=p;s=p;
        while(k-- && s!=NULL)s=s->next;
        while(s!=NULL){
            reverse(p,s);
            k=len;
            while(k-- && s!=NULL)s=s->next;
        }
        return head->next;
    }
private:
    void reverse(ListNode* &p,ListNode* &s){
        ListNode *tmp,*tail=p->next,*flag=s->next,*l=p->next;
        p->next=NULL;
        while(l!=flag){
            tmp=p->next;
            p->next=l;
            l=l->next;
            p->next->next=tmp;
        }
        tail->next=l;
        p=tail;
        s=tail;
    }
};
