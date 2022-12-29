class MyCircularQueue {
public:
    int i, j, n, sz;
    vector<int> q;
    MyCircularQueue(int k) {
        q = vector<int> (k, -1);
        i = 0;
        j = 0;
        n = k;
        sz = 0;
    }

    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            i = 0, j = 0;
            q[j] = value;
            sz++;
            return true;
        }
        j++;
        j = j%n;
        q[j] = value;
        sz++;
        return true;
    }

    bool deQueue() {
        if(isEmpty()) return false;
        i++;
        i = i%n;
        sz--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : q[i];
    }

    int Rear() {
        return isEmpty() ? -1 : q[j];
    }

    bool isEmpty() {
        return sz==0;
    }

    bool isFull() {
        return sz==n;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
