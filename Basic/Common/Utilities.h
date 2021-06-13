#pragma once

#include<algorithm>

template<class T>
inline constexpr const T& Clamp(const T& v, const T& low, const T high) 
{
	//max関数：v が low より小さければ low を、大きければ v を返す
	//min関数：帰ってきた値が v で high より大きければ high

	//式： low <= v <= high の範囲にする

	return std::min(std::max(v, low), high);
}

template<class T>
inline constexpr const T& Leap(const T& start, const T& end, const T time) {
	return start + t * (end - start);
}