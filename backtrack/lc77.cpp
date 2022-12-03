//
// Created by liangke on 2022/12/3.
//

#include <iostream>
#include "vector"
using namespace std;
class Soltion{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n,int k,int index){
        if(path.size() == k){
            result.push_back(path);
            return;
        }
        for(int i = index;i<=n;i++){
            path.push_back(i);
            backtracking(n,k,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k){
        result.clear();
        path.clear();
        backtracking(n,k,1);
        return result;
    }
};

int main(){
    Soltion soltion;
    vector<vector<int>> res = soltion.combine(4,2);
    cout << res.size() << endl;

    return 0;
}
