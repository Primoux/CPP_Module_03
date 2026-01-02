#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <ostream>
using std::string;

class Claptrap
{
  private:
	string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackPoints;

  public:
	// CONSTRUCTOR
	Claptrap(string name);
	~Claptrap();
	Claptrap(Claptrap const &original);

	// OPERATOR
	Claptrap &operator=(Claptrap const &other);

	// MEMBER FUNCTION
	void attack(const string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// GETTER
	const string &getName(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackPoints(void) const;

	// SETTER
	void setEnergyPoints(unsigned int points);
	void setAttackPoints(unsigned int points);
	void setHitPoints(unsigned int points);

};
std::ostream &operator<<(std::ostream &o, const Claptrap &obj);

#endif // !CLAPTRAT_HPP