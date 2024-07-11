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
void displayActivities(const vector<Activity> &activities, const string &type) {
    cout << "\nAvailable " << type << " Activities:\n";
    for (size_t i = 0; i < activities.size(); ++i) {
        const Activity &activity = activities[i];
        if (activity.type == type) {
            cout << activity.name << " (" << activity.type << "), Capacity: "
                 << activity.currentCount << "/" << activity.capacity << endl;
        }
    }
}

// Function to add a student
void addStudent(vector<Student> &students, vector<Activity> &activities) {
    Student student;
    cout << "\nEnter first name: ";
    cin >> ws; // consume any leading whitespace
    getline(cin, student.firstname);
    cout << "Enter surname: ";
    getline(cin, student.surname);
    cout << "Enter gender (Male/Female): ";
    getline(cin, student.gender);
    cout << "Enter age: ";
    cin >> student.age;
    cout << "Enter BBIT group (1, 2, or 3): ";
    cin >> student.group;
    if (student.group < 1 || student.group > 3) {
        cout << "Invalid group number. Returning to main menu.\n";
        return;
    }

    // Display available sports
    displayActivities(activities, "Sport");

    // Allocate sport to the student
    cout << "\nEnter the name of the sport the student will partake in (or 'None' if not participating in any sport): ";
    string sport;
    cin >> ws; // consume any leading whitespace
    getline(cin, sport);
    if (sport != "None") {
        student.activities.push_back(sport);
        // Update the activity count
        for (size_t i = 0; i < activities.size(); ++i) {
            if (activities[i].name == sport) {
                activities[i].currentCount++;
                break;
            }
        }
    }
 // Display available clubs
    displayActivities(activities, "Club");

    // Allocate clubs to the student
    cout << "\nEnter the number of clubs the student will join (maximum 3 if not participating in a sport, otherwise maximum 2): ";
    int numClubs;
    cin >> numClubs;

    for (int i = 0; i < numClubs; ++i) {
        string clubName;
        cout << "Enter the name of club " << i + 1 << ": ";
        cin >> ws; // consume any leading whitespace
        getline(cin, clubName);
        student.activities.push_back(clubName);

        // Update the activity count
        for (size_t j = 0; j < activities.size(); ++j) {
            if (activities[j].name == clubName) {
                activities[j].currentCount++;
                break;
            }
        }
    }

    students.push_back(student); // Add the student to the list
    cout << "\nStudent added successfully!\n";
}

// Function to view all students
void viewStudents(const vector<Student> &students) {
    cout << "\nStudents:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        const Student &student = students[i];
        cout << student.firstname << " " << student.surname << " (" << student.gender
             << ", Age: " << student.age << ", Group: " << student.group << "): ";
        for (size_t j = 0; j < student.activities.size(); ++j) {
            cout << student.activities[j] << " ";
        }
        cout << endl;
    }
}
// Function to view activities of a specific type (Sport or Club)
void viewActivities(const vector<Activity> &activities, const string &type) {
    cout << "\n" << type << " Activities:\n";
    for (size_t i = 0; i < activities.size(); ++i) {
        const Activity &activity = activities[i];
        if (activity.type == type) {
            cout << activity.name << " (" << activity.type << "), Capacity: "
                 << activity.currentCount << "/" << activity.capacity << endl;
        }
    }
}

// Function to save student data to a CSV file
void saveToCSV(const vector<Student> &students) {
    ofstream outFile("students.csv");

    // Write the header line
    outFile << "Firstname,Surname,Gender,Age,Group,Activities\n";

    // Write student data
    for (size_t i = 0; i < students.size(); ++i) {
        const Student &student = students[i];
        outFile << student.firstname << "," << student.surname << "," << student.gender
                << "," << student.age << "," << student.group << ",";
        for (size_t j = 0; j < student.activities.size(); ++j) {
            outFile << student.activities[j] << " ";
        }
        outFile << "\n";
    }

    outFile.close();
    cout << "\nData saved to students.csv\n";
}
int main() {
    vector<Student> students; // Vector to hold student data
    vector<Activity> activities;

    // Initialize activities
    activities.push_back((Activity){"Rugby", "Sport", 20, 0});
    activities.push_back((Activity){"Athletics", "Sport", 20, 0});
    activities.push_back((Activity){"Swimming", "Sport", 20, 0});
    activities.push_back((Activity){"Soccer", "Sport", 20, 0});
    activities.push_back((Activity){"Journalism Club", "Club", 60, 0});
    activities.push_back((Activity){"Red Cross Society", "Club", 60, 0});
    activities.push_back((Activity){"AISEC", "Club", 60, 0});
    activities.push_back((Activity){"Business Club", "Club", 60, 0});
    activities.push_back((Activity){"Computer Science Club", "Club", 60, 0});

    while (true) {
        displayMenu(); // Show the menu
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students, activities); // Add a new student
            break;
        case 2:
            viewStudents(students); // View all students
            break;
        case 3:
            viewActivities(activities, "Club"); // View clubs/societies
            break;
        case 4:
            viewActivities(activities, "Sport"); // View sports
            break;
        case 5:
            saveToCSV(students); // Save data to CSV
            break;
        case 6:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    return 0;
}
