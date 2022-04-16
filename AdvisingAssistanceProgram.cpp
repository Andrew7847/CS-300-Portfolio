//===========================================================================================
// Name        : AdvisingAssistanceProgram.cpp
// Author      : Andrew Jones
// Version     : 1.0
// Date        : 04/13/2022
// Description : A program to load school courses from a file, sort them alphanumerically, 
//               and print either the entire course list or one single course's information.
//===========================================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

// Create a structure to hold course information
struct Course {
    string courseID;
    string courseDesc;
    string preReq;
    Course() {
        
    }
};

/**
 * Method to display all of the valid courses
 * that were read from the input file
 * 
 * @param course the course structure to be displayed 
 *               that is part of the courses vector
 * 
 */
void displayCourseList(Course course) {
    cout << course.courseID << ", " << course.courseDesc << endl;
}

/**
 * Method to load course information from an input
 * file and store them in a vector of courses
 *
 * @param csvPath the path to the input file
 *
 */
vector<Course> loadCourses(string csvPath) {
    // Declare necessary variables
    vector<Course> courses;
    string line;

    // Open the file
    ifstream readFile(csvPath);

    // If file is not found, inform the user
    if (!readFile) {
        cerr << "Error opening the file" << endl;
        return courses;
    }

    cout << "Loading courses from " << csvPath << endl;

    // Read the file line by line
    while (getline(readFile, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;
        Course course;

        // Store the individual paramaters of the line in tokens
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }
        // If there are less than 2 parameters on a line, it is not valid so skip the line
        if (tokens.size() < 2) {
            continue;
        }

        // Store the first item on the line as the course ID
        course.courseID = tokens[0];
        // Store the second item on the line as the course description
        course.courseDesc = tokens[1];
        // Check if there are any prerequisites
        if (tokens.size() > 2) {
            // For all except the final prerequisite, concatinate to a string with a comma in between values
            for (int i = 2; i < tokens.size() - 1; i++) {
                course.preReq = course.preReq + tokens[i] + ", ";
            }
            // Add the final prerequisite to the string concatination without a comma at the end
            course.preReq = course.preReq + tokens[tokens.size() - 1];
        }
        // Add the course struct to the courses vector
        courses.push_back(course);
    }

    // Close the file to prevent memory leaks
    readFile.close();
    
    // Sort the courses vector alphanumerically using a simple lambda function that compares the courseID's
    sort(courses.begin(), courses.end(), [](Course a, Course b) {
        return a.courseID < b.courseID;
        });

    cout << "Courses loaded successfully!" << endl;
    // Return the sorted course vector
    return courses;
}


/**
 * Method to search the courses vector to find if
 * a user-specified course is in the courses vector.
 * If the course is found, return that course struct.
 * 
 * @param courses Address of the vector<Course> instance
 *                to be searched
 * @param courseID The user-specified search value to 
 *                 search for in the courses vector
 * @return a container holding the course information
 */
Course searchCourse(vector<Course>& courses, string courseID) {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].courseID == courseID) {
            return courses[i];
        }
    }
    Course course;
    return course;
}



int main()
{
    // Housekeeping variables
    string csvPath;
    string searchValue;
    Course course;
    vector<Course> courses;

    int choice = 0;
    // Display a menu for the user to navigate
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Data Structure" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print A Course" << endl;
        cout << "  9. Exit" << endl;
        cout << "What would you like to do: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            // Prompt the user for the file name and store it
            cout << "Enter the name of the file you wish to load courses from: ";
            cin >> csvPath;

            // Complete the call to the loadCourses method using the provided file name
            courses = loadCourses(csvPath);
            break;
        case 2:
            // Loop and display the courses read
            for (int i = 0; i < courses.size(); i++) {
                displayCourseList(courses[i]);
            }
            break;
        case 3:
            // Prompt the user for a search value and store it
            cout << "Enter a course to search for: ";
            cin >> searchValue;
            
            // Complete the call to the searchCourse method using the search value and the courses vector
            course = searchCourse(courses, searchValue);

            // If the returned course container is not empty
            if (!course.courseID.empty()) {
                // If there are no prerequisites for the returned course
                if (course.preReq.empty()) {
                    cout << course.courseID << ", " << course.courseDesc << endl;
                }
                // Otherwise, print the courseID, courseDesc, and all preReq
                else {
                    cout << course.courseID << ", " << course.courseDesc << endl;
                    cout << "Prerequisites: " << course.preReq << endl;
                }
            }
            // If the course that was searched for does not exist in the vector
            else {
                cout << searchValue << " not found in course list." << endl;
            }
            break;
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            return 0;

        // If the user does not enter a valid menu choice
        default:
            cout << choice << " is not a valid option." << endl;
        }
    }
}