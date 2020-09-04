// #include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int depth;
void dfs_helper(pair<int, int> ele, pair<int, int> goal_state, queue<pair<int, int>> &q, map<pair<int, int>, bool> &visited, map<pair<int, int>, bool> &openlist, vector<pair<string, pair<int, int>>> &v)
{
    // if (v.size() > depth)
    //     return;
    if (ele == goal_state)
    {
        cnt++;
        v.push_back(make_pair("Goal State Reached ", ele));
        // cout << "Solution exists\n";
        for (auto items : v)
            cout
                << "(" << items.second.first << "," << items.second.second << ")  " << items.first << " \n";

        cout
            << "\n\n";
        v.pop_back();
        return;
    }
    visited[ele] = true;
    openlist[ele] = true;
    int x = ele.first, y = ele.second;
    pair<int, int> p;
    if (x < 4)
    {
        p = {4, ele.second};
        if (visited[p] == false and openlist[p] == false)
        {

            v.push_back(make_pair("Fill 4L jug  ", ele));
            dfs_helper(p, goal_state, q, visited, openlist, v);
            v.pop_back();
        }
    }

    if (y < 3)
    {
        p.first = x;
        p.second = 3;
        if (visited[p] == false and openlist[p] == false)
        {

            // v.push_back(ele);
            v.push_back(make_pair("Fill 3L jug ", ele));
            dfs_helper(p, goal_state, q, visited, openlist, v);
            v.pop_back();
        }
    }
    if (x > 0)
    {
        p.first = 0;
        p.second = y;
        if (visited[p] == false and openlist[p] == false)
        {

            // v.push_back(ele);
            v.push_back(make_pair("Empty 4L Jug on Ground ", ele));
            dfs_helper(p, goal_state, q, visited, openlist, v);
            v.pop_back();
        }
    }
    if (y > 0)
    {
        p.first = x;
        p.second = 0;
        if (visited[p] == false and openlist[p] == false)
        {

            // v.push_back(ele);
            v.push_back(make_pair("Empty 3L Jug on Ground ", ele));
            dfs_helper(p, goal_state, q, visited, openlist, v);
            v.pop_back();
        }
    }
    if (x > 0 and (x + y) >= 4 and y > 0)
    {
        p.first = 4;
        p.second = y - (4 - x);
        if (visited[p] == false and openlist[p] == false)
        {

            // v.push_back(ele);
            v.push_back(make_pair("Pour Water from 3L jug to fill 4L jug ", ele));
            dfs_helper(p, goal_state, q, visited, openlist, v);
            v.pop_back();
        }
    }
    if (x > 0 and x + y > 0 and x + y >= 3)
    {
        p.first = x - (3 - y);
        p.second = 3;
        if (visited[p] == false and openlist[p] == false)
        {

            // v.push_back(ele);
            v.push_back(make_pair("Pour Water from 4L jug to fill 3L jug ", ele));
            dfs_helper(p, goal_state, q, visited, openlist, v);
            v.pop_back();
        }
    }
    if (y >= 0 and x + y > 0 and x + y <= 4)
    {
        p.first = x + y;
        p.second = 0;
        if (visited[p] == false and openlist[p] == false)
        {

            // v.push_back(ele);
            v.push_back(make_pair("Pour all Water from 3L jug into 4L jug  ", ele));
            dfs_helper(p, goal_state, q, visited, openlist, v);
            v.pop_back();
        }
    }
    if (x + y > 0 and x + y <= 3 and x >= 0)
    {
        p.first = 0;
        p.second = x + y;
        if (visited[p] == false and openlist[p] == false)
        {

            // v.push_back(ele);
            v.push_back(make_pair("Pour all Water from 4L jug into 3L jug  ", ele));
            dfs_helper(p, goal_state, q, visited, openlist, v);
            v.pop_back();
        }
    }
}
void dfs(pair<int, int> initial_state, pair<int, int> goal_state)
{
    cnt = 0;

    queue<pair<int, int>> q;
    q.push(initial_state);
    map<pair<int, int>, bool> visited, openlist;
    // vector<pair<int, int>> v;
    vector<pair<string, pair<int, int>>> v;
    while (!q.empty())
    {

        pair<int, int> p = q.front();
        q.pop();
        dfs_helper(p, goal_state, q, openlist, visited, v);
    }
}

int main()
{
    cout << "4L and 3L Water Jug Problem\n";
    cout << "enter the initial state\n";
    pair<int, int> p1, p2;
    cin >> p1.first >> p1.second;
    cout << "enter the goal state\n";
    cin >> p2.first >> p2.second;
    // cout << "enter the max depth\n";
    // cin >> depth;
    dfs(p1, p2);
    if (cnt == 0)
        cout << "No solution exists\n";
    return 0;
}