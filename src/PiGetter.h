#pragma once

template<typename ReturnType, int Precision, bool First = false>
struct PiGetter
{
    static constexpr const ReturnType Value = (First+1)*((2.0*(ReturnType)Precision)/(2.0*(ReturnType)Precision-1.0))*((2.0*(ReturnType)Precision)/(2.0*(ReturnType)Precision+1.0))*PiGetter<ReturnType, Precision-1>::Value;
};

template<typename T>
struct PiGetter<T, 0>
{
    static constexpr const T Value = 1;
};
