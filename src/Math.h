#pragma once

#include "PiGetter.h"
#include "SinGetter.h"

template<typename ReturnType, typename ArgType>
class Math
{
    template<typename ArgTypeF, int Numerator, int Denominator>
    struct Arg
    {
        typedef ArgTypeF Type;
        static constexpr const Type Value = ((Type)(Numerator))/((Type)(Denominator));
    };

public:
    using Pi = PiGetter<ReturnType, 800, true>;
    template<int Numerator, int Denominator>
    using Sin = SinGetter< ReturnType, Arg<ArgType, Numerator, Denominator>, 800, Pi, true>;
    template<int Numerator, int Denominator>
    using Cos = SinGetter< ReturnType, Arg<ArgType, Numerator+(int)(Pi::Value/2*Denominator), Denominator>, 800, Pi, true>;

};