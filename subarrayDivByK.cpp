class Solution {
public:
    // Brute-Force solution, time exceeds limit
    // int subarraysDivByK(vector<int>& A, int K) {
    //     ios_base::sync_with_stdio(false);
    //     int sol = 0;
    //     for(int i = 0; i < A.size(); ++i) {
    //         int sum = 0;
    //         int j = i;
    //         while(j < A.size()) {
    //             sum += A[j];
    //             if(sum % K == 0) {
    //                 ++sol;
    //             }
    //             ++j;
    //         }
    //     }
    //     return sol;
    // }
    
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;
        int sol = 0;
        for(int i = 0; i < A.size(); ++i) {
            sum += A[i];
            // int mod = sum % K;
            // have to deal with negative sum
            int mod = (sum % K + K) % K;
            auto iter = map.find(mod);
            if(iter != map.end()) {
                sol += map[mod];
                ++map[mod];
            }
            else {
                map[mod] = 1;
            }
        }
        return sol;
    }
};
