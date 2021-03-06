#ifndef HOBO_AREA
#define HOBO_AREA

#include "container_entity.hpp"
#include "actor/actor.hpp"
#include "util/ptr_map.hpp"

#include <string>
#include <memory>
#include <unordered_map>

namespace hoboquest {

  class Actor;

  class Area : public ContainerEntity {
    public:
      typedef std::unordered_map<std::string, std::shared_ptr<Area>> exit_map;

    protected:
      PtrMap<Actor> _actors;
      std::string _description;
      exit_map _exits;

      void notify_actors(const std::string &event, std::shared_ptr<Entity> source);

    public:
      Area(const std::string &id, const std::string &name);
      
      void add_exit(const std::string &direction, std::shared_ptr<Area> exit);
      bool has_exit(const std::string &direction) const;
      std::shared_ptr<Area> get_exit(const std::string &direction) const;
      std::shared_ptr<Area> remove_exit(const std::string &direction);
      const exit_map & exits() const;

      virtual bool add_actor(std::shared_ptr<Actor> actor);
      bool has_actor(const std::string &id) const;
      std::shared_ptr<Actor> get_actor(const std::string &id) const;
      virtual void remove_actor(const std::string &id);

      void describe_exits(std::ostream &out) const;
      void describe_actors(std::ostream &out) const;
      virtual void describe(std::ostream &out) const;
  };
}

#endif
