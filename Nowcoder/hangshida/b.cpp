#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    if(n % 7 == 0){
        cout << "hello world." << endl;
    }
    else if(n % 2 == 0){
        cout << "if you don't walk out, you will think that this is the whole world." << endl;
    }
    else if(n % 5 == 0){
        cout << "life isn't like in the movies.life is much harder." << endl;
    }
    else{
        cout << "right now the paradiso needs you and you need the paradiso." << endl;
    }
}