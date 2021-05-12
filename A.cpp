#include <bits/stdc++.h>
using namespace std;
int process(int n)
{
	int tong = 0;
	while(n)
	{
		tong+=n%10;
		n/=10;
	}
	if(tong<10) return tong;
	return process(tong);
}
main()
{
	int n;
	cin >> n;
	cout << process(n) << endl;
}
