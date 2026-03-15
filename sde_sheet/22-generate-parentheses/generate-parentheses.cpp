class Solution {
public:
    void helper(int n ,int open , int close , string str ,vector<string> &ans){
        if(open ==n && close == n){
            ans.push_back(str);
            return;
        }
        if(open !=n){
            string op1 =str;
            op1.push_back('(');
           helper(n ,open +1 ,close ,op1,ans);
        }
        
        if(open > close){
            string op2 =str;
            op2.push_back(')');
            helper(n,open ,close+1 ,op2,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
     vector<string>ans;
     string str="";
     helper(n,0,0,str,ans);
     return ans;
    }
};