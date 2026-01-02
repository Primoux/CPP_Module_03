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
	Claptrap();
	~Claptrap();
	Claptrap(Claptrap const &original);
	Claptrap(string name);

	// OPERATOR
	Claptrap &operator=(Claptrap const &other);
};
std::ostream &operator<<(std::ostream &o, const Claptrap &obj);

#endif // !CLAPTRAT_HPP