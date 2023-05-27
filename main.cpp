#include <iostream>
#include "Ball.h"
#include <cmath>

int main() {
    Ball ball;

    int n{};
    std::cin >> n;
    if(n < 1 || n > pow(10,5)) {
        return 0;
    }

    int arr[n];
    /*
     * In the question, i must be between 1 and 10^5
     * To make it, we have to use i-1 for array
     */
    for (int i {1}; i <= n; i++) {
        std::cin >> arr[i-1];
        if(arr[i-1] < 1 || arr[i-1] > pow(10,5)) {
            return 0;
        }
    }

    /*
     * Calculates the minimum energy
     * Check Ball.cpp for the algorithm explanation
     */
    ball.calcMinEnergy(arr, n);

    std::cout << ball.getMinEnergy();
    return 0;
}
