#include <iostream>
#include <string>

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

class Dog : virtual public Animal
{
public:
	void makeSound() const { std::cout << "woof" << std::endl; };
};
class Cat : virtual public Animal
{
public:
	void makeSound() const { std::cout << "meow" << std::endl; };
};
class Bird : virtual public Animal
{
public:
	void makeSound() const { std::cout << "tweet" << std::endl; };
};
class Mouse : virtual public Animal
{
public:
	void makeSound() const { std::cout << "squeek" << std::endl; };
};
class Cow : virtual public Animal
{
public:
	void makeSound() const { std::cout << "moo" << std::endl; };
};
class Frog : virtual public Animal
{
public:
	void makeSound() const { std::cout << "croak" << std::endl; };
};
class Elephant :virtual  public Animal
{
public:
	void makeSound() const { std::cout << "toot" << std::endl; };
};
class Duck : virtual public Animal
{
public:
	void makeSound() const { std::cout << "quack" << std::endl; };
};
class Fish : virtual public Animal
{
public:
	void makeSound() const { std::cout << "blub" << std::endl; };
};
class Seal : virtual public Animal
{
public:
	void makeSound() const { std::cout << "ow ow ow" << std::endl; };
};


// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{
	if (name.compare("dog") == 0)
		return new Dog();
	else if (name.compare("cat") == 0)
		return new Cat();
	else if (name.compare("bird") == 0)
		return new Bird();
	else if (name.compare("mouse") == 0)
		return new Mouse();
	else if (name.compare("cow") == 0)
		return new Cow();
	else if (name.compare("frog") == 0)
		return new Frog();
	else if (name.compare("elephant") == 0)
		return new Elephant();
	else if (name.compare("duck") == 0)
		return new Duck();
	else if (name.compare("fish") == 0)
		return new Fish();
	else if (name.compare("seal") == 0)
		return new Seal();
	else {
		std::cout << name << " is not an animal" << std::endl;
		return 0;
	}
}

void makeSound(const std::string& name)
{
	// Create our instance
	Animal* animal = Animal::create(name);

	if (animal != 0) {
		animal->makeSound();

		// Destroy our instance
		Animal::destroy(animal);
	}
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
