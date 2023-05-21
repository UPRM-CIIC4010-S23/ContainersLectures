#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Student {

    private:
    int id;
    string firstName;
    string lastName;

    public:
    int getId() const { return id; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    Student(int id, string fn, string ln): id(id), firstName(fn), lastName(ln) {}

    bool operator< (const Student &s) const { return this->getId() < s.getId(); }

};

int countUnique(const vector<Student> &students)
{

    set<Student> studentSet;

    for (Student s : students) {
        studentSet.insert(s);
    }

    return studentSet.size();
    
}

int main() {

    vector<Student> testStudents;
    testStudents.push_back( Student(10, "Bienve", "Velez"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(32, "Amanda", "Vazquez"));
    testStudents.push_back( Student(32, "Amanda", "Davis"));
    testStudents.push_back( Student(65, "Joshua", "Vazquez"));
    testStudents.push_back( Student(43, "Alejandra", "Munoz"));
    testStudents.push_back( Student(54, "Fatima", "Puig"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(76, "Rey", "Cotto"));

    cout << "Count of Vector Students: " << testStudents.size() << endl;
    cout << "Count of Unique Students: " << countUnique(testStudents) << endl;

    set<Student> s2(testStudents.begin(), testStudents.end());
    cout << "2nd Count of Unique Students: " << s2.size() << endl;

    set<string> pueblosDePR;
    pueblosDePR.insert("Aibonito");

}