#include <iostream>

#include "array_stack.hpp"

using namespace itis;
using namespace std;

int main(int argc, char **argv) {

  auto stack = ArrayStack(10);
  cout << stack.IsEmpty();
  cout << stack.capacity();
  cout << stack.size();

  return 0;
}