#include <iostream>

unsigned int len(const char* num)
{
    unsigned int index = 0;
    unsigned int len = 0;
    if (num[index] == '-' || num[index] == '+')
    {
        index++;
    }
    while (num[index] != '.' && num[index] != '\0')
    {
        len++;
        index++;
    }
    return len;
}


bool is_abs_greater(const char* num1, const char* num2)
{
    unsigned int i = 0;
    unsigned int j = 0;

    while (num1[i] != '.' && num1[i] != '\0' && num2[j] != '.' && num2[j] != '\0')
    {
        if (num1[i] > num2[j])
        {
            return true;
        }
        else if (num1[i] < num2[j])
        {
            return false;
        }
        else
        {
            ++i;
            ++j;
        }
    }

    if (num1[i] == '.') 
    {
        ++i;
    }
    if (num2[j] == '.')
    { 
        ++j;
    }

    while (num1[i] != '\0' || num2[j] != '\0')
    {
        char c1 = (num1[i] != '\0') ? num1[i] : '0';
        char c2 = (num2[j] != '\0') ? num2[j] : '0';
        if (c1 > c2)
        {
            return true;
        }
        else if (c1 < c2)
        {
            return false;
        }
        if (num1[i] != '\0') ++i;
        if (num2[j] != '\0') ++j;
    }
    return false;
}



int main(int argc, char*argv[])
{
    const char* num1 = argv[1];
    const char* num2 = argv[2];

    unsigned int len1 = len(num1);
    unsigned int len2 = len(num2);

    bool is_neg1 = (num1[0] == '-') ? true : false;
    bool is_neg2 = (num2[0] == '-') ? true : false;

    const char* d1 = (num1[0] == '-' || num1[0] == '+') ? num1 + 1 : num1;
    const char* d2 = (num2[0] == '-' || num2[0] == '+') ? num2 + 1 : num2;

    if (is_neg1 && !is_neg2)
    {
        std::cout << "less"<< '\n';
    }
    else if (!is_neg1 && is_neg2)
    {
        std::cout << "greater" << '\n';
    }
    else if (is_neg1 && is_neg2)
    {
        if (len1 > len2)
        {
            std::cout << "less" << '\n';
        }
        else if (len1 < len2)
        {
           std::cout << "greater" << '\n'; 
        }
        else
        {
            if(is_abs_greater(d1, d2))
            {
                std::cout << "less" << '\n'; 
            }
            else if(is_abs_greater(d2, d1))
            {
                std::cout << "greater" << '\n';
            }
            else
            {
                std::cout << "equal" << '\n';
            }
        }
    }
    else if (!is_neg1 && !is_neg2)
    {
        if (len1 > len2)
        {
            std::cout << "greater" << '\n';
        }
        else if (len1 < len2)
        {
           std::cout << "less" << '\n'; 
        }
        else
        {
            if(is_abs_greater(d1, d2))
            {
                std::cout << "greater" << '\n'; 
            }
            else if(is_abs_greater(d2, d1))
            {
                std::cout << "less" << '\n';
            }
            else
            {
                std::cout << "equal" << '\n';
            }
        }
    }
    return 0;
}
