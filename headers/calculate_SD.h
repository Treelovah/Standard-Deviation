#pragma GCC diagnostic ignored "-Wnarrowing"
#ifndef CALCULATE_SD_H
#define CALCULATE_SD_H
#include <vector>

using namespace std;

class calculate_SD
{
private:
    float median(vector<float> &data, int m, int n); // internal version of get_median(), will rewrite this later.

protected:
    float list_sum, // sum of all data 
        list_mean, // average of all data divided by size of list
        list_median, // the middle of the list
        list_standard_deviation, // math..
        q1, q2, q3, // quartiles
        iqr; // Interguartile Range

    vector<float> data; // array to hold user's list of data.
public:
    calculate_SD(vector<float> list_of_data); // default constructor;
    void quartiles(); // split up the list of data into 4 quarters.
    float sum(); // get the sum from the list of data
    float mean(); // get the mean from the list of data
    float median(); // get the median from the list of data
    float SD(); // calculate the standard deviation from the data
    float IQR(); // calculate the Interquartile Range
    float range(); // calculate the range from the list of data
};
#endif