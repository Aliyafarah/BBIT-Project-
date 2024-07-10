#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Student {
    string firstname;  // Student's first name
    string surname;    // Student's surname
    string gender;     // Student's gender
    int age;           // Student's age
    int group;         // BBIT group the student belongs to
    vector<string> activities; // List of activities the student participates in
};

// Define a structure to hold activity data
struct Activity {
    string name;       // Name of the activity
    string type;       // Type of the activity (Sport or Club)
    int capacity;      // Maximum number of participants allowed
    int currentCount;  // Current number of participants
};

// Function prototypes
void displayMenu();
void displayActivities(const vector<Activity> &activities, const string &type);
void addStudent(vector<Student> &students, vector<Activity> &activities);
void viewStudents(const vector<Student> &students);
void viewActivities(const vector<Activity> &activities, const string &type);
void saveToCSV(const vector<Student> &students);

// Function to display the menu
void displayMenu() {
    cout << "\nBBIT Year 1 Co-Curricular Activity Allocation System\n";
    cout << "Menu:\n";
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. View Clubs/Societies\n";
    cout << "4. View Sports\n";
    cout << "5. Save all Files\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}
