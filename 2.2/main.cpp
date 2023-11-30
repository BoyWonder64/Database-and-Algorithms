#include "Dictionary.h"
#include <iostream>

/*
 * @file main.cpp
 * @author Kim Murphy
 * @brief Use the Templated Dictionary to determine the number of each of the
 * grades in the class.
 * @date 1/2/2023
 */

using namespace std;

int main() {

  /***********************************************************
Use the Templated Dictionary to determine the number of each of the grades in
the class.
  *
  ************************************************************/
  // Number of students
  const int NUM_STUDENTS = 32;
  // Student grades
  char grades[NUM_STUDENTS] = {'A', 'A', 'B', 'A', 'C', 'A', 'C', 'A',
                               'B', 'A', 'D', 'F', 'A', 'A', 'B', 'C',
                               'B', 'A', 'C', 'A', 'A', 'B', 'B', 'B',
                               'A', 'B', 'D', 'D', 'A', 'A', 'A', 'A'};
  // Define the dictionary
  Dictionary<char, int, 5> class_grades;

  // Iterate through each grade
  for (int i = 0; i < NUM_STUDENTS; i++) {
    char current_grade = grades[i];
    if (class_grades.IndexOfTerm(grades[i]) < 0) {
      class_grades.Add(current_grade, 1);

    } else {
      // Update the else statement

      // find the definition of the given grade in the class_grades dictionary
      // Add one to the definition
      // update the class_grades with the new definition of the grade
 
    int foo = class_grades.GetDefinition(grades[i]);
    foo++;
    class_grades.UpdateDefinition(grades[i], foo);

    }
  }
  cout << class_grades;
}