#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

class ToDolist
{
private:
    int id;
    string description;
    int periority;
    int date;
    fstream file;
    vector<string> lines;
    string line;
public: 
    void showMeniu()
    {
        cout << "---------^^^^your ToDO list^^^^---------\n";
        cout << "1- Add New Task \n";
        cout << "2- Mark As Complete \n";
        cout << "3- Display All Tasks \n";
        cout << "4- Remove Task \n";
        cout << "5- Edit Task \n"; 
        cout << "0- Exit \n";
        cout << "Enter your chiose : \n";
        
    }

    void setPeriority(int periority)
    {
        if(periority > 3)
        {
            throw out_of_range("enter a number betwin 0 - 3 \n");
        }
        this->periority = periority;
    }

    void addNewTask()
    {
        cout << "Enter Id : \n";
        cin >> id;

        cout << "Enter your task : \n";
        cin >> description;

        try
        {
        cout << "What is the periority ?\n";
        cin >> periority;
        setPeriority(periority);
        }
        catch(const logic_error& e)
        {
            std::cerr << e.what() << '\n';
        }

        cout << "Date: ";
        cin >> date;
        
        file.open("Items.txt" , ios::app);
        if (file.fail())
        {
            cout << "Error opening file." << '\n';
        }        
        file << id << ' ' << description << ' ' << periority << ' ' << date << ' ' << 0 << '\n';
        file.close();
        
        system("cls");
    }
    
    void deleteTask() 
    {
        string fileName;
        int lineNumber;

        cout << "File: ";
        cin >> fileName;

        cout << "Line Number: ";
        cin >> lineNumber;

        file.open(fileName);

        if (file.fail())
        {
            cout << "Error opening file." << '\n';
        }

        while (getline(file, line))
            lines.push_back(line);
 
        file.close();

        if (lineNumber > lines.size())
        {
            cout << "Line " << lineNumber;
            cout << " not in file." << '\n';

            cout << "File has " << lines.size();
            cout << " lines." << '\n';
        }

        ofstream writeFile;
        writeFile.open(fileName , ios::trunc);

        if (writeFile.fail())
        {
            cout << "Error opening file." << '\n';
        }

        lineNumber--;

        for (int i = 0; i < lines.size(); i++)
            if (i != lineNumber)
            writeFile << lines[i] << '\n';


        writeFile.close();

    }
    
    void readTaskFromFile()
    {
        ifstream Items("Items.txt");
        string myText;
        if (Items.fail())
        {
            cout << "Error opening file." << '\n';
        }        
        while (getline(Items , myText))
        {
            cout << myText << '\n';
        }
        
    }

    void setComplete()
    {
        string fileName;
        string description;
        int lineNumber;
        int periority;
        int date;

        cout << "File: ";
        cin >> fileName;

        cout << "Line Number: ";
        cin >> lineNumber;

        cout << "Description: ";
        cin >> description;

        cout << "Periority: ";
        cin >> periority;

        cout << "Date: ";
        cin >> date;

        file.open(fileName);

        while (getline(file, line))
            lines.push_back(line);
        
        file.close();
        
        if (lineNumber > lines.size())
        {
            cout << "Line " << lineNumber;
            cout << " not in file." << '\n';

            cout << "File has " << lines.size();
            cout << " lines." << '\n';
        }

        ofstream writeFile;
        
        writeFile.open(fileName);

        if (writeFile.fail())
        {
            cout << "Error opening file." << '\n';
        }

        lineNumber--;

        for (int i = 0; i < lines.size(); i++)
        {
            if (i != lineNumber)
            writeFile << lines[i] << '\n';
            else 
            writeFile << lineNumber + 1 << ' ' <<  description << ' ' << periority << ' ' << date << ' ' << 1 << '\n'; 
        }
        writeFile.close();

    }

    void edit()
    {
        string fileName;
        string newDescription;
        int lineNumber;
        int newPeriority;
        int newDate;

        cout << "File: ";
        cin >> fileName;

        cout << "Line Number: ";
        cin >> lineNumber;

        cout << "New Description: ";
        cin >> newDescription;

        cout << "New Periority: ";
        cin >> newPeriority;

        file.open(fileName);

        while (getline(file, line))
            lines.push_back(line);
        
        file.close();
        
        if (lineNumber > lines.size())
        {
            cout << "Line " << lineNumber;
            cout << " not in file." << '\n';

            cout << "File has " << lines.size();
            cout << " lines." << '\n';
        }

        ofstream writeFile;
        
        writeFile.open(fileName , ios::trunc);

        if (writeFile.fail())
        {
            cout << "Error opening file." << '\n';
        }

        lineNumber--;

        for (int i = 0; i < lines.size(); i++)
        {
            if (i != lineNumber)
            writeFile << lines[i] << '\n';
            else 
            writeFile << lineNumber + 1 << ' ' <<  newDescription << ' ' << newPeriority << ' ' << newDate << ' ' << 0 << '\n'; 
        }
        writeFile.close();

    }
};

int main()
{
    ToDolist todo;
while (1)
{
    int choise;
    todo.showMeniu();
    cin >> choise;
    system("cls");
    switch (choise)
    {
    case 1:
        todo.addNewTask();
        break;
    case 2:
        todo.setComplete();
        break;
    case 3:
        todo.readTaskFromFile();
        cout << '\n';
        break;
    case 4:
        todo.deleteTask();
        break;
    case 5:
        todo.edit();
        break;
    case 0:
        return 0;
        break;
    }
}
    return 0;
}