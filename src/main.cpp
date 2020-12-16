#include <iostream>
#include "../headers/calculate_SD.h"
#include <algorithm>

using namespace std;


int main()
{
    vector<float> data;
    int i = 0;
    float input;

    while (input || data.size() < 100)
    {
        cin >> input;
        if (input == -1)
            break;
        else
        {
            try
            {
                data.push_back(input);
            }
            catch (const exception &e)
            {
                cerr << e.what() << '\n';
            }
        }
    }
    calculate_SD list_of_data(data);
    cout << "\nThe Sum of your input list is: " << list_of_data.sum() << '\n';
    cout << "The Mean of your input list is: " << list_of_data.mean() << '\n';
    cout << "The Median of your input list is: " << list_of_data.median() << '\n';
    list_of_data.quartiles();
    cout << "The Standard Deviation of your input list is: " << list_of_data.SD() << '\n';
    cout << "The IQR is: " << list_of_data.IQR() << '\n';
    cout << "The Minimum is: " << *min_element(data.begin(), data.end()) << '\n';
    cout << "The Maximum is: " << *max_element(data.begin(), data.end()) << '\n';
    cout << "The Range is: " << list_of_data.range() << endl;
    return 0;
}