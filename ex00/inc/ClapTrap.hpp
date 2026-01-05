#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <ostream>
using std::string;

class ClapTrap
{
  private:
	string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackPoints;


  public:
	// CONSTRUCTOR
	ClapTrap();
	ClapTrap(string name);
	ClapTrap(ClapTrap const &original);
	~ClapTrap();

	// OPERATOR
	ClapTrap &operator=(ClapTrap const &other);

	// MEMBER FUNCTION
	void attack(const string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// GETTER
	const string &getName(void) const;
	unsigned int getHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getAttackPoints(void) const;

	// SETTER
	void setEnergyPoints(unsigned int points);
	void setAttackPoints(unsigned int points);
	void setHitPoints(unsigned int points);

};
std::ostream &operator<<(std::ostream &o, const ClapTrap &obj);

#endif // !CLAPTRAT_HPP