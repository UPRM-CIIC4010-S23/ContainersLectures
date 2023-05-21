#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {

private:
    int id;
    string firstName;
    string lastName;
    float gpa;

public:
    Student(int id, string fn, string ln, float g) : id(id), firstName(fn), lastName(ln), gpa(g) {}

    int getId() const { return id; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    float getGpa() const { return gpa; }

    // operator< required by sort without parameters
    bool operator<(const Student &s) const {
        return this->getId() < s.getId();
    }
};

bool compByGPAIncreasing(const Student &s1, const  Student &s2) {
    return (s1.getGpa() < s2.getGpa());
}

bool compByGPADecreasing(const Student &s1, const  Student &s2) {
    return (s1.getGpa() > s2.getGpa());
}

int main() {

    vector<Student> testStudents;
    testStudents.push_back(Student(10, "Bienve", "Velez", 3.5));
    testStudents.push_back(Student(65, "Joshua", "Cruz", 3.1));
    testStudents.push_back(Student(33, "Amanda", "Vazquez", 4.0));
    testStudents.push_back(Student(32, "Amanda", "Davis", 2.9));
    testStudents.push_back(Student(66, "Joshua", "Vazquez", 3.45));
    testStudents.push_back(Student(43, "Alejandra", "Munoz", 3.2));
    testStudents.push_back(Student(54, "Theo", "Puig", 4.0));
    testStudents.push_back(Student(76, "Rey", "Cotto", 3.7));

    cout << "Count of Vector Students: " << testStudents.size() << endl;

    // // Sort students by id using operator<
    // sort(testStudents.begin(),testStudents.end());

    // // Sort increasingly by GPA using standalone comparator function
    // sort(testStudents.begin(),testStudents.end(),compByGPAIncreasing);

    // // Sort decreasingly by GPA using standalone comparator function
    // sort(testStudents.begin(),testStudents.end(),compByGPADecreasing);

    // // Sort increasingly by GPA using lambda expression
    // sort(testStudents.begin(), testStudents.end(),
    //      [](const Student &s1, const Student &s2) { return s1.getLastName() < s2.getLastName(); });

    // Find Student with last name "Vazquez"
    auto it = find_if(testStudents.begin(), testStudents.end(),
                      [](const Student &s) { return s.getLastName() == "Vazquez"; });
    cout << "First ID: " << it->getId() << endl;

    // Find second Student with last name "Vazquez"
    auto it2 = find_if(it+1, testStudents.end(),
                      [](const Student &s) { return s.getLastName() == "Vazquez"; });
    cout <<  "Second ID: " << it2->getId() << endl;

    // Find third Student with last name "Vazquez"
    auto it3 = find_if(it2+1, testStudents.end(),
                      [](const Student &s) { return s.getLastName() == "Vazquez"; });
    cout <<  "Third ID: " << it3->getId() << endl;
    cout << boolalpha << (it3 == testStudents.end()) << endl;

    // Remove all Student's with less than 3.5  GPA


    cout << "The End" << endl;
}
