#include <iostream>
#include <string>
#include <ctype.h>

int main()
{
    std::string arithmetic;
    std::cout << "Arithmetic to calculate: ";
    std::cin >> arithmetic;

    double result = 0;
    while (std::size_t found = arithmetic.find_first_of('*'))
    {
        if (found == std::string::npos)
            break;

        if (arithmetic.length() > 1)
        {
            if (!isdigit(arithmetic.at(0)))
                return 1;

            int pos = arithmetic.find_first_of('*');
            std::size_t closest_left;
            std::size_t found_add_left = arithmetic.rfind('+', pos) == std::string::npos ? 0 : arithmetic.rfind('+', pos);
            std::size_t found_sub_left = arithmetic.rfind('-', pos) == std::string::npos ? 0 : arithmetic.rfind('-', pos);
            std::size_t found_div_left = arithmetic.rfind('/', pos) == std::string::npos ? 0 : arithmetic.rfind('/', pos);
            closest_left = found_add_left;
            if (found_sub_left > closest_left)
                closest_left = found_sub_left;
            if (found_div_left > closest_left)
                closest_left = found_div_left;
            double num = double(std::stoi(arithmetic.substr(closest_left, pos)));

            std::size_t closest_right;
            std::size_t found_add_right = arithmetic.find_first_of('+', pos) == std::string::npos ? arithmetic.length()-1 : arithmetic.find_first_of('+', pos);
            std::size_t found_sub_right = arithmetic.find_first_of('-', pos) == std::string::npos ? arithmetic.length()-1 : arithmetic.find_first_of('-', pos);
            std::size_t found_div_right = arithmetic.find_first_of('/', pos) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('/', pos);
            std::size_t found_mul_right = arithmetic.find_first_of('*', pos+1) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('*', pos+1);
            closest_right = found_add_right;
            if (found_sub_right < closest_right)
                closest_right = found_sub_right;
            if (found_div_right < closest_right)
                closest_right = found_div_right;
            if (found_mul_right < closest_right)
                closest_right = found_mul_right;
            double num2 = double(std::stoi(arithmetic.substr(pos+1, closest_right)));

            arithmetic.replace(closest_left, closest_right-1, std::to_string(num * num2));
        }
    }

    //Division
    while (std::size_t found = arithmetic.find_first_of('/'))
    {
        if (found == std::string::npos)
            break;

        if (arithmetic.length() > 1)
        {
            if (!isdigit(arithmetic.at(0)))
                return 1;

            int pos = arithmetic.find_first_of('/');
            std::size_t closest_left;
            std::size_t found_add_left = arithmetic.rfind('+', pos) == std::string::npos ? 0 : arithmetic.rfind('+', pos);
            std::size_t found_sub_left = arithmetic.rfind('-', pos) == std::string::npos ? 0 : arithmetic.rfind('-', pos);
            std::size_t found_mul_left = arithmetic.rfind('*', pos) == std::string::npos ? 0 : arithmetic.rfind('*', pos);
            closest_left = found_add_left;
            if (found_sub_left > closest_left)
                closest_left = found_sub_left;
            if (found_mul_left > closest_left)
                closest_left = found_mul_left;
            double num = double(std::stoi(arithmetic.substr(closest_left, pos)));

            std::size_t closest_right;
            std::size_t found_add_right = arithmetic.find_first_of('+', pos) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('+', pos);
            std::size_t found_sub_right = arithmetic.find_first_of('-', pos) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('-', pos);
            std::size_t found_div_right = arithmetic.find_first_of('/', pos+1) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('/', pos+1);
            std::size_t found_mul_right = arithmetic.find_first_of('*', pos) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('*', pos);
            closest_right = found_add_right;
            if (found_sub_right < closest_right)
                closest_right = found_sub_right;
            if (found_div_right < closest_right)
                closest_right = found_div_right;
            if (found_mul_right < closest_right)
                closest_right = found_mul_right;
            double num2 = double(std::stoi(arithmetic.substr(pos + 1, closest_right)));

            arithmetic.replace(closest_left, closest_right - 1, std::to_string(num / num2));
        }
    }

    //Add
    while (std::size_t found = arithmetic.find_first_of('+'))
    {
        if (found == std::string::npos)
            break;

        if (arithmetic.length() > 1)
        {
            if (!isdigit(arithmetic.at(0)))
                return 1;

            int pos = arithmetic.find_first_of('+');
            std::size_t closest_left;
            std::size_t found_div_left = arithmetic.rfind('/', pos) == std::string::npos ? 0 : arithmetic.rfind('/', pos);
            std::size_t found_sub_left = arithmetic.rfind('-', pos) == std::string::npos ? 0 : arithmetic.rfind('-', pos);
            std::size_t found_mul_left = arithmetic.rfind('*', pos) == std::string::npos ? 0 : arithmetic.rfind('*', pos);
            closest_left = found_div_left;
            if (found_sub_left > closest_left)
                closest_left = found_sub_left;
            if (found_mul_left > closest_left)
                closest_left = found_mul_left;
            double num = double(std::stoi(arithmetic.substr(closest_left, pos)));

            std::size_t closest_right;
            std::size_t found_add_right = arithmetic.find_first_of('+', pos + 1) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('+', pos + 1);
            std::size_t found_sub_right = arithmetic.find_first_of('-', pos) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('-', pos);
            std::size_t found_div_right = arithmetic.find_first_of('/', pos) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('/', pos);
            std::size_t found_mul_right = arithmetic.find_first_of('*', pos) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('*', pos);
            closest_right = found_add_right;
            if (found_sub_right < closest_right)
                closest_right = found_sub_right;
            if (found_div_right < closest_right)
                closest_right = found_div_right;
            if (found_mul_right < closest_right)
                closest_right = found_mul_right;
            double num2 = double(std::stoi(arithmetic.substr(pos + 1, closest_right)));

            arithmetic.replace(closest_left, closest_right, std::to_string(num + num2));
        }
    }

    //Sub
    while (std::size_t found = arithmetic.find_first_of('-'))
    {
        if (found == std::string::npos)
            break;

        if (arithmetic.length() > 1)
        {
            if (!isdigit(arithmetic.at(0)))
                return 1;

            int pos = arithmetic.find_first_of('-');
            std::size_t closest_left;
            std::size_t found_div_left = arithmetic.rfind('/', pos) == std::string::npos ? 0 : arithmetic.rfind('/', pos);
            std::size_t found_add_left = arithmetic.rfind('+', pos) == std::string::npos ? 0 : arithmetic.rfind('+', pos);
            std::size_t found_mul_left = arithmetic.rfind('*', pos) == std::string::npos ? 0 : arithmetic.rfind('*', pos);
            closest_left = found_div_left;
            if (found_add_left > closest_left)
                closest_left = found_add_left;
            if (found_mul_left > closest_left)
                closest_left = found_mul_left;
            double num = double(std::stoi(arithmetic.substr(closest_left, pos)));

            std::size_t closest_right;
            std::size_t found_add_right = arithmetic.find_first_of('+', pos) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('+', pos );
            std::size_t found_sub_right = arithmetic.find_first_of('-', pos + 1) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('-', pos + 1);
            std::size_t found_div_right = arithmetic.find_first_of('/', pos) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('/', pos);
            std::size_t found_mul_right = arithmetic.find_first_of('*', pos) == std::string::npos ? arithmetic.length() - 1 : arithmetic.find_first_of('*', pos);
            closest_right = found_add_right;
            if (found_sub_right < closest_right)
                closest_right = found_sub_right;
            if (found_div_right < closest_right)
                closest_right = found_div_right;
            if (found_mul_right < closest_right)
                closest_right = found_mul_right;
            double num2 = double(std::stoi(arithmetic.substr(pos + 1, closest_right)));

            arithmetic.replace(closest_left, closest_right, std::to_string(num - num2));
        }
    }


    std::cout << arithmetic << std::endl;

    return 0;
}