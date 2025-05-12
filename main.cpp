#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;

i64 partyCnt, voteCnt;
const i64 N = 300; // 의원정수 (지역구 253 + 비례대표 47)
i64 R = 253; // 의석할당정당이 아닌 정당의 지역구 당선인 수 총합
i64 pVoteCnt = 0; // 의석할당정당의 득표수의 합계
i64 si1Sum = 0; // 연동 배분 의석 수의 합

struct party {
    string name; // 정당명
    i64 regionalSeats = 0; // 지역구 의석 수
    i64 votes = 0; // 비례대표국회의원선거 득표수
    bool proportionalSeats = false;
    f64 voteRatio = 0; // 비례대표국회의원선거 득표비율
    i64 seats1 = 0; // 연동 배분 의석 수
    i64 seats = 0; // 비례대표 의석 수

    friend istream& operator>>(istream& in, party& p) {
        in >> p.name >> p.regionalSeats >> p.votes;
        return in;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> partyCnt >> voteCnt;
    vector<party> parties(partyCnt);
    map<string, party*> pm;
    for(auto& p : parties) cin >> p;
    voteCnt = 0;
    for(auto& p : parties) voteCnt += p.votes;
    for(auto& p : parties) {
        p.proportionalSeats = p.votes * 100 >= voteCnt * 3 || p.regionalSeats >= 5;
        if(p.proportionalSeats) pVoteCnt += p.votes, R -= p.regionalSeats;
    }
    for(auto& p : parties) {
        pm.emplace(p.name, &p);
        if(!p.proportionalSeats) continue;
        p.voteRatio = p.votes / (f64) pVoteCnt;
        f64 i = ( (N - R) * p.voteRatio - p.regionalSeats ) / 2;
        p.seats1 = i < 1 ? 0 : round(i);
        si1Sum += p.seats1;
        if(si1Sum * 2 >= N - R) break;
    }
    if(si1Sum < 30) {
        vector<pair<f64, string>> arr;
        i64 ds = 0;
        for(auto& p : parties) {
            if(!p.proportionalSeats) continue;
            f64 d = (30 - si1Sum) * p.voteRatio;
            p.seats = p.seats1 + i64(d); ds += i64(d);
            arr.emplace_back(d - i64(d), p.name);
        }
        si1Sum += ds;
        sort(arr.begin(), arr.end(), [](const pair<f64, string>& a, const pair<f64, string>& b) {
            if(a.first != b.first) return a > b;
            return a.second < b.second;
        });
        i64 idx = 0;
        while(si1Sum < 30) {
            pm[arr[idx].second]->seats++;
            idx++; si1Sum++;
        }
    }
    else if(si1Sum > 30) {
        vector<pair<f64, string>> arr;
        i64 sSum = 0;
        for(auto& p : parties) {
            if(!p.proportionalSeats) continue;
            f64 d = (30 * p.seats1) / (f64) si1Sum;
            p.seats = i64(d); sSum += i64(d);
            arr.emplace_back(d - i64(d), p.name);
        }
        sort(arr.begin(), arr.end(), [](const pair<f64, string>& a, const pair<f64, string>& b) {
            if(a.first != b.first) return a > b;
            return a.second < b.second;
        });
        i64 idx = 0;
        while(sSum < 30) {
            pm[arr[idx].second]->seats++;
            idx++; sSum++;
        }
    }
    i64 s3 = 0;
    vector<pair<f64, string>> arr;
    for(auto& p : parties) {
        if(!p.proportionalSeats) continue;
        f64 d = 17 * p.voteRatio;
        p.seats += i64(d); s3 += i64(d);
        arr.emplace_back(d - i64(d), p.name);
    }
    sort(arr.begin(), arr.end(), [](const pair<f64, string>& a, const pair<f64, string>& b) {
        if(a.first != b.first) return a > b;
        return a.second < b.second;
    });
    i64 idx = 0;
    while(s3 < 17) {
        pm[arr[idx].second]->seats++;
        idx++; s3++;
    }

    vector<pair<string, i64>> ans;
    for(auto& p : parties) ans.emplace_back(p.name, p.regionalSeats + p.seats);
    sort(ans.begin(), ans.end(), [](const pair<string, i64>& a, const pair<string, i64>& b) {
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    for(auto& [a, b] : ans) {
        cout << a << " " << b << "\n";
    }
}
