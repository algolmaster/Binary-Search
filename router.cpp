//
//  router.cpp
//  BinarySearch
//
//  Created by 신예지 on 24/04/2019.
//  Copyright © 2019 신예지. All rights reserved.
//
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c, install;

int binary(vector<int> house, int low, int high) {
    int mid = (low+high)/2; install++;
    return house[mid]-house[low]>house[high]-house[mid] ? house[high]-house[mid] : house[mid]-house[low];
}

int main() {
    int n;
    
    cin >> n >> c;
    vector<int> house;
    
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        house.push_back(temp);
    }
    sort(house.begin(), house.end());
    
    install = 2;
    int low=0, high=n-1, mid;
    
    int dist = binary(house, low, high);
    while(install<c) {
        mid = (low+high)/2;
        dist = binary(house, low, mid)>binary(house, mid, high) ? binary(house, mid, high) : binary(house, low, mid);
    }
    cout<<dist;
}
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int c, install;
vector<int> dist;

void binary(vector<int> house, int low, int high) {
    int mid = (low+high)/2; install++;
    
    dist.push_back(house[mid]-house[low]>house[high]-house[mid]? house[high]-house[mid]:house[mid]-house[low]);
    queue<pair<int, int>> q;
    q.push(pair<int, int>(low, mid));
    q.push(pair<int, int>(mid, high));
    while (install<c) {
        pair<int, int> temp = q.front();
        binary(house, temp.first, temp.second);
        q.pop();
    }
}

int main() {
    int n;
    
    cin >> n >> c;
    vector<int> house;
    
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        house.push_back(temp);
    }
    sort(house.begin(), house.end());
    
    install = 2;
    int low=0, high=n-1;
    
    binary(house, low, high);
    
    sort(dist.begin(), dist.end());
    cout<<dist[0];
}
