#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define sz(x) ((int)x.size())
#define fin freopen ("a.txt","r",stdin);
#define fout freopen ("b.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
//rapadura é doce, mas não é mole não
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//I see you
std::mt19937 rng((int) std::chrono ::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
//~ long double pi = 3.141592653589793;

int dp[100001];

int f(int i,int n,int v[]){
	
	if(i>=n-1) return 0;
	if(dp[i]!=-1) return dp[i];
	int op1 = abs(v[i]-v[i+1]) + f(i+1,n,v), op2 = INT_MAX;
	if(i+2<n) op2 = abs(v[i]-v[i+2]) + f(i+2,n,v);
	return dp[i] = min(op1,op2);
}

int main () {
	
	fast;
	memset(dp,-1,sizeof(dp));
	int n; cin >> n;
	int v[n];
	for(int i=0;i<n;i++)
		cin >> v[i];
	cout << f(0,n,v) << "\n";
}
