#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int ans = 0;

    for (int x : s) {
        if (s.find(x - 1) == s.end()) {
            int count = 1;
            int num = x;

            while (s.find(num + 1) != s.end()) {
                num++;
                count++;
            }

            ans = max(ans, count);
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums);
    return 0;
}