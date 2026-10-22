#include <iostream>

int main(int argc, char* argv[]) 
{
    if (argc < 2) {
        return 1;
    }

    int n = 0;
    for (int i = 0; argv[1][i] != '\0'; ++i) 
    {
        n = n * 10 + (argv[1][i] - '0');
    } 

    double* a = new double[n];
    double* b = new double[n];

    for (int i = 0; i < n; i++) 
    {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) 
    {
        std::cin >> b[i];
    }

    double dot_product = 0.0;
    for (int i = 0; i < n; i++) 
    {
        dot_product += a[i] * b[i];
    }

    std::cout << dot_product << std::endl;

    delete[] a;
    delete[] b;

    return 0;
}
