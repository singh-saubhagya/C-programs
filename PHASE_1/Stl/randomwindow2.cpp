#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<(n);++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define per(i,a,b) for(lli i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define sz(x) (lli)(x).size()
#define endl '\n'
typedef long long lli;        typedef long double ld;
typedef pair<lli,lli> ii;     typedef vector<lli> vi;
typedef vector<ii> vii;       typedef vector<vi> graph;
long long MOD=1000000007;     long double EPS=1e-9;
#ifndef ONLINE_JUDGE
#define debarr(a,n) cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
#else
#define pr(...) {}
#define debarr(a,n) {}
#define debmat(mat,row,col) {}
#endif
lli binpow(lli b,lli p,lli mod){lli ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
 
void pre(){
 
}
 
 
struct sliding_median{
	multiset<lli> lo,hi;
	lli losum,hisum;
	void insert(lli x){
		if(!lo.empty()){
			auto v=lo.end();v--;
			if(x<=*v){lo.insert(x);losum+=x;return;}
		}
		if(!hi.empty()){
			auto v=hi.begin();
			if(x>=*v){hi.insert(x);hisum+=x;return;}
		}
		lo.insert(x);
		losum+=x;
	}
	void erase(lli x){
		if(!lo.empty()){
			auto v=lo.end();v--;
			if(x<=*v){lo.erase(lo.find(x));losum-=x;return;}
		}
		if(!hi.empty()){
			auto v=hi.begin();
			if(x>=*v){hi.erase(hi.find(x));hisum-=x;return;}
		}
	}
	void rebalance(){
		while(lo.size()>=hi.size()+2){
			auto it=lo.end();
			it--;lli val=*it;lo.erase(it);
			hi.insert(val);losum-=val;hisum+=val;
		}
		while(hi.size()>lo.size()){
			auto it=hi.begin();
			lli val=*it;hi.erase(it);
			lo.insert(val);hisum-=val;losum+=val;
		}
	}
	lli getMedian(){
		rebalance();
		auto it=lo.end();it--;
		return *it;
	}
	lli getcost(){
		lli x=getMedian();
		return (lo.size()*x-losum)+(hisum-hi.size()*x);
	}
	void init(){
		lo.clear();hi.clear();
		losum=0;hisum=0;
	};
}med;
 
void solve(){
	med.init();
	lli n,k;cin>>n>>k;
	lli arr[n];fr(i,n)cin>>arr[i];
	fr(i,k-1){
		med.insert(arr[i]);
	}
	rep(i,k-1,n-1){
		med.insert(arr[i]);
		cout<<med.getcost()<<" ";
		med.erase(arr[i-k+1]);
	}
 
}
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //cout<<fixed<<setprecision(15);
    //clock_t begin = clock();
    pre();lli _t=1;//cin>>_t;
    for(lli i=1;i<=_t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    // clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;cerr << elapsed_secs;
}