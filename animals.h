#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


class Animals							// A
{
	string objectName;
	float weight;
	float age;

protected:
	virtual void Breathe() {}
	virtual void Age() {}
	virtual void Weight() {}

public:
	virtual void addObject(string objName) {}
	virtual void delObject(string objName) {}
	virtual void modObject(string objName) {}
	virtual void showObjInfo(string objName) {}
	virtual void showList() {}
	virtual void saveList() {}
	virtual void readList() {}

	bool leaf;
	Animals()
	{
		weight = 0;
		age = 0;
		objectName = "Animal";
		leaf = false;
	}
	virtual ~Animals() {}
	string show_name()
	{
	 	return objectName;
	}

};


class Fish : public Animals				// B
{
	string objectName;
	float weight;
	float age;

protected:
	void Swim(){
		cout << "Potrafie plywac!" << endl;
	}

	void Breathe(){
		cout << "Potrafie oddychac!" << endl;
	}

	int ageOption; // opcja wieku: wartosc 1 prezentuje wiek w latach, wartosc 2 prezentuje wiek w miesiacach, wartosc 3 prezentuje wiek w dniach

	void Age(){
		int ageOption2;
		cout << "Aby obliczyc wiek zwierzecia w latach, wpisz 1. Aby obliczyc wiek zwierzecia w miesiacach, wpisz 2." << endl;
		cout << "Aby obliczyc wiek zwierzecia w dniach, wpisz 3." << endl;
		cin >> ageOption2;
		if((ageOption2 == 1) || (ageOption2 == 2) || (ageOption2 == 3)){
			if(ageOption == 1 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age << endl;
			else if(ageOption == 2 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age << endl;
			else if(ageOption == 3 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age << endl;
			else if(ageOption == 1 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age*12 << endl;
			else if(ageOption == 1 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age*365 << endl;
			else if(ageOption == 2 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age/12 << endl;
			else if(ageOption == 2 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age*30 << endl;
			else if(ageOption == 3 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age/365 << endl;
			else if(ageOption == 3 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age*12 << endl;
		}
	else
		cout << "Wybrano nieprawidlowa opcje." << endl;
	}

	int weightOption;	// opcja wagi: wartosc 1 prezentuje wage w kg, wartosc 2 prezentuje wage w gramach

	void Weight(){
		int weightOption2;
		cout << "Aby obliczyc wage zwierzecia w kilogramach, wpisz 1. Aby obliczyc wage zwierzecia w gramach, wpisz 2." << endl;
		cin >> weightOption2;
		if((weightOption2 == 1) || (weightOption2 == 2)){
			if(weightOption == 1 && weightOption2 == 1)
				cout << "Waga zwierzecia w kilogramach wynosi: " << weight << endl;
			else if(weightOption == 2 && weightOption2 == 2)
				cout << "Waga zwierzecia w gramach wynosi: " << weight << endl;
			else if(weightOption == 1 && weightOption2 == 2)
				cout << "Waga zwierzecia w gramach wynosi: " << weight*1000 << endl;
			else if(weightOption == 2 && weightOption2 == 1)
				cout << "Waga zwierzecia w kilogramach wynosi: " << weight/1000 << endl;
		}
		else
			cout << "Wybrano nieprawidlowa opcje." << endl;
	}


public:
	Fish()
	{
		weight = 0;
		weightOption = 0;
		age = 0;
		ageOption = 0;
		objectName = "Fish";
		leaf = true;
	}
	~Fish() {}

	Fish(string objName, float w, float a, int wo, int ao) : objectName(objName), weight(w), age(a), weightOption(wo), ageOption(ao) {}
	vector<Fish*> objList;
	void addObject(string objName)
	{
		float w, a;
		int wo, ao;
		cout << "Wybierz sposob zapisu wieku zwierzecia:\n1. Lata\n2. Miesiace\n3. Dni" << endl;
		cin >> ao;
		cout << "Prosze podac wiek zwierzecia." << endl;
		cin >> a;
		cout << "Wybierz sposob zapisu wagi zwierzecia:\n1. Kilogramy\n2. Gramy" << endl;
		cin >> wo;
		cout << "Prosze podac wage zwierzecia." << endl;
		cin >> w;
		Fish *ptrFish = new Fish(objName, w, a, wo, ao);
		objList.push_back(ptrFish);
		cout << "Pomyslnie dodano nowy obiekt do klasy 'Fish'." << endl;
	}

	void delObject(string objName)
	{
		if(!objList.empty())
		{
			int exists = 0;
			for(vector<Fish*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					objList.erase(it);
					cout << "Usunieto obiekt." << endl;
					delete *it;
				}
			if(exists == 0)
				cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void modObject(string objName)
	{
		if(!objList.empty())
		{
			int exists = 0;
			int option;
			for(vector<Fish*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					while(1){
						cout << "Zmiana danych obiektu. Wybierz numer pola, ktore chcesz zmienic:" << endl << "1. Nazwa obiektu\n2. Wiek zwierzecia\n3.Waga zwierzecia" << endl;
						cout << "Aby zakonczyc edycje, wybierz 4." << endl;
						cin >> option;
						if(option == 1){
							cout << "Wpisz nowa nazwe obiektu:" << endl;
							getline(cin, (*it)->objectName);
							cout << "Pomyslnie zmieniono nazwe obiektu na " << (*it)->objectName << endl;
							continue;
						}
						else if(option == 2){
							int ageOp;
							//float a2;
							cout << "Wybierz numer nowej formy zapisu wieku:\n1. Lata\n2. Miesiace\n3. Dni" << endl;
							cin >> ageOp;
							if(ageOp == 1 || ageOp == 2 || ageOp == 3)
								(*it)->ageOption = ageOp;
							else{
								cout << "Wybrano niepoprawna opcje." << endl;
								continue;
							}
							cout << "Wpisz nowy wiek:" << endl;
							//cin >> a2;
							// (*it)->age = a2;
							cin >> (*it)->age; // zobacz czy to dziala, jak nie to opcja z wyzej
							cout << "Poprawnie zmieniono wiek." << endl;
							continue;
						}
						else if(option == 3){
							int weOp;
							cout << "Wybierz numer nowej formy zapisu wagi:\n1. Kilogramy\n2. Gramy" << endl;
							cin >> weOp;
							if(weOp == 1 || weOp == 2)
								(*it)->weightOption = weOp;
							else{
								cout << "Wybrano niepoprawna opcje." << endl;
								continue;
							}
							cout << "Wpisz nowa wage:" << endl;
							cin >> (*it)->weight;
							cout << "Poprawnie zmieniono wage." << endl;
							continue;
						}
						else if(option == 4)
							break;
						else{
							cout << "Wybrano nieprawidlowa opcje." << endl;
							continue;
						}
					}
				}
				if(exists == 0)
					cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void showObjInfo(string objName){
		if(!objList.empty())
		{
			int exists = 0;
			for(vector<Fish*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					cout << "Informacje o obiekcie:" << endl << "Nazwa wezla: Fish" << endl;
					cout << "Nazwa obiektu: " << objName << endl;
					if((*it)->ageOption == 1)
						cout << "Wiek: " << (*it)->age << " lat/a" << endl;
					else if((*it)->ageOption == 2)
						cout << "Wiek: " << (*it)->age << " miesiace/miesiecy" << endl;
					else if((*it)->ageOption == 3)
						cout << "Wiek: " << (*it)->age << " dni" << endl;
					if((*it)->weightOption == 1)
						cout << "Waga: " << (*it)->weight << " kilogramy/kilogramow" << endl;
					else if((*it)->weightOption == 2)
						cout << "Waga: " << (*it)->weight << " gramy/gramow" << endl;
					Breathe();
					Swim();
					int option;
					cout << "\nJesli chcesz przeliczyc wiek zwierzecia na inna jednostke czasu, wybierz 1." << endl;
					cout << "Jezli chcesz przeliczyc wage zwierzecia na inna jednostke wagi, wybierz 2." << endl;
					cout << "Jezeli chcesz zakonczyc wyswietlanie danych o obiekcie, wybierz dowolna inna liczbe." << endl << endl;
					cin >> option;
					if (option == 1){
						Age();
					}
					else if(option == 2){
						Weight();
					}
				}
			if(exists == 0)
				cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl << endl;
	}

	void showList(){
		if(!objList.empty())
		{
			cout << "Nazwa wezla: Fish" << endl;
			for(vector<Fish*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				cout << "Nazwa obiektu: " << (*it)->objectName << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void saveList(){
		fstream file;
		file.open ("fish.txt", ios::app | ios::out);
		if(!objList.empty()){
			if(file.good()){
				file << objList.size() << endl;
				for(vector<Fish*>::iterator it = objList.begin() ; it < objList.end() ; it++){
					file << (*it)->objectName << endl;
					file << (*it)->age << endl;
					file << (*it)->ageOption << endl;
					file << (*it)->weight << endl;
					file << (*it)->weightOption << endl;
				}
				file.close();
			}
			else
				cout << "Wystapil blad przy otwieraniu pliku." << endl;
		}
		else
			cout << "Lista FISH jest pusta. Brak mozliwosci zapisu danych do pliku." << endl;
	}

	void readList(){
		fstream file;
		file.open ("fish.txt", ios::in);
		if(file.good()){
			int listsize, ao, wo;
			float a, w;
			string name;
			file >> listsize;
			for(int i = 0; i < listsize; i++){
				file >> name;
				file >> a;
				file >> ao;
				file >> w;
				file >> wo;
				Fish *ptrFish = new Fish(name, w, a, wo, ao);
				objList.push_back(ptrFish);
			}
			file.close();
		}
		else
			cout << "Wystapil blad przy otwieraniu pliku." << endl;
	}

};


class Birds : public Animals			// C
{
	string objectName;
	float weight;
	float age;

protected:
	virtual void Fly() {}
	virtual void Chirping() {}
	virtual void Walk() {}

public:
	Birds(){
	weight = 0;
	age = 0;
	objectName = "Bird";
	leaf = false;
	}
	virtual ~Birds() {}
};


class Mammals : public Animals			// D
{
	string objectName;
	float weight;
	float age;

protected:
	virtual void Walk() {}

public:
	Mammals(){
		weight = 0;
		age = 0;
		objectName = "Mammal";
		leaf = false;
	}
	virtual ~Mammals() {}
};


class DomesticBirds : public Birds		// G
{
	string objectName;
	float weight;
	float age;

protected:
	int ageOption;
	void Age(){
		int ageOption2;
		cout << "Aby obliczyc wiek zwierzecia w latach, wpisz 1. Aby obliczyc wiek zwierzecia w miesiacach, wpisz 2." << endl;
		cout << "Aby obliczyc wiek zwierzecia w dniach, wpisz 3." << endl;
		cin >> ageOption2;
		if((ageOption2 == 1) || (ageOption2 == 2) || (ageOption2 == 3)){
			if(ageOption == 1 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age << endl;
			else if(ageOption == 2 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age << endl;
			else if(ageOption == 3 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age << endl;
			else if(ageOption == 1 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age*12 << endl;
			else if(ageOption == 1 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age*365 << endl;
			else if(ageOption == 2 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age/12 << endl;
			else if(ageOption == 2 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age*30 << endl;
			else if(ageOption == 3 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age/365 << endl;
			else if(ageOption == 3 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age*12 << endl;
		}
		else
			cout << "Wybrano nieprawidlowa opcje." << endl;
	}
	int weightOption;
	void Weight(){
		int weightOption2;
		cout << "Aby obliczyc wage zwierzecia w kilogramach, wpisz 1. Aby obliczyc wage zwierzecia w gramach, wpisz 2." << endl;
		cin >> weightOption2;
		if((weightOption2 == 1) || (weightOption2 == 2)){
			if(weightOption == 1 && weightOption2 == 1)
				cout << "Waga zwierzecia w kilogramach wynosi: " << weight << endl;
			else if(weightOption == 2 && weightOption2 == 2)
				cout << "Waga zwierzecia w gramach wynosi: " << weight << endl;
			else if(weightOption == 1 && weightOption2 == 2)
				cout << "Waga zwierzecia w gramach wynosi: " << weight*1000 << endl;
			else if(weightOption == 2 && weightOption2 == 1)
				cout << "Waga zwierzecia w kilogramach wynosi: " << weight/1000 << endl;
		}
		else
			cout << "Wybrano nieprawidlowa opcje." << endl;
	}

	void Breathe(){
		cout << "Potrafie oddychac!" << endl;
	}

	void Fly(){
		cout << "Potrafie latac!" << endl;
	}

	void Walk(){
		cout << "Potrafie chodzic!" << endl;
	}

	void Chirping(){
		cout << "Cwir! Cwir!" << endl;
	}

public:
	DomesticBirds(){
		weight = 0;
		weightOption = 0;
		age = 0;
		ageOption = 0;
		objectName = "Domestic Bird";
		leaf = true;
	}
	~DomesticBirds() {}
	DomesticBirds(string objName, float w, float a, int wo, int ao) : objectName(objName), weight(w), age(a), weightOption(wo), ageOption(ao) {}
	vector<DomesticBirds*> objList;
	void addObject(string objName)
	{
		float w, a;
		int wo, ao;
		cout << "Wybierz sposob zapisu wieku zwierzecia:\n1. Lata\n2. Miesiace\n3. Dni" << endl;
		cin >> ao;
		cout << "Prosze podac wiek zwierzecia." << endl;
		cin >> a;
		cout << "Wybierz sposob zapisu wagi zwierzecia:\n1. Kilogramy\n2. Gramy" << endl;
		cin >> wo;
		cout << "Prosze podac wage zwierzecia." << endl;
		cin >> w;
		DomesticBirds *ptrDBirds = new DomesticBirds(objName, w, a, wo, ao);
		objList.push_back(ptrDBirds);
		cout << "Pomyslnie dodano nowy obiekt do klasy 'Domestic Birds'." << endl;
	}

	void delObject(string objName)
	{
		if(!objList.empty())
		{
			int exists = 0;
			for(vector<DomesticBirds*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					objList.erase(it);
					cout << "Usunieto obiekt." << endl;
					delete *it;
				}
			if(exists == 0)
				cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void modObject(string objName)
	{
		if(!objList.empty())
		{
			int exists = 0;
			int option;
			for(vector<DomesticBirds*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					while(1){
						cout << "Zmiana danych obiektu. Wybierz numer pola, ktore chcesz zmienic:" << endl << "1. Nazwa obiektu\n2. Wiek zwierzecia\n3.Waga zwierzecia" << endl;
						cout << "Aby zakonczyc edycje, wybierz 4." << endl;
						cin >> option;
						if(option == 1){
							cout << "Wpisz nowa nazwe obiektu:" << endl;
							getline(cin, (*it)->objectName);
							cout << "Pomyslnie zmieniono nazwe obiektu na " << (*it)->objectName << endl;
							continue;
						}
						else if(option == 2){
							int ageOp;
							//float a2;
							cout << "Wybierz numer nowej formy zapisu wieku:\n1. Lata\n2. Miesiace\n3. Dni" << endl;
							cin >> ageOp;
							if(ageOp == 1 || ageOp == 2 || ageOp == 3)
								(*it)->ageOption = ageOp;
							else{
								cout << "Wybrano niepoprawna opcje." << endl;
								continue;
							}
							cout << "Wpisz nowy wiek:" << endl;
							//cin >> a2;
							// (*it)->age = a2;
							cin >> (*it)->age; // zobacz czy to dziala, jak nie to opcja z wyzej
							cout << "Poprawnie zmieniono wiek." << endl;
							continue;
						}
						else if(option == 3){
							int weOp;
							cout << "Wybierz numer nowej formy zapisu wagi:\n1. Kilogramy\n2. Gramy" << endl;
							cin >> weOp;
							if(weOp == 1 || weOp == 2)
								(*it)->weightOption = weOp;
							else{
								cout << "Wybrano niepoprawna opcje." << endl;
								continue;
							}
							cout << "Wpisz nowa wage:" << endl;
							cin >> (*it)->weight;
							cout << "Poprawnie zmieniono wage." << endl;
							continue;
						}
						else if(option == 4)
							break;
						else{
							cout << "Wybrano nieprawidlowa opcje." << endl;
							continue;
						}
					}
				}
				if(exists == 0)
					cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void showObjInfo(string objName){
		if(!objList.empty())
		{
			int exists = 0;
			for(vector<DomesticBirds*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					cout << "Informacje o obiekcie:" << endl << "Nazwa wezla: Domestic Birds" << endl;
					cout << "Nazwa obiektu: " << objName << endl;
					if((*it)->ageOption == 1)
						cout << "Wiek: " << (*it)->age << " lat/a" << endl;
					else if((*it)->ageOption == 2)
						cout << "Wiek: " << (*it)->age << " miesiace/miesiecy" << endl;
					else if((*it)->ageOption == 3)
						cout << "Wiek: " << (*it)->age << " dni" << endl;
					if((*it)->weightOption == 1)
						cout << "Waga: " << (*it)->weight << " kilogramy/kilogramow" << endl;
					else if((*it)->weightOption == 2)
						cout << "Waga: " << (*it)->weight << " gramy/gramow" << endl;
					Breathe();
					Walk();
					Fly();
					Chirping();
					int option;
					cout << "\nJesli chcesz przeliczyc wiek zwierzecia na inna jednostke czasu, wybierz 1." << endl;
					cout << "Jezli chcesz przeliczyc wage zwierzecia na inna jednostke wagi, wybierz 2." << endl;
					cout << "Jezeli chcesz zakonczyc wyswietlanie danych o obiekcie, wybierz dowolna inna liczbe." << endl;
					cin >> option;
					if (option == 1){
						Age();
					}
					else if(option == 2){
						Weight();
					}
				}
			if(exists == 0)
				cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void showList(){
		if(!objList.empty())
		{
			cout << "Nazwa wezla: Domestic Birds" << endl;
			for(vector<DomesticBirds*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				cout << "Nazwa obiektu: " << (*it)->objectName << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void saveList(){
		fstream file;
		file.open ("domesticbirds.txt", ios::app | ios::out);
		if(!objList.empty()){
			if(file.good()){
				file << objList.size() << endl;
				for(vector<DomesticBirds*>::iterator it = objList.begin() ; it < objList.end() ; it++){
					file << (*it)->objectName << endl;
					file << (*it)->age << endl;
					file << (*it)->ageOption << endl;
					file << (*it)->weight << endl;
					file << (*it)->weightOption << endl;
				}
				file.close();
			}
			else
				cout << "Wystapil blad przy otwieraniu pliku." << endl;
		}
		else
			cout << "Lista DOMESTIC BIRDS jest pusta. Brak mozliwosci zapisu danych do pliku." << endl;
	}

	void readList(){
		fstream file;
		file.open ("domesticbirds.txt", ios::in);
		if(file.good()){
			int listsize, ao, wo;
			float a, w;
			string name;
			file >> listsize;
			for(int i = 0; i < listsize; i++){
				file >> name;
				file >> a;
				file >> ao;
				file >> w;
				file >> wo;
				DomesticBirds *ptrDBirds = new DomesticBirds(name, w, a, wo, ao);
				objList.push_back(ptrDBirds);
			}
			file.close();
		}
		else
			cout << "Wystapil blad przy otwieraniu pliku." << endl;
	}
};


class WildBirds : public Birds			// H
{
	string objectName;
	float weight;
	float age;

protected:
	int ageOption;
	void Age(){
		int ageOption2;
		cout << "Aby obliczyc wiek zwierzecia w latach, wpisz 1. Aby obliczyc wiek zwierzecia w miesiacach, wpisz 2." << endl;
		cout << "Aby obliczyc wiek zwierzecia w dniach, wpisz 3." << endl;
		cin >> ageOption2;
		if((ageOption2 == 1) || (ageOption2 == 2) || (ageOption2 == 3)){
			if(ageOption == 1 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age << endl;
			else if(ageOption == 2 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age << endl;
			else if(ageOption == 3 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age << endl;
			else if(ageOption == 1 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age*12 << endl;
			else if(ageOption == 1 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age*365 << endl;
			else if(ageOption == 2 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age/12 << endl;
			else if(ageOption == 2 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age*30 << endl;
			else if(ageOption == 3 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age/365 << endl;
			else if(ageOption == 3 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age*12 << endl;
		}
		else
			cout << "Wybrano nieprawidlowa opcje." << endl;
	}
	int weightOption;
	void Weight(){
		int weightOption2;
		cout << "Aby obliczyc wage zwierzecia w kilogramach, wpisz 1. Aby obliczyc wage zwierzecia w gramach, wpisz 2." << endl;
		cin >> weightOption2;
		if((weightOption2 == 1) || (weightOption2 == 2)){
			if(weightOption == 1 && weightOption2 == 1)
				cout << "Waga zwierzecia w kilogramach wynosi: " << weight << endl;
			else if(weightOption == 2 && weightOption2 == 2)
				cout << "Waga zwierzecia w gramach wynosi: " << weight << endl;
			else if(weightOption == 1 && weightOption2 == 2)
				cout << "Waga zwierzecia w gramach wynosi: " << weight*1000 << endl;
			else if(weightOption == 2 && weightOption2 == 1)
				cout << "Waga zwierzecia w kilogramach wynosi: " << weight/1000 << endl;
		}
		else
			cout << "Wybrano nieprawidlowa opcje." << endl;
	}

	void Breathe(){
		cout << "Potrafie oddychac!" << endl;
	}

	void Fly(){
		cout << "Potrafie latac!" << endl;
	}

	void Walk(){
		cout << "Potrafie chodzic!" << endl;
	}

	void Chirping(){
		cout << "Cwir! Cwir!" << endl;
	}


public:
	WildBirds(){
		weight = 0;
		weightOption = 0;
		age = 0;
		ageOption = 0;
		objectName = "Wild Bird";
		leaf = true;
	}
	~WildBirds() {}
	WildBirds(string objName, float w, float a, int wo, int ao) : objectName(objName), weight(w), age(a), weightOption(wo), ageOption(ao) {}
	vector<WildBirds*> objList;
	void addObject(string objName)
	{
		float w, a;
		int wo, ao;
		cout << "Wybierz sposob zapisu wieku zwierzecia:\n1. Lata\n2. Miesiace\n3. Dni" << endl;
		cin >> ao;
		cout << "Prosze podac wiek zwierzecia." << endl;
		cin >> a;
		cout << "Wybierz sposob zapisu wagi zwierzecia:\n1. Kilogramy\n2. Gramy" << endl;
		cin >> wo;
		cout << "Prosze podac wage zwierzecia." << endl;
		cin >> w;
		WildBirds *ptrWBirds = new WildBirds(objName, w, a, wo, ao);
		objList.push_back(ptrWBirds);
		cout << "Pomyslnie dodano nowy obiekt do klasy 'Domestic Birds'." << endl;
	}

	void delObject(string objName)
	{
		if(!objList.empty())
		{
			int exists = 0;
			for(vector<WildBirds*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					objList.erase(it);
					cout << "Usunieto obiekt." << endl;
					delete *it;
				}
			if(exists == 0)
				cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void modObject(string objName)
	{
		if(!objList.empty())
		{
			int exists = 0;
			int option;
			for(vector<WildBirds*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					while(1){
						cout << "Zmiana danych obiektu. Wybierz numer pola, ktore chcesz zmienic:" << endl << "1. Nazwa obiektu\n2. Wiek zwierzecia\n3.Waga zwierzecia" << endl;
						cout << "Aby zakonczyc edycje, wybierz 4." << endl;
						cin >> option;
						if(option == 1){
							cout << "Wpisz nowa nazwe obiektu:" << endl;
							getline(cin, (*it)->objectName);
							cout << "Pomyslnie zmieniono nazwe obiektu na " << (*it)->objectName << endl;
							continue;
						}
						else if(option == 2){
							int ageOp;
							//float a2;
							cout << "Wybierz numer nowej formy zapisu wieku:\n1. Lata\n2. Miesiace\n3. Dni" << endl;
							cin >> ageOp;
							if(ageOp == 1 || ageOp == 2 || ageOp == 3)
								(*it)->ageOption = ageOp;
							else{
								cout << "Wybrano niepoprawna opcje." << endl;
								continue;
							}
							cout << "Wpisz nowy wiek:" << endl;
							//cin >> a2;
							// (*it)->age = a2;
							cin >> (*it)->age; // zobacz czy to dziala, jak nie to opcja z wyzej
							cout << "Poprawnie zmieniono wiek." << endl;
							continue;
						}
						else if(option == 3){
							int weOp;
							cout << "Wybierz numer nowej formy zapisu wagi:\n1. Kilogramy\n2. Gramy" << endl;
							cin >> weOp;
							if(weOp == 1 || weOp == 2)
								(*it)->weightOption = weOp;
							else{
								cout << "Wybrano niepoprawna opcje." << endl;
								continue;
							}
							cout << "Wpisz nowa wage:" << endl;
							cin >> (*it)->weight;
							cout << "Poprawnie zmieniono wage." << endl;
							continue;
						}
						else if(option == 4)
							break;
						else{
							cout << "Wybrano nieprawidlowa opcje." << endl;
							continue;
						}
					}
				}
				if(exists == 0)
					cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void showObjInfo(string objName){
		if(!objList.empty())
		{
			int exists = 0;
			for(vector<WildBirds*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					cout << "Informacje o obiekcie:" << endl << "Nazwa wezla: Wild Birds" << endl;
					cout << "Nazwa obiektu: " << objName << endl;
					if((*it)->ageOption == 1)
						cout << "Wiek: " << (*it)->age << " lat/a" << endl;
					else if((*it)->ageOption == 2)
						cout << "Wiek: " << (*it)->age << " miesiace/miesiecy" << endl;
					else if((*it)->ageOption == 3)
						cout << "Wiek: " << (*it)->age << " dni" << endl;
					if((*it)->weightOption == 1)
						cout << "Waga: " << (*it)->weight << " kilogramy/kilogramow" << endl;
					else if((*it)->weightOption == 2)
						cout << "Waga: " << (*it)->weight << " gramy/gramow" << endl;
					Breathe();
					Walk();
					Fly();
					Chirping();
					int option;
					cout << "\nJesli chcesz przeliczyc wiek zwierzecia na inna jednostke czasu, wybierz 1." << endl;
					cout << "Jezli chcesz przeliczyc wage zwierzecia na inna jednostke wagi, wybierz 2." << endl;
					cout << "Jezeli chcesz zakonczyc wyswietlanie danych o obiekcie, wybierz dowolna inna liczbe." << endl << endl;
					cin >> option;
					if (option == 1){
						Age();
					}
					else if(option == 2){
						Weight();
					}
				}
			if(exists == 0)
				cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void showList(){
		if(!objList.empty())
		{
			cout << "Nazwa wezla: Wild Birds" << endl;
			for(vector<WildBirds*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				cout << "Nazwa obiektu: " << (*it)->objectName << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void saveList(){
		fstream file;
		file.open ("wildbirds.txt", ios::app | ios::out);
		if(!objList.empty()){
			if(file.good()){
				file << objList.size() << endl;
				for(vector<WildBirds*>::iterator it = objList.begin() ; it < objList.end() ; it++){
					file << (*it)->objectName << endl;
					file << (*it)->age << endl;
					file << (*it)->ageOption << endl;
					file << (*it)->weight << endl;
					file << (*it)->weightOption << endl;
				}
				file.close();
			}
			else
				cout << "Wystapil blad przy otwieraniu pliku." << endl;
		}
		else
			cout << "Lista WILDBIRDS jest pusta. Brak mozliwosci zapisu danych do pliku." << endl;
	}

	void readList(){
		fstream file;
		file.open ("wildbirds.txt", ios::in);
		if(file.good()){
			int listsize, ao, wo;
			float a, w;
			string name;
			file >> listsize;
			for(int i = 0; i < listsize; i++){
				file >> name;
				file >> a;
				file >> ao;
				file >> w;
				file >> wo;
				WildBirds *ptrWBirds = new WildBirds(name, w, a, wo, ao);
				objList.push_back(ptrWBirds);
			}
			file.close();
		}
		else
			cout << "Wystapil blad przy otwieraniu pliku." << endl;
	}
};


class Dogs : public Mammals				// I
{
	string objectName;
	float weight;
	float age;

protected:
	virtual void Bark() {}

public:
	Dogs(){
		weight = 0;
		age = 0;
		objectName = "Dog";
		leaf = false;
	}
	virtual ~Dogs() {}
};


class Cats : public Mammals				// J
{
	string objectName;
	float weight;
	float age;

protected:
	int ageOption;
	void Age(){
		int ageOption2;
		cout << "Aby obliczyc wiek zwierzecia w latach, wpisz 1. Aby obliczyc wiek zwierzecia w miesiacach, wpisz 2." << endl;
		cout << "Aby obliczyc wiek zwierzecia w dniach, wpisz 3." << endl;
		cin >> ageOption2;
		if((ageOption2 == 1) || (ageOption2 == 2) || (ageOption2 == 3)){
			if(ageOption == 1 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age << endl;
			else if(ageOption == 2 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age << endl;
			else if(ageOption == 3 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age << endl;
			else if(ageOption == 1 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age*12 << endl;
			else if(ageOption == 1 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age*365 << endl;
			else if(ageOption == 2 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age/12 << endl;
			else if(ageOption == 2 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age*30 << endl;
			else if(ageOption == 3 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age/365 << endl;
			else if(ageOption == 3 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age*12 << endl;
		}
		else
			cout << "Wybrano nieprawidlowa opcje." << endl;
	}
	int weightOption;
	void Weight(){
		int weightOption2;
		cout << "Aby obliczyc wage zwierzecia w kilogramach, wpisz 1. Aby obliczyc wage zwierzecia w gramach, wpisz 2." << endl;
		cin >> weightOption2;
		if((weightOption2 == 1) || (weightOption2 == 2)){
			if(weightOption == 1 && weightOption2 == 1)
				cout << "Waga zwierzecia w kilogramach wynosi: " << weight << endl;
			else if(weightOption == 2 && weightOption2 == 2)
				cout << "Waga zwierzecia w gramach wynosi: " << weight << endl;
			else if(weightOption == 1 && weightOption2 == 2)
				cout << "Waga zwierzecia w gramach wynosi: " << weight*1000 << endl;
			else if(weightOption == 2 && weightOption2 == 1)
				cout << "Waga zwierzecia w kilogramach wynosi: " << weight/1000 << endl;
		}
		else
			cout << "Wybrano nieprawidlowa opcje." << endl;
	}
	void Meow(){
		cout << "Meow! Meow!" << endl;
	}
	void Walk(){
        cout << "Potrafie chodzic!" << endl;
        }
    void Breathe(){
		cout << "Potrafie oddychac!" << endl;
	}

public:
	Cats(){
		weight = 0;
		weightOption = 0;
		age = 0;
		ageOption = 0;
		objectName = "Cat";
		leaf = true;
	}
	~Cats() {}

	Cats(string objName, float w, float a, int wo, int ao) : objectName(objName), weight(w), age(a), weightOption(wo), ageOption(ao) {}
	vector<Cats*> objList;
	void addObject(string objName)
	{
		float w, a;
		int wo, ao;
		cout << "Wybierz sposob zapisu wieku zwierzecia:\n1. Lata\n2. Miesiace\n3. Dni" << endl;
		cin >> ao;
		cout << "Prosze podac wiek zwierzecia." << endl;
		cin >> a;
		cout << "Wybierz sposob zapisu wagi zwierzecia:\n1. Kilogramy\n2. Gramy" << endl;
		cin >> wo;
		cout << "Prosze podac wage zwierzecia." << endl;
		cin >> w;
		Cats *ptrCats = new Cats(objName, w, a, wo, ao);
		objList.push_back(ptrCats);
		cout << "Pomyslnie dodano nowy obiekt do klasy 'Cats'." << endl;
	}

	void delObject(string objName)
	{
		if(!objList.empty())
		{
			int exists = 0;
			for(vector<Cats*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					objList.erase(it);
					cout << "Usunieto obiekt." << endl;
					delete *it;
				}
			if(exists == 0)
				cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void modObject(string objName)
	{
		if(!objList.empty())
		{
			int exists = 0;
			int option;
			for(vector<Cats*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					while(1){
						cout << "Zmiana danych obiektu. Wybierz numer pola, ktore chcesz zmienic:" << endl << "1. Nazwa obiektu\n2. Wiek zwierzecia\n3.Waga zwierzecia" << endl;
						cout << "Aby zakonczyc edycje, wybierz 4." << endl;
						cin >> option;
						if(option == 1){
							cout << "Wpisz nowa nazwe obiektu:" << endl;
							getline(cin, (*it)->objectName);
							cout << "Pomyslnie zmieniono nazwe obiektu na " << (*it)->objectName << endl;
							continue;
						}
						else if(option == 2){
							int ageOp;
							//float a2;
							cout << "Wybierz numer nowej formy zapisu wieku:\n1. Lata\n2. Miesiace\n3. Dni" << endl;
							cin >> ageOp;
							if(ageOp == 1 || ageOp == 2 || ageOp == 3)
								(*it)->ageOption = ageOp;
							else{
								cout << "Wybrano niepoprawna opcje." << endl;
								continue;
							}
							cout << "Wpisz nowy wiek:" << endl;
							//cin >> a2;
							// (*it)->age = a2;
							cin >> (*it)->age; // zobacz czy to dziala, jak nie to opcja z wyzej
							cout << "Poprawnie zmieniono wiek." << endl;
							continue;
						}
						else if(option == 3){
							int weOp;
							cout << "Wybierz numer nowej formy zapisu wagi:\n1. Kilogramy\n2. Gramy" << endl;
							cin >> weOp;
							if(weOp == 1 || weOp == 2)
								(*it)->weightOption = weOp;
							else{
								cout << "Wybrano niepoprawna opcje." << endl;
								continue;
							}
							cout << "Wpisz nowa wage:" << endl;
							cin >> (*it)->weight;
							cout << "Poprawnie zmieniono wage." << endl;
							continue;
						}
						else if(option == 4)
							break;
						else{
							cout << "Wybrano nieprawidlowa opcje." << endl;
							continue;
						}
					}
				}
				if(exists == 0)
					cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void showObjInfo(string objName){
		if(!objList.empty())
		{
			int exists = 0;
			for(vector<Cats*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					cout << "Informacje o obiekcie:" << endl << "Nazwa wezla: Cats" << endl;
					cout << "Nazwa obiektu: " << objName << endl;
					if((*it)->ageOption == 1)
						cout << "Wiek: " << (*it)->age << " lat/a" << endl;
					else if((*it)->ageOption == 2)
						cout << "Wiek: " << (*it)->age << " miesiace/miesiecy" << endl;
					else if((*it)->ageOption == 3)
						cout << "Wiek: " << (*it)->age << " dni" << endl;
					if((*it)->weightOption == 1)
						cout << "Waga: " << (*it)->weight << " kilogramy/kilogramow" << endl;
					else if((*it)->weightOption == 2)
						cout << "Waga: " << (*it)->weight << " gramy/gramow" << endl;
					Breathe();
					Walk();
					Meow();
					int option;
					cout << "\nJesli chcesz przeliczyc wiek zwierzecia na inna jednostke czasu, wybierz 1." << endl;
					cout << "Jezli chcesz przeliczyc wage zwierzecia na inna jednostke wagi, wybierz 2." << endl;
					cout << "Jezeli chcesz zakonczyc wyswietlanie danych o obiekcie, wybierz dowolna inna liczbe." << endl << endl;
					cin >> option;
					if (option == 1){
						Age();
					}
					else if(option == 2){
						Weight();
					}
				}
			if(exists == 0)
				cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void showList(){
		if(!objList.empty())
		{
			cout << "Nazwa wezla: Cats" << endl;
			for(vector<Cats*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				cout << "Nazwa obiektu: " << (*it)->objectName << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void saveList(){
		fstream file;
		file.open ("cats.txt", ios::app | ios::out);
		if(!objList.empty()){
			if(file.good()){
				file << objList.size() << endl;
				for(vector<Cats*>::iterator it = objList.begin() ; it < objList.end() ; it++){
					file << (*it)->objectName << endl;
					file << (*it)->age << endl;
					file << (*it)->ageOption << endl;
					file << (*it)->weight << endl;
					file << (*it)->weightOption << endl;
				}
				file.close();
			}
			else
				cout << "Wystapil blad przy otwieraniu pliku." << endl;
		}
		else
			cout << "Lista CATS jest pusta. Brak mozliwosci zapisu danych do pliku." << endl;
	}

	void readList(){
		fstream file;
		file.open ("cats.txt", ios::in);
		if(file.good()){
			int listsize, ao, wo;
			float a, w;
			string name;
			file >> listsize;
			for(int i = 0; i < listsize; i++){
				file >> name;
				file >> a;
				file >> ao;
				file >> w;
				file >> wo;
				Cats *ptrCats = new Cats(name, w, a, wo, ao);
				objList.push_back(ptrCats);
			}
			file.close();
		}
		else
			cout << "Wystapil blad przy otwieraniu pliku." << endl;
	}
};


class PureBredDogs : public Dogs		// H
{
	string objectName;
	float weight;
	float age;

protected:
		int ageOption;
		void Age(){
		int ageOption2;
		cout << "Aby obliczyc wiek zwierzecia w latach, wpisz 1. Aby obliczyc wiek zwierzecia w miesiacach, wpisz 2." << endl;
		cout << "Aby obliczyc wiek zwierzecia w dniach, wpisz 3." << endl;
		cin >> ageOption2;
		if((ageOption2 == 1) || (ageOption2 == 2) || (ageOption2 == 3)){
			if(ageOption == 1 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age << endl;
			else if(ageOption == 2 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age << endl;
			else if(ageOption == 3 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age << endl;
			else if(ageOption == 1 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age*12 << endl;
			else if(ageOption == 1 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age*365 << endl;
			else if(ageOption == 2 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age/12 << endl;
			else if(ageOption == 2 && ageOption2 == 3)
				cout << "Wiek zwierzecia w dniach wynosi: " << age*30 << endl;
			else if(ageOption == 3 && ageOption2 == 1)
				cout << "Wiek zwierzecia w latach wynosi: " << age/365 << endl;
			else if(ageOption == 3 && ageOption2 == 2)
				cout << "Wiek zwierzecia w miesiacach wynosi: " << age*12 << endl;
		}
		else
			cout << "Wybrano nieprawidlowa opcje." << endl;
	}
	int weightOption;
	void Weight(){
		int weightOption2;
		cout << "Aby obliczyc wage zwierzecia w kilogramach, wpisz 1. Aby obliczyc wage zwierzecia w gramach, wpisz 2." << endl;
		cin >> weightOption2;
		if((weightOption2 == 1) || (weightOption2 == 2)){
			if(weightOption == 1 && weightOption2 == 1)
				cout << "Waga zwierzecia w kilogramach wynosi: " << weight << endl;
			else if(weightOption == 2 && weightOption2 == 2)
				cout << "Waga zwierzecia w gramach wynosi: " << weight << endl;
			else if(weightOption == 1 && weightOption2 == 2)
				cout << "Waga zwierzecia w gramach wynosi: " << weight*1000 << endl;
			else if(weightOption == 2 && weightOption2 == 1)
				cout << "Waga zwierzecia w kilogramach wynosi: " << weight/1000 << endl;
		}
		else
			cout << "Wybrano nieprawidlowa opcje." << endl;
	}
	void Bark(){
		cout << "Woof woof!" << endl;
	}
	void Walk(){
        cout << "Potrafie chodzic!" << endl;
        }
    void Breathe(){
		cout << "Potrafie oddychac!" << endl;
	}

public:
	PureBredDogs(){
		weight = 0;
		weightOption = 0;
		age = 0;
		ageOption = 0;
		objectName = "Pure Bred Dog";
		leaf = true;
	}
	~PureBredDogs() {}

	PureBredDogs(string objName, float w, float a, int wo, int ao) : objectName(objName), weight(w), age(a), weightOption(wo), ageOption(ao) {}
	vector<PureBredDogs*> objList;
	void addObject(string objName)
	{
		float w, a;
		int wo, ao;
		cout << "Wybierz sposob zapisu wieku zwierzecia:\n1. Lata\n2. Miesiace\n3. Dni" << endl;
		cin >> ao;
		cout << "Prosze podac wiek zwierzecia." << endl;
		cin >> a;
		cout << "Wybierz sposob zapisu wagi zwierzecia:\n1. Kilogramy\n2. Gramy" << endl;
		cin >> wo;
		cout << "Prosze podac wage zwierzecia." << endl;
		cin >> w;
		PureBredDogs *ptrPBDogs = new PureBredDogs(objName, w, a, wo, ao);
		objList.push_back(ptrPBDogs);
		cout << "Pomyslnie dodano nowy obiekt do klasy 'Pure Bred Dogs'." << endl;
	}

	void delObject(string objName)
	{
		if(!objList.empty())
		{
			int exists = 0;
			for(vector<PureBredDogs*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					objList.erase(it);
					cout << "Usunieto obiekt." << endl;
					delete *it;
				}
			if(exists == 0)
				cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void modObject(string objName)
	{
		if(!objList.empty())
		{
			int exists = 0;
			int option;
			for(vector<PureBredDogs*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					while(1){
						cout << "Zmiana danych obiektu. Wybierz numer pola, ktore chcesz zmienic:" << endl << "1. Nazwa obiektu\n2. Wiek zwierzecia\n3.Waga zwierzecia" << endl;
						cout << "Aby zakonczyc edycje, wybierz 4." << endl;
						cin >> option;
						if(option == 1){
							cout << "Wpisz nowa nazwe obiektu:" << endl;
							getline(cin, (*it)->objectName);
							cout << "Pomyslnie zmieniono nazwe obiektu na " << (*it)->objectName << endl;
							continue;
						}
						else if(option == 2){
							int ageOp;
							//float a2;
							cout << "Wybierz numer nowej formy zapisu wieku:\n1. Lata\n2. Miesiace\n3. Dni" << endl;
							cin >> ageOp;
							if(ageOp == 1 || ageOp == 2 || ageOp == 3)
								(*it)->ageOption = ageOp;
							else{
								cout << "Wybrano niepoprawna opcje." << endl;
								continue;
							}
							cout << "Wpisz nowy wiek:" << endl;
							//cin >> a2;
							// (*it)->age = a2;
							cin >> (*it)->age; // zobacz czy to dziala, jak nie to opcja z wyzej
							cout << "Poprawnie zmieniono wiek." << endl;
							continue;
						}
						else if(option == 3){
							int weOp;
							cout << "Wybierz numer nowej formy zapisu wagi:\n1. Kilogramy\n2. Gramy" << endl;
							cin >> weOp;
							if(weOp == 1 || weOp == 2)
								(*it)->weightOption = weOp;
							else{
								cout << "Wybrano niepoprawna opcje." << endl;
								continue;
							}
							cout << "Wpisz nowa wage:" << endl;
							cin >> (*it)->weight;
							cout << "Poprawnie zmieniono wage." << endl;
							continue;
						}
						else if(option == 4)
							break;
						else{
							cout << "Wybrano nieprawidlowa opcje." << endl;
							continue;
						}
					}
				}
				if(exists == 0)
					cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void showObjInfo(string objName){
		if(!objList.empty())
		{
			int exists = 0;
			for(vector<PureBredDogs*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				if((*it)->objectName == objName)
				{
					exists = 1;
					cout << "Informacje o obiekcie:" << endl << "Nazwa wezla: Pure Bred Dogs" << endl;
					cout << "Nazwa obiektu: " << objName << endl;
					if((*it)->ageOption == 1)
						cout << "Wiek: " << (*it)->age << " lat/a" << endl;
					else if((*it)->ageOption == 2)
						cout << "Wiek: " << (*it)->age << " miesiace/miesiecy" << endl;
					else if((*it)->ageOption == 3)
						cout << "Wiek: " << (*it)->age << " dni" << endl;
					if((*it)->weightOption == 1)
						cout << "Waga: " << (*it)->weight << " kilogramy/kilogramow" << endl;
					else if((*it)->weightOption == 2)
						cout << "Waga: " << (*it)->weight << " gramy/gramow" << endl;
					Breathe();
					Walk();
					Bark();
					int option;
					cout << "\nJesli chcesz przeliczyc wiek zwierzecia na inna jednostke czasu, wybierz 1." << endl;
					cout << "Jezli chcesz przeliczyc wage zwierzecia na inna jednostke wagi, wybierz 2." << endl;
					cout << "Jezeli chcesz zakonczyc wyswietlanie danych o obiekcie, wybierz dowolna inna liczbe." << endl << endl;
					cin >> option;
					if (option == 1){
						Age();
					}
					else if(option == 2){
						Weight();
					}
				}
			if(exists == 0)
				cout << "Obiekt o podanej nazwie nie istnieje w liscie." << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void showList(){
		if(!objList.empty())
		{
			cout << "Nazwa wezla: Pure Bred Dogs" << endl;
			for(vector<PureBredDogs*>::iterator it = objList.begin() ; it < objList.end() ; it++)
				cout << "Nazwa obiektu: " << (*it)->objectName << endl;
		}
		else
			cout << "Brak elementow w liscie." << endl;
	}

	void saveList(){
		fstream file;
		file.open ("pbdogs.txt", ios::app | ios::out);
		if(!objList.empty()){
			if(file.good()){
				file << objList.size() << endl;
				for(vector<PureBredDogs*>::iterator it = objList.begin() ; it < objList.end() ; it++){
                    file << (*it)->objectName << endl;
					file << (*it)->age << endl;
					file << (*it)->ageOption << endl;
					file << (*it)->weight << endl;
					file << (*it)->weightOption << endl;
				}
				file.close();
			}
			else
				cout << "Wystapil blad przy otwieraniu pliku." << endl;
		}
		else
			cout << "Lista PUREBREDDOGS jest pusta. Brak mozliwosci zapisu danych do pliku." << endl;
	}

	void readList(){
		fstream file;
		file.open ("pbdogs.txt", ios::in);
		if(file.good()){
			int listsize, ao, wo;
			float a, w;
			string name;
			file >> listsize;
			for(int i = 0; i < listsize; i++){
				file >> name;
				file >> a;
				file >> ao;
				file >> w;
				file >> wo;
				PureBredDogs *ptrPBDogs = new PureBredDogs(name, w, a, wo, ao);
				objList.push_back(ptrPBDogs);
			}
			file.close();
		}
		else
			cout << "Wystapil blad przy otwieraniu pliku." << endl;
	}
};


#endif
