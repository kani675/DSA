#include<iostream>
using namespace std;
class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size);
    ~Stack();
    void push(int x);
    void pop();
    int peek();
    bool isEmpty();
};

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size);
    ~Queue();
    void enqueue(int x);
    void dequeue();
    int frontElement();
    bool isEmpty();
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
    void DFS(int startVertex);
    void BFS(int startVertex);
};


Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int x) {
    if (top == capacity - 1) {
        cout << "Stack overflow!" << endl;
        return;
    }
    arr[++top] = x;
}

void Stack::pop() {
    if (top == -1) {
        cout << "Stack underflow!" << endl;
        return;
    }
    top--;
}

int Stack::peek() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return arr[top];
}

bool Stack::isEmpty() {
    return top == -1;
}

Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(int x) {
    if (rear == capacity - 1) {
        cout << "Queue overflow!" << endl;
        return;
    }
    arr[++rear] = x;
}

void Queue::dequeue() {
    if (front > rear) {
        cout << "Queue underflow!" << endl;
        return;
    }
    front++;
}

int Queue::frontElement() {
    if (front > rear) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return arr[front];
}

bool Queue::isEmpty() {
    return front > rear;
}

AdjMatrix::AdjMatrix(int n, int e) {
    edges = e;
    noOfVertices = n;
    AdjacentMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        AdjacentMatrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AdjacentMatrix[i][j] = 0;
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
    cout << "Enter edges (u v) for " << edges << " edges:\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        AdjacentMatrix[u][v] = 1;
        AdjacentMatrix[v][u] = 1;
    }
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

void AdjMatrix::DFS(int startVertex) {
    bool* visited = new bool[noOfVertices] { false };
    Stack s(noOfVertices);
    s.push(startVertex);

    cout << "DFS Traversal starting from vertex " << startVertex << ": ";
    while (!s.isEmpty()) {
        int vertex = s.peek();
        s.pop();

        if (!visited[vertex]) {
            cout << vertex << " ";
            visited[vertex] = true;
        }

        for (int i = noOfVertices; i >0 ; i--) {
            if (AdjacentMatrix[vertex][i] == 1 && !visited[i]) {
                s.push(i);
            }
        }
    }
    cout << endl;
    delete[] visited;
}

void AdjMatrix::BFS(int startVertex) {
    bool* visited = new bool[noOfVertices] { false };
    Queue q(noOfVertices);
    q.enqueue(startVertex);
    visited[startVertex] = true;

    cout << "BFS Traversal starting from vertex " << startVertex << ": ";
    while (!q.isEmpty()) {
        int vertex = q.frontElement();
        q.dequeue();
        cout << vertex << " ";

        for (int i = 0; i < noOfVertices; i++) {
            if (AdjacentMatrix[vertex][i] == 1 && !visited[i]) {
                q.enqueue(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
    delete[] visited;
}



int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    AdjMatrix graph(vertices, edges);

    graph.setAdjMatrix();
    graph.displayMatrix();

    int startVertex;
    cout << "Enter starting vertex for DFS: ";
    cin >> startVertex;
    graph.DFS(startVertex);

    cout << "Enter starting vertex for BFS: ";
    cin >> startVertex;
    graph.BFS(startVertex);

    return 0;
}
