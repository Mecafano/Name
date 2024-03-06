#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Student {
private:
    std::string name;
    long int id;
    std::string groupName;

public:
    Student(std::string n, long int i, std::string g) : name(n), id(i), groupName(g) {}

    std::string getGroupName() const {
        return groupName;
    }
};

void printGroupCounts(const std::vector<Student>& students) {
    std::map<std::string, int> groupCounts;

    for (const auto& student : students) {
        groupCounts[student.getGroupName()]++;
    }

    for (const auto& pair : groupCounts) {
        std::cout << pair.first << ":" << pair.second << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Input number of students: ";
    std::cin >> n;

    std::vector<Student> students;
    for (int i = 0; i < n; ++i) {
        std::string name, group;
        long int id;
        std::cout << "Input student details (name, id, group): ";
        std::cin >> name >> id >> group;
        students.emplace_back(name, id, group);
    }

    std::cout << "Output:" << std::endl;
    printGroupCounts(students);

    return 0;
}
