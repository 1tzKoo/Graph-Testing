#include "Graph.h"



int main(){
    
        int V;
        cout << "How many verticies are in your graph? " << endl;
        cin >> V;
        Graph G(V);
        for (int i = 0; i < V; i++){
            cout << "For Vertex " << i <<": who are their Neighbors? (-1 stops inquiry for Vertex " << i<<")" << endl;
            while(true){
                int ADJ;
                cin >> ADJ;
                
                if (ADJ >= 0){
                    G.addEdge(i, ADJ);
                } else if (ADJ > V || ADJ <-1){
                    cout << "Please insert a new vertex number, your vertex is out of scope: " << endl;
                } else {
                    break;
                }
            }
        }
        
        G.printADJList();
    
    
        cout << "Input walk sequence of alternating vertices that starts and ends with a vertex: (-1 stops input)" << endl;
        vector<int> Walk;
        int num;
        while (true) {
            cin >> num;
            if (num >= 0){
                Walk.push_back(num);
            } else {
                break;
            }
        }
    if (G.validateWalk(Walk)){
        cout << "WALK IS VALID!" << endl;
        cout << "The Walk Sequence <";
        for (int e : Walk){
            cout << e << ", ";
        }
        cout << "> has the following properties:" << endl;
        if (G.isOpen(Walk)){
            cout << "OPEN" << endl;
            if (G.isTrail(Walk)){
                cout << "TRAIL" << endl;
            }
            if (G.isPath(Walk)){
                cout << "PATH" << endl;
            }
        } else {
            cout << "CLOSED" << endl;
            if (G.isTrail(Walk)){
                cout << "TRAIL" << endl;}
            if (G.isCircuit(Walk)){
                cout << "CIRCUIT" << endl;}
            if (G.isCycle(Walk)){
                cout << "CYCLE" << endl;
            }
            if (G.isPath(Walk)){
                cout << "PATH" << endl;
            }
        }
    } else {
            cout << "WALK IS INVALID!" << endl;
        }
}
    
    
    /*
     Vertex 0: 3 2 1
     Vertex 1: 0 3
     Vertex 2: 1 4 2
     Vertex 3: 2 4 1
     Vertex 4: 0 1
     */

    
    

