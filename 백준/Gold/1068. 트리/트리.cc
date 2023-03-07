#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef struct node
{
	vector<int> child;
	int parent;
}node;

node tree[51];

int dfs(int index)
{
	if (!tree[index].child.size())
		return 1;

	int leaf_sum = 0;

	for (int i = 0; i < tree[index].child.size(); ++i)
		leaf_sum += dfs(tree[index].child[i]);
	return leaf_sum;
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, parent, root;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> parent;
		tree[i].parent = parent;
		if (parent != -1)
			tree[parent].child.push_back(i);
		else
			root = i;
	}

	int del;
	cin >> del;
	
	if (del != root)
	{
		for (int i = 0; i < tree[tree[del].parent].child.size(); ++i)
		{
			if (tree[tree[del].parent].child[i] == del)
			{
				tree[tree[del].parent].child.erase(tree[tree[del].parent].child.begin() + i);
				break;
			}
		}
		cout << dfs(root);
	}
	else
		cout << 0;
}