#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define f(x,a,b) for(long long x=a;x<b;x++)
#define pb push_back
#define eb emplace_back //faster than push_back
#define mod1 1000000007
#define mod2 998244353
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define vecpii vector<pair<ll,ll>>
#define endl '\n'
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


/*
    ll n;cin>>n;
    ll arr[n];
    f(i,0,n){
       cin>>arr[i];
    }
*/




ll binary_exponentiation(ll a, ll b, ll mod)
{
ll ans = 1;
while (b)
{
   if (b % 2 == 1)
      {
         ans = (ans * a) % mod;
      }
   a = (a * a) % mod;
   b /= 2;
}
return ans;
}

bool isPrime(ll x){
    for(ll i=2;i*i<=x;i++){
        if(x%i==0)return 0;
    }
    return 1;
}

vector<ll> Divisors(ll x){
    vector<ll> ans;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            ans.push_back(i);
            if(i*i!=x){
                ans.push_back(x/i);
            }
        }
    }
    return ans;
}

using ii = pair<ll, ll>;
vector<ii> Factors(ll x){
    vector<ii> ans;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            ll cnt=0;
            while(x%i==0){
                cnt++;
                x/=i;
            }
            ans.push_back({i,cnt});
        }
    }
    if(x>1){
        ans.push_back({x,1});
    }
    return ans;
}

void SieveofEratosthenes(ll N){
    vector<ll> isPrime(N,1);
    isPrime[0]=isPrime[1]=0;

    for(ll i=2;i<=N;i++){
        if(isPrime[i]){
            for(ll j=1ll*i*i;j<=N;j+=i){
                isPrime[j]=0;
            }
        }
    }
}
int segn;
int segarr[100100];
int segt[400400];
//4*n because 1+2+...+2^ceil(log(n))+1 because of indexing like i->2*i and 2*i+1

void segbuild(int index, int l, int r){
    if(l==r){
        segt[index]=segarr[l];
        return;
    }
    int mid=(l+r)/2;
    segbuild(index*2,l,mid);
    segbuild(index*2,mid+1,r);
    segt[index] = segt[2*index] + segt[2*index+1];
}

void segupdate(int index, int l, int r, int pos, int val){
    if(pos<l||pos>r)return;
    if(l==r){
        segt[index]= val;
        segarr[l]=val;
        return;
    }
    int mid = (l+r)/2;
    segupdate(index*2,l,mid,pos,val);
    segupdate(index*2+1,mid+1,r,pos,val);
    segt[index] = segt[2*index] + segt[2*index + 1];

}

int segquery(int index, int l, int r, int lq, int rq){
    if(l>rq || lq<r) return 0;
    if(lq<=l && r<=rq){
        //lq<=l<=r<=rq
        return segt[index];
    }
    int mid=(l+r)/2;
    return segquery(index*2,l,mid,lq,rq) + segquery(index*2+1,mid+1,r,lq,rq);
}

void segsolve(){
    cin>>segn;
    f(i,0,segn){
        cin>>segarr[i];
    }
    segbuild(1,0,segn-1);
    int q;cin>>q;
    f(i,0,q){
        int ch;cin>>ch;
        if(ch==1){
            int x,y;cin>>x>>y;
            segupdate(1,0,segn-1,x,y);
        }
        else{
            int l,r;cin>>l>>r;
            segquery(1,0,segn-1,l,r);
        }
    }
}

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        
        for (auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }
        
        for (auto it: graph) {
            auto destinations=it.second;
            sort(destinations.rbegin(), destinations.rend());
        }
        
        vector<string> itinerary;
        
        function<void(const string&)> dfs = [&](const string& airport) {
            while (!graph[airport].empty()) {
                string next = graph[airport].back();
                graph[airport].pop_back();
                dfs(next);
            }
            itinerary.push_back(airport);
        };
        
        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
    }
};
void solve() {
}
signed main()
{
fast
int tc; cin>>tc; while(tc--)
solve();
return 0;
}