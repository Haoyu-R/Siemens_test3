#include <iostream>
#include <numeric>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::vector;

double calculateStd(vector<vector<double>>& data) {
    if (data.size() < 1) {
        std::cout << "No data avaiable!" << std::endl;
        return 0;
    }
    double dAvg = 0;
    double dVariance = 0;
    dAvg = std::accumulate(data.begin(), data.end(), 0, [](double sum, vector<double>& rec) {return sum + rec[0]; }) / data.size();
    dVariance = std::accumulate(data.begin(), data.end(), 0, [dAvg](double sum, vector<double>& rec) { return sum + pow(rec[0] - dAvg, 2); }) / data.size();
    return sqrt(dVariance);
}

int main()
{
    // random range [m, m+n[ is set here
    int n = 40, m = 1;
    // The length of dataset
    int times = 10;
    // Dataset
    vector<vector<double>> data;

    // Random seed
    srand(time(nullptr));

    for (int i = 0; i < times; i++) {
        // Random number between [m, m+n[
        vector<double> temp = { (double)(rand() % n + m) , (double)i};
        data.push_back(temp);
    }

    double dStd = calculateStd(data);

    for (const auto& rec : data) {
        std::cout << "Time: " << rec[1] + 1 << "  Temperature: " << rec[0] << std::endl;
    }

    std::cout << "Std: " << dStd << std::endl;
}

