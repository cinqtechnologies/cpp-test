#include <iostream>
#include <string>

// Dog goes "woof"
// Cat goes "meow"
// Bird goes "tweet"
// And mouse goes "squeek"
// Cow goes "moo"
// Frog goes "croak"
// And the elephant goes "toot"
// Ducks say "quack"
// And fish go "blub"
// And the seal goes "ow ow ow"
#define ANIMAL_NAME_DOG					"dog"
#define ANIMAL_NAME_CAT					"cat"
#define ANIMAL_NAME_BIRD				"bird"
#define ANIMAL_NAME_MOUSE				"mouse"
#define ANIMAL_NAME_COW					"cow"
#define ANIMAL_NAME_FROG				"frog"
#define ANIMAL_NAME_ELEPHANT		"elephant"
#define ANIMAL_NAME_DUCK				"duck"
#define ANIMAL_NAME_FISH				"fish"
#define ANIMAL_NAME_SEAL				"seal"

#define ANIMAL_SOUND_DOG				"woof"
#define ANIMAL_SOUND_CAT				"meow"
#define ANIMAL_SOUND_BIRD				"tweet"
#define ANIMAL_SOUND_MOUSE			"squeek"
#define ANIMAL_SOUND_COW				"moo"
#define ANIMAL_SOUND_FROG				"croak"
#define ANIMAL_SOUND_ELEPHANT		"toot"
#define ANIMAL_SOUND_DUCK				"quack"
#define ANIMAL_SOUND_FISH				"blub"
#define ANIMAL_SOUND_SEAL				"ow ow ow"

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
	void makeSound() const override
	{
		std::cout << ANIMAL_SOUND_DOG << std::endl;
	}
};

// Class Cat
class Cat : public Animal
{
public:
	void makeSound() const override
	{
		std::cout << ANIMAL_SOUND_CAT << std::endl;
	}
};

// Class Bird
class Bird : public Animal
{
public:
	void makeSound() const override
	{
		std::cout << ANIMAL_SOUND_BIRD << std::endl;
	}
};

// Class Mouse
class Mouse : public Animal
{
public:
	void makeSound() const override
	{
		std::cout << ANIMAL_SOUND_MOUSE << std::endl;
	}
};

// Class Cow
class Cow : public Animal
{
public:
	void makeSound() const override
	{
		std::cout << ANIMAL_SOUND_COW << std::endl;
	}
};

// Class Frog
class Frog : public Animal
{
public:
	void makeSound() const override
	{
		std::cout << ANIMAL_SOUND_FROG << std::endl;
	}
};

// Class Elephant
class Elephant : public Animal
{
public:
	void makeSound() const override
	{
		std::cout << ANIMAL_SOUND_ELEPHANT << std::endl;
	}
};

// Class Duck
class Duck : public Animal
{
public:
	void makeSound() const override
	{
		std::cout << ANIMAL_SOUND_DUCK << std::endl;
	}
};

// Class Fish
class Fish : public Animal
{
public:
	void makeSound() const override
	{
		std::cout << ANIMAL_SOUND_FISH << std::endl;
	}
};

// Class Seal
class Seal : public Animal
{
public:
	void makeSound() const override
	{
		std::cout << ANIMAL_SOUND_SEAL << std::endl;
	}
};

// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{
	Animal* new_animal = NULL;

	if (name.compare(ANIMAL_NAME_DOG) == 0)
	{
		new_animal = new Dog();
	}
	else if (name.compare(ANIMAL_NAME_CAT) == 0)
	{
		new_animal = new Cat();
	}
	else if (name.compare(ANIMAL_NAME_BIRD) == 0)
	{
		new_animal = new Bird();
	}
	else if (name.compare(ANIMAL_NAME_MOUSE) == 0)
	{
		new_animal = new Mouse();
	}
	else if (name.compare(ANIMAL_NAME_COW) == 0)
	{
		new_animal = new Cow();
	}
	else if (name.compare(ANIMAL_NAME_FROG) == 0)
	{
		new_animal = new Frog();
	}
	else if (name.compare(ANIMAL_NAME_ELEPHANT) == 0)
	{
		new_animal = new Elephant();
	}
	else if (name.compare(ANIMAL_NAME_DUCK) == 0)
	{
		new_animal = new Duck();
	}
	else if (name.compare(ANIMAL_NAME_FISH) == 0)
	{
		new_animal = new Fish();
	}
	else if (name.compare(ANIMAL_NAME_SEAL) == 0)
	{
		new_animal = new Seal();
	}
	
	return new_animal;
}

void makeSound(const std::string& name)
{
	// Create our instance
	Animal* animal = Animal::create(name);

	if (NULL != animal)
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
