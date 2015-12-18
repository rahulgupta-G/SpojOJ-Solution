    /*  We need only 2 things in each segment tree node,
        1) The number of unmatched open parenthesis in this range
        2) The number of unmatched closed parenthesis in this range
    */

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <ctime>
#include <climits>
#include <iomanip>
#include <sstream>

using namespace std;

typedef long long LL;
#define MAX 30000+10

char str[MAX];
struct node {
    int open, close;
    node():close(0),open(0){}

    void init(char s){
        if(s == '(') open = 1, close = 0;
        else close = 1, open = 0;
    }

    void merge(const node& l, const node& r) {
        int mini = min(l.open, r.close);
        open = l.open + r.open - mini;
        close = l.close + r.close - mini;
    }
}tree[4*MAX];

void build(int node, int b, int e)
{
    if(b==e) {
        tree[node].init(str[b]);
        return;
    }

    int mid = (b+e)/2;

    build(node*2, b, mid);
    build(node*2+1, mid+1, e);

    tree[node].merge(tree[node*2], tree[node*2+1]);
}

void update(int node, int b, int e, int pos)
{
    if(pos>e || pos<b) return;
    if(b==e) {
        if(str[b]== '(') str[b] = ')';
        else str[b] = '(';
        tree[node].init(str[b]);
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    update(left, b, mid, pos);
    update(right, mid+1, e, pos);

    tree[node].merge(tree[left], tree[right]);
}
int main()
{
    clock_t startTime = clock();
    ios_base::sync_with_stdio(false);

    int test = 10;
    while(test--){
        int n; scanf("%d", &n);
        scanf("%s", str);
        build(1, 0, n-1);

        int m; scanf("%d", &m);
        printf("Test %d:\n", 10-test);

        while(m--){
            int q; scanf("%d", &q);
            if(!q) {
                bool ans  = !tree[1].open && !tree[1].close;
                if(ans) puts("YES");
                else puts("NO");
            } else {
                --q;
                update(1, 0, n-1, q);
            }
        }
    }

    clock_t endTime = clock();
    cout<<"\nTime:"<< double(endTime - startTime) / CLOCKS_PER_SEC <<" seconds\n" ;

    return 0;
}
