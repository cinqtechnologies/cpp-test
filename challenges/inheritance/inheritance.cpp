#include <iostream>
#include <string>
#include <algorithm>

class Animal
{
public:
	/// This is the function which will be called to reproduce the sound each
	/// animal makes.
	virtual void makeSound() const = 0;

	/// This is our factory. You need to code the missing implementation.
	static Animal* create(const std::string& name);

	/// This function will terminate the class instance.
	static void destroy(Animal* animal)
	{
		delete animal;
	}
};

// Write your classes here
class Dog : public Animal
{
public:
    void makeSound() const
    {
	std::cout << "woof" << std::endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() const
    {
	std::cout << "meow" << std::endl;
    }
};

class Bird : public Animal
{
public:
    void makeSound() const
    {
	std::cout << "tweet" << std::endl;
    }
};

class Mouse : public Animal
{
public:
    void makeSound() const
    {
	std::cout << "squeek" << std::endl;
    }
};

class Cow : public Animal
{
public:
    void makeSound() const
    {
	std::cout << "moo" << std::endl;
    }
};

class Frog : public Animal
{
public:
    void makeSound() const
    {
	std::cout << "croak" << std::endl;
    }
};

class Elephant : public Animal
{
public:
    void makeSound() const
    {
	std::cout << "toot" << std::endl;
    }
};

class Duck : public Animal
{
public:
    void makeSound() const
    {
	std::cout << "quack" << std::endl;
    }
};

class Fish : public Animal
{
public:
    void makeSound() const
    {
	std::cout << "blub" << std::endl;
    }
};

class Seal : public Animal
{
public:
    void makeSound() const
    {
	std::cout << "ow ow ow" << std::endl;
    }
};

// For organization
enum string_enum {
    e_Cat,
    e_Dog,
    e_Bird,
    e_Mouse,
    e_Cow,
    e_Frog,
    e_Elephant,
    e_Duck,
    e_Fish,
    e_Seal
};

// Enum hashing function
string_enum get_enum(std::string const& str)
{
    if(str == "cat") return e_Cat;
    if(str == "dog") return e_Dog;
    if(str == "bird") return e_Bird;
    if(str == "mouse") return e_Mouse;
    if(str == "cow") return e_Cow;
    if(str == "frog") return e_Frog;
    if(str == "elephant") return e_Elephant;
    if(str == "duck") return e_Duck;
    if(str == "fish") return e_Fish;
    if(str == "seal") return e_Seal;
}

// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{
    Animal *animal = 0;
    switch(get_enum(name))
    {
	case e_Cat:
	    animal = new Cat();
	    break;
	case e_Dog:
	    animal = new Dog();
	    break;
	case e_Bird:
	    animal = new Bird();
	    break;
	case e_Mouse:
	    animal = new Mouse();
	    break;
	case e_Cow:
	    animal = new Cow();
	    break;
	case e_Frog:
	    animal = new Frog();
	    break;
	case e_Elephant:
	    animal = new Elephant();
	    break;
	case e_Duck:
	    animal = new Duck();
	    break;	   
	case e_Fish:
	    animal = new Fish();
	    break;
	case e_Seal:
	    animal = new Seal();
	    break;
	default:
	    std::cout << name << " is not an animal" << std::endl;
	    break;
    }
    return animal;
}

void makeSound(const std::string& name)
{
	// Create our instance
	Animal* animal = Animal::create(name);

	animal->makeSound();

	// Destroy our instance
	Animal::destroy(animal);
}

int main(int argc, char** argv)
{
	int n = 0;
	std::cin >> n;

	while(n--)
	{
		std::string animal;

		std::cin.ignore();
		std::cin >> animal;

		makeSound(animal);
	}

	return 0;
}
