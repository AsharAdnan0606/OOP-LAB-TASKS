#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int size = 5;
    int* arr = new int[size];
    int count = 0;

    for (int i = 1; i < argc; i++) {
        if (count == size) {
            size *= 2;
            int* newarr = new int[size];
            for (int j = 0; j < count; j++) {
                newarr[j] = arr[j];
            }
            delete[] arr;
            arr = newarr;
        }
        arr[count] = atoi(argv[i]);
        count++;
    }

    int* result = new int[count];
    for (int i = 0; i < count; i++) {
        result[i] = arr[i];
    }

    delete[] arr;
    arr = result;

    delete[] arr;

    return 0;
}
