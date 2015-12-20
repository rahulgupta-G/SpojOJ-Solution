#include <bits//stdc++.h>

using namespace std;

#define mx 100000+10
int arr[mx];
struct node {
    int maxNum, secondMaxNum, totalMax;

    node init(int num) {
        maxNum = num;
        secondMaxNum = -1;
    }

    node merge(const node& l, const node& r) {
        maxNum = max(l.maxNum, r.maxNum);
        secondMaxNum = min(max(l.maxNum, r.secondMaxNum), max(r.maxNum, l.secondMaxNum));
        totalMax = maxNum + secondMaxNum;
    }
}tree[mx*4];

void build(int Node, int b, int e)
{
    if(b==e)
    {
        tree[Node].init(arr[b]);
        return;
    }

    int left = Node*2;
    int right = Node*2+1;
    int mid = (b+e)/2;
    build(left, b, mid);
    build(right, mid+1, e);
    tree[Node].merge(tree[left], tree[right]);
}

void query(node& resultNode, int Node, int b, int e, int i, int j)
{
    if(i > e || j < b) return;
    if(b == i && e == j) {
        resultNode = tree[Node];
        return;
    }
    int left = Node*2;
    int right = Node*2 + 1;
    int mid = (b+e)/2;
    if(j<=mid)
        query(resultNode, 2*Node, b, mid, i, j);
    else if(i>mid)
        query(resultNode, 2*Node+1, mid+1, e, i, j);
    else {
        node p1, p2;
        query(p1, left, b, mid, i, mid);
        query(p2, right, mid+1, e, mid+1, j);
        resultNode.merge( p1, p2 );
    }
}

void update(int node, int b, int e, int i, int newvalue)
{
    if(i > e || i < b) return;
    if(b == e)
    {
        tree[node].init(newvalue);
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    tree[node].merge(tree[left], tree[right]);
}

int main()
{
    int n,m;
    node res;
    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>arr[i];
    }
    build(1, 1, n);
    cin>>m;
    while(m--){
        char ch;
        int x, y;
        cin>>ch>>x>>y;
        if(ch== 'U') {
            update(1, 1, n, x, y);
        } else {
            query(res, 1, 1, n, x, y);
            printf("%d\n", res.totalMax);
        }
    }
    return 0;
}
