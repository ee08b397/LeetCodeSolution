/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 419ms
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len=lists.size();
        if(len==0)return NULL;
        else if(len==1)return lists[0];
        WinnerTree=(int*)malloc(sizeof(int)*len);
        initTree(lists,len);
        if(lists[WinnerTree[1]]==NULL)return NULL;
        ListNode *p,*head;
        p=lists[WinnerTree[1]];
        lists[WinnerTree[1]]=lists[WinnerTree[1]]->next;
        head=p;
        adjustToRoot(lists,(WinnerTree[1]+len)/2,len);
        while(lists[WinnerTree[1]]!=NULL){
            p->next=lists[WinnerTree[1]];
            lists[WinnerTree[1]]=lists[WinnerTree[1]]->next;
            p=p->next;
            adjustToRoot(lists,(WinnerTree[1]+len)/2,len);
        }
        return head;
    }
private:
    int *WinnerTree;
    void initTree(vector<ListNode*>& lists,int len){
        for(int i=len-1;i>=1;i--){
            adjustWinnerTree(lists,i,len);
        }
    }
    void adjustToRoot(vector<ListNode*>& lists,int tar,int len){
        while(tar>0){
            adjustWinnerTree(lists,tar,len);
            tar=tar/2;
        }
    }
    void adjustWinnerTree(vector<ListNode*>& lists,int i,int len){
        int l,r;
        if(i+i < len){
            l=WinnerTree[i+i];
        }else{
            l=i+i-len;
        }
        if(i+i+1 < len){
            r=WinnerTree[i+i+1];
        }else{
            r=i+i+1-len;
        }
        if(lists[l]==NULL)WinnerTree[i]=r;
        else if(lists[r]==NULL)WinnerTree[i]=l;
        else WinnerTree[i]= lists[l]->val > lists[r]->val ?r:l;
    }
};
