#include <bits/stdc++.h>
using namespace std;

string getLCS(string s1, string s2)
{
	string s;
	int lcs[101][101];
	memset(lcs, 0, sizeof(lcs));
	for(int i = 0; i <= s1.length(); ++i)
	{
		for(int j = 0; j <= s2.length(); ++j)
		{
			if(i == 0 || j == 0)
				lcs[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				lcs[i][j] = 1 + lcs[i-1][j-1];
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}
	int len = lcs[s1.length()][s2.length()];
	int i = s1.length(), j = s2.length();
	while(i > 0 and j > 0)
	{
		if(s1[i-1] == s2[j-1])
		{
			s += s1[i-1];
			i--;
			j--;
		}
		else
		{
			if(lcs[i-1][j] > lcs[i][j-1])
				i--;
			else
				j--;
		}
	}
	reverse(s.begin(), s.end());
	return s;
}

int main() 
{
	while(!cin.eof())
	{
		string s1, s2;
		cin>>s1>>s2;
		string s = getLCS(s1, s2);
		int i = 0, j = 0;
		for(int k = 0; k < s.length(); ++k)
		{
			while(i < s1.length() and s1[i] != s[k])
			{
				cout<<s1[i];
				i++;
			}
			while(j < s2.length() and s2[j] != s[k])
			{
				cout<<s2[j];
				j++;
			}
			cout<<s[k];
			i++;
			j++;
		}
		while(i < s1.length())
		{
			cout<<s1[i];
			i++;
		}
		while(j < s2.length())
		{
			cout<<s2[j];
			j++;
		}
		cout<<"\n";
	}
	return 0;
}
