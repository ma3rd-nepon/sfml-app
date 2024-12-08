#pragma once

#include <random>

template <typename T>
T clamp(const T& value, const T& low, const T& top) {
    if (value > top) {
        return top;
    }
    if (value < low) {
        return low;
    }
    return value;
}

template <typename I>
I linear_interpolation(const I& value, const I& x0, const I& x1, const I& y0, const I& y1) {
    return y0 + (y1 - y0) * (value - x0)/(x1 - x0);
}

namespace randoms {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // template <typename T>
    // static T random(T& min=-2'147'483'648, T& max=2'147'483'647) {
    //     std::uniform_real_distribution<T> dist(min, max); 

    //     return dist(gen);
    // }

    static int random_int(const int& min=-2'147'483'648, const int& max=2'147'483'647) {
        std::uniform_int_distribution<int> dist(min, max);

        return dist(gen);
    }

    // template <typename T>
    // static T random_shuffle(T& array) {
    //     std::uniform_int_distribution<int> dist(0, array.size());

    //     std::random_shuffle(array.begin(), array.end());
    // }
}