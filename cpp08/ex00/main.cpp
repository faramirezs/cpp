#include "easyfind.hpp"
#include <vector>

int main() {

  int arr[] = {0, 1, 2, 3, 4, 5};
  std::vector<int> vec(arr, arr + 6);
  try {
    std::vector<int>::iterator iti = easyfind(vec, 2);
    std::cout << "Found: " << *iti << std::endl;
    std::vector<int>::iterator oto = easyfind(vec, 9);
    std::cout << "Found: " << *oto << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
