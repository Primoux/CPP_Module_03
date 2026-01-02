#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <ostream>
using std::string;

class Claptrap
{
  private:
	string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackPoints;

  public:
	// CONSTRUCTOR
	Claptrap(string name);
	~Claptrap();
	Claptrap(Claptrap const &original);

	// OPERATOR
	Claptrap &operator=(Claptrap const &other);
};
std::ostream &operator<<(std::ostream &o, const Claptrap &obj);

#endif // !CLAPTRAT_HPP