#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;

    int sum = 0, count = 0;

    for (int x : nums)
    {
        sum += x;

        if (mp.find(sum - k) != mp.end())
        {
            count += mp[sum - k];
        }

        mp[sum]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    cout << subarraySum(nums, 2);
    return 0;
}