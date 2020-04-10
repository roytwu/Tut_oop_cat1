#include <boost/algorithm/string.hpp>
class Cat{
private:
	bool m_angry;
	static int countObject; 
	int m_id;


public:
	Cat(); 
	~Cat();  
	
	bool m_happy;
	void jump();

	static int const MAX = 99;
	int getID();
};


