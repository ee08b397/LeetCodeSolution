/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0 || matrix[0].size()==0)return res;
        int x=0,y=-1,xmin=0,xmax=matrix.size()-1,ymin=0,ymax=matrix[0].size()-1;
        while(true){
            while(y+1 <= ymax)res.push_back(matrix[x][++y]);
            if(++xmin > xmax)break;
            while(x+1 <= xmax)res.push_back(matrix[++x][y]);
            if(--ymax < ymin)break;
            while(y-1 >= ymin)res.push_back(matrix[x][--y]);
            if(--xmax < xmin)break;
            while(x-1 >= xmin)res.push_back(matrix[--x][y]);
            if(++ymin > ymax)break;
        }
        return res;
    }
};
