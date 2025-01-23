#include <bits/stdc++.h>

using namespace std;
typedef pair<double, double> PII;

double caluS(PII x1, PII x2, PII x3){
    double a = sqrt((x1.first - x2.first) * (x1.first - x2.first) + (x1.second - x2.second) * (x1.second - x2.second));
    double b = sqrt((x1.first - x3.first) * (x1.first - x3.first) + (x1.second - x3.second) * (x1.second - x3.second));
    double c = sqrt((x2.first - x3.first) * (x2.first - x3.first) + (x2.second - x3.second) * (x2.second - x3.second));

    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    PII x1 = {a, c}, x2 = {b, d};

    double mx = 0;
    PII ans = {-1, -1};
    for(int x = a; x <= b; x ++){
        PII x3 = {x, d};
        double s = caluS(x1, x2, x3);

        double a = sqrt((x1.first - x2.first) * (x1.first - x2.first) + (x1.second - x2.second) * (x1.second - x2.second));
        double b = sqrt((x1.first - x3.first) * (x1.first - x3.first) + (x1.second - x3.second) * (x1.second - x3.second));
        double c = sqrt((x2.first - x3.first) * (x2.first - x3.first) + (x2.second - x3.second) * (x2.second - x3.second));

        double R = a * b * c / 4 / s;
        // cout << "R: " << R << endl;
        // cout << x3.first << " " << x3.second << endl;
        if(R > mx){
            mx = R;
            ans = x3;
        }
    }
    // cout << "----------------" << endl;
    // cout << ans.first << " " << ans.second << " " << mx << endl;
    // cout << "----------------" << endl;

    for(int y = c; y <= d; y ++){
        PII x3 = {a, y};
        double s = caluS(x1, x2, x3);

        double a = sqrt((x1.first - x2.first) * (x1.first - x2.first) + (x1.second - x2.second) * (x1.second - x2.second));
        double b = sqrt((x1.first - x3.first) * (x1.first - x3.first) + (x1.second - x3.second) * (x1.second - x3.second));
        double c = sqrt((x2.first - x3.first) * (x2.first - x3.first) + (x2.second - x3.second) * (x2.second - x3.second));

        double R = a * b * c / 4 / s;
        // cout << "R: " << R << endl;
        // cout << x3.first << " " << x3.second << endl;
        if(R > mx){
            mx = R;
            ans = x3;
        }
    }

    cout << x1.first << " " << x1.second << endl;
    cout << x2.first << " " << x2.second << endl;
    cout << ans.first << " " << ans.second << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}