#ifndef HOBO_HELP_COMMAND
#define HOBO_HELP_COMMAND

#include "command.hpp"
#include "../actor/player.hpp"

#include <deque>
#include <string>

namespace hoboquest {
  class HelpCommand : public Command {
    public:
      HelpCommand() : Command("help", "h") {}

      CommandOutcome execute(Player &player, std::deque<std::string> &args) {
        player.message("Available commands:");
        player.out() << player.commands;
        return NOOP;
      }
  };
} /* hoboquest */ 

#endif
