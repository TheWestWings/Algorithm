#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

// 判断给定 (hh:mm:ss) 是否在通勤时段内：07:00:00-09:00:00 或 18:00:00-20:00:00
bool isCommute(int hh, int mm, int ss) {
    // 07:00:00 ~ 09:00:00
    // 18:00:00 ~ 20:00:00
    // 全部包含左右边界
    if ((hh > 7 && hh < 9) || (hh == 7) || (hh == 9 && mm == 0 && ss == 0)) return true;
    if ((hh > 18 && hh < 20) || (hh == 18) || (hh == 20 && mm == 0 && ss == 0)) return true;
    return false;
}

// 判断给定 (hh:mm:ss) 是否在午休时段内：11:00:00-13:00:00
bool isLunch(int hh, int mm, int ss) {
    // 11:00:00 ~ 13:00:00，包含边界
    // hour in [11..13], 并且若 hh==13 则需要 mm=0 && ss=0 才算在内吗？
// 题意：时间段均包含左右边界值 => [11:00:00..13:00:00]
    if (hh < 11 || hh > 13) return false;
    return true;
}

// 判断给定 (hh:mm:ss) 是否在临睡时段内：22:00:00-01:00:00
bool isSleep(int hh, int mm, int ss) {
    // 分两段: [22..23]，[0..1]，包含边界
    if (hh >= 22 || hh <= 1) return true;
    return false;
}

int main() {
    vector<pii> ta = { {7 * 3600, 9 * 3600} ,{18*3600,20*3600} };
    pii tb = { 11 * 3600, 13 * 3600 };
    vector<pii> tc = { {22 * 3600, 23 * 3600 + 59 * 60 + 59}, {0, 1 * 3600} };
    set<string> a, b, c;
    int n, h, m;
    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        string login_date, login_time,user_id;;
        cin >> user_id >> login_date >> login_time;

        int year, month, day;
        sscanf(login_date.c_str(), "%d-%d-%d", &year, &month, &day);

        if (year != h || month != m) continue;

        int hh, mm, ss;
        sscanf(login_time.c_str(), "%d:%d:%d", &hh, &mm, &ss);
        int seconds = hh * 3600 + mm * 60 + ss;

        for (auto& period : ta) {
            if (seconds >= period.first && seconds <= period.second) {
                a.insert(user_id);
                break;
            }
        }

        if (seconds >= tb.first && seconds <= tb.second) {
            b.insert(user_id);
        }

        for (auto& period : tc) {
            if (seconds >= period.first && seconds <= period.second) {
                c.insert(user_id);
                break;
            }
        }
    }

    cout << a.size() << " " << b.size() << " " << c.size() << "\n";
}