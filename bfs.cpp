#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> graph[], bool visited[], int start){
	queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
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

    bfs(graph, visited, start);

	return 0;
}