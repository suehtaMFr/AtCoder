#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define mid ((l+r)>>1)
#define midf ((l+r)/2.0)
#define sz(x) ((int)x.size())
#define fin freopen ("input.txt","r",stdin);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
//rapadura é doce, mas não é mole não
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//I see you
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
//~ long double pi = 3.141592653589793;
#define pfc(x) {cout << x;continue;}

int dp[100001][3],mat[100001][3],n;

int f(int i,int j,bool o){
	if(i==n) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	return dp[i][j] = max({((o || j!=0) ? f(i+1,0,0) + mat[i][0] : -1), ((o || j!=1) ? f(i+1,1,0) + mat[i][1] : -1), ((o || j!=2) ? f(i+1,2,0) + mat[i][2] : -1)});
}

int main () {
	fast;
	memset(dp,-1,sizeof(dp));
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
	cout << f(0,0,1) << "\n";
}
