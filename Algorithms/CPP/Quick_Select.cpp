#include<bits/stdc++.h>

using namespace std;

int part(vector<int> &v , int l , int r) {
    int x = v[r] , i = l;
    for(int k = l; k <= r-1; k++) {
        if(v[k] <= x) {
            swap(v[k] , v[i]);
            i++;
        }
    }
    swap(v[r] , v[i]);
    return i;
}

int quick_select(vector<int> &v , int l , int r , int k) {
    int p = part(v , l , r);
    if(p + 1 == k) return p;
    else if(p + 1 < k) {
        return quick_select(v , p + 1 , r , k);
    }
    else {
        return quick_select(v , l , p - 1 , k);
    }
}

int main() {
    vector<int> res;
    int k; cin >> k;
    if(k > 10) return 999;
    for(int i = 0; i < 10; i++) {
        int x; cin >> x;
        res.push_back(x);
    }
    int x = quick_select(res , 0 , 9 , k);
    cout << res[x];
    return 0;
}
/*
3
20 25 30 40 11 12 13 14 15 50
*/
