#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n;
    cin >> t;
    vector<int> vec;
    while (t--)
    {
        cin >> n;
        vec.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        set<int> vec2;
        int len = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (vec[i + 1] - vec[i] < 3)
                len += 1;
            else
            {
                vec2.insert(len);
                len = 1;
            }
        }
        vec2.insert(len);
        cout << *min_element(vec2.begin(), vec2.end()) << " " << *max_element(vec2.begin(), vec2.end()) << endl;
        vec.clear();
        vec2.clear();
    }
    return 0;
}