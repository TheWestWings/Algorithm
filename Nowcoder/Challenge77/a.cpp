#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll k, a, b;

vector<ll> turn2_k(ll k, ll x){
    vector<ll> res;
    while(x){
        res.push_back(x % k);
        x /= k;
    }
    return res;
}

ll turn2_10(ll k, vector<ll> x){
    ll res = 0;
    ll base = 1;
    for(int i = 0; i < x.size(); i++){
        res += x[i] * base;
        base *= k;
    }
    return res;

}


int main(){
    // int k, a, b;

    cin >> k >> a >> b;

    auto a_k = turn2_k(k, a);
    auto b_k = turn2_k(k, b);

    // for(int i = 0; i < a_k.size(); i++){
    //     cout << a_k[i] << " ";
    // }
    // for(int i = 0; i < b_k.size(); i++){
    //     cout << b_k[i] << " ";
    // }

    vector<ll> res;
    ll i;
    for(i = 0; i < min(a_k.size(), b_k.size()); i++){
        res.push_back((a_k[i] + b_k[i]) % k);
    }

    for(; i < a_k.size(); i++){
        res.push_back(a_k[i]);
    }
    
    for(; i < b_k.size(); i++){
        res.push_back(b_k[i]);
    }

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

    // cout << turn2_10(k, res) << endl;

    

    // cout << a_k << " " << b_k << endl;
    // // cout << (a_k ^ b_k) << endl;
    // cout << turn2_10(k, a_k ^ b_k) << endl;
}