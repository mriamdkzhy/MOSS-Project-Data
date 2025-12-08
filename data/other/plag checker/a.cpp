#include <iostream>
#include <vector>

std::vector<int> findEvenNumbers(const std::vector<int>& arr) {
    std::vector<int> evenNumbers;
    for (int num : arr) {
        if (num % 2 == 0) {
            evenNumbers.push_back(num);
        }
    }
    return evenNumbers;
}

int main() {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> evenNumbers = findEvenNumbers(array);

    std::cout << "Even numbers: ";
    for (int num : evenNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
