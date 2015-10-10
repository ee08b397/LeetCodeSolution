/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
char* minWindow(char* s, char* t) {
    int hash[128],hash1[128],hash2[128],i;
    int start=0,end=-1;
    int minstart=0,minend=2147483647;
    int len=0;
    for(i=0;i<128;i++){
        hash[i]=-1;
        hash1[i]=0;
        hash2[i]=0;
    }
    for(i=0;t[i];i++){
        hash[t[i]]=0;
        hash1[t[i]]++;
        hash2[t[i]]++;
    }
    len=i;
    for(i=0;s[i];i++){
        if(hash[s[i]]!=-1){
            if(hash1[s[i]]>0){
                len--;
                hash1[s[i]]--;
            }
            hash[s[i]]++;
            while(hash[s[start]]>hash2[s[start]] || hash[s[start]]==-1){
                if(hash[s[start]]>1)hash[s[start]]--;
                start++;
            }
            if(len==0){
                end = i;
                if(minend-minstart > end-start){
                    minstart=start;
                    minend=end;
                }
            }
        }
    }
    if(minend==2147483647)minend=-1;
    s[minend+1]=0;
    return s+minstart;
}
