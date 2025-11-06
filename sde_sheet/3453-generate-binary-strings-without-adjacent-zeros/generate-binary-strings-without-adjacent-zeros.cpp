class Solution {
public:
    void helper(int n ,string st ,vector<string>&ans){
        if(st.length()==n){
            ans.push_back(st);
            return ;
        }
        st.push_back('1');
        helper(n,st,ans);
        st.pop_back();

        if(st.empty() || st.back()=='1'){
            st.push_back('0');
            helper(n,st,ans);
            st.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string st="";
        vector<string>ans;
        helper(n,st,ans);
        return ans ;
    }
};