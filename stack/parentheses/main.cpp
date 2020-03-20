#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> parents;
//leftCnt 可用左括号数，可用右括号数
void add_par(string ans,int leftCnt,int rightCnt){
    //说明已用的左括号数少于已用的右括号数 : 不匹配
    if(leftCnt > rightCnt){
        return;
    }
   
    if(leftCnt == 0){  //没有左括号可用
        for (size_t i = 0; i < rightCnt; i++)
        {
            ans.push_back(')');
        }
        parents.push_back(ans);
        return;
    }
    else{  // 接下来是有左括号使用的情况
        
        if(leftCnt == rightCnt){ //必须用左括号
            add_par(ans + '(',leftCnt - 1,rightCnt);
        }
        else{ //可用可不用
             add_par(ans + '(',leftCnt - 1,rightCnt);
             add_par(ans + ')',leftCnt ,rightCnt - 1);
        }
    }
}

int main(){
    int n;
    cin>>n;
    string ans("");
    add_par(ans,n,n);
    for (auto&& str :parents)
    {
       cout<<str<<endl;
    }
}

