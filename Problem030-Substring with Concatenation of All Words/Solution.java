/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 658ms
 */
public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        Map<String,Integer> tmp,map=new HashMap<String,Integer>();
        int lens=s.length(),lenw=words[0].length();
        for(int i=0;i<words.length;i++){
            if(map.containsKey(words[i])){
                map.put(words[i],map.get(words[i])+1);
            }else{
                map.put(words[i],1);
            }
        }
        List<Integer> res = new ArrayList<Integer>();
        for(int i=0;i<=lens-lenw*words.length;i++){
            tmp=new HashMap<String,Integer>();
            int j=0;
            for(;j<words.length;j++){
                int pos=i+j*lenw;
                String sub=s.substring(pos,pos+lenw);
                if(map.containsKey(sub)){
                    int num=0;
                    if(tmp.containsKey(sub))num=tmp.get(sub);
                    if(map.get(sub) < num+1)break;
                    else tmp.put(sub,num+1);
                }else break;
            }
            if(j>=words.length){
                res.add(i);
            }
        }
        return res;
    }
}