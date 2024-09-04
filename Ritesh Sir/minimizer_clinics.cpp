#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct City {
    int index;        // City index
    int population;
    int clinics;
    
    // Comparator to prioritize cities with the highest load
    bool operator<(const City &other) const {
        return (double)population / clinics < (double)other.population / other.clinics;
    }
};

vector<int> minimizeMaxLoad(int n, vector<int>& population, int m) {
    priority_queue<City> pq;
    vector<int> clinicDistribution(n, 1); // Start with 1 clinic in each city
    
    // Initialize each city with 1 clinic
    for (int i = 0; i < n; ++i) {
        pq.push({i, population[i], 1});
    }
    
    // Distribute the remaining m - n clinics
    for (int i = 0; i < m - n; ++i) {
        City topCity = pq.top();
        pq.pop();
        
        // Assign an additional clinic to the city with the highest load
        topCity.clinics++;
        clinicDistribution[topCity.index] = topCity.clinics;
        
        pq.push(topCity);
    }
    
    return clinicDistribution; // Return the sequence of clinic distribution
}

int main() {
    int n = 3;
    vector<int> population = {100, 50, 200};
    int m = 4;
    
    vector<int> result = minimizeMaxLoad(n, population, m);
    
    cout << "Clinic distribution: ";
    for (int clinics : result) {
        cout << clinics << " ";
    }
    cout << endl;
    
    return 0;
}
