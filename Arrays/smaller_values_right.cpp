#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<pair<int, int>> &a, vector<int> &ans,
               int l, int r)
{
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;

    mergeSort(a, ans, l, mid);
    mergeSort(a, ans, mid + 1, r);

    vector<pair<int, int>> temp;
    int i = l, j = mid + 1;

    while (i <= mid && j <= r)
    {
        if (a[i].first <= a[j].first)
        {
            ans[a[i].second] += j - (mid + 1);
            temp.push_back(a[i++]);
        }
        else
        {
            temp.push_back(a[j++]);
        }
    }

    while (i <= mid)
    {
        ans[a[i].second] += j - (mid + 1);
        temp.push_back(a[i++]);
    }

    while (j <= r)
    {
        temp.push_back(a[j++]);
    }

    for (int k = 0; k < temp.size(); k++)
    {
        a[l + k] = temp[k];
    }
}

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    vector<pair<int, int>> a;

    for (int i = 0; i < n; i++)
    {
        a.push_back({nums[i], i});
    }

    mergeSort(a, ans, 0, n - 1);
    return ans;
}

int main()
{
    vector<int> nums = {5, 2, 6, 1};
    vector<int> ans = countSmaller(nums);

    for (int x : ans)
        cout << x << " ";
    return 0;
}