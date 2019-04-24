//
//  budget.cpp
//  BinarySearch
//
//  Created by 신예지 on 23/04/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int want;
    vector<int> _want;
    
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin>> want;
        sum += want;
        _want.push_back(want);
    }
    
    int budget;
    cin >> budget;
    
    sort(_want.begin(), _want.end());
    
    int limit=0;
    int reduce = sum-budget;
    int diff1 = _want[n-1]-_want[n-2]; //max-(max-1)
    int diff2 = _want[n-2]-_want[n-3];
    
    if(reduce<diff1) limit=_want[n-1]-reduce;
    else {
        _want[n-1] -= diff1;
        reduce -= diff1;
        
        if(reduce<2*diff2) {
            if(reduce%2==1) limit=_want[n-1]-(reduce/2+1);
            else limit= _want[n-1]-(reduce/2);
        }
    }
    cout << limit;
}
