#ifndef HOBO_ITEM_EQUIPPABLE
#define HOBO_ITEM_EQUIPPABLE

#include <string>

#include "item.hpp"

namespace hoboquest {
  class Actor;

  class Equippable : public Item {
    public:
      Equippable(std::string name, std::string description);

      virtual bool is_equippable() const;
      virtual void on_equip(std::shared_ptr<Actor> actor);
  };
}

#endif
