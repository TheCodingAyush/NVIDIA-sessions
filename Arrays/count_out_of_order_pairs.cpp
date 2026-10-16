#include <bits/stdc++.h>
using namespace std;

long long mergeSort(vector<int> &a, vector<int> &temp,
                    int l, int r)
{
    if (l >= r)
        return 0;

    int mid = l + (r - l) / 2;

    long long count = 0;

    count += mergeSort(a, temp, l, mid);
    count += mergeSort(a, temp, mid + 1, r);

    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];

    for (int x = l; x <= r; x++)
    {
        a[x] = temp[x];
    }

    return count;
}

int main()
{
    vector<int> nums = {3, 1, 2};
    vector<int> temp(nums.size());

    cout << mergeSort(nums, temp, 0, nums.size() - 1);
    return 0;
}