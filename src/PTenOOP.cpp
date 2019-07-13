//============================================================================
// Name        : PTenOOP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

class Animal {
public:
	std::string GetName() { return name; }
	void SetName(std::string name) { this->name = name; }
	double GetHeight() { return height; }
	void SetHeight(double height) { this->height = height; }
	double GetWeight() { return weight; }
	void SetWeight(double height) { this->weight = height; }

	void SetAll(std::string, double, double);
	Animal(std::string, double, double);
	Animal();
	~Animal();
	static int GetNumOfAnimals() { return numOfAnimals; }
	void Display();

private:
	std::string name;
	double height;
	double weight;

	static int numOfAnimals;
};

int Animal::numOfAnimals = 0;
void Animal::SetAll(std::string name, double height, double weight) {
	this->name = name;
	this->height = height;
	this->weight = weight;
	Animal::numOfAnimals++;
}

Animal::Animal(std::string name, double height, double weight) {
	this->name = name;
	this->height = height;
	this->weight = weight;
	Animal::numOfAnimals++;
}

Animal::Animal() {
	this->name = "";
	this->height = 0;
	this->weight = 0;
	Animal::numOfAnimals++;
}

Animal::~Animal() {
	std::cout << "Animal " << this->name << " destroyed\n";
}

void Animal::Display() {
	std::cout << this->name << " is " <<
			this->height << " cms tall and " <<
			this->weight << " kgs in weight" << std::endl;
}

class Dog : public Animal {
public:
	void MakeSound() {
		std::cout << "The dog " << this->GetName() << " says " << this->sound << std::endl;
	}
	Dog(std::string name, double height, double weight, std::string sound);
	Dog();
	void Display();

private:
	std::string sound = "woof";
};

Dog::Dog(std::string name, double height, double weight,
		std::string sound): Animal(name, height, weight) {
	this->sound = sound;
}

Dog::Dog(): Animal() {
	this->sound = sound;
}

void Dog::Display() {
	std::cout << this->GetName() << " is " <<
			this->GetHeight() << " cms tall and " <<
			this->GetWeight() << " kgs in weight" <<
			" and says \"" << this->sound << "\"\n";

}

int main() {
	int iAnimals = 0;

	std::cout << "Number of animals created: " << iAnimals << std::endl;

	Animal rob;
	rob.Display();
	rob.SetHeight(33);
	rob.SetWeight(10);
	rob.SetName("Rob");
	rob.Display();
	iAnimals = rob.GetNumOfAnimals();

	std::cout << "Number of animals created: " << iAnimals << std::endl;

	Animal jack("Jack", 36, 15);
	jack.Display();

	std::cout << "Number of animals created: " << jack.GetNumOfAnimals() << std::endl;

	Dog spike("Spike", 10, 5, "Bark");
	spike.Display();

	std::cout << "Number of animals created: " << spike.GetNumOfAnimals() << std::endl;
	//return 0; default return is zero (only in main)
}
