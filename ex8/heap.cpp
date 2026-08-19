#include <iostream>
using namespace std;

class BinHeap{
private:
        int* heap;
        int capacity;
        int size;

public:
        BinHeap(int capacity);
        ~BinHeap();
        void Enqueue(int key);
        int DequeueMin();
        int getMin();
        int decreaseToKey(int index, int newValue);
        int decreaseByKey(int index, int newValue);
        int increaseToKey(int index, int newValue);
        int increaseByKey(int index, int newValue);
        void buildHeap(int* arr, int n);
        bool isEmpty();
        bool isFull();
        int search(int key);
        void display();
        void perculateUp(int index);
        void perculateDown(int index);
};



BinHeap::BinHeap(int c) {
        capacity = c;
        size = 1;
        heap = new int[capacity];
        heap[0]=-999;
        for(int i=1;i<capacity;i++){
            heap[i]=-1;
        }
}

BinHeap::~BinHeap() {
        delete[] heap;
}

bool BinHeap::isEmpty() {
        return size == 1;
}
bool BinHeap::isFull() {
        return size==capacity;
}
void BinHeap::display() {
        if (isEmpty()) {
                cout << "The heap is empty!" << endl;
                return;
        }
        cout << "Heap elements: ";
        for (int i = 1; i < size; i++) {
                cout << heap[i] << " ";
        }
        cout << endl;
}

void BinHeap::Enqueue(int key) {
        if (isFull()) {
                cout << "Heap is full!" << endl;
                return;
        }
        heap[size] = key;
        cout<<"perculate Up"<<endl;
        perculateUp(size);
        size++;
}

int BinHeap::DequeueMin() {
        if (isEmpty()) {
                cout << "Heap is empty!" << endl;
                return -1;
        }
        int minValue = heap[1];
        heap[1] = heap[size-1];
        cout<<heap[1];
        heap[size]=-1;
        --size;
        cout<<"perculate Down"<<endl;
        perculateDown(1);
        return minValue;
}

int BinHeap::getMin() {
        if (isEmpty()) {
                cout << "Heap is empty!" << endl;
                return -1;
        }
        return heap[1];
}

int BinHeap::decreaseToKey(int oldValue, int newValue) {

        if(isEmpty()) {
                return -1;
        }
        int index=search(oldValue);
        if(index<0) {
                return -2;
        }
        else {
                heap[index]=newValue;
                cout<<"perculate Up"<<endl;
                perculateUp(index);
                return 1;
        }
}

int BinHeap::decreaseByKey(int oldValue, int reduce) {

        if(isEmpty()) {
                return -1;
        }
        int index=search(oldValue);
        if(index<0) {
                return -2;
        }
        else {
                heap[index]-=reduce;
                cout<<"perculate Up"<<endl;
                perculateUp(index);
                return 1;
        }
}

int BinHeap::increaseToKey(int oldValue, int newValue) {

        if(isEmpty()) {
                return -1;
        }
        int index=search(oldValue);
        if(index<0) {
                return -2;
        }
        else {
                heap[index]=newValue;
                cout<<"perculate Down"<<endl;
                perculateDown(index);
                return 1;
        }
}

int BinHeap::increaseByKey(int oldValue, int increase) {

        if(isEmpty()) {
                return -1;
        }
        int index=search(oldValue);
        if(index<0) {
                return -2;
        }
        else {
                heap[index]+=increase;
                cout<<"perculate Down"<<endl;
                perculateDown(index);
                return 1;
        }
}

int BinHeap::search(int key)
{
        if(isEmpty())
        {
                return -1;
        }
        else {
                for(int i=1; i<size; i++) {
                        if(key==heap[i]) {
                                return i;
                        }
                }
                return -2;
        }
}


void BinHeap::buildHeap(int* arr, int n) {
        if (n+1 > capacity) {
                cout << "Array size exceeds heap capacity!" << endl;
                return;
        }
        for (int i = 0; i < n; i++) {
                heap[i+1] = arr[i];
        }
        size = n+1;
        for (int i = (size / 2) ; i != 0; i--) {
                perculateDown(i);
        }
}

