#include <queue>
using namespace std;

void BFS(Graph &g, int start) {
    int V = g.size();

    bool* visited = new bool[V + 1];
    for (int i = 0; i <= V; i++)
        visited[i] = false;

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        Node* temp = g.getAdjList(curr);

        while (temp) {
            if (!visited[temp->val]) {
                q.push(temp->val);
                visited[temp->val] = true;
            }
            temp = temp->next;
        }
    }

    cout << '\n';
    delete[] visited;
}