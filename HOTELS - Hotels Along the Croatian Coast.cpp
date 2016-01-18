#include <bits//stdc++.h>

using namespace std;

int main()
{
    int n, M, A[300001];
    cin>>n>>M;

    for(int i = 0; i < n; i++) cin>>A[i];

    int l = 0, r = 0, ans = 0, sum = 0;

    while(l < n)
    {
        while(r < n && sum + A[r] <= M) {
            sum += A[r];
            r++;
        }
        ans = max(ans, sum);
        sum -= A[l];
        l++;
    }

    cout<<ans<<endl;
    return 0;
}
