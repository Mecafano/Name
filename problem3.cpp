#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Student {
public:
    std::string name;
    long int id;
    std::string groupName;

    Student(const std::string& n, long int i, const std::string& g) : name(n), id(i), groupName(g) {}
};

std::vector<Student> inputStudents(int n) {
    std::vector<Student> students;
    students.reserve(n);

    for (int i = 0; i < n; ++i) {
        std::string name, group;
        long int id;

        std::cout << "Input student details (name, id, group): ";
        std::cin >> name >> id >> group;

        students.emplace_back(name, id, group);
    }

    return students;
}

std::map<std::string, int> countGroups(const std::vector<Student>& students) {
    std::map<std::string, int> groupCounts;

    for (const auto& student : students) {
        groupCounts[student.groupName]++;
    }

    return groupCounts;
}

void printGroupCounts(const std::map<std::string, int>& groupCounts) {
    std::cout << "Output:" << std::endl;
    for (const auto& pair : groupCounts) {
        std::cout << pair.first << ":" << pair.second << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Input number of students: ";
    std::cin >> n;

    std::vector<Student> students = inputStudents(n);
    std::map<std::string, int> groupCounts = countGroups(students);
    printGroupCounts(groupCounts);

    return 0;
}
