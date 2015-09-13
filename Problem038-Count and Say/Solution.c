/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
char* countAndSay(int n) {
    char* seq=(char*)malloc(sizeof(char)*100000);
    char* bak=(char*)malloc(sizeof(char)*100000);
    char* tmp;
    char t;
    int top=1,i,index,num,l,r;
    seq[0]='1';seq[1]=0;
    while(--n){
        index=0;
        for(i=0;i<top;i++){
            num=1;
            while(i+1<top && seq[i+1]==seq[i]){
                i++;
                num++;
            }
            l=index;
            while(num>0){
                bak[index++]=num%10+'0';
                num/=10;
            }
            r=index-1;
            while(l<r){
                t=bak[l];bak[l]=bak[r];bak[r]=t;
            }
            bak[index++]=seq[i];
        }
        bak[index]=0;
        top=index;
        tmp=seq;seq=bak;bak=tmp;
    }
    free(bak);
    return seq;
}
