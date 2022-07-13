#include <bits/stdc++.h>

using namespace std;

using PP = pair<string, string>;

vector<string> solution(vector<string> record) { // 가장 최근에 채팅방 안에서 닉네임을 변경했거나, 나갔다 닉네임을 바꿔서 다시 접속하는 경우만 고려 대상이다.
                                                 // 0 ~ N - 1번 탐색, N - 1 ~ 0번 탐색으로, 총 시간 복잡도는 O(N + N) 
    vector<string> answer;

    vector<PP> talk_order;

    map<string, string> last_nickname;

    for (auto& e : record)
    {
        string a = "", b = "", c = "";
        stringstream s_in;
        s_in.str(e);
        s_in >> a >> b >> c;
        if (a == "Enter")
            talk_order.push_back({ b, "들어왔습니다." });

        if (a == "Leave")
            talk_order.push_back({ b, "나갔습니다." });
        else
            last_nickname[b] = c;
    }

    answer.resize(talk_order.size());

    for (int i = talk_order.size() - 1; i >= 0; i--)
        answer[i] = last_nickname[talk_order[i].first] + "님이 " + talk_order[i].second;

    return answer;
}