#include <bits//stdc++.h>

using namespace std;

#define PI 3.1416
#define MX 1000005
#define INF 99999999
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef map<string, int> mp;

ll arr[MX];
ll tree[MX*3];

void init(ll node, ll b, ll e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }

    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) return tree[node];
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid+1, e, i, j);
    //cout<<p1<<" "<<p2<<endl;
    return p1+p2;
}

void update(ll node, ll b, ll e, ll i, ll newvalue)
{
    if(i > e || i < b) return;
    if(b >= i && e <= i)
    {
        tree[node] += newvalue;
        return;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    tree[node] = tree[left] + tree[right];
}

int main()
{
    ll n, q;
    scanf("%lld %lld", &n, &q);
    for(ll i=1; i<=n; i++) arr[i] = 0;
    init(1, 1, n);
    while(q--) {
        char in[5];
        scanf("%s", in);

        if (in[0] == 'f'){
                ll i, j;
                scanf("%lld %lld", &i, &j);
            ll res = query(1, 1, n, i, j);
            printf("%lld\n", res);
        }
        else {
            ll p, f;
            scanf("%lld %lld", &p, &f);
            update(1, 1, n, p, f);
        }
    }
    return 0;
}
