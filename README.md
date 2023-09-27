# tCodeChallenge25sep23
tCodeChallenge25sep23: Create a linked list of animal names. Use Discord and help your classmates!

Posted: Sept 25, 2023
by: dH


Linked List of Species Names - C++ Code Challenge
Introduction
Welcome to the "Linked List of Species Names" C++ code challenge! This challenge is designed to test your skills in creating a linked list of structs with string data fields representing species and animal names using C++. The goal is to read species and animal names from a file named animalNames.txt and organize them into a linked list data structure.

This is a cooperative class assignment, and we encourage you to use platforms like Discord to collaborate and share your coding solutions with your fellow students.

Challenge Description
Objective
Your task is to create a C++ program that reads species and animal names from the animalNames.txt file and constructs a linked list of structs to store this information. Each node in the linked list should contain a species name and an animal name, both represented as strings.

Struct Definition
You should define a struct to represent each node in the linked list. Here's an example definition:

struct AnimalNode {
    std::string species;
    std::string name;
    AnimalNode* next;

    // Constructor to initialize values
    AnimalNode(const std::string& s, const std::string& n) : species(s), name(n), next(nullptr) {}
};

File Format

The animalNames.txt file will contain data in the following format:

Species Name:

Simba, Shere, Khan, ...

Animal names are seperated by commas.

Linked List Construction:

You need to read the data from animalNames.txt and construct a linked list where each node contains a species and an animal name. 
The linked list should be constructed in the order in which the names appear in the file.

Sample Code:

Here's a sample C++ code snippet to get you started:


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct AnimalNode {
    string species;
    string name;
    AnimalNode* next;
};

int main() {
    
    // Initialize the linked list head
    AnimalNode* head = nullptr; 
    
    // Read data from the file
    std::ifstream inputFile("animalNames.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    // TODO: Read data from the file and construct the linked list

    // TODO: Print the linked list

    // TODO: Clean up memory (delete linked list nodes)

    return 0;
}

Modify and expand upon this sample code to complete the challenge. Advanced is to organize thge names into male and female names for each species.

Submission
Once you have completed the challenge, share your code with your fellow students on Discord. Make sure to test your code thoroughly and ensure it works as expected.

Good luck, and have fun coding!
