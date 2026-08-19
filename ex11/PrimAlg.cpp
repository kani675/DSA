#include <iostream>
#include <climits>
using namespace std;

class BinHeap {
private:
    int* heap;
    int* weight;   // Stores weights of vertices for priority ordering
    int capacity;
    int size;

public:
    BinHeap(int capacity);
    ~BinHeap();
    void Enqueue(int vertex, int w);
    int DequeueMin();
    int getMin();
    bool isEmpty();
    bool isFull();
    int decreaseToKey(int, int);
    void percolateUp(int index);
    void percolateDown(int index);
    friend class Prims;
};
class AdjMatrix {
private:
    int edges;
    int noOfVertices;
    int** AdjacentMatrix;

public:
    AdjMatrix(int n, int e);
    ~AdjMatrix();
    void displayMatrix();
    void setAdjMatrix();
    int** getMatrix();
    friend class Prims;
};
class Prims {
private:
   // int noOfVertices;
    //int edges;
    BinHeap m;
    AdjMatrix matrix;
    int MSTcost;

public:
    Prims(int n, int e);
    void constructMST(int start);
    void setAdjMatrix();
    void displayMatrix();
};

BinHeap::BinHeap(int c) {
    capacity = c;
    size = 0;
    heap = new int[capacity];
    weight = new int[capacity];
}

BinHeap::~BinHeap() {
    delete[] heap;
    delete[] weight;
}

int BinHeap::decreaseToKey(int vertex, int newWeight) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == vertex) {
            if (weight[i] > newWeight) {
                weight[i] = newWeight;
                percolateUp(i);
            }
            return 1;
        }
    }
    return -2;
}

bool BinHeap::isEmpty() {
    return size == 0;
}

bool BinHeap::isFull() {
    return size == capacity;
}

void BinHeap::Enqueue(int vertex, int w) {
    if (isFull()) {
        cout << "Heap is full!" << endl;
        return;
    }
    heap[size] = vertex;
    weight[size] = w;
    percolateUp(size);
    size++;
}

int BinHeap::DequeueMin() {
    if (isEmpty()) {
        cout << "Heap is empty!" << endl;
        return -1;
    }
    int minVertex = heap[0];
    heap[0] = heap[size - 1];
    weight[0] = weight[size - 1];
    size--;
    percolateDown(0);
    return minVertex;
}

int BinHeap::getMin() {
    if (isEmpty()) {
        cout << "Heap is empty!" << endl;
        return -1;
    }
    return heap[0];
}

void BinHeap::percolateUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (weight[parentIndex] <= weight[index]) {
            break;
        }
        //swap(heap[parentIndex], heap[index]);
        int temp=heap[parentIndex];
        heap[parentIndex]=heap[index];
        heap[index]=temp;
        //swap(weight[parentIndex], weight[index]);
        int temp2=weight[parentIndex];
        weight[parentIndex]=weight[index];
        weight[index]=temp2;
        index = parentIndex;
    }
}

void BinHeap::percolateDown(int index) {
    while (2 * index + 1 < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && weight[leftChild] < weight[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && weight[rightChild] < weight[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
          //  swap(heap[index], heap[smallest]);
           int temp=heap[index];
           heap[index]=heap[smallest];
           heap[smallest]=temp;
          // swap(weight[index], weight[smallest]);
           int temp2=weight[index];
           weight[index]=weight[smallest];
           weight[smallest]=temp2;
           index = smallest;
        } else {
            break;
        }
    }
}

AdjMatrix::AdjMatrix(int n, int e) {
    noOfVertices = n;
    edges = e;
    AdjacentMatrix = new int*[noOfVertices];
    for (int i = 0; i < noOfVertices; i++) {
        AdjacentMatrix[i] = new int[noOfVertices];
    }
    for(int i = 0 ; i < noOfVertices ; i++){
       for(int j=0;j<noOfVertices;j++){
          AdjacentMatrix[i][j]=0;
    }
}
}
AdjMatrix::~AdjMatrix() {
    for (int i = 0; i < noOfVertices; i++) {
        delete[] AdjacentMatrix[i];
    }
    delete[] AdjacentMatrix;
}

void AdjMatrix::setAdjMatrix() {
    cout << "Enter edges (u v w) where u and v are vertex indices (0-indexed):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        cout << "Its weight: ";
        cin >> w;
        AdjacentMatrix[u][v] = w;
        AdjacentMatrix[v][u] = w;
    }
}

int** AdjMatrix::getMatrix() {
    return AdjacentMatrix;
}

void AdjMatrix::displayMatrix() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            cout << AdjacentMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

Prims::Prims(int n, int e) : m(n), matrix(n, e)
{
    //noOfVertices = n;
    //edges = e;
    MSTcost = 0;
    //matrix(n,e);
    //m(n);
}

void Prims::setAdjMatrix() {
    matrix.setAdjMatrix();
}

void Prims::displayMatrix() {
    matrix.displayMatrix();
}

void Prims::constructMST(int start) {
    int** AdjacentMatrix = matrix.getMatrix();
    bool* visited = new bool[matrix.noOfVertices];
    for(int i=0;i<matrix.noOfVertices;i++)
    {
       visited[i]=false;
    }
    int* parent = new int[matrix.noOfVertices];
    int* key = new int[matrix.noOfVertices];

    for (int i = 0; i < matrix.noOfVertices; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[start] = 0;
    m.Enqueue(start, 0);

    while (!m.isEmpty()) {
        int u = m.DequeueMin();
        visited[u] = true;

        for (int v = 0; v < matrix.noOfVertices; v++) {
            if (AdjacentMatrix[u][v] != 0 && !visited[v] && AdjacentMatrix[u][v] < key[v]) {
                key[v] = AdjacentMatrix[u][v];
                parent[v] = u;

                int result = m.decreaseToKey(v, key[v]);
                if (result == -2) {  // Vertex not in the heap
                    m.Enqueue(v, key[v]);
                }
            }
        }
    }

    cout << "Vertex\tPath Towards\tWeight\n";
    for (int i = 0; i < matrix.noOfVertices; i++) {
        if (parent[i] != -1 && parent[i] != i) {
            cout << i << "\t" << parent[i] << "\t\t" << AdjacentMatrix[parent[i]][i] << endl;
            MSTcost += AdjacentMatrix[parent[i]][i];
        }
    }
    cout << "\nThe total MST cost is: " << MSTcost << endl;

    delete[] visited;
    delete[] parent;
    delete[] key;
}


int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    Prims prims(vertices, edges);

    prims.setAdjMatrix();
    prims.displayMatrix();

    int startVertex;
    cout << "Enter the starting vertex for Prim's MST: ";
    cin >> startVertex;

    prims.constructMST(startVertex);

    return 0;
}
