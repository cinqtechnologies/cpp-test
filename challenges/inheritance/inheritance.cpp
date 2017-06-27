#include <iostream>
#include <string>
#include <algorithm>

class Animal
{
public:
	virtual ~Animal() { }
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

#define HIGH_ORDER_ANIMALS_MACRO(code) \
	code (Dog, "woof") \
	code (Cat, "meow") \
	code (Bird, "tweet") \
	code (Mouse, "squeek") \
	code (Cow , "moo") \
	code (Frog , "croak") \
	code (Elephant, "toot") \
	code (Duck, "quack") \
	code (Fish, "blub") \
	code (Seal, "ow ow ow")


#define DEFINE_ANIMALS_CLASSES(AnimalType, AnimalSound) \
	class AnimalType : public Animal { \
		virtual void makeSound() const { \
			std::cout << AnimalSound << std:: endl; \
		} \
	};

HIGH_ORDER_ANIMALS_MACRO(DEFINE_ANIMALS_CLASSES)
#undef DEFINE_ANIMALS_CLASSES


std::string toLower(std::string name) {
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	return name;
}

#define RETURN_NEW_ANIMAL_INSTANCE(AnimalType, _) if (toLower(#AnimalType) == name) return new AnimalType;
// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{
	HIGH_ORDER_ANIMALS_MACRO(RETURN_NEW_ANIMAL_INSTANCE);
	return NULL;
}
#undef RETURN_NEW_ANIMAL_INSTANCE

void makeSound(const std::string& name)
{
	// Create our instance
	Animal* animal = Animal::create(name);

	if (!animal)
	{
		std::cout << name << " is not an animal" << std::endl;
		return;
	}

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
