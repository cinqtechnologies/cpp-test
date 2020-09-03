#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

class Animal
{
    static std::unordered_map<std::string, std::function<Animal*()>> registry;

    template<typename T>
    friend class AnimalRegistry;

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
std::unordered_map<std::string, std::function<Animal*()>> Animal::registry;

template<typename AnimalType>
Animal* animalCreator() {
    return new AnimalType;
}

template <typename AnimalType>
class AnimalRegistry {
public:
    AnimalRegistry(const std::string& name) {
        Animal::registry.insert(std::make_pair(name, animalCreator<AnimalType>));
    }
};

class Dog : public Animal {
public:
    static const AnimalRegistry<Dog> reg;

    void makeSound() const override {
        std::cout << "woof" << std::endl;
    }
};
const AnimalRegistry<Dog> Dog::reg("dog");

class Cat : public Animal {
public:
    static const AnimalRegistry<Cat> reg;
    void makeSound() const override {
        std::cout << "meow" << std::endl;
    }
};
const AnimalRegistry<Cat> Cat::reg("cat");

class Bird : public Animal {
public:
    static const AnimalRegistry<Bird> reg;
    void makeSound() const override {
        std::cout << "tweet" << std::endl;
    }
};
const AnimalRegistry<Bird> Bird::reg("bird");

class Mouse : public Animal {
public:
    static const AnimalRegistry<Mouse> reg;
    void makeSound() const override {
        std::cout << "squeek" << std::endl;
    }
};
const AnimalRegistry<Mouse> Mouse::reg("mouse");

class Cow : public Animal {
public:
    static const AnimalRegistry<Cow> reg;
    void makeSound() const override {
        std::cout << "moo" << std::endl;
    }
};
const AnimalRegistry<Cow> Cow::reg("cow");

class Frog : public Animal {
public:
    static const AnimalRegistry<Frog> reg;
    void makeSound() const override {
        std::cout << "croak" << std::endl;
    }
};
const AnimalRegistry<Frog> Frog::reg("frog");

class Elephant : public Animal {
public:
    static const AnimalRegistry<Elephant> reg;
    void makeSound() const override {
        std::cout << "toot" << std::endl;
    }
};
const AnimalRegistry<Elephant> Elephant::reg("elephant");

class Duck : public Animal {
public:
    static const AnimalRegistry<Duck> reg;
    void makeSound() const override {
        std::cout << "quack" << std::endl;
    }
};
const AnimalRegistry<Duck> Duck::reg("duck");

class Fish: public Animal {
public:
    static const AnimalRegistry<Fish> reg;
    void makeSound() const override {
        std::cout << "blub" << std::endl;
    }
};
const AnimalRegistry<Fish> Fish::reg("fish");

class Seal : public Animal {
public:
    static const AnimalRegistry<Seal> reg;
    void makeSound() const override {
        std::cout << "ow ow ow" << std::endl;
    }
};
const AnimalRegistry<Seal> Seal::reg("seal");
// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{
    const auto it = registry.find(name);
    if (it == registry.end()) {
        return nullptr;
    }
    return it->second();
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
