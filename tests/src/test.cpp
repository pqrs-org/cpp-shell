#include <boost/ut.hpp>
#include <pqrs/shell.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "make_background_command_string"_test = [] {
    {
      std::string command = "open '/Applications/Utilities/Activity Monitor.app'";
      std::string expected = "open '/Applications/Utilities/Activity Monitor.app' &";
      expect(pqrs::shell::make_background_command_string(command) == expected);
    }
    {
      std::string command = "open '/Applications/Utilities/Activity Monitor.app'&";
      std::string expected = "open '/Applications/Utilities/Activity Monitor.app'&";
      expect(pqrs::shell::make_background_command_string(command) == expected);
    }
    {
      std::string command = "ls & echo hello";
      std::string expected = "ls & echo hello &";
      expect(pqrs::shell::make_background_command_string(command) == expected);
    }
  };

  return 0;
}
