#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data;
  data.value = 3333;

  std::cout << "Data address: " << &data << std::endl;
  std::cout << "Data value: " << data.value << std::endl;

  uintptr_t serialized = Serializer::serialize(&data);
  std::cout << "Serialized value: " << serialized << std::endl;

  Data *deserialized = Serializer::deserialize(serialized);

  std::cout << "Deserialized Data address: " << deserialized << std::endl;
  std::cout << "Deserialized Data value: " << deserialized->value << std::endl;

  return 0;
}
