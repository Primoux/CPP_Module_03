#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <ostream>

class ScavTrap : public ClapTrap
{
  private:
	

  public:
	// CONSTRUCTOR
	ScavTrap();
	ScavTrap(const string &name);
	ScavTrap(ScavTrap const &original);
	~ScavTrap();

	// OPERATOR
	ScavTrap &operator=(ScavTrap const &other);

	// MEMBER FUNCTION
	void guardGate(void);
};
std::ostream &operator<<(std::ostream &o, const ScavTrap &obj);

#endif // !SCAVTRAP_HPP