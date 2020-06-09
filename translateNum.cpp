class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        str = "0" + str;
        // int dp[str.length()];
        vector<int> dp(str.length());
        // if(str[0] == '0') {
        //     dp[0] = 0;
        // }
        // else {
        dp[0] = 1;
        //}
        for(int i = 1; i < str.length(); ++i) {
            dp[i] += dp[i - 1];
            if(str[i - 1] != '0' && (str[i - 1] - '0') * 10 + str[i] - '0' <= 25) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[str.length() - 1];
    }
};
