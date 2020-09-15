#include <iostream>
#include <fstream>
#include <string>
#include "animals.h"

using namespace std;

void tree();

int main()
{
	cout << "Wybierz polecenie:" << endl << endl << "CD[nazwa wezla] - zmiana wezla w strukturze" << endl << "\tNazwy wezlow oddzielone przecinkiem:" << endl << "\tANIMALS, FISH, BIRDS, DOMESTICBIRDS, WILDBIRDS, MAMMALS, CATS, DOGS, PUREBREDDOGS" << endl;
    cout << "MO - tworzenie obiektu dla biezacego liscia" << endl << "DO - usuwanie obiektu dla biezacego liscia" << endl << "MDO - modyfikacja obiektu dla biezacego liscia" << endl << "SHOW - wyswietla szczegolowe informacje o obiekcie" << endl << "DIR - wyswietla informacje o obiektach widocznych z danego poziomu" << endl << "SAVE - zapis zbioru do pliku" << endl << "READ - odczyt zbioru z pliku" << endl << "TREE - wyswietla cala strukture na ekranie" << "EXIT - koniec pracy programu" << endl;
    cout << "Uwaga. Wielkosc liter ma znaczenie." << endl << endl;
    string moption, name;

    Animals *Animal = new Animals;
    Fish *AFish = new Fish;
    Birds *Bird = new Birds;
    DomesticBirds *DBirds = new DomesticBirds;
    WildBirds *WBirds = new WildBirds;
    Mammals *Mammal = new Mammals;
    Dogs *Dog = new Dogs;
    Cats *Cat = new Cats;
    PureBredDogs *PBDog = new PureBredDogs;

	Animals *pointer = Animal;

    while(moption != "EXIT"){
    	getline(cin, moption);
    	if(moption == "CD ANIMALS"){
    		pointer = Animal;
    		cout << "Wezel: ANIMALS" << endl;
    	}
    	if(moption == "CD FISH"){
    		pointer = AFish;
    		cout << "Wezel: FISH" << endl;
    	}
    	if(moption == "CD BIRDS"){
    		pointer = Bird;
    		cout << "Wezel: BIRDS" << endl;
    	}
    	if(moption == "CD DOMESTICBIRDS"){
    		pointer = DBirds;
    		cout << "Wezel: DOMESTICBIRDS" << endl;
    	}
    	if(moption == "CD WILDBIRDS"){
    		pointer = WBirds;
    		cout << "Wezel: WILDBIRDS" << endl;
    	}
    	if(moption == "CD MAMMALS"){
    		pointer = Mammal;
    		cout << "Wezel: MAMMALS" << endl;
    	}
    	if(moption == "CD CATS"){
    		pointer = Cat;
    		cout << "Wezel: CATS" << endl;
    	}
    	if(moption == "CD DOGS"){
    		pointer = Dog;
    		cout << "Wezel: DOGS" << endl;
    	}
    	if(moption == "CD PUREBREDDOGS"){
    		pointer = PBDog;
    		cout << "Wezel: PUREBREDDOGS" << endl;
    	}
    	if(moption == "MO"){
    		if(pointer->leaf){
    			cout << "Wpisz nazwe obiektu do dodania:" << endl;
    			cin >> name;
    			pointer->addObject(name);
    		}
    		else
    			cout << "Biezacy wezel nie jest lisciem. Wybierz wezel, ktory jest lisciem." << endl;
    	}
    	if(moption == "DO"){
    		if(pointer->leaf){
    			cout << "Wpisz nazwe obiektu do usuniecia:" << endl;
    			cin >> name;
    			pointer->delObject(name);
    		}
    		else
    			cout << "Biezacy wezel nie jest lisciem. Wybierz wezel, ktory jest lisciem." << endl;
    	}
    	if(moption == "MDO"){
    		if(pointer->leaf){
    			cout << "Wpisz nazwe obiektu do zmodyfikowania:" << endl;
    			cin >> name;
    			pointer->modObject(name);
    		}
    		else
    			cout << "Biezacy wezel nie jest lisciem. Wybierz wezel, ktory jest lisciem." << endl;
    	}
    	if(moption == "SHOW"){
    		if(pointer->leaf){
    			cout << "Wpisz nazwe obiektu do wyswietlenia:" << endl;
    			cin >> name;
    			pointer->showObjInfo(name);
    		}
    		else
    			cout << "Biezacy wezel nie jest lisciem. Wybierz wezel, ktory jest lisciem." << endl;
    	}
    	if(moption == "DIR"){
    		if(pointer->leaf)
    			pointer->showList();
    		else{
    			string classname = pointer->show_name();
    			if(classname == "Dog")
    				if(!PBDog->objList.empty())
    					PBDog->showList();
    			if(classname == "Mammal"){
    				if(!PBDog->objList.empty())
    					PBDog->showList();
    				if(!Cat->objList.empty())
    					Cat->showList();
    			}
    			if(classname == "Bird"){
    				if(!WBirds->objList.empty())
    					WBirds->showList();
    				if(!DBirds->objList.empty())
    					DBirds->showList();
    			}
    			if(classname == "Animal"){
    				if(!AFish->objList.empty())
    					AFish->showList();
    				if(!WBirds->objList.empty())
    					WBirds->showList();
    				if(!DBirds->objList.empty())
    					DBirds->showList();
    				if(!Cat->objList.empty())
    					Cat->showList();
    				if(!PBDog->objList.empty())
    					PBDog->showList();
    			}
    		}
    	}
    	if(moption == "SAVE"){
    		AFish->saveList();
    		DBirds->saveList();
    		WBirds->saveList();
    		Cat->saveList();
    		PBDog->saveList();

    		cout << "Utworzono pliki .txt ze zbiorami obiektow, ktorych listy nie byly puste." << endl;
    	}
    	if(moption == "READ"){
    		cout << "Nastapi usuniecie wszystkich obecnych obiektow z pamieci programu. Wpisz TAK, jezeli chcesz kontynuowac." << endl;
    		string op;
    		cin >> op;
    		if(op == "TAK"){
    			if(!AFish->objList.empty()){
    				for(int i = 0; i < AFish->objList.size(); i++){
    					delete AFish->objList[i];
    				}
    				AFish->objList.clear();
    			}
    			if(!DBirds->objList.empty()){
    				for(int i = 0; i < DBirds->objList.size(); i++){
    					delete DBirds->objList[i];
    				}
    				DBirds->objList.clear();
    			}
    			if(!WBirds->objList.empty()){
    				for(int i = 0; i < WBirds->objList.size(); i++){
    					delete WBirds->objList[i];
    				}
    				WBirds->objList.clear();
    			}
    			if(!Cat->objList.empty()){
    				for(int i = 0; i < Cat->objList.size(); i++){
    					delete Cat->objList[i];
    				}
    				Cat->objList.clear();
    			}
    			if(!PBDog->objList.empty()){
    				for(int i = 0; i < PBDog->objList.size(); i++){
    					delete PBDog->objList[i];
    				}
    				PBDog->objList.clear();
    			}

    			AFish->readList();
    			DBirds->readList();
    			WBirds->readList();
    			Cat->readList();
    			PBDog->readList();

    			cout << "Dokonano odczytu z plikow .txt ze zbiorami obiektow, ktorych listy nie byly puste." << endl;
    		}
    	}
    	if(moption == "TREE"){
    		tree();
    	}

    }

    return 0;
}

void tree()
{

    cout << "Pokazywanie wezlow w strukturze:\n" << endl << ">ANIMALS" << endl << "\t>FISH" << endl << "\t>BIRDS" << endl;
    cout << "\t\t>DOMESTIC BRIDS" << endl << "\t\t>WILD BRIDS" << endl << "\t>MAMMALS" << endl << "\t\t>CATS" << endl;
    cout << "\t\t>DOGS" << endl << "\t\t\t>PURE BRED DOGS" << endl;
}
