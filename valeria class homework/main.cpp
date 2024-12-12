//
//  main.cpp
//  valeria class homework
//
//  Created by Valeria  Bukova on 12.12.2024.
//

#include <iostream>
using namespace std;


void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sumOfDigits(const int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int temp = arr[i] > 0 ? arr[i] : -arr[i];
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
    }
    return sum;
}


double averageOfPositive(const int* arr, int size) {
    int sum = 0, count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
            count++;
        }
    }
    return count > 0 ? static_cast<double>(sum) / count : 0.0;
}


void maxNegative(const int* arr, int size, int& maxNeg, int& pos) {
    maxNeg = -1000000;
    pos = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0 && arr[i] > maxNeg) {
            maxNeg = arr[i];
            pos = i;
        }
    }
}


int mostFrequent(const int* arr, int size) {
    int maxCount = 0, mostFreqNum = arr[0];
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mostFreqNum = arr[i];
        }
    }
    return mostFreqNum;
}


int maxDivisibleBy3OddIndex(const int* arr, int size) {
    int maxVal = -1000000;
    for (int i = 1; i < size; i += 2) {
        if (arr[i] % 3 == 0 && arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


void swapMaxEvenMinOdd(int* arr, int size) {
    int maxEven = -1000000, minOdd = 1000000;
    int maxEvenIdx = -1, minOddIdx = -1;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && arr[i] > maxEven) {
            maxEven = arr[i];
            maxEvenIdx = i;
        }
        if (arr[i] % 2 != 0 && arr[i] < minOdd) {
            minOdd = arr[i];
            minOddIdx = i;
        }
    }

    if (maxEvenIdx != -1 && minOddIdx != -1) {
        int temp = arr[maxEvenIdx];
        arr[maxEvenIdx] = arr[minOddIdx];
        arr[minOddIdx] = temp;
    } else {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
}


void createThirdArray(const int* arr1, int size1, const int* arr2, int size2, int* both, int& bothSize, int* onlyOne, int& onlyOneSize) {
    bothSize = 0;
    onlyOneSize = 0;
    for (int i = 0; i < size1; i++) {
        bool inArr2 = false;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                inArr2 = true;
                break;
            }
        }
        if (inArr2) {
            both[bothSize++] = arr1[i];
        } else {
            onlyOne[onlyOneSize++] = arr1[i];
        }
    }

    for (int j = 0; j < size2; j++) {
        bool inArr1 = false;
        for (int i = 0; i < size1; i++) {
            if (arr2[j] == arr1[i]) {
                inArr1 = true;
                break;
            }
        }
        if (!inArr1) {
            onlyOne[onlyOneSize++] = arr2[j];
        }
    }
}

int main() {
    int arr[] = {12, 104, 81};
    int arrSize = 3;

    
    cout << "1. Сумма цифр массива: " << sumOfDigits(arr, arrSize) << endl;

    
    cout << "2. Среднее арифметическое положительных элементов массива: " << averageOfPositive(arr, arrSize) << endl;

   
    int maxNeg, pos;
    maxNegative(arr, arrSize, maxNeg, pos);
    if (pos != -1) {
        cout << "3. Максимальный отрицательный элемент: " << maxNeg << ", на позиции " << pos << endl;
    } else {
        cout << "3. В массиве нет отрицательных элементов" << endl;
    }

   
    cout << "4. Число, чаще всего встречающееся в массиве: " << mostFrequent(arr, arrSize) << endl;

    
    cout << "5. Наибольший элемент с нечётными индексами, делящийся на 3: " << maxDivisibleBy3OddIndex(arr, arrSize) << endl;

   
    int arr6[] = {1, 2, 3, 4, 5};
    int arr6Size = 5;
    swapMaxEvenMinOdd(arr6, arr6Size);
    cout << "6. Массив после преобразования: ";
    printArray(arr6, arr6Size);

    // 7
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    int both[10], onlyOne[10], bothSize, onlyOneSize;
    createThirdArray(arr1, 5, arr2, 5, both, bothSize, onlyOne, onlyOneSize);
    cout << "7а. Элементы, присутствующие в обоих массивах: ";
    printArray(both, bothSize);
    cout << "7б. Элементы, присутствующие только в одном из массивов: ";
    printArray(onlyOne, onlyOneSize);

    return 0;
}
#include <iostream>
using namespace std;