void BinHeap::perculateUp(int index) {
        while ((index)> 1) {
                int parentIndex = (index) / 2;
                if (heap[parentIndex] <= heap[index]) {
                        break;
                }
                int j =heap[parentIndex];
                heap[parentIndex] = heap[index];
                heap[index] = j;
                index = parentIndex;
        }
}

void BinHeap::perculateDown(int index) {
        while (index <= size) {
                int leftChild = 2 * index ;
                int rightChild = 2 * index + 1;
                int i = index;

                if (leftChild < size && heap[leftChild] < heap[i] ) {
                        i = leftChild;
                }

                if (rightChild < size && heap[rightChild] < heap[i]) {
                        i = rightChild;
                }

                if (heap[i] < heap[index]) {
                        int j =heap[index];
                    heap[index] = heap[i];
                    heap[i] = j;
                        index = i;
                } else {
                        break;
                }
        }
}


int main() {
        int capacity = 10;
        BinHeap pq(capacity);

        int ch, d;
        cout << "\n1. Enqueue\n2. Find MIN\n3. Dequeue\n4. IsEmpty\n5. Display\n6.DeleteByKey\n7.DeleteToKey\n8.IncreaseByKey\n9.IncreaseToKey \n10.Build Heap\n11.Exit\n";
        do {
                cout << "Enter your choice: ";
                cin >> ch;
                switch (ch) {
                case 1: {
                        cout << "Enter the data: ";
                        cin >> d;
                        pq.Enqueue(d);
                        cout << "The node is Enqueueed " << d << endl;
                        break;
                }
                case 2: {
                        int minValue = pq.getMin();
                        if (minValue == -1)
                                cout << "Empty" << endl;
                        else
                                cout << "The minimum term is " << minValue << endl;
                        break;
                }
                case 3: {
                        int minValue = pq.DequeueMin();
                        if (minValue == -1)
                                cout << "Empty" << endl;
                        else
                                cout << "The minimum term is " << minValue << endl;
                        break;
                }
                case 4: {
                        if (pq.isEmpty())
                                cout << "Heap is empty." << endl;
                        else
                                cout << "Heap is not empty." << endl;
                        break;
                }
                case 5: {
                        pq.display();
                        break;
                }
                case 6:
                {
                    int old,newVal;
                    cout<<"Enter the old and the value to reduce:";
                    cin>>old>>newVal;
                    int e = pq.decreaseByKey(old,newVal);
                    if(e<1){
                        cout<<"value not found"<<endl;
                    }
                    else{
                        cout<<"the Value is changed"<<endl;
                    }
                    break;
                }
                case 7:
                {
                    int old,newVal;
                    cout<<"Enter the old and the new values:";
                    cin>>old>>newVal;
                    int e = pq.decreaseToKey(old,newVal);
                    if(e<1){
                        cout<<"value not found"<<endl;
                    }
                    else{
                        cout<<"the Value is changed"<<endl;
                    }
                    break;
                }
                case 8:
                {
                    int old,newVal;
                    cout<<"Enter the old and the value to be increase:";
                    cin>>old>>newVal;
                    int e = pq.increaseByKey(old,newVal);
                    if(e<1){
                        cout<<"value not found"<<endl;
                    }
                    else{
                        cout<<"the Value is changed"<<endl;
                    }
                    break;
                }
                case 9:
                {
                    int old,newVal;
                    cout<<"Enter the old and the new values:";
                    cin>>old>>newVal;
                    int e = pq.increaseToKey(old,newVal);
                    if(e<1){
                        cout<<"value not found"<<endl;
                    }
                    else{
                        cout<<"the Value is changed"<<endl;
                    }
                    break;
                }
                case 10:
                {
                    int l;
                    int* a;
                    cout<<"Enter the array length:";
                    cin>>l;
                    a = new int[l];
                    cout<<"enter the values:";
                    for(int i = 0;i <l;i++){
                        cin>>a[i];
                    }
                    for(int i=0;i<l;i++){
                        cout<<a[i]<< " ";
                    }
                    pq.buildHeap(a,l);
                    break;
                }
                case 11: {
                        break;
                }
                default: {
                        cout << "Invalid choice." << endl;
                }
                }
        } while (ch != 11);

        return 0;
}
