#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> graph[], bool visited[], int start){
	visited[start] = true;
	cout << start << ' ';

	for(int i = 0; i < graph[start].size(); i++){
		int next = graph[start][i];
		if(!visited[next])
			dfs(graph, visited, next);
	}
}

int main(){
	int n, m, start;
	cin >> n >> m >> start;
	
	vector<int> graph[n+1];
    bool* visited = new bool[n+1];
	
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

    for(int i=1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(graph, visited, start);

	return 0;
}