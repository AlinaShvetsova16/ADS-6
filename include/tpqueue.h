// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (head != nullptr) {
            pop();
        }
    }

    void push(const T& item) {
        Node* newNode = new Node(item);

        if (head == nullptr || item.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data.prior >= item.prior) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    T pop() {
        if (head == nullptr) {
            throw std::runtime_error("Queue is empty");
        }

        T result = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return result;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
