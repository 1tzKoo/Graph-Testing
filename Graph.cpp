//
//  Graph.cpp
//  Graph_Project
//
//  Created by Kyle Schoby on 10/30/24.
//

#include "Graph.h"
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
    matrix.resize(V, vector<bool>(V, false));
}

Graph::~Graph(){
    delete[] adj;
}

void Graph::addEdge(int x, int y) {
    if (x >= V || y >= V || x < 0 || y < 0) {
        cout << "Invalid vertex number!" << endl;
        return;
    }
    if (!checkADJ(x,y)){
        adj[x].push_back(y);
        adj[y].push_back(x);
        
    }
}
bool Graph::checkADJ(int a, int b){
    bool T = false;
    if (a == b){
        return true;
    }
    for (int nbr : adj[a]){
        if (nbr == b){
            return true;
        }else {
            T = false;
        }
    }
        if (!T){
            for (int nbr : adj[b]){
                if (nbr == a){
                    return true;
                }
                else {
                    T = false;
                }
            }
        }
    return T;
}


void Graph::printADJList() {
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        for (int nbr : adj[i]) {
            cout << nbr << " ";
        }
        cout << endl;
    }
}

void Graph::printADJ(int Pos) {
    cout << "Vertex " << Pos << ": ";
    for (int nbr : adj[Pos]){
        cout << nbr << " ";
    }
}
void Graph::visitEdge(int x, int y){
    
    if (!checkVisit(x, y)){
        matrix[x][y] = true;
        matrix[y][x] = true;
    } else{
        Visit = true;
    }
}
bool Graph::checkVisit(int x, int y){
    if(matrix[x][y]){
        return true;
        
    } else if (matrix[y][x]){
        return true;
    }
    return false;
}

bool Graph::validateWalk(const vector<int>& walk) {
    for (size_t i = 0; i < walk.size() - 1; ++i) {
        int curr = walk.at(i);
        int next = walk.at(i+1);
        int end = walk.at(walk.size()-1);
        
        if (curr != end){
            bool found = false;
            if (checkADJ(curr, next)){
                found = true;
            }
        if (!found) {
            return false;
            }
        }
    }
    return true;
}

bool Graph::isOpen(const vector<int>& walk){
    int begin = walk.at(0);
    int end = walk.at(walk.size()-1);
    if (begin != end){
        return true;
    }
    return false;
}

bool Graph::isTrail(const vector<int>& walk){

    for (unsigned int i= 0; i < walk.size()-1; i++){
        int curr = walk.at(i);
        int next = walk.at(i+1);
        int end = walk.at(walk.size()-1);
        if (next == end){
            break;
        }
        visitEdge(curr, next);
    }
    if (!Visit){
        return true;
    }
    return false;
}

bool Graph::isPath(const vector<int>& walk){
    for (unsigned int i = 0; i < walk.size()-1; i++){
        int counter = 0;
        for(int e : walk){
            if (e == walk.at(i)){
                counter++;
                if (counter > 1){
                    return false;
                }
            }
        }
    }
    return true;
}

bool Graph::isCircuit(const vector<int>& walk){
    
    return !isOpen(walk) && isTrail(walk);
}

bool Graph::isCycle(const vector<int>& walk){
    
    return !isOpen(walk) && isPath(walk);
}
