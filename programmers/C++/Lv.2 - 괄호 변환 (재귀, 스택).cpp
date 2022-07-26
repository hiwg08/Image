
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
#include <bits/stdc++.h>

using namespace std;

string S;

stack<char> Q;

bool CHK_Correct(string S) // 올바른 괄호 문자열 판별은 스택으로 구현
{
    for (auto e : S)
    {
        if (e == '(')
            Q.push(e);
        else if (e == ')' && !Q.empty() && Q.top() == '(')
            Q.pop();
        else
            return false;
    }
    return true;
}

string Return_Ans(string S) // 문자열 변환 방법은 문제에 나온 방법 그대로 따라서 구현
{
    if (S == "")
        return S;

    bool CHK_Index = true;
    int CNT_L = 0, CNT_R = 0;
    string u = "", v = "";

    for (auto e : S)
    {
        if (CHK_Index)
            u += e;
        else
            v += e;

        if (e == '(')
            CNT_L++;
        if (e == ')')
            CNT_R++;

        if (CNT_L == CNT_R)
            CHK_Index = false;
    }

    if (CHK_Correct(u))
        return u + Return_Ans(v);

    string temp = "(" + Return_Ans(v) + ")";
    u = u.substr(1, u.size() - 2);

    for (auto& e : u)
    {
        if (e == '(')
            e = ')';
        else if (e == ')')
            e = '(';
    }

    return temp + u;
}

string solution(string p) {

    return Return_Ans(p);
}