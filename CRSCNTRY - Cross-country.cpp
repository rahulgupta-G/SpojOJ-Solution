#include <bits//stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MAX 1000000
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define SET(x) memset(x, 0, sizeof(x))
#define CLR(x) memset(x, -1, sizeof(x))
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define in scanf
#define pf printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
//Convert int to string
template <typename T>
string to_str(T str)
{
    stringstream stream;
    stream << str;
    return stream.str();
}

//Convert string to int
template <typename T>
int to_int(T num)
{
    int val;
    stringstream stream;
    stream << num;
    stream >> val;
    return val;
}

//Split String by Single Character Delimiter
vector<string> split(const string& s, char delim)
{
    vector<string> elems;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim))
        elems.push_back(item);

    return elems;
}
// this function goes to main for splitting
//vector<string> words;
//words = split("lorem_ipsum_dolor_sit_amet_no_tota_tacimates_delicata_eum", '_');
//for(int i=0; i<words.size(); i++)
//cout << words.at(i) << endl;


//sort with respect to the second element in a pair !!
//bool comp(const pair<int, int>&i, const pair<int, int>&j) {
//        return i.second < j.second;
//}
//vector< pair<int, int> >v;
//sort(v.begin(), v.end(), comp);

const int dr [] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc [] = {0, 1, 1, 1, 0, -1, -1, -1};

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int i32;
typedef unsigned long int ui32;
typedef long long int i64;
typedef unsigned long long int  ui64;

const int T2=105; const int T3=1005; const int T4=10005; const int T5=100005;

int a[T3], b[T3], dp[T3][T3];

int lcs(int m , int n){
	int i, j;

	for (i = 0; i <= m; ++i)
		dp[i][0] = 0;

	for (j = 0; j <= n; ++j)
		dp[0][j] = 0;

	for (i = 1; i <= m; ++i){
		for (j = 1; j <= n; ++j){
			if (a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else if (dp[i-1][j] >= dp[i][j-1]){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	return dp[m][n];
}

int main()
{
    int t, n, i, p, q, mx;
    cin >> t;
    while(t--) {
            i = mx = 0;
        while(scanf("%d", &n) == 1) {
            if(n == 0) break;
            a[i++] = n;
        }
        p = i;
        //cout <<p <<endl;
        while(scanf("%d", &n) && n!=0){
            i = 0;
            b[i++] = n;
           while(scanf("%d", &n) == 1) {
                if(n == 0) break;
                b[i++] = n;
            }
            q = i;
            //cout << q <<endl;
            mx = max(mx, lcs(p, q));
        }
        cout << mx <<endl;
    }
}
