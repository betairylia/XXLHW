#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<double, int> pDouble;

int q;
vector<pDouble> p;
vector<string> str;

void fano(int s, int e, double sum)
{
	if (e == s + 1) return;

	double nSum = 0;
	int i, j;
	for (i = s; i < e; i++)
	{
		if (nSum + p[i].first > (sum / 2.00)) break;
		nSum += p[i].first;
		str[p[i].second] += '0';
	}

	if (i < e && ((sum - nSum) - nSum) > (nSum + p[i].first - (sum - nSum)))
	{
		nSum += p[i].first;
		str[p[i].second] += '0';
		i++;
	}

	for (j = i; j < e; j++)
	{
		str[p[j].second] += '1';
	}

	fano(s, i, nSum);
	fano(i, e, sum - nSum);
}

int main()
{
	cout << "This is a simple Fano Code example. By Zhang Yuhui (2013210875)" << endl << "Please input your data, format in <q> <p0> <p1> ..." << endl;
	cin >> q;
	
	int i;
	double sum = 0;
	pDouble tmp;
	for (i = 0; i < q; i++)
	{
		tmp.second = i;
		cin >> tmp.first;
		p.push_back(tmp);
		sum += tmp.first;
	}

	str.resize(q);

	//sort
	sort(p.begin(), p.end());
/*
	for (i = 0;i < p.size(); i++)
		cout << p[i].first << " " << p[i].second << endl;
*/
	fano(0, q, sum);

	cout << endl << "The answer is:" << endl << endl;

	for (i = 0;i < p.size(); i++)
		cout << "s" << i << "\t>\t" << str[i] << endl;

	cout << endl;
	system("pause");

	return 0;
}