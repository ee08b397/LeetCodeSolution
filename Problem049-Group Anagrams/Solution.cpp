/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 84ms
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> returnColumn;
        map<string,int> hash;
        for(int i=0;i<strs.size();i++){
            int len = strs[i].size();
            char* tmp = (char*)malloc(sizeof(char)*(len+1));
            strcpy(tmp,strs[i].data());
            sort(tmp,tmp+len);
            string res(tmp);
            free(tmp);
            map<string,int>::iterator it = hash.find(res);
            if(it != hash.end()){
                int index = it->second;
                vector<string> column = returnColumn[index];
                column.push_back(strs[i]);
                returnColumn[index] = column;
            }else{
                hash[res] = returnColumn.size();
                vector<string> column;
                column.push_back(strs[i]);
                returnColumn.push_back(column);
            }
        }
        for(int i=0;i<returnColumn.size();i++){
            sort(returnColumn[i].begin(),returnColumn[i].end());
        }
        return returnColumn;
    }
};
