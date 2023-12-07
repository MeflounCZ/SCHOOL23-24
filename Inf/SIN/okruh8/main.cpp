#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct TCLOVEK{
    char jmeno[30],prijmeni[];
    char rodneCislo[];
};

void CreateFile(){
    ofstream file;
    file.open("people.dat");
    file.close();
}

void AddPerson(){
    TCLOVEK person;
    cout << "Name:"
    cin >> person.jmeno;
    cout << "Surname:"
    cin >> person.prijmeni
    cout << "ID number:"
    cin >> person.rodneCislo
    fstream file;
    file.open("people.dat", ios::binary|ios::out|ios::app);
    file.write((char *)&person, sizeof(TCLOVEK));
    file.close();
}

void PrintPeople(){
    TCLOVEk person;
    ifstream file;
    file.open("people.dat", ios::binary)
    while file.read(&person, sizeof(TCLOVEK)){
        string day = person.rodneCislo[4] + person.rodneCislo[5]
        string month
        if (person.rodneCislo[2] < '2'){
            month = person.rodneCislo[2] + person.rodneCislo[3]
        }
        else{
            month = (person.rodneCislo[2]-5) + person.rodneCislo[3]
        }
        string year
        int yr = (person.rodneCislo[0]-48)*10 + (person.rodneCislo[1]-48)
        if (strlen(person.rodneCislo)==9){
            if(yr >= 54){
                year = "18" + person.rodneCislo[0] + person.rodneCislo[1]
            }
        }
        else if (yr < 54){
            year = "20" + person.rodneCislo[0] + person.rodneCislo[1]
        }
        else{
            year = "19" + person.rodneCislo[0] + person.rodneCislo[1]
        }


        cout << "Name: " << person.name << endl;
        cout << "Surname: " << person.surname << endl;
        cout << "Date: " << day << "." << month << "." << year << endl << endl;

    }
    file.close()
}

int main()
{
    int choice
    while (choice != 0){
        cin >> choice;
        switch (choice){
        case 1:
            CreateFile();
            break;
        case 2:
            AddPerson();
            break;
        case 3:
            PrintPeople();
        }
    }
    return 0;
}
