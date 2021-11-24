/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - Simulation.cpp */

/*
This is the .cpp file for Simulation
*/

//this statement includes the Simulation.h file
#include "Simulation.h"
#include "Database.h"
#include "DatabaseOperations.h"
#include "GenStack.h"


Simulation::Simulation(){
  //default constructor
  Database<T> *studentDB;
  Database<T> *facultyDB;
  GenStack<DatabaseOperations> stack = new GenStack<DatabaseOperations>();
}

Simulation::~Simulation(){
  //destructor
  delete studentDB;
  delete facultyDB;
  delete stack;
}

void Simulation::start(){
  bool fileProcessed = fileProcessor();
  if (!fileProcessed){
    studentDB = new Database<T>();
    facultyDB = new Database<T>();
  }
}

void Simulation::simulate(){
  try{
    bool userExit = false;
    while (!userExit){
      cout << "--------------------------------------------------------------------------------------------------" << endl;
      cout << "Welcome to the School Database! Please enter the number for the action which you wish to complete!" << endl;
      cout << "--------------------------------------------------------------------------------------------------" << endl;
      cout << "\n" << endl;
      cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
      cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
      cout << "3. Find and display student information given the students id" << endl;
      cout << "4. Find and display faculty information given the faculty id" << endl;
      cout << "5. Given a student's id, print the name and info of their faculty advisor" << endl;
      cout << "6. Given a faculty id, print ALL the names and info of his/her advisees" << endl;
      cout << "7. Add a new student" << endl;
      cout << "8. Delete a student given the id" << endl;
      cout << "9. Add a new faculty member" << endl;
      cout << "10. Delete a faculty member given the id" << endl;
      cout << "11. Change a student's advisor given the student id and the new faculty id" << endl;
      cout << "12. Remove an advisee from a faculty member given the id" << endl;
      cout << "13. Rollback" << endl;
      cout << "14. Exit" << endl;
      int userInput;
      cin >> userInput;

      if (userInput == 1){
        //1. Print all students and their information (sorted by ascending id #)
        StudentDB->printDB();
      }
      else if (userInput == 2){
        //2. Print all faculty and their information (sorted by ascending id #)
        FacultyDB->printDB();
      }
      else if (userInput == 3){
        //3. Find and display student information given the students id
        int stuID;
        cout << "Enter student ID: ";
        cin >> stuID;
        StudentDB->displayObject(stuID);
      }
      else if (userInput == 4){
        //4. Find and display faculty information given the faculty id
        int facID;
        cout << "Enter faculty ID: ";
        cin >> facID;
        FacultyDB->displayObject(facID);
      }
      else if (userInput == 5){
        //5. Given a student's id, print the name and info of their faculty advisor
        int stuID;
        int facID;
        cout << "Enter student ID: ";
        cin >> stuID;
        facID = StudentDB->displayAdvisorNum(stuID);
        FacultyDB->displayObejct(facID);
      }
      else if (userInput == 6){
        //6. Given a faculty id, print ALL the names and info of his/her advisees
        int facID;
        cout << "Enter faculty ID: ";
        cin >> facID;
        FacultyDB->displayAllAdvisees(facID);
      }
      else if (userInput == 7){
        //7. Add a new student
        cout << "Adding a student" << endl;
        int id;
        int adv;
        string name;
        string level;
        string major;
        double gpa;
        cout << "Name of Student: ";
        cin >> name;
        cout << "Student ID: ";
        cin >> id;
        cout << "Level: ";
        cin >> level;
        cout << "major: ";
        cin >> major;
        cout << "GPA: ";
        cin >> gpa;
        cout << "Advisor ID: ";
        cin >> adv;
        StudentDB->addStudent(id, name, level, major, gpa, adv);
      }
      else if (userInput == 8){
        //8. Delete a student given the id
        int stu;
        cout << "Enter student ID: ";
        cin >> stu
        StudentDB->deleteObject(stu);
      }
      else if (userInput == 9){
        //9. Add a new faculty member
        cout << "Adding a Faculty member" << endl;
        int id;
        string name;
        string level;
        string department;
        cout << "Name of Faculty: ";
        cin >> name;
        cout << "Faculty ID: ";
        cin >> id;
        cout << "Level: ";
        cin >> level;
        cout << "department: ";
        cin >> department;
        FacultyDB->addFaculty(id, name, level, department);
      }
      else if (userInput == 10){
        //10. Delete a faculty member given the id
        int fac;
        cout << "Enter Faculty ID: ";
        cin >> fac
        FacultyDB->deleteObject(fac);
      }
      else if (userInput == 11){
        //11. Change a student's advisor given the student id and the new faculty id
        int stu;
        int fac;
        cout << "Student ID: ";
        cin >> stu;
        cout << "New Faculty ID: ";
        cin >> fac;
        StudentDB->changeAdvisor(stu, fac);
      }
      else if (userInput == 12){
        //12. Remove an advisee from a faculty member given the id
        int stu;
        int fac;
        cout << "Faculty ID: ";
        cin >> fac;
        cout << "Student to be removed ID: ";
        cin >> stu;
        StudentDB->removeAdvisee(fac, stu);
      }
      else if (userInput == 13){
        //13. Rollback
        rollback();
      }
      else if (userInput == 14){
        //14. Exit
        userExit = true;
        exit();
        cout << "Thank you goodbye." << endl;
        continue;
      }
      else {
        cout << "Sorry that was not a valid option, please try again" << endl;
      }
    }
  }

  catch(runtime_error &excpt){
    cerr << excpt.what() << endl;
  }
}

