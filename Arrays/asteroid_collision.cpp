#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> asteroids = {5, 10, -5};
    vector<int> st;

    for (int x : asteroids)
    {
        if (x > 0)
        {
            st.push_back(x);
        }
        else
        {
            while (!st.empty() && st.back() > 0 &&
                   abs(x) > st.back())
            {
                st.pop_back();
            }

            if (!st.empty() && st.back() > 0 &&
                abs(x) == st.back())
            {
                st.pop_back();
            }
            else if (st.empty() || st.back() < 0)
            {
                st.push_back(x);
            }
        }
    }

    for (int x : st)
    {
        cout << x << " ";
    }

    return 0;
}