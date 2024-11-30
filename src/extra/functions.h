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

template <typename I>
I linear_interpolation(const I& value, const I& x0, const I& x1, const I& y0, const I& y1) {
    return y0 + (y1 - y0) * (value - x0)/(x1 - x0);
}