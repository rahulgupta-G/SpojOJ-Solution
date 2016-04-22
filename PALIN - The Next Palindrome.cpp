#include <bits//stdc++.h>
using namespace std;

int main()
{
    int T, i, j, len;
    cin >> T;

    while(T--) {
        string given, palin;
        cin >> given;
        palin = given;
        len = palin.size();
        i = 0, j = len - 1;

        while(i <= j) {
            palin[j] = palin[i];
            i++, j--;
        }
        i--;
        if(palin > given) cout << palin <<endl;
        else {
            if(i>=0 && palin[i] < '9') {
                palin[i]++;
                palin[len-1-i] = palin[i];
            }
            else {
                while(i>=0 && palin[i] == '9'){
                    // move towards the starting pos and replace it with 0
                    palin[i] = '0';
                    palin[len-1-i] = palin[i];
                    i--;
                }
                if(i>=0) {
                    // means reached a digit which is not 9
                    palin[i]++;
                    palin[len-i-1] = palin[i];
                }
                else {
                    //reached at pos 0
                    // need to insert a 1 before the string, 999 => 1 + 00 + 1
                    palin = '1' + palin;
                    palin[palin.size()-1] = '1'; // changin last position with 0
                }
            }
            cout << palin << endl;
        }
    }
}
