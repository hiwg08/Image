#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    
    vector<int> answer;
    
    map<string, int> parking_info; // 주차장에 있는 각 차량의 시간
    
    map<string, int> parking_time_sum; // 각 차량의 누적 주차 시간
    
    vector<string> car_num; // 차량 수
    
    bool parking_lot_exist[10000]{0}; // 차량이 주차장에 존재하는 지에 대한 여부
    
    int conv_arr[2] = {10, 1};
    
    for (auto& params : records) // IN과 OUT을 처리해줄 필요가 없다
    {
        int park_time_convert = 0;
        string a, b;
        
        stringstream s_in;
        s_in.str(params);
        s_in >> a >> b;
        car_num.push_back(b);
        
        // 1
        for (int i = 0; i < 2; i++)
            park_time_convert += (static_cast<int>(a[i]) - 48) * conv_arr[i];
            
        park_time_convert *= 60;
        
        for (int i = 3; i < 5; i++)
            park_time_convert += (static_cast<int>(a[i]) - 48) * conv_arr[i - 3];
        
        // 2
        if (!parking_lot_exist[stoi(b)])
        {
            parking_info[b] = park_time_convert;
            parking_lot_exist[stoi(b)] = true;
            continue; 
        }
        parking_time_sum[b] += (park_time_convert - parking_info[b]);
        parking_info[b] = 0;
        parking_lot_exist[stoi(b)] = false;
    }
    
    sort(car_num.begin(), car_num.end());
    car_num.erase(unique(car_num.begin(), car_num.end()), car_num.end());
    
    for (auto& q : car_num)
    {
        if (parking_lot_exist[stoi(q)]) // 아직도 주차장에 존재한다면 자정을 넘어서 OUT하지 않았다는 뜻
            parking_time_sum[q] += ((23 * 60) + 59) - parking_info[q];
    }
    
    for (auto q : car_num)
    {
        int Results = 0;
        Results += fees[1];
        if (parking_time_sum[q] - fees[0] > 0)
        Results += ceil((parking_time_sum[q] - fees[0]) / (double)fees[2]) * (double)fees[3];
        answer.push_back(Results);
    }
    return answer;
}