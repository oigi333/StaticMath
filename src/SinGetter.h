#pragma once

#include "PiGetter.h"


template<typename ReturnType, typename ArgValue, int Precision, typename Pi, bool First = false>
struct SinGetter
{
    static constexpr const ReturnType Value = (ArgValue::Value - (!First)*(ArgValue::Value-1))*(
        (1-ArgValue::Value/(Precision*Pi::Value))*(1+ArgValue::Value/(Precision*Pi::Value)))*SinGetter<ReturnType, ArgValue, Precision-1, Pi>::Value;
};

template<typename ReturnType, typename ArgValue,  typename Pi>
struct SinGetter<ReturnType, ArgValue, 0, Pi>
{
    static constexpr const ReturnType Value = 1;
};

