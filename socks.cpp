#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	long long scambi = 0;
	long C;
	unordered_map<long, int> calzini;
	cin >> N >> C;

	int prossimo_calzino;
	for (int i = 0; i < N; i++)
	{
		cin >> prossimo_calzino;
		auto paia = calzini.find(prossimo_calzino);
		if (paia != calzini.end())
		{
			scambi += paia->second;
		}
		else
		{
			scambi += calzini.size();
			calzini.insert(make_pair(prossimo_calzino, calzini.size()));
		}
	}
	cout << scambi << endl;
}
