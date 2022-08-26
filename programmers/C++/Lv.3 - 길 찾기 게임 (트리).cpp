#include <bits/stdc++.h>

using namespace std;

class Node_Info
{
public:
    int Num;
    int x;
    Node_Info* Left;
    Node_Info* Right;
    Node_Info(int _Num = 0, int _x = 0, Node_Info* _Left = nullptr, Node_Info* _Right = nullptr)
        :Num(_Num), x(_x), Left(_Left), Right(_Right)
    {}
};

vector<pair<pair<int, int>, int>> Tree;

vector<int> PreFix, PostFix;

bool cmp(pair<pair<int, int>, int>a, pair<pair<int, int>, int> b)
{
    if (a.first.second == b.first.second)
        return a.first.first < b.first.first;
    return a.first.second > b.first.second;
}

void AddTree(Node_Info*& QQ, pair<pair<int, int>, int> temp)
{
    if (QQ == nullptr)
    {
        QQ = new Node_Info(temp.second, temp.first.first);
        return;
    }
    if (QQ->x < temp.first.first)
        AddTree(QQ->Right, temp);
    else if (QQ->x > temp.first.first)
        AddTree(QQ->Left, temp);
}

void Pre_Order(Node_Info*& QQ)
{
    if (QQ == nullptr)
        return;
    PreFix.push_back(QQ->Num);
    Pre_Order(QQ->Left);
    Pre_Order(QQ->Right);
}
void Post_Order(Node_Info*& QQ)
{
    if (QQ == nullptr)
        return;
    Post_Order(QQ->Left);
    Post_Order(QQ->Right);
    PostFix.push_back(QQ->Num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

    for (int i = 0; i < nodeinfo.size(); i++)
        Tree.push_back({ {nodeinfo[i][0], nodeinfo[i][1]}, i + 1 });

    sort(Tree.begin(), Tree.end(), cmp);

    Node_Info* T = new Node_Info(Tree[0].second, Tree[0].first.first);

    for (int i = 1; i < Tree.size(); i++)
        AddTree(T, Tree[i]);

    // 전위 순회
    Pre_Order(T);

    // 후위 순회
    Post_Order(T);

    return { { PreFix, PostFix} };
}