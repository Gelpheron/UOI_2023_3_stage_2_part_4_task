// D second tour.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct  Rect
{
	int x1, x2, y1, y2;
};
bool Cross(Rect a, Rect b)
{
	return !(a.x1 > b.x2 || a.x2 < b.x1 || a.y2<b.y1 || a.y1>b.y2);
}
int main()
{
	int n, m, k;
	cin >> n;//x
	cin >> m;//y
	cin >> k;
	int curr;
	vector <Rect> rects(k);
	vector <vector<int>> graph(k);
	for (int i = 0; i < k; i++)
	{
		cin >> rects[i].x1;
		cin >> rects[i].y1;
		cin >> rects[i].x2;
		cin >> rects[i].y2;
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (Cross(rects[i], rects[j]) && i != j)
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	vector <bool> used(k, false);
	for (int i = 0; i < k; i++)
	{
		if ((rects[i].x1 == 0 || rects[i].y2 == m) && !used[i])
		{
			queue <int> que;
			que.push(i);
			used[i] = true;
			while (!que.empty())
			{
				curr = que.front();
				que.pop();
				if (rects[curr].y1 == 0 || rects[curr].x2 == n)
				{
					cout << "NO";
					return 0;
				}
				int size = graph[curr].size();
				for (int j = 0; j < size; j++)
				{
					if (!used[graph[curr][j]])
					{
						used[graph[curr][j]] = true;
						que.push(graph[curr][j]);
					}

				}

			}
		}
	}
	cout << "YES";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
