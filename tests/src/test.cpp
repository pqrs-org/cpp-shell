#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/shell.hpp>

TEST_CASE("make_background_command_string") {
  {
    std::string command = "open '/Applications/Utilities/Activity Monitor.app'";
    std::string expected = "open '/Applications/Utilities/Activity Monitor.app' &";
    REQUIRE(pqrs::shell::make_background_command_string(command) == expected);
  }
  {
    std::string command = "open '/Applications/Utilities/Activity Monitor.app'&";
    std::string expected = "open '/Applications/Utilities/Activity Monitor.app'&";
    REQUIRE(pqrs::shell::make_background_command_string(command) == expected);
  }
  {
    std::string command = "ls & echo hello";
    std::string expected = "ls & echo hello &";
    REQUIRE(pqrs::shell::make_background_command_string(command) == expected);
  }
}
