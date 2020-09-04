#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<pair<int, int>> q;
    q.push({1, 2});
    auto ele = q.front();
    q.pop();
    if (q.empty())
        cout << "yes\n";
    return 0;
}
