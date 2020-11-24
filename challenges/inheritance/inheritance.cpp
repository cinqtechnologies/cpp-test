#include <iostream>
#include <string>
#include <exception>

class Animal
{
public:
	
	/**
	 * This function returns the sound made by each specific animal.
	 */
	virtual void makeSound() const = 0;

	/**
	 * Animal factory. Returns an instance of desired animal by its name.
	 * 
	 * @param name Desired animal name
	 */
	static Animal* create(const std::string& name);

	/**
	 * Destroys an animal instance.
	 * 
	 * @param animal Instance to be destroyed
	 */
	static void destroy(Animal* animal)
	{
		delete animal;
	}
};

/**
 * This class represents a dog.
 */
class Dog : public Animal
{
public:

	/**
	 * Class constructor.
	 */
	Dog() {}

	/**
	 * This method prints the sound made by this animal;
	 */
	void makeSound() const
	{
		std::cout << "woof" << std::endl;
	}
};

/**
 * This class represents a cat.
 */
class Cat : public Animal
{
public:

	/**
	 * Class constructor.
	 */
	Cat() {}

	/**
	 * This method prints the sound made by this animal;
	 */
	void makeSound() const
	{
		std::cout << "meow" << std::endl;
	}
};

/**
 * This class represents a bird.
 */
class Bird : public Animal
{
public:

	/**
	 * Class constructor.
	 */
	Bird() {}

	/**
	 * This method prints the sound made by this animal;
	 */
	void makeSound() const
	{
		std::cout << "tweet" << std::endl;
	}
};

/**
 * This class represents a mouse.
 */
class Mouse : public Animal
{
public:

	/**
	 * Class constructor.
	 */
	Mouse() {}

	/**
	 * This method prints the sound made by this animal;
	 */
	void makeSound() const
	{
		std::cout << "squeek" << std::endl;
	}
};

/**
 * This class represents a cow.
 */
class Cow : public Animal
{
public:

	/**
	 * Class constructor.
	 */
	Cow() {}

	/**
	 * This method prints the sound made by this animal;
	 */
	void makeSound() const
	{
		std::cout << "moo" << std::endl;
	}
};

/**
 * This class represents a frog.
 */
class Frog : public Animal
{
public:

	/**
	 * Class constructor.
	 */
	Frog() {}

	/**
	 * This method prints the sound made by this animal;
	 */
	void makeSound() const
	{
		std::cout << "croak" << std::endl;
	}
};

/**
 * This class represents an elephant.
 */
class Elephant : public Animal
{
public:

	/**
	 * Class constructor.
	 */
	Elephant() {}

	/**
	 * This method prints the sound made by this animal;
	 */
	void makeSound() const
	{
		std::cout << "toot" << std::endl;
	}
};

/**
 * This class represents a duck.
 */
class Duck : public Animal
{
public:

	/**
	 * Class constructor.
	 */
	Duck() {}

	/**
	 * This method prints the sound made by this animal;
	 */
	void makeSound() const
	{
		std::cout << "quack" << std::endl;
	}
};

/**
 * This class represents a fish.
 */
class Fish : public Animal
{
public:

	/**
	 * Class constructor.
	 */
	Fish() {}

	/**
	 * This method prints the sound made by this animal;
	 */
	void makeSound() const
	{
		std::cout << "blub" << std::endl;
	}
};

/**
 * This class represents a seal.
 */
class Seal : public Animal
{
public:

	/**
	 * Class constructor.
	 */
	Seal() {}

	/**
	 * This method prints the sound made by this animal;
	 */
	void makeSound() const
	{
		std::cout << "ow ow ow" << std::endl;
	}
};

// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{
	if (name == "dog")
	{
		return new Dog;
	}
	else if (name == "cat")
	{
		return new Cat;
	}
	else if (name == "bird")
	{
		return new Bird;
	}
	else if (name == "mouse")
	{
		return new Mouse;
	}
	else if (name == "cow")
	{
		return new Cow;
	}
	else if (name == "frog")
	{
		return new Frog;
	}
	else if (name == "elephant")
	{
		return new Elephant;
	}
	else if (name == "duck")
	{
		return new Duck;
	}
	else if (name == "fish")
	{
		return new Fish;
	}
	else if (name == "seal")
	{
		return new Seal;
	}
	else
	{
		return NULL;
	}
}

/**
 * This function returns the sound made by an animal identified by its name.
 * 
 * @param name Animal name
 */
void makeSound(const std::string& name)
{
	// Create our instance
	Animal* animal = Animal::create(name);

	if (animal)
	{
		animal->makeSound();
	}
	else
	{
		std::cout << name << " is not an animal" << std::endl;
	}
	

	// Destroy our instance
	Animal::destroy(animal);
}

/**
 * Program main function, returns an output text based on received inputs.
 * 
 * @param argc Number of arguments received from command line
 * @param argv Array of arguments received from command line
 */
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
