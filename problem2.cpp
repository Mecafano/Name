#include <iostream>

class Timer {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Timer(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalizeTime();
    }

    void normalizeTime() {
        minutes += seconds / 60;
        seconds %= 60;

        hours += minutes / 60;
        minutes %= 60;

        hours %= 24;
    }

    void printTime() {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }
};

int main() {
    int hours, minutes, seconds;
    std::cout << "Input hours, minutes, seconds: ";
    std::cin >> hours >> minutes >> seconds;

    Timer timer(hours, minutes, seconds);
    std::cout << "Output: ";
    timer.printTime();

    return 0;
}
