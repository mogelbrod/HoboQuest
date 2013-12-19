#ifndef HOBO_CONTAINER
#define HOBO_CONTAINER

#include <string>
#include <unordered_map>
#include <utility>
#include <memory>
#include "item.hpp"

namespace hoboquest {
	class Container {
		protected:
      std::unordered_map<std::string, std::shared_ptr<Item>> _items;
      unsigned _capacity, _carrying, _money;

		public:
			Container() : _capacity(100), _carrying(0), _money(0) {}

      unsigned carrying() const { return this->_carrying; }
      unsigned capacity() const { return this->_capacity; }
      bool over_encumbered() const {
        return this->_carrying > this->_capacity;
      }

      unsigned money() const { return this->_money; }
      unsigned take_money(unsigned amount) {
        if (amount > this->_money)
          return amount = this->_money;
        this->_money -= amount;
        return amount;
      }
      unsigned take_money() { return this->take_money(this->_money); }
      void give_money(unsigned amount) { this->_money += amount; }

      void set_capacity(unsigned capacity) { this->_capacity = capacity; }

			bool has_item(const std::string &name) const {
				return this->_items.count(name) > 0;
			}

      // Returns item or nullptr.
      std::shared_ptr<Item> get_item(const std::string &name) const {
        if (!this->has_item(name))
          return nullptr;
				return this->_items.at(name);
			}

			bool pickup(std::shared_ptr<Item> item) {
        // Already has item
        if (this->has_item(item->name()))
          return false;
        // Not enough carrying capacity remaining?
        if (item->weight() > this->capacity() - this->carrying())
          return false;
				this->_items[item->name()] = item;
        this->_carrying += item->weight();
        return true;
			}

      // Drops and returns item if present, otherwise returns nullptr
      std::shared_ptr<Item> drop(const std::string &name) {
        std::shared_ptr<Item> item = this->get_item(name);
        if (item != nullptr) {
          this->_items.erase(name);
          this->_carrying -= item->weight();
        }
				return item;
			}
	};
}

#endif
