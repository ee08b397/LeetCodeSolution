/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 17ms
 */

int min(int a,int b){
	return a>b?b:a;
}
int findKth(int *a,int len1,int* b,int len2,int k){
    int mid1,mid2;
    if(len1==0)return b[k-1];
    if(len2==0)return a[k-1];
	if(k==1){
		return a[0]<b[0]?a[0]:b[0];
	}
    mid1 = min(k/2,len1);
    mid2 = min(k/2,len2);
    if(a[mid1-1]<b[mid2-1]){
        findKth(a+mid1,len1-mid1,b,len2,k-mid1);
    }else{
        findKth(a,len1,b+mid2,len2-mid2,k-mid2);
    }
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int k=nums1Size+nums2Size;
    if(k%2==1){
        return findKth(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size+1)/2);
    }else{
        return (findKth(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size+1)/2) + findKth(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size+1)/2+1)*1.0)/2;
    }
}
