#include <bits/stdc++.h>

using namespace std;

const int N = 110, UNKNOW = -999, TOP = 50, LOW = -50;

int a[N], t[N];
int n, m;



int main(){
    
    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        cin >> t[i];
    }

    memcpy(a, t, sizeof(t));

    for(int i = 0; i < n; i ++){
        if(i == 0 && a[i] == UNKNOW){
            a[i] = TOP;
        }
        else if(a[i] == UNKNOW){
            if(a[i - 1] - m < LOW){
                a[i] = TOP;
            }
            else{
                a[i] = a[i - 1] - m;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i < n; i ++){
        if(a[i - 1] - a[i] >= m){
            ans ++;
        }
    }

    cout << ans ;

    memcpy(a, t, sizeof(t));

    ans = 0;
    for(int i = 0; i < n; i ++){
        if(a[i] == UNKNOW){
            int j = i;
            while(j < n && a[j] == UNKNOW){
                j ++;
            }
            if(j == n){
                break;
            }
            if(a[i] - a[j] >= m * (j - i)){
                ans ++;
                i = j;
                continue;
            }
        }
        if(a[i - 1] - a[i] >= m){
            ans ++;
        }
    }

    cout << " " << ans << endl;

}