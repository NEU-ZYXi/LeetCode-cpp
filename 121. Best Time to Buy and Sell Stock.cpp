class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min_price = INT_MAX;
        for (int price : prices) {
            min_price = min(min_price, price);
            ans = max(ans, price - min_price);
        }
        return ans;
    }
};




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int F_i10 = 0, F_i11 = INT_MIN;
        for (int price : prices) {
            F_i10 = max(F_i10, F_i11 + price);
            F_i11 = max(F_i11, -price);
        }
        return F_i10;
    }
};
