#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    int totalGrade;
};

bool compareStudents(const Student &a, const Student &b) {
    if (a.totalGrade != b.totalGrade)
        return a.totalGrade > b.totalGrade;
}

int main() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    vector<Student> students(N);


    for (int i = 0; i < N; ++i) {
        students[i].id = i + 1;
        int grade1, grade2, grade3;
        cin >> grade1 >> grade2 >> grade3;
        students[i].totalGrade = grade1 + grade2 + grade3;
    }


    sort(students.begin(), students.end(), compareStudents);


    int rank = 0;
    for (int i = 0; i < N; ++i) {
        if (students[i].id == 2) {
            rank = i + 1;
            break;
        }
    }

    cout << "Output: " << rank << endl;

    return 0;
}
