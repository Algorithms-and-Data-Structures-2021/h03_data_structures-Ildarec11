#include "linked_queue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedQueue::Enqueue(Element e) {
    SinglyNode* new_node = new SinglyNode(e, nullptr);
    if (size_ == 0) {
        front_ = new_node;
        back_ = new_node;
    } else {
        back_->next = new_node;
        back_ = new_node;
    }
    size_ ++;
  // TODO: напишите здесь свой код ...
}

void LinkedQueue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("could not dequeue from empty queue");
  }
  SinglyNode* node_to_delete = front_;
  if (size_>1) {
      front_ = front_->next;
  } else {
      front_ = nullptr;
      back_ = nullptr;
  }
  delete node_to_delete;
  size_--;
  // TODO: напишите здесь свой код ...
}

void LinkedQueue::Clear() {
    // TODO: напишите здесь свой код ...
    if (size_ != 0) {
        SinglyNode *current_node;
        SinglyNode *next_node = front_->next;
        delete front_;
        for (int i = 1; i < size_; i++) {
            current_node = next_node;
            next_node = current_node->next;
            delete current_node;
        }
        size_ = 0;
        front_ = nullptr;
        back_ = nullptr;
    }
}

// === РЕАЛИЗОВАНО ===

LinkedQueue::~LinkedQueue() {
  Clear();
}

std::optional<Element> LinkedQueue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedQueue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedQueue::IsEmpty() const {
  return size_ == 0;
}
int LinkedQueue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedQueue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis