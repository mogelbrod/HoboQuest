#ifndef HOBO_TEST_GAME
#define HOBO_TEST_GAME

#include <memory>
#include <cassert>
#include "../area.hpp"
#include "../actor/actor.hpp"
#include "../engine.hpp"
#include "../item/item.hpp"
#include "../item/equippable.hpp"
#include "../item/consumable.hpp"
// #include "../item/container_item.hpp"

using namespace std;
using namespace hoboquest;

/*
=================  TEST GAME MAP =================

                Dark forest
                    |
                    |
    Cliff ------ Forest ------ House ----
                    |            |      |
                    |            |    Cellar
                    |            |
                  Lake ------ Garden

Notes:
test_large() uses the full map.
test_small() only contains House, Cellar, Garden.
==================================================
*/

void test_small() {
  auto house = make_shared<Area>("house", "House");
  auto garden = make_shared<Area>("garden", "Garden");
  auto cellar = make_shared<Area>("cellar", "Cellar");

  auto player = make_shared<Actor>("player", "Player");
  auto troll = make_shared<Actor>("troll", "Troll");

  // auto bag = make_shared<ContainerItem>("Bag");
  auto beer = make_shared<Consumable>("beer", "Beer");
  auto book = make_shared<Equippable>("book", "Recipe Book");

  garden->add_exit("door", house);
  house->add_exit("front door", garden);
  house->add_exit("stairs", cellar);
  cellar->add_exit("stairs", house);

  garden->add_actor(player);
  cellar->add_actor(troll);

  //TODO add items
}

void test_large() {
  //TODO
}

void test_game() {
  test_small();
  test_large();
}

#endif