void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int sumOfDigits(const int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int temp = arr[i] > 0 ? arr[i] : -arr[i];
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
    }
    return sum;
}


double averageOfPositive(const int* arr, int size) {
    int sum = 0, count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
            count++;
        }
    }
    return count > 0 ? static_cast<double>(sum) / count : 0.0;
}


void maxNegative(const
    pos = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0 && arr[i] > maxNeg) {
            maxNeg = arr[i];
            pos = i;
        }
    }
}

int mostFrequent(const int* arr, int size) {
    int maxCount = 0, mostFreqNum = arr[0];
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mostFreqNum = arr[i];
        }
    }
    return mostFreqNum;
}


int maxDivisibleBy3OddIndex(const int* arr, int size) {
    int maxVal = -1000000;
    for (int i = 1; i < size; i += 2) {
        if (arr[i] % 3 == 0 && arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


void swapMaxEvenMinOdd(int* arr, int size) {
    int maxEven = -1000000, minOdd = 1000000;
    int maxEvenIdx = -1, minOddIdx = -1;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && arr[i] > maxEven) {
            maxEven = arr[i];
            maxEvenIdx = i;
        }
        if (arr[i] % 2 != 0 && arr[i] < minOdd) {
            minOdd = arr[i];
            minOddIdx = i;
        }
    }

    if (maxEvenIdx != -1 && minOddIdx != -1) {
        int temp = arr[maxEvenIdx];
        arr[maxEvenIdx] = arr[minOddIdx];
        arr[minOddIdx] = temp;
    } else {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
}


void createThirdArray(const int* arr1, int size1, const int* arr2, int size2, int* both, int& bothSize, int* onlyOne, int& onlyOneSize) {
    bothSize = 0;
    onlyOneSize = 0;
    for (int i = 0; i < size1; i++) {
        bool inArr2 = false;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                inArr2 = true;
                break;
            }
        }
        if (inArr2) {
            both[bothSize++] = arr1[i];
        } else {
            onlyOne[onlyOneSize++] = arr1[i];
        }
    }

    for (int j = 0; j < size2; j++) {
        bool inArr1 = false;
        for (int i = 0; i < size1; i++) {
            if (arr2[j] == arr1[i]) {
                inArr1 = true;
                break;
            }
        }
        if (!inArr1) {
            onlyOne[onlyOneSize++] = arr2[j];
        }
    }
}

int main() {
    int arr[] = {12, 104, 81};
    int arrSize = 3;

    
    cout << "1. Сумма цифр массива: " << sumOfDigits(arr, arrSize) << endl;

   
    cout << "2. Среднее арифметическое положительных элементов массива: " << averageOfPositive(arr, arrSize) << endl;
 
    int maxNeg, pos;
    maxNegative(arr, arrSize, maxNeg, pos);
    if (pos != -1) {
        cout << "3. Максимальный отрицательный элемент: " << maxNeg << ", на позиции " << pos << endl;
    } else {
        cout << "3. В массиве нет отрицательных элементов" << endl;
    }

  
    cout << "4. Число, чаще всего встречающееся в массиве: " << mostFrequent(arr, arrSize) << endl;

  
    cout << "5. Наибольший элемент с нечётными индексами, делящийся на 3: " << maxDivisibleBy3OddIndex(arr, arrSize) << endl;

   
    int arr6[] = {1, 2, 3, 4, 5};
    int arr6Size = 5;
    swapMaxEvenMinOdd(arr6, arr6Size);
    cout << "6. Массив после преобразования: ";
    printArray(arr6, arr6Size);

  
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    int both[10], onlyOne[10], bothSize, onlyOneSize;
    createThirdArray(arr1, 5, arr2, 5, both, bothSize, onlyOne, onlyOneSize);
    cout << "7а. Элементы, присутствующие в обоих массивах: ";
    printArray(both, bothSize);
    cout << "7б. Элементы, присутствующие только в одном из массивов: ";
    printArray(onlyOne, onlyOneSize);

    return 0;
}
