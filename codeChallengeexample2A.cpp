#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std; // Use the std namespace

// Define a struct for an animal name
struct AnimalName {
    string name;
    AnimalName* next;

    AnimalName(const string& n) : name(n), next(0) {}
};

// Define a struct for a species linked list node
struct SpeciesNode {
    SpeciesNode* next;
    AnimalName* namesHead;
    string speciesName;

    SpeciesNode(const string& name) : speciesName(name), next(0), namesHead(0) {}
};


int main() {
    
    // Open the file
    ifstream inputFile("C:\\Users\\Johnny\\Downloads\\animalNames.txt");

    // create an error message if file is not found
    if (!inputFile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    string line;
    SpeciesNode* headSpecies = 0;
    SpeciesNode* currentSpecies = 0;

    while (getline(inputFile, line)) {
        size_t found = line.find(" Names:");
        if (found != -1) { // Check if " Names:" was found
            // Extract the species name
            string speciesName = line.substr(0, found);

            // Create a new species node
            SpeciesNode* newSpecies = new SpeciesNode(speciesName);
            if (!headSpecies) { // if list is empty
                headSpecies = newSpecies;
                currentSpecies = newSpecies;
            }
            else { // if list is not empty
                currentSpecies->next = newSpecies;
                currentSpecies = newSpecies;
            }
        }
        else if (currentSpecies) {
            // Read and create a linked list of names for the current species
            istringstream nameStream(line);
            string name;

            // Split the line into individual names
            while (getline(nameStream, name, ',')) {
                // Create a new name node and add it to the current species
                AnimalName* newName = new AnimalName(name);
                newName->next = currentSpecies->namesHead;
                currentSpecies->namesHead = newName;
            }
        }
    }

    inputFile.close();

    // Display all species and their names
    SpeciesNode* current = headSpecies;
    while (current) {
        cout << current->speciesName << " Names:" << endl;

        // Print the linked list of names for the current species
        AnimalName* currentName = current->namesHead;
        while (currentName) {
            cout << "  " << currentName->name << endl;
            currentName = currentName->next;
        }

        cout << endl;
        current = current->next;
    }

    // Search for and print a specific species
    string speciesToSearch;
    cout << "Enter a species name to search for: ";
    getline(cin, speciesToSearch);

    current = headSpecies;
    while (current) {
        if (current->speciesName == speciesToSearch) {
            cout << current->speciesName << " Names:" << endl;

            // Print the linked list of names for the searched species
            AnimalName* currentName = current->namesHead;
            while (currentName) {
                cout << "  " << currentName->name << endl;
                currentName = currentName->next;
            }

            break; // No need to continue searching after finding the species
        }
        current = current->next;
    }

    

    return 0;
}