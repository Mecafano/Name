#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int id;
    int totalGrade;
};

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


    int id2TotalGrade = 0;
    for (int i = 0; i < N; ++i) {
        if (students[i].id == 2) {
            id2TotalGrade = students[i].totalGrade;
            break;
        }
    }


    int rank = 1;
    for (int i = 0; i < N; ++i) {
        if (students[i].totalGrade > id2TotalGrade) {
            rank++;
        }
    }

    cout << "Output: " << rank << endl;

    return 0;
}
