// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
    T vall;
    Node* next;
  };

  Node* head;

 public:
  TPQueue() {
    head = nullptr;
  }

  ~TPQueue() {
    while (head != nullptr) {
      Node* tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  void push(T x) {
    Node* n = new Node;
    n->vall = x;
    n->next = nullptr;

    if (head == nullptr || x.prior > head->vall.prior) {
      n->next = head;
      head = n;
      return;
    }

    Node* cur = head;

    while (cur->next != nullptr &&
           cur->next->vall.prior >= x.prior) {
      cur = cur->next;
    }

    n->next = cur->next;
    cur->next = n;
  }

  T pop() {
    if (head == nullptr) {
      return T{};
    }

    Node* tmp = head;
    T res = head->vall;

    head = head->next;
    delete tmp;

    return res;
  }

  bool isEmpty() {
    return head == nullptr;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
