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

typedef struct {
    int val;
    int sum;
}in;

int main()
{
    ios_base::sync_with_stdio(0);
    in a[T4];
    in b[T4];
    int n, m, sum;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        sum = 0;
        REP(i, n) {
            scanf("%d", &a[i].val);
            sum += a[i].val;
            a[i].sum = sum;
        }

        scanf("%d", &m);
        sum = 0;
        REP(i, m) {
            scanf("%d", &b[i].val);
            sum += b[i].val;
            b[i].sum = sum;
        }
        a[n].val = T4;
        a[n].sum = a[n-1].sum + T4;
        b[m].val = T4;
        b[m].sum = b[m-1].sum + T4;

        int i, j, last_sum_i, last_sum_j, sum_i, sum_j, mxsum;
        i = j = mxsum = sum_i = sum_j = last_sum_i = last_sum_j = 0;

        while(i<=n && j<=m) {
            if(a[i].val<b[j].val) i++;
            else if(b[j].val<a[i].val) j++;
            else {
                sum_i = a[i].sum - last_sum_i;
                sum_j = b[j].sum - last_sum_j;
                mxsum += max(sum_i, sum_j);
                last_sum_i = a[i].sum;
                last_sum_j = b[j].sum;
                i++; j++;
            }
        }
        cout << mxsum - T4<<endl;
    }
    return 0;
}