//1.
void Simulation::printAllStudentInfo(){
  studentDB->printDB();
}

//2.
void Simulation::printAllFalcultyInfo(){
  facultyDB->printDB();
}

//3.
void Simulation::displayStudentInfo(int studentID){
  int studentID;
  cout << "Enter the ID number of the student you wish to display: ";
  cin >> studentID;
  studentDB->displayObject(studentID);
}

//4.
void Simulation::displayFacultyInfo(int facultyID){
  int facultyID;
  cout << "Enter the ID number of the faculty you wish to display: ";
  cin >> facultyID;
  facultyDB->displayObject(facultyID);
}

//5.
void Simulation::displayStudentAdvisor(int studentID){
  int studentID;
  cout << "Enter the ID number of the student who's advisor you wish to display: ";
  cin >> studentID;
  int advisorID = studentDB->getObject(studentID)->getAdvisorID();
  displayObject(advisorID);
}

//6.
void Simulation::displayAllAdvisees(int facultyID){
  int facultyID;
  cout << "Enter the ID number of the faculty to display all of their advisees: ";
  cin >> facultyID;
  facultytDB->displayAllAdvisees(facultyID);
}

//7.
void Simulation::addStudent(){
  int newID;
  cout << "Enter the ID for the new Student: ";
  cin >> newID;
  string newName = "";
  cout << "Enter the name for the new Student: ";
  cin >> newName;
  string newLevel = "";
  cout << "Enter the level for the new Student: ";
  cin >> newLevel;
  string newMajor = "";
  cout << "Enter the major for the new Student: ";
  cin >> newMajor;
  double newGPA = 0.0;
  cout << "Enter the GPA for the new Student: ";
  cin >> newGPA;
  int newAdvisorID = 0;
  cout << "Enter the ID of the advisor for the new Student: ";
  cin >> newAdvisorID;
  studentDB->addStudent(newID, newName, newLevel, newMajor, newGPA, newAdvisorID);
  DatabaseOperations<Student> *operation = new DatabaseOperations<Student>(0,true,studentDB->getObject(newID));
  stack->push(operation);
}

