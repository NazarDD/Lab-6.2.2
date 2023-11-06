#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

void generateArray(int a[], int size, int index = 0) {
    if (index < size) {
        a[index] = rand() % 101;
        generateArray(a, size, index + 1);
    }
}

int findMaxRecursive(const std::vector<int>& a, int index, int max) {
    if (index < a.size()) {
        if (a[index] > max) {
            max = a[index];
        }
        return findMaxRecursive(a, index + 1, max);
    }
    return max;
}

int findMinRecursive(const std::vector<int>& a, int index, int min) {
    if (index < a.size()) {
        if (a[index] < min) {
            min = a[index];
        }
        return findMinRecursive(a, index + 1, min);
    }
    return min;
}

int main() {
    std::srand(std::time(0));

    const int size = 15;
    int a[size];
    generateArray(a, size);

    std::cout << "Generated array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    if (a[0] == -1) {
        std::cerr << "The array is empty." << std::endl;
    }
    else {
        std::vector<int> aVector(a, a + size);
        int max = findMaxRecursive(aVector, 0, aVector[0]);
        int min = findMinRecursive(aVector, 0, aVector[0]);

        std::cout << "Maximum element: " << max << std::endl;
        std::cout << "Minimum element: " << min << std::endl;
    }
    return 0;
}
