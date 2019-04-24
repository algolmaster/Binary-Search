#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nation;
vector<int> country;
int budget;
int answer=1;
int main()
{
    int left=1, right, mid;

    cin>>nation;
    int inputSum =0;
    for (int i = 0; i <nation ; ++i) {
        int temp;
        cin>> temp;
        inputSum+=temp;
        country.push_back(temp);
    }
    cin>>budget;
    sort(country.begin(),country.end(), greater<int>());

    //int over=nation;
    int forCalcul;
    int expect;
    right = country.at(0);
//    for (int j = 0; j <nation-1 ; ++j) {
//        inputSum-=country.at(j);
//        if(inputSum<=budget&&budget-inputSum>country.at(j+1))
//        {
//            if(inputSum+country.at(j)*(nation-(j+1))) {
//                left = country.at(j + 1);
//                over = j + 1;
//                break;
//            }
//        }
//    }
    while(left<=right)
    {
        mid = (left+right)/2;
        int sum =0;
        for (int i = 0; i < nation; ++i) {
            if(country.at(i)<mid)
            {
                sum+=country.at(i);
            } else{
                sum+=mid;
            }
        }
        if(sum<=budget)
        {
            answer= mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<answer;
}