//8.
void Simulation::deleteStudent(){
  int studentID;
  cout << "Enter the ID number of the student you wish to delete: ";
  cin >> studentID;
  DatabaseOperations<Student> *operation = new DatabaseOperations<Student>(1,true,studentDB->getObject(studentID));
  stack->push(operation);

  studentDB->deleteStudent(studentID);
}

//9.
void Simulation::addFaculty(){
  int newID;
  cout << "Enter the ID for the new Advisor: ";
  cin >> newID;
  string newName = "";
  cout << "Enter the name for the new Advisor: ";
  cin >> newName;
  string newLevel = "";
  cout << "Enter the level for the new Advisor: ";
  cin >> newLevel;
  string newDepartment = "";
  cout << "Enter the deparment for the new Advisor: ";
  cin >> newDepartment;
  int newIDListSize = 10;
  facultyDB->addFaculty(newID, newName, newLevel, newDepartment, newIDListSize);
  DatabaseOperations<Faculty> *operation = new DatabaseOperations<Faculty>(0,false,facultyDB->getObject(newID));
  stack->push(operation);
}

//10.
void Simulation::deleteFaculty(){
  int facultyID;
  cout << "Enter the ID number of the faculty member you wish to delete: ";
  cin >> facultyID;
  DatabaseOperations<Faculty> *operation = new DatabaseOperations<Faculty>(1,false,facultyDB->getObject(facultyID));
  stack->push(operation);

  facultyDB->deleteFaculty(facultyID);
}

//11.
void Simulation::changeAdvisor(){
  int studentID;
  cout << "Enter the ID number of the student who needs their advisor changed: ";
  cin >> studentID;
  int facultyID;
  cout << "Enter the ID number of the new advisor: ";
  cin >> facultyID;
  studentDB->changeAdvisor(studentID, facultyID);
}

//12.
void Simulation::removeAdvisee(){
  int facultyID;
  cout << "Enter the ID number of the faculty member you wish to edit: ";
  cin >> facultyID;
  int studentID;
  cout << "Enter the ID number of the advisee you wish to remove: ";
  cin >> studentID;
  facultyDB->removeAdvisee(facultyID, studentID);
}

//13.
void Simulation::rollback(){
  if (stack->isEmpty()){
    throw runtime_error("Stack is empty, there are no actions to undo!");
  }

  int action = stack->peek()->getAction();
  bool isStudent = stack->peek()->isStudent();
  if (isStudent){
    if (action == 0){
      int studentID = stack->pop()->getObject()->getStudentID();
      studentDB->deleteStudent(studentID);
    }
    else if (action == 1){
      int studentID = stack->peek()->getObject()->getStudentID();
      string name = stack->peek()->getObject()->getStudentName();
      string level = stack->peek()->getObject()->getStudentLevel();
      string major = stack->peek()->getObject()->getStudentMajor();
      double studentGPA = stack->peek()->getObject()->getStudentGPA();
      int advisorID = stack->pop()->getObject()->getAdvisorID();
      studentDB->addStudent(studentID, name, level, major, studentGPA, advisorID);
    }
    else {
      throw runtime_error("Rollback action doesn't exist!");
    }
  }
  else{
    if (action == 0){
      int facultyID = stack->pop()->getObject()->getFacultyID();
      facultyDB->deleteFaculty(facultyID);
    }
    else if (action == 1){
      int facultyID = stack->peek()->getObject()->getFacultyID();
      string name = stack->peek()->getObject()->getFacultyName();
      string level = stack->peek()->getObject()->getFacultyLevel();
      string department = stack->peek()->getObject()->getFacultyMajor();
      facultytDB->addFaculty(facultyID, name, level, department);
    }
    else {
      throw runtime_error("Rollback action doesn't exist!");
    }
  }

}

//14.
void Simulation::exit(){
  //uhhhh idk

}

bool Simulate::fileProcessor(){
  string facultyTableFile = "facultyTable.txt";
  string studentTableFile = "studentTable.txt";

  if (facultyTableFile.open()){
    //process file, create trees
    return true;
  }
  else {
    return false;
  }

}
