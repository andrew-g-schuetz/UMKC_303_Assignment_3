#include <iostream>

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        
    };

    Node* front;
    Node* back;
    int size;

public:
    Queue() : front(nullptr), back(nullptr), size(0) {}

   
    /// @brief Adds a value to the back of the queue
    /// @param value : value being added to the queue
    void Enqueue(int value) {
        Node* node = new Node();
        node->data = value;
        node->next = nullptr;
        
        if (isEmpty()) {
            front = node;
            back = node;
        } else {
            back->next = node;
            back = node;
        }
        size++;
    }

    /// @brief Deletes the value at the front of the queue
    /// @return The value deleted at the queue
    int Dequeue() {
        if (isEmpty()) {
            std::cout << "Error! Queue is already empty" << std::endl;
            return -1; 
        }
       
        int frontValue = front->data;
        front = front->next;
        
        size--;
        if (isEmpty()) {
            back = nullptr;
        }
        return frontValue;
    }

    /// @brief Gets the value at the front of the queue
    /// @return value at the front
    int getFront() const {
        if (isEmpty()) {
            std::cout << "Error! Queue is empty" << std::endl;
            return -1; 
        }
        return front->data;
    }

    /// @brief Checks to see if the queue is empty
    /// @return true if queue is empty or false otherwise
    bool isEmpty() const {
        if(size == 0) return true;
            return false;
    }

    /// @brief Size of the queue
    /// @return size property
    int getSize() const {
        return size;
    }

   
};

int main() {
    Queue queue;

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    queue.Enqueue(50);

    std::cout << "Front element: " << queue.getFront() << std::endl;
    std::cout << "Size of queue: " << queue.getSize() << std::endl;
    
    std::cout << "Dequeued: " << queue.Dequeue() << std::endl;
    std::cout << "Front element of queue: " << queue.getFront() << std::endl;
    std::cout << "Size of queue " << queue.getSize() << std::endl;
    
    
    
    std::cout << "Is queue empty? ";
    if(queue.isEmpty()){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

   
    


    return 0;
}
