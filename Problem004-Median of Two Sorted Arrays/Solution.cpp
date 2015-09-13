/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 77ms
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size(),size2=nums2.size();
        if((size1+size2)%2){
            return findKth(nums1,nums2,(size1+size2+1)/2);
        }else{
            return (1.0*findKth(nums1,nums2,(size1+size2+1)/2)+findKth(nums1,nums2,(size1+size2+1)/2+1))/2;
        }
    }
private:
    int findKth(vector<int> a,vector<int> b,int k){
        int len1=a.size();
        int len2=b.size();
        if(len1==0)return b[k-1];
        if(len2==0)return a[k-1];
        if(k==1)return min(a[0],b[0]);
        int mid1 = min(k/2,len1);
        int mid2 = min(k/2,len2);
        if(a[mid1-1] < b[mid2-1]){
            a.erase(a.begin(),a.begin()+mid1);
            return findKth(a,b,k-mid1);
        }else{
            b.erase(b.begin(),b.begin()+mid2);
            return findKth(a,b,k-mid2);
        }
    }
    int min(int a,int b){
        return a>b?b:a;
    }
};
