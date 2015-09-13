/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 704ms
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int lens=s.size(),lenw=words[0].size(),length=words.size();
        map<string,int> strmap,tmp;
        for(int i=0;i<length;i++){
            strmap[words[i]]++;
        }
        vector<int> res;
        for(int i=0;i<lens-lenw*length+1;i++){
            tmp.clear();
            int j=0;
            for(j=0;j<length;j++){
                string sub=s.substr(i+j*lenw,lenw);
                if(strmap.find(sub) == strmap.end())break;
                tmp[sub]++;
                if(strmap[sub] < tmp[sub])break;
            }
            if(j>=length)res.push_back(i);
        }
        return res;
    }
};
