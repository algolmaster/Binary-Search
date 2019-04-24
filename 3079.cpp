//
// Created by 이석규 on 2019-04-22.
//
#include <iostream>
using namespace std;
long long immigration[100001];
int immi,peo;
int main ()
{
    cin>>immi>>peo;
//    long long *immigration;
//    immigration = new long long[immi];
    long long max =0;
    for (int i = 0; i < immi; ++i) {
        cin>>immigration[i];
        if(immigration[i]>max)
            max = immigration[i];
    }
//    for (int j = 0; j < immi; ++j) {
//        for (int i = 1; i < peo; ++i) {
//            if(immigration[j]*i)
//            vec.push_back(immigration[j]*i);
//        }
//    }
    long long left = 0;
    long long right = max*peo;
    long long answer= right;

    while(left<=right)
    {
        long long mid =(left+right)/2;

        long long num=0;
        for (int i = 0; i < immi; ++i) {
            num += mid/immigration[i];
        }

        if(num>=peo)
        {
            answer = mid;
            right= mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    cout<<answer;
}
