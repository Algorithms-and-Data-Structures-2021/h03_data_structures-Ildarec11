#include "linked_stack.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedStack::Push(Element e) {
    SinglyNode* new_node = new SinglyNode(e, top_);
    top_ = new_node;
  // TODO: напишите здесь свой код ...
  size_++;
}

void LinkedStack::Pop() {
  if (top_ == nullptr) {
    throw std::logic_error("cannot pop out from empty stack");
  }
  SinglyNode* node_to_delete = top_;
  top_ = top_->next;
  delete node_to_delete;
  size_--;
  // TODO: напишите здесь свой код ...
}

void LinkedStack::Clear() {
  // TODO: напишите здесь свой код ...
  if (size_ >1 ) {
      SinglyNode* current_node;
      SinglyNode* next_node = top_->next;
  for (int i = 1; i < size_; i++) {
      current_node = next_node;
      next_node = current_node->next;
      delete current_node;
  }
  }
  if (size_!= 0)
    delete top_;
  size_ = 0;
  top_ = nullptr;
}

// === РЕАЛИЗОВАНО ===

LinkedStack::~LinkedStack() {
  Clear();
}

std::optional<Element> LinkedStack::Peek() const {
  return top_ == nullptr ? std::nullopt : std::make_optional(top_->data);
}

bool LinkedStack::IsEmpty() const {
  return size_ == 0;
}

int LinkedStack::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedStack &stack) {
  os << "size: " << stack.size_ << '\n';
  for (auto current_node = stack.top_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == stack.top_) os << "[TOP] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis