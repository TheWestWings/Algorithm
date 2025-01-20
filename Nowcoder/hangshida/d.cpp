#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    int ans = 0, ans_2 = 0;
    for(int i = 0; i < n; i ++){
        if(str[i] == 'A'){
            ans += 2;
            if(i + 1 < n && str[i + 1] == 'A'){
                ans += 2;
            }
            if(i + 1 < n - 1 && (str[i + 1] == '(' || str[i + 1] == ')') && str[i + 2] == 'A'){
                ans += 2;
            }
            if(i - 1 >= 0 && str[i - 1] == 'A'){
                ans += 2;
            }
            if(i - 1 >= 1 && (str[i - 1] == '(' || str[i - 1] == ')') && str[i - 2] == 'A'){
                ans += 2;
            }
            if(i + 1 < n && str[i + 1] == 'B'){
                ans += 1;
            }
            if(i + 1 < n - 1 && (str[i + 1] == '(' || str[i + 1] == ')') && str[i + 2] == 'B'){
                ans += 1;
            }
            if(i - 1 >= 0 && str[i - 1] == 'B'){
                ans += 1;
            }
            if(i - 1 >= 1 && (str[i - 1] == '(' || str[i - 1] == ')') && str[i - 2] == 'B'){
                ans += 1;
            }
        }
        if(str[i] == 'B'){
            ans += 1;
            if(i + 1 < n && str[i + 1] == 'B'){
                ans += 2;
            }
            if(i + 1 < n - 1 && (str[i + 1] == '(' || str[i + 1] == ')') && str[i + 2] == 'B'){
                ans += 2;
            }
            if(i - 1 >= 0 && str[i - 1] == 'B'){
                ans += 2;
            }
            if(i - 1 >= 1 && (str[i - 1] == '(' || str[i - 1] == ')') && str[i - 2] == 'B'){
                ans += 2;
            }
            if(i + 1 < n && str[i + 1] == 'A'){
                ans += 1;
            }
            if(i + 1 < n - 1 && (str[i + 1] == '(' || str[i + 1] == ')') && str[i + 2] == 'A'){
                ans += 1;
            }

            if(i - 1 >= 0 && str[i - 1] == 'A'){
                ans += 1;
            }
            if(i - 1 >= 1 && (str[i - 1] == '(' || str[i - 1] == ')') && str[i - 2] == 'A'){
                ans += 1;
            }
        }
    }
    int a = -1;
    for(int i = 0; i < n; i ++){
        if(str[i] == '('){
            a = i;
            break;
        }
    }
    int b = -1;
    for(int i = n - 1; i >= 0; i --){
        if(str[i] == ')'){
            b = i;
            break;
        }
    }

    if(a == -1 || b == -1 || b <= a){
        cout << ans << endl;
        return 0;
    }

    int res = ans;
    ans = 0;    
    for(int i = a + 1; i < b; i ++){
        if(str[i] == 'A'){
            ans += 2;
        }
        if(str[i] == 'B'){
            ans += 1;
        }

    }

    cout << res - ans + 2 * ans << endl;

}