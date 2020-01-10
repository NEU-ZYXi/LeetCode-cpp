class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int F_i20 = 0, F_i21 = INT_MIN, F_i10 = 0, F_i11 = INT_MIN;
        for (int price : prices) {
            F_i20 = max(F_i20, F_i21 + price);
            F_i21 = max(F_i21, F_i10 - price);
            F_i10 = max(F_i10, F_i11 + price);
            F_i11 = max(F_i11, -price);
        }
        return F_i20;
    }
};
