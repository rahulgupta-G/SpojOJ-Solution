#include <cstdio>
#include <iostream>

using namespace std;
#define mx 100005
#define i64 long long
int arr[mx]={0};
struct info
{
    i64 prop, sum;
    info():prop(0), sum(0){}
    void reset(){
        prop = 0;
        sum = 0;
    }
}tree[mx*3];

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].sum = arr[b];
        return;
    }

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void update(int node, int b, int e, int i, int j, i64 x)
{
    if(i > e || j < b) return;
    if(b >= i && e <= j)
    {
        tree[node].sum += ((e-b+1) * x);
        tree[node].prop += x;
        return;
    }

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e-b+1)*tree[node].prop;

}

i64 query(int node, int b, int e, int i, int j, i64 carry = 0)
{
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) return tree[node].sum + carry*(e-b+1);

    int Left = node << 1;
    int Right = (node << 1) + 1;

    int mid = (b + e) >> 1;
    i64 p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    i64 p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);
    return p1 + p2;
}

int main()
{
    int test, n, c, doit, x, y, z;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &n, &c);
       //for(int i = 1; i <= n; i++) arr[i] = 0;
       for(int i=1; i<=mx*3; i++) tree[i].reset();
       //init(1, 1, n);
        while(c--){
            scanf("%d", &doit);
            if(doit==0){
                scanf("%d %d %d", &x, &y, &z);
                update(1, 1, n, x, y, z);
            } else {
                scanf("%d %d", &x, &y);
                cout<<query(1, 1, n, x, y)<<endl;
            }
        }
    }
    return 0;
}
