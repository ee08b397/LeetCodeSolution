/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        char* str=(char*)malloc(sizeof(char)*(strs[0].size()+1));
        for(int i=0;i<strs[0].size();i++){
            str[i]=strs[0][i];
        }
        str[strs[0].size()]=0;
        for(int i=1;i<strs.size();i++){
            int j=0;
            while(str[j] && strs[i][j] && str[j]==strs[i][j])j++;
            str[j]=0;
        }
        return string(str);
    }
};
