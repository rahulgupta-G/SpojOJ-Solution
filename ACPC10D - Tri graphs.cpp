#include <bits//stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back
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
#define xx first
#define yy second
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

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

int main()
{
    //ios_base::sync_with_stdio(0);
    int n, kase = 0;

    while(scanf("%d", &n) && n != 0) {
        int a[n+1][3];

        for(int i=0; i<n; i++)
            cin >> a[i][0] >> a[i][1] >> a[i][2];

        if(n == 1)
            a[0][2] += a[0][1];
        else {
            a[0][2] += a[0][1];
            a[1][0] += a[0][1];
            a[1][1] += min(min(a[0][1], a[0][2]), a[1][0]);
            a[1][2] += min(a[0][1], min(a[0][2], a[1][1]));

            for(int i=2; i<n; i++) {
                a[i][0] += min(a[i-1][0], a[i-1][1]);
                a[i][1] += min(min(a[i-1][1], a[i][0]), min(a[i-1][2], a[i-1][0]));
                a[i][2] += min(min(a[i][1], a[i-1][1]), a[i-1][2]);
            }
        }
        ++kase;
        cout << kase << ". " << a[n-1][1] << endl;
    }
    return 0;
}

