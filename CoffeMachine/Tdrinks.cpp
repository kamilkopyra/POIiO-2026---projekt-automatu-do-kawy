#include <iostream>
#include <string>
#include <vector>
#include "Tdrinks.h"
using namespace std;

// Constructor to initialize the name and volume of the drink
Tdrinks::Tdrinks(string name, float volume, float volumeofMilk, int power)
{
	this->name = name;
	this->volume = volume;
	this->volumeOfMilk = volumeofMilk;
	this->power = power;
}
Tdrinks::Tdrinks(const Tdrinks& other) {
	for (auto& drink : drinks) {
		if (drink.getName() == other.getName()) {
			this->name = other.getName() + "_copy" + std::to_string(floor(rand() % 1000));
		}
	}
	this->volume = other.getVolumeOfWater();
	this->volumeOfMilk = other.getVolumeOfMilk();
	this->power = other.getPowerOfCoffe();
}
int Tdrinks::getDrinkId(string name)
{
	int count = drinks.size();
	int _id = -1;
	bool run = true;

	while (run)
	{
		_id += 1;
		string sub_name = drinks[_id].getName();

		if (sub_name == name) run = false;

		if ((_id + 1 == count) && (run == true))
		{
			cout << "Nie znaleziono plynu o podanej nazwie: \"" << name << "\"!\n";
			run = false;
			_id = -1;
		}
	}
	return _id;
}


// Returns the name of the drink
std::string Tdrinks::getName() const
{
	return name;
}
// Returns the volume of the drink
float Tdrinks::getVolume() const
{
	return volume + volumeOfMilk;
}
float Tdrinks::getVolumeOfWater() const
{
	return volume;
}
float Tdrinks::getVolumeOfMilk() const
{
	return volumeOfMilk;
}


int Tdrinks::getPowerOfCoffe() const
{
	return power;
}

void Tdrinks::show() 
{
	std::cout << "Informacje o napoju:\n";
	std::cout << "Nazwa: " << getName() << "\n";
	std::cout << "Ilosc kawy :  " << getVolume() << " ml\n";
	std::cout << "Ilosc wody:  " << getVolumeOfWater() << " ml\n";
	std::cout << "Ilosc mleka:  " << getVolumeOfMilk() << " ml\n";
	std::cout << "Moc: " << getPowerOfCoffe() << "\n";
	std::cout << "Ilosc ziaren kawy: " << getAmountOfCoffee() << " g\n";
	std::cout << "----------------------------\n";
}

void Tdrinks::editVolume(float newVolume) {
	volume = newVolume;
}
void Tdrinks::editVolumeOfMilk(float newVolumeOfMilk) {
	volumeOfMilk = newVolumeOfMilk;
}
void Tdrinks::editPower(int newPower) {
	power = newPower;
}


// zmieni³em ¿eby dodawanie by³o ³atwiejsze, napój jest dodawany bezpoœrednio do wektora po utworzeniu
void Tdrinks::addDrink(std::string name, float volume, float volumeOfMilk, int power) {
	drinks.push_back(Tdrinks(name, volume, volumeOfMilk, power));
}

void Tdrinks::removeDrink(std::string name) {
	for (int i = 0; i < drinks.size(); i++) {
		if (drinks[i].getName() == name) {
			drinks.erase(drinks.begin() + i);
			return;
		}
	}
}
int Tdrinks::getAmountOfCoffee() {
	float AmountPerVolume;
	switch (power) {
	case 1:
		AmountPerVolume = 8.0/250.0;
		break;
	case 2:
		AmountPerVolume = 10.0/250.0;
		break;
	case 3:
		AmountPerVolume = 14.0/250.0;
		break;
	case 4:
		AmountPerVolume = 16.0/250.0;
		break;
	case 5:
		AmountPerVolume = 18.0/250.0;
		break;
	default:
		std::cout << "Invalid power level. Setting to default (3).\n";
		power = 3;
		AmountPerVolume = 14.0 / 250.0;
		break;


	}
	return int(AmountPerVolume * volume);
}


void Tdrinks::copyDrink(std::string name) {
	for (auto& drink : drinks) {
		if (drink.getName() != name) {
			cout << "Nie znaleziono napoju o nazwie: \"" << name << "\"!\n";
		}
		else {
			drinks.push_back(Tdrinks(drink));
			cout << "Napój \"" << name << "\" zosta³ skopiowany jako \"" << drinks.back().getName() << "\"\n";
			return;
		}
	}
}


// funkcja do znajdywania napoju po nazwie
Tdrinks* Tdrinks::getDrinkByName(std::string name) {
	for (auto& drink : drinks) {
		if (drink.getName() == name) {
			return &drink;
		}
	}
	return nullptr;
}

	// List of drinks with their names and volumes
// (nazwa, iloœæ wody, iloœæ mleka, moc)
std::vector<Tdrinks> Tdrinks::drinks = {
	Tdrinks("Black Coffee", 250, 0, 4),
	Tdrinks("Latte", 200, 100, 2),
	Tdrinks("Cappuccino", 100, 250, 3),
	Tdrinks("Espresso", 100, 0, 5)
};