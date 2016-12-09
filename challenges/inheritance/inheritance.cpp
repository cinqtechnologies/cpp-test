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

// Write your classes here
class Dog : public Animal
{
	public:
	void makeSound() const
	{
		std::cout << "woof\n";
	}
};

class Cat : public Animal
{
	public:
	void makeSound() const
	{
		std::cout << "meow\n";
	}
};

class Bird : public Animal
{
	public:
	void makeSound() const
	{
		std::cout << "tweet\n";
	}
};

class Mouse : public Animal
{
	public:
	void makeSound() const
	{
		std::cout << "squuek\n";
	}
};

class Cow : public Animal
{
	public:
	void makeSound() const
	{
		std::cout << "moo\n";
	}
};

class Frog : public Animal
{
	public:
	void makeSound() const
	{
		std::cout << "croak\n";
	}
};

class Elephant : public Animal
{
	public:
	void makeSound() const
	{
		std::cout << "toot\n";
	}
};

class Duck : public Animal
{
	public:
	void makeSound() const
	{
		std::cout << "quack\n";
	}
};

class Fish : public Animal
{
	public:
	void makeSound() const
	{
		std::cout << "blub\n";
	}
};

class Seal : public Animal
{
	public:
	void makeSound() const
	{
		std::cout << "ow ow ow\n";
	}
};

// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{
	if (name == "dog")
	{
		return new Dog();
	}
	else if (name == "cat")
	{
		return new Cat();
	}
	else if (name == "bird")
	{
		return new Bird();
	}
	else if (name == "cow")
	{
		return new Cow();
	}
	else if (name == "frog")
	{
		return new Frog();
	}
	else if (name == "elephant")
	{
		return new Elephant();
	}
	else if (name == "duck")
	{
		return new Duck();
	}
	else if (name == "fish")
	{
		return new Fish();
	}
	else if (name == "seal")
	{
		return new Seal();
	}
	else
	{
		return 0;
	}
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
