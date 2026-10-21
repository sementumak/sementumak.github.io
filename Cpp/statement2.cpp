#include <iostream>

void reverse(int* start, int* end) {
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }

    int n = 0;
    for (int i = 0; argv[1][i] != '\0'; ++i) {
        n = n * 10 + (argv[1][i] - '0');
    }

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    long long k_input;
    std::cin >> k_input;

    int k = static_cast<int>(k_input % n);

    if (k < 0) {
        k = k + n;
    }

    if (k > 0) {
        reverse(arr, arr + n - 1);
        reverse(arr, arr + k - 1);
        reverse(arr + k, arr + n - 1);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << "\n";
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    delete[] arr;

    return 0;
}
