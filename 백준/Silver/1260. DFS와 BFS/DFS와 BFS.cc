#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct node
{
	vector<int> child;
} node;

node nd[1001];
int visit[1001];
int stack[100000];
int top;
int queue[100000];
int front, rear;

void push_stack(int num)
{
	stack[++top] = num;
}

int pop_stack()
{
	return stack[top--];
}

void push_queue(int num)
{
	queue[front++] = num;
}

int pop_queue()
{
	return queue[rear++];
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, M, V;

	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		nd[s].child.push_back(e);
		nd[e].child.push_back(s);
	}
	top = -1;
	front = rear = 0;

	for (int i = 1; i <= N; ++i)
		sort(nd[i].child.begin(), nd[i].child.end());
	
	push_stack(V);
	memset(visit, 0, sizeof(visit));
	while (top > -1)
	{
		int p = pop_stack();
		if (visit[p])
			continue;
		visit[p] = 1;
		cout << p << " ";
		for (int i = nd[p].child.size() - 1; i >= 0; --i)
		{
			if (!visit[nd[p].child[i]])
			{
				push_stack(nd[p].child[i]);
			}
		}
	}
	cout << "\n";
	memset(visit, 0, sizeof(visit));
	push_queue(V);
	visit[V] = 1;
	while (front != rear)
	{
		int p = pop_queue();
		cout << p << " ";
		for (int i = 0; i < nd[p].child.size(); ++i)
			if (!visit[nd[p].child[i]])
			{
				push_queue(nd[p].child[i]);
				visit[nd[p].child[i]] = 1;
			}
	}

}