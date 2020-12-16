#include <iostream>
#include "../headers/calculate_SD.h"
#include <cmath>
#include <algorithm>
#include <list>
calculate_SD::calculate_SD(std::vector<float> arr)
{
    
    this->list_sum = 0.0;
    this->list_standard_deviation = 0.0;
    this->list_mean = 0.0;
    this->data = arr;
    this->list_median = 0.0;
}


float calculate_SD::sum()
{
    /*
    * add up items is data
    */
    for (auto num : data)
        list_sum += num;
    return list_sum;
}

float calculate_SD::mean()
{
    /*
    * 1. add up items in list.
    * 2. divide sum by number of items in list
    * 3. result is mean
    */
    list_mean = (list_sum / data.size());
    return list_mean;
}

float calculate_SD::median(vector<float> &v, int m, int n)
{
    /*
    * 1. Sort vector
    * 2. get mid
    * 3. if no mid is found, average the 2 middle numbers in vector
    * 4. set median
    */
    
    vector<float> tmp(v.begin() + m, v.begin() + n+1);
    sort(tmp.begin() + m, tmp.begin() + n+1);

    if (tmp.size() < 1) return 0.0;
    else if (tmp.size() == 1) return tmp.at(0);
    else if (tmp.size() == 2) return (tmp.at(0) + tmp.at(1)) / 2;
    else if ((tmp.size() - 1) % 2 == 0)
    {
        list_mean = tmp.at((tmp.size() -1) / 2);
        return list_mean;
    } else
    {
        int upper, lower;
        upper = (int)((tmp.size() - 1) / 2) + 1; // narrowing intended
        lower = (int)((tmp.size() - 1) / 2); // narrowing intended
        list_mean = (tmp.at(lower) + tmp.at(upper)) / 2;
        return list_mean;
    }
}

float calculate_SD::median()
{
    list_median = median(data, 0, data.size() -1);
    return list_median;
}

float calculate_SD::SD()
{
    for (auto num : data)
        list_standard_deviation += pow(num - list_mean, 2); // get standard deviation

    return sqrt(list_standard_deviation / data.size());
}

float calculate_SD::IQR()
{
    iqr = q3 - q1;
    return iqr;
}

float calculate_SD::range()
{
    return *max_element(data.begin(), data.end()) - *min_element(data.begin(), data.end());
}

void calculate_SD::quartiles()
{
    vector<float> tmp_l; // lower half
    vector<float> tmp_u; // upper half
    sort(data.begin(), data.end());
    q2 = list_mean;
    for (auto element : data)
    {
        if (element < list_mean)
            tmp_l.push_back(element);
        else if (element > list_mean)
            tmp_u.push_back(element);
    }
    q1 = median(tmp_l, 0, tmp_l.size() - 1);
    q3 = median(tmp_u, 0, tmp_u.size() - 1);

    cout << "lower quartile (Q1): " << q1 << '\n';
    cout << "second quartile (Q2): " << q2 << '\n';
    cout << "upper quartile (Q3): " << q3 << '\n';
}