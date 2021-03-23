#include <iostream>

#include "array_stack.hpp"
#include "linked_dequeue.hpp"
#include "linked_queue.hpp"
#include "linked_stack.hpp"
using namespace itis;
using namespace std;

int main(int argc, char **argv) {

  auto stack = ArrayStack(10);
  cout << stack.IsEmpty();
  cout << stack.capacity();
  cout << stack.size();

  LinkedDequeue dequeue = LinkedDequeue();
  dequeue.Enqueue(Element::MERCEDES);
  dequeue.Enqueue(Element::FERRARI);
  dequeue.Enqueue(Element::BMW);


  DoublyNode* new_node = new DoublyNode(Element::MASERATI, nullptr, nullptr);
  delete new_node;

  SinglyNode* singlyNode = new SinglyNode(Element::BMW, nullptr );
  delete singlyNode;
  dequeue.Clear();

  return 0;
}