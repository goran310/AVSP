#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int n;
string str[100];

double WP(int i, int j)
{
	int wp1 = 0;
	int wp2 = 0;
	for(int k = 0; k < n; ++ k)
	{
		if(k == j) continue;
		if(str[i][k] == '1')
		{
			wp1 ++;
			wp2 ++;
		}
		else if(str[i][k] == '0')
		{
			wp2 ++;
		}
	}
	return (double)wp1 / (double)wp2;
}

double OWP(int i, int j)
{
	double average = 0.0;
	int cnt = 0;
	for(int k = 0; k < n; ++ k)
	{
		if(str[i][k] != '.')
		{
			average += WP(k, i);
			++ cnt;
		}
	}
	return average / (double)cnt;
}

double OOWP(int i, int j)
{
	double average = 0.0;
	int cnt = 0;
	for(int k = 0; k < n; ++ k)
	{
		if(str[i][k] != '.')
		{
			average += OWP(k, i);
			++ cnt;
		}
	}
	return average / (double)cnt;
}

int main()
{
	freopen("1.in", "rb", stdin);
	freopen("res.out", "wb", stdout);
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; ++ tt)
	{
		cout << "Case #" << tt << ":" << endl;
		cin >> n;
		for(int i = 0; i < n; ++ i)
		{
			cin >> str[i];
		}
		for(int i = 0; i < n; ++ i)
		{
			double wp = WP(i, i);
			double owp = OWP(i, i);
			double oowp = OOWP(i, i);
			cout << 0.25 * wp + 0.50 * owp + 0.25 * oowp << endl;
		}
	}
	return 0;
}