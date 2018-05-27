#pragma once

namespace maths
{
    namespace func
    {
        /*
            Keeps the given value between the specified limit [min:max]
            Params
                - min: the smallest possible number that value can reach
                - max: the biggest possible number that value can reach
                - value: the value that needs constraints
        */
        inline double Clamp(double value, double min, double max)
        {
            if (value < min)
                return min;
            if (value > max)
                return max;

            return value;
        }
        /*
            Keeps the given value between the specified limit [min:max]
            Params
                - min: the smallest possible number that value can reach
                - max: the biggest possible number that value can reach
                - value: the value that needs constraints
        */
        float Clamp(float value, float min, float max)
        {
            if (value < min)
                return min;
            if (value > max)
                return max;

            return value;
        }
        /*
            Keeps the given value between the specified limit [min:max]
            Params
                - min: the smallest possible number that value can reach
                - max: the biggest possible number that value can reach
                - value: the value that needs constraints
        */
        int Clamp(int value, int min, int max)
        {
            if (value < min)
                return min;
            if (value > max)
                return max;

            return value;
        }
    }
}