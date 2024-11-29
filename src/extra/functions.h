#pragma once

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