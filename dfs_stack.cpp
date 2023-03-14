#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<int> graph[], bool visited[], int start){
	stack<int> s;
    s.push(start);
    visited[start] = true;

    while(!s.empty()){
        int cur = s.top();
        s.pop();
        cout << cur << ' ';
        
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            if(!visited[next]){
                visited[next] = true;
                s.push(next);
                break;
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

	dfs(graph, visited, start);

	return 0;
}