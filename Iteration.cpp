#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// تابع محاسبه تکرار ارقام
int calculateFitness(int number, int target) {
    int fitness = 0;
    for (int i = 0; i < 4; ++i) {
        if (number % 10 == target % 10)
            fitness++;
        number /= 10;
        target /= 10;
    }
    return fitness;
}

int main() {
    srand(time(0));

    int targetNumber; 
    cout << "Enter a 4-digit number for the algorithm to guess: ";
    cin >> targetNumber;

    int currentGuess = rand() % 10000; // حدس اولیه 
    int bestGuess = currentGuess;
    int bestFitness = calculateFitness(currentGuess, targetNumber);

    // ABC
    int maxIterations = 10000;
    for (int i = 0; i < maxIterations; ++i) {
        int newGuess = currentGuess + rand() % 21 - 10; // جابجایی تصادفی
        int newFitness = calculateFitness(newGuess, targetNumber);
        
        if (newFitness > bestFitness) {
            bestGuess = newGuess;
            bestFitness = newFitness;
        }

        currentGuess = newGuess;

        cout << "Iteration " << i+1 << ": Guess = " << currentGuess << ", Fitness = " << newFitness << endl;
    }

    cout << "The algorithm's best guess is: " << bestGuess << endl;
    cout << "With fitness: " << bestFitness << endl;

    return 0;
}
