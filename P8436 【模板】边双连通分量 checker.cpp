#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > Input, Ans;
int node;
bool cmp(vector <int> x, vector <int> y)
{
	if (x.size() != y.size()) return x.size() < y.size();
	return x[0] < y[0]; 	
}
int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    int input_ans = ouf.readInt(), std_ans = ans.readInt();
    if (input_ans != std_ans)
    	quitf(_wa, "The number of E-DCC is %d, but your answer is %d.", std_ans, input_ans);
	for (int i = 0; i < std_ans; ++i)
	{
		Ans.push_back(vector <int>());
		int x = ans.readInt();
		for (int j = 1; j <= x; ++j)
		{
			node = ans.readInt();
			Ans[i].push_back(node);
		}
	}
	for (int i = 0; i < input_ans; ++i)
	{
		Input.push_back(vector <int>());
		int x = ouf.readInt();
		for (int j = 1; j <= x; ++j)
		{
			node = ouf.readInt();
			Input[i].push_back(node);
		}
	}
	for (int i = 0; i < std_ans; ++i)
	{
		sort(Input[i].begin(), Input[i].end());
		sort(Ans[i].begin(), Ans[i].end());
	}
	sort(Input.begin(), Input.end(), cmp);
	sort(Ans.begin(), Ans.end(), cmp);
	for (int i = 0; i < std_ans; ++i)
	{
		if (Ans[i].size() != Input[i].size())
			quitp(0.5, "Wrong size of E-DCC.");
		for (int j = 0; j < (int)Ans[i].size(); ++j)
			if (Ans[i][j] != Input[i][j])
				quitp(0.5, "Your output contains the wrong nodes.");
	}
	quitf(_ok, "Accepted! CSP/NOIP/NOI RP++!");
}
