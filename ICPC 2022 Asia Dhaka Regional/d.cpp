#include <bits/stdc++.h>

using namespace std;

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    double k; cin>>k;
    double x = 4 - (k * k);
    double y = (k * k) - 1;
    double ans = sqrt(y / x);
    cout<< fixed << setprecision(4) << ans << '\n';
}
