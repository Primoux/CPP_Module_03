#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <ostream>

class FragTrap : public ClapTrap
{
  private:

  
  public:
	// CONSTRUCTOR
	FragTrap();
	FragTrap(const string &name);
	~FragTrap();
	FragTrap(FragTrap const &original);

	// OPERATOR
	FragTrap &operator=(ClapTrap const &other);

	// MEMBER FUNCTION
	void	highFivesGuys(void);

};
std::ostream &operator<<(std::ostream &o, const FragTrap &obj);

#endif // !FRAGTRAP_HPP