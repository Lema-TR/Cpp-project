#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void registerStudent (char []);
void showStudent (char []);
void searchStudent (char [], int);
void updateStudent (char [], int);
void deleteStudent (char [],int);
struct student
{
int id;
char name[50];
float gpa;
};
char filename[35];
const int SIZE=3;
student s[SIZE];
fstream file;
int id;
  void registerStudent (char filename[])
  {
file.open(filename, ios::out | ios::binary);
  if (file.is_open()) {
  for(int i=0; i<SIZE; i++)
{
cout << "id" << endl ;
cin >> s[i].id;
cin.ignore();
cout << "name" << endl;
cin.getline(s[i].name,50) ;
cout << "gpa"<< endl;
cin >> s[i].gpa;

}
  file.write((char*)s, SIZE *sizeof(student));
  cout << "Registered successfully!";
  file.close();
  }

  }

void showStudent(char fileName[])
{
    file.open(fileName, ios::in | ios::binary);
    if(file.is_open())
    {
        for(int i=0; i<SIZE; i++)
        {
            while(file.read((char*) & s[i], sizeof(student)))
            {
                cout << "ID " << s[i].id << endl;
                cout << "Name " << s[i].name << endl;
                cout << "GPA " << s[i].gpa << endl;
            }
        }
        file.close();
    }
    else
    {
        cout << "Error while finding";
    }
}

void searchStudent (char filename[], int id)
{
bool isfound=false;
file.open(filename,ios::in | ios::binary);
if (file.is_open())
{
  for (int i=0; i<SIZE; i++)
  {
while(file.read((char*) & s[i], sizeof(student)))

    if (s[i].id == id) {
     cout << "ID " << s[i].id << endl;
                cout << "Name " << s[i].name << endl;
                cout << "GPA " << s[i].gpa << endl;
               isfound=true;
      break;
    }
  }
}
 if (!isfound) {
    cout << " \nNo match!";
 }

}
void updateStudent(char filename[], int id) {
    bool isfound = false;
    file.open(filename, ios::in | ios::out | ios::binary);
    if (file.is_open()) {
            for (int i=0; i<SIZE; i++) {
        while (file.read((char*)&s, sizeof(student))) {
            if (s[i].id == id) {
                cout << "Enter new id: ";
                cin >> s[i].id;
                cin.ignore();
                cout << "Enter new name: ";
                cin.getline(s[i].name, 50);
                cout << "Enter new gpa: ";
                cin >> s[i].gpa;
                int pos = sizeof(s[i]);
                file.seekp(-pos, ios::cur);
                file.write((char*)&s[i], sizeof(s[i]));
                cout << "\nUpdated successfully!";
                isfound = true;
                break;
            }
        }
            }
        file.close();
        if (!isfound) {
            cout << "\nIncorrect ID is entered.";
        }
    } else {
        cerr << "Unable to open file!";
    }
}




void deleteStudent(char filename[], int id) {
file.open(filename, ios::in | ios::binary);
fstream temp;
temp.open("temp.bin", ios::out | ios::binary);
if (file.is_open()) {
if (temp.is_open()) {
for (int i = 0; i < SIZE; i++) {
while (file.read((char *)&s[i], sizeof(student))) {
if (s[i].id != id ) {
temp.write((char *)&s[i], sizeof(student));
    }
   }
  }
 }
}
file.close();
temp.close();
remove(filename);
rename("temp.bin", "filename");
cout << "Delete succefully." << endl;
 }
int main()
{


cout << "Enter the filename:";
cin >> filename;
registerStudent (filename);
   //showStudent(filename);

cout << " \nEnter the ID of student you wanna delete:";
cin >> id;
//searchStudent (filename,id);

deleteStudent(filename,id);



//this is to check


    return 0;
}
