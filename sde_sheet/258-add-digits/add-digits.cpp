class Solution {
public:
    int addDigits(int num) {
      if(num % 10 ==num) return num;
      int ans =0;
      while(num){
        ans+=num%10;
        num=num/10;
      }  
      return addDigits(ans);
    }
};