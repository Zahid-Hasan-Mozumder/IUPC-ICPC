#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define pipii pair<int, pair<int, int>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define plpii pair<ll, pair<int, int>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const int mod = 1e9+7;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;


void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n & 1){
            int f = 1, s = n / 2 + 2;
            deque<int> dq;
            for(int i = 1; i<=n; i++){
                if(i & 1){
                    dq.push_back(f);
                    f++;
                }
                else{
                    dq.push_back(s);
                    s++;
                }
            }
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    cout<< dq[j - 1] << " ";
                }
                cout<< '\n';
                int x = dq.front();
                dq.pop_front();
                dq.push_back(x);
            }
        }
        else{
            cout<< -1 << '\n';
        }
    }
}
