#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){

    char fileName[30];
    cout << "Enter file name -> ";
    cin.getline(fileName, 30);

    ifstream fin;
    fin.open(fileName);

    char dataType[100][100];
    char dataName[100][100];

    int dataMemberCount = 0;

    // Reading all the data types and names
    while (!fin.eof()) {

        fin >> dataType[dataMemberCount];
        fin >> dataName[dataMemberCount];
        fin.ignore();

        dataMemberCount++;

    }


    // Removing semi-colons
    for (int i = 0; i < dataMemberCount; i++) {

        dataName[i][strlen(dataName[i]) - 1] = '\0';

    }

    fin.close();
    
    ofstream fout;
    fout.open("gettersAndSetters.txt");

    char strPtr[] = "char*";
    char intPtr[] = "int*";

    // Writing the prototypes

    fout << "// Getter Prototypes \n" << endl;

    for (int i = 0; i < dataMemberCount; i++) {

        fout << dataType[i] << " get" << dataName[i] << "();" << endl;

    }

    fout << "\n\n// Setter Prototypes \n" << endl;

    for (int i = 0; i < dataMemberCount; i++) {

        if (strcmp(dataType[i], intPtr) == 0) {
            
            fout << "void set" << dataName[i] << "(" << dataType[i] << " " << dataName[i] << ", int s);" << endl;

        } else {

            fout << "void set" << dataName[i] << "(" << dataType[i] << " " << dataName[i] << ");" << endl;

        }

    }

    fout << endl << endl;

    // Writing the getter definitions

    fout << "// Getter definitions \n" << endl;

    for (int i = 0; i < dataMemberCount; i++) {

        fout << dataType[i] << " get" << dataName[i] << "() {\n";

        fout << "\treturn " << dataName[i] << ";" << endl;

        fout << "}\n" << endl;

    }

    fout << "// Setter definitions \n" << endl;

    for (int i = 0; i < dataMemberCount; i++) {

        fout << "void set" << dataName[i] << "(" << dataType[i] << " " << dataName[i] << ") {\n";

        if (strcmp(strPtr, dataType[i]) == 0) {

            fout << "\tif (" << dataName[i] << " != nullptr) \n\t\t delete[] this->" << dataName[i] << endl;
            fout << "\tthis->" << dataName[i] << " = new char[strlen(" << dataName[i] << ") + 1];\n";
            fout << "\tstrcpy(this->" << dataName[i] << ", " << dataName[i] << ");\n"; 

        } else if (strcmp(intPtr, dataType[i]) == 0) {

            fout << "\tif (" << dataName[i] << " != nullptr) \n\t\t delete[] this->" << dataName[i] << ";\n";
            fout << "\tthis->" << dataName[i] << " = new int[s];\n";
            fout << "\tfor (int i = 0; i < s; i++) \n\t\tthis->" << dataName[i] << "[i] = " << dataName[i] << "[i]; ";
        
        } else {

            fout << "\tthis->" << dataName[i] << " = " << dataName[i] << ";" << endl;

        }

        fout << "\n}\n" << endl;

    }

    fout.close();

    return 0;
}