#include <iostream>
#include<list>

using namespace std;

struct Node{
    int label;
    list<int> neighbours ;

};

struct Graph{
    int n=8;
    Node * nodes = new Node[n];

    void intializenodes(){
        for(int i=0;i<n;i++){
            nodes[i].label=i;
        }
    }

    void addedge(int u, int v) {
    nodes[u].neighbours.push_back(v);
}

    void print(){
        for (int i = 0; i < n; i++) {
            cout << "Node " << (nodes[i].label) + 1 << ": ";
            for (int neighbour : nodes[i].neighbours) {
                cout << neighbour << " ";
            }
            cout << endl;
        }

    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    g->addedge(1,2);
    g->addedge(1,3);
    g->addedge(1,4);
    g->addedge(1,5);
    g->addedge(2,3);
    g->addedge(2,6);
    g->addedge(4,6);
    g->addedge(4,7);
    g->addedge(4,8);
    g->addedge(5,6);
    g->addedge(5,7);
    g->addedge(5,8);
    g->print();
}