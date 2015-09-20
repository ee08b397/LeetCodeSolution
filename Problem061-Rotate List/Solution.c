/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *p,*s,*t;
    int len=0;
    p=head;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    if(len==0 || k%len==0)return head;
    k = k%len;
    p=head;s=head;
    while(k-- && p!=NULL)p=p->next;
    if(p==NULL)return head;
    while(p->next != NULL){
        s=s->next;
        p=p->next;
    }
    t = s->next;
    s->next=NULL;
    p->next = head;
    return t;
}
