#include <iostream>
#include <numeric>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using std::vector;

double calculateStd(vector<vector<double>>& data) {
    if (data.size() < 1) {
        std::cout << "No data avaiable!" << std::endl;
        return 0;
    }
    double dMean = 0;
    double dVariance = 0;
    dMean = std::accumulate(data.begin(), data.end(), 0, [](double sum, vector<double>& rec) {return sum + rec[0]; }) / data.size();
    // take each number, subtract the mean and square the result
    dVariance = std::accumulate(data.begin(), data.end(), 0, [dMean](double sum, vector<double>& rec) { return sum + pow(rec[0] - dMean, 2); }) / data.size();
    return sqrt(dVariance);
}

int main()
{
    // random range [m, m+n[ is set here
    int n = 40, m = 1;
    // The length of dataset
    int times = 50;
    // Dataset
    vector<vector<double>> data;

    // Random seed
    srand(time(nullptr));

    for (size_t i = 0; i < times; ++i) {
        // Random floating number between [m, m+n[
        vector<double> temp = { (double)(rand() % n + m + rand() / (RAND_MAX + 1.) - 0.5), (double)i};
        data.push_back(temp);
    }

    double dStd = calculateStd(data);

    // Set output decimal place
    std::cout << std::fixed; 
    std::cout << std::setprecision(2);

    for (const auto& rec : data) {
        std::cout << "Time: " << rec[1] + 1 << "  Temperature: " << rec[0] << std::endl;
    }

    std::cout << "The Standard Deviation: " << dStd << std::endl;
}

