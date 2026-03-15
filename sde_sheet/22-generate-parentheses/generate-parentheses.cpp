class Solution {
public:
    void helper(int n ,int open , int close , string str ,vector<string> &ans){
        if(open ==0 && close == 0){
            ans.push_back(str);
            return;
        }
        if(open !=0){
            string op1 =str;
            op1.push_back('(');
           helper(n ,open -1 ,close ,op1,ans);
        }
        
        if(open < close){
            string op2 =str;
            op2.push_back(')');
            helper(n,open ,close-1 ,op2,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
     vector<string>ans;
     string str="";
     helper(n,n,n,str,ans);
     return ans;
    }
};