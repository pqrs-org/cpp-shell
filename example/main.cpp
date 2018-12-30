#include <iostream>
#include <pqrs/shell.hpp>

int main(void) {
  std::cout << pqrs::shell::make_background_command_string("/bin/ls -la /") << std::endl;
  std::cout << pqrs::shell::make_background_command_string("/bin/ls -la &") << std::endl;

  return 0;
}
