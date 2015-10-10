/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 20ms
 */
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(128,-1),hash1(128,0),hash2(128,0);
        int i,start=0,end,minstart=0,minend=2147483647;
        for(i=0;i<t.size();i++){
            hash[t[i]]=0;
            hash1[t[i]]++;
            hash2[t[i]]++;
        }
        int len=i;
        for(i=0;i<s.size();i++){
            if(hash[s[i]]!=-1){
                if(hash1[s[i]]>0){
                    hash1[s[i]]--;
                    len--;
                }
                hash[s[i]]++;
                while(hash[s[start]]>hash2[s[start]] || hash[s[start]]==-1){
                    if(hash[s[start]]>hash2[s[start]])hash[s[start]]--;
                    start++;
                }
                if(len==0){
                    end=i;
                    if(minend-minstart > end-start){
                        minstart=start;
                        minend=end;
                    }
                }
            }
        }
        if(minend==2147483647)return "";
        return s.substr(minstart,minend-minstart+1);
    }
};
