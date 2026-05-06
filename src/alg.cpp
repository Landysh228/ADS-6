// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node * next;
    explicit Node(const T& value) : data(value), next(nullptr) {}
  };
  Node* head;
 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (head) {
      Node* tmp = head;
      head = head -> next;
      delete tmp;
    }
  }
  TPQueue(const TPQueue&) = delete;
  TPQueue& operator = (const TPQueue&) = delete;
  void push(const T& value) {
    Node * newNode = new Node(value);
    if (!head || value.prior > head->data.prior) {
      newNode -> next = head;
      head = newNode;
    } else {
      Node * curt = head;
      while (curt -> next && curt -> next -> data.prior >= value.prior) {
        curt = curt -> next;
      }
      newNode -> next = curt -> next;
      curt -> next = newNode;
    }
  }
  T pop() {
    if (!head) {
      throw "Queue is empty";
    }
    Node * tmp = head;
    T rslt = head -> data;
    head = head -> next;
    delete tmp;
    return rslt;
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
