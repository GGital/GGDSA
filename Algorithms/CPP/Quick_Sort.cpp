#include<bits/stdc++.h>

using namespace std;

int part(vector<int> &v , int l , int r) {
    int x = v[r] , i = l; // x is the pivot value assumed pivot is right-most
    for(int k = l; k <= r-1; k++) {
        if(v[k] <= x) {
            swap(v[k] , v[i]);
            i++;
        }
    }
    swap(v[r] , v[i]);
    return i;
}

void qs(vector<int> &v , int l , int r) {
    if(r - l <= 0) return;
    int x = part(v , l , r);
    qs(v , l , x-1);
    qs(v , x + 1 , r);
}

int main() {
    vector<int> v;
    for(int i = 0; i < 10; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    qs(v , 0 , 9);
    for(int e : v) cout << e << ' ';
    return 0;
}
