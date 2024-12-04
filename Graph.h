//
//  Graph.hpp
//  Graph_Project
//
//  Created by Kyle Schoby on 10/30/24.
//

#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <list>
#include <vector>
using namespace std;



class Graph {
private:
    int V; // Number of vertices
    list<int> *adj;
    vector<vector<bool>> matrix;
    bool Visit = false;
   
    
public:
    
    //Constructor
    Graph(int V);
    //Destructor
    ~Graph();
    
    void addEdge(int x, int y);
    
    void printADJList();
    bool checkADJ(int a, int b);
    void printADJ(int Pos);
    
    void visitEdge(int x, int y);
    
    bool checkVisit(int x, int y);
    bool validateWalk(const vector<int>& walk);
    bool isOpen(const vector<int>& walk);
    bool isTrail(const vector<int>& walk);
    bool isPath(const vector<int>& walk);
    bool isCircuit(const vector<int>& walk);
    bool isCycle(const vector<int>& walk);

};

#endif
