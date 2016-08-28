class Solution {
public:
    
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int head = 0;
        int tail = nums.size() - 1;
        vector<int> res;
        if(!a) {
            for(int i = 0; i < nums.size(); i++) {
                res.push_back(b * nums[i] + c);
            }
            if(b < 0) {
                reverse(res.begin(), res.end());
            }
            return res;
        }
        double mid = -(double)b/2 / a;
        while (head <= tail) {
            if(abs(nums[head] - mid) <= abs(nums[tail] - mid)) {
                res.push_back(a * nums[tail] * nums[tail] + b * nums[tail] + c);
                tail--;
            }
            else {
                res.push_back(a * nums[head] * nums[head] + b * nums[head] + c);
                head++;
            }
        }
        if(a > 0){
            reverse(res.begin(), res.end());
        }
        return res;
    }
};
