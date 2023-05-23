#include <cstring>
#include <iostream>
using namespace std;
#define INF 9999999
#define V 6

int Adj[V][V] = {
  {0, 3, 0, 0, 0,1},
  {3, 0, 2, 1, 10,0},
  {0, 2, 0, 3, 0, 5},
  {0, 1, 3, 0, 5, 0},
  {0, 10, 0, 5, 0,4},
  {1, 0, 5, 0, 4,0}};

int main() {
  int no_edges;  
  int sel[V];
  memset(sel, false, sizeof(sel));
  no_edges = 0;
  sel[0] = true;
  int x;  
  int y;  
  cout << "Edge"
     << " : "
     << "Weight";
  cout << endl;
  while (no_edges < V - 1) {
    int min = INF;
    x = 0;
    y = 0;
    for (int i = 0; i < V; i++) {
      if (sel[i]) {
        for (int j = 0; j < V; j++) {
          if (!sel[j] && Adj[i][j]) { 
            if (min > Adj[i][j]) {
              min = Adj[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << Adj[x][y];
    cout << endl;
    sel[y] = true;
    no_edges++;
  }
  return 0;
}