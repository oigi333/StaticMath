#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>

#include "Math.h"

template<int i>
struct ForLoop {
    template<template <int> typename Func>
    static void Iterate() {
        Func<i>()();
        ForLoop<i-1>::template Iterate<Func>();
    }
};
 
template<>
struct ForLoop<0> {
    template<template <int> typename Func>
    static void Iterate() {
        Func<0>()();
    }
};

const int numerator = Math<double,double>::Pi::Value*1000;
const int denominator = 1000;
const constexpr int fractionsNumerator[9] = {0, 166, 25, 33, 5, 66, 75, 833, 1};
const constexpr int fractionsDenominator[9] = {1, 1000, 100, 100, 10, 100, 100, 1000, 1};

template<int i>
struct ForBody
{
    void operator()() 
    {
        double sinv = Math<double,double>::Sin<numerator*fractionsNumerator[i],denominator*fractionsDenominator[i]>::Value;
        double cosv = Math<double,double>::Cos<(int)(numerator*fractionsNumerator[i]),denominator*fractionsDenominator[i]>::Value;

        printf("%.3f: %.3f %.3f %.3f %.3f\n",
            (((double)numerator*(double)fractionsNumerator[i])/((double)denominator*(double)fractionsDenominator[i]))*180.0/Math<double,double>::Pi::Value,
            sinv, 
            cosv,
            cosv>0.01|cosv<-0.01?sinv/cosv:nan(""),
            sinv>0.01|sinv<-0.01?cosv/sinv:nan("")
            );
    }
};

int main()
{

    printf("     sinx | cosx | tanx | ctgx \n");
    
    ForLoop<8>::Iterate<ForBody>();
    //for(constexpr int i = 0; i < 6; i++)
        //printf("%f %fs \n", Math<double,double>::Sin<numerator*fractions[0],denominator>::Value, Math<double,double>::Cos<numerator*fractions[0],denominator>::Value);

    return 0;
}