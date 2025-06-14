//
// Created by liang on 2025/6/14.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <tuple>
using namespace std;

string getTopCar(vector<string> cars, int mon) {
    map<string, tuple<string, int, int>> carMap;
    for (int i = 0; i < cars.size(); i++) {
        stringstream ss(cars[i]);
        string name;
        string day;
        string time;
        ss >> name >> day >> time;
        if (stoi(day.substr(5,2)) == mon) {
            if (carMap.count(name)) {
                get<1>(carMap[name]) += stoi(time);
                get<2>(carMap[name])++;
            } else {
                carMap[name] = make_tuple(name, stoi(time), 1);
            }
        }
    }
    vector<tuple<string, int, int>> carList;
    for (auto car : carMap) {
        carList.push_back(car.second);
    }
    sort(carList.begin(), carList.end(), [](tuple<string, int, int> a, tuple<string, int, int> b) {
        if (get<1>(a) == get<1>(b)) {
            if (get<2>(a) == get<2>(b)) {
                return get<0>(a) > get<0>(b);
            }
            return get<2>(a) > get<2>(b);
        } else {
            return get<1>(a) > get<1>(b);
        }
    });

    return get<0>(carList[0]);
}

int main() {
    vector<string> cars = {"YB0001 2019-01-03 100", "YB0002 2019-01-05 250",
    "YB0001 2019-01-04 100","YB0003 2019-01-03 250","YB0004 2019-01-05 100", "YB0004 2019-01-05 150"};
    int month = 1;
    string car = getTopCar(cars, month);
    cout << car << endl;
    return 0;
}
