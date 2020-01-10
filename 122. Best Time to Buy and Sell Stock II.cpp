class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int F_ik0 = 0, F_ik1 = INT_MIN;
        for (int price : prices) {
            int tmp = F_ik0;
            F_ik0 = max(F_ik0, F_ik1 + price);
            F_ik1 = max(F_ik1, tmp - price);
        }
        return F_ik0;
    }
};
