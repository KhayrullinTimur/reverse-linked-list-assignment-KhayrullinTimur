#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ > 0) {
      Node* curr = front_;
      Node* prev = nullptr;

      while (curr != back_) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      curr->next = prev;

      Node* back = back_;
      back_ = front_;
      front_ = back;
    }
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ > 0) {
      reverse_recursive_helper(front_, nullptr);
      Node* back = back_;
      back_ = front_;
      front_ = back;
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    Node* node = curr->next;
    curr->next = prev;

    if (node != nullptr) {
      reverse_recursive_helper(node, curr);
    }
  }

}  // namespace assignment
