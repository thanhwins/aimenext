#include <bits/stdc++.h>
using namespace std;
int pow(int a,int b) // return a^b
{
	long long res=1;
	for(int i=1;i<=b;i++) res*=a;
	return res;
}
int toInt(string s)
{
	int res=0;
	for(int i=0;i<s.length();i++)
	{
		res+=(s[i]-64)*(pow(27,s.length()-1-i));
	}
	return res;
}
string reverse(string s)
{
	string res="";
	for(int i=s.length()-1;i>=0;i--) res+=s[i];
	return res;
}
string toString(int n)
{
	string res = "";
	while(n)
	{
		res+=(char)(n%27+64);
		n=n/27;
	}
	return reverse(res);
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];  
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void process(string s[],int n)
{
	int t=0,a[1000];
	for(int i=0;i<n;i++)
	{
		t++;
		a[t]=toInt(s[i]);
	}
	quickSort(a,1,t+1);
	string res[1000];
	for(int i=1;i<=t;i++)
	{
		res[i]=toString(a[i]);
		//cout << res[i] << " ";
	}
	// print
	for(int i=1;i<=t;i++)
	{
		cout << res[i] << " ";
	}
}
main()
{
	string s[100]={"A","B","AA","BA","AZ","C"};
	process(s,6);
}
