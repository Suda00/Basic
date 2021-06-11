#pragma once

#include<algorithm>

template<class T>
inline constexpr const T& Clamp(const T& v, const T& low, const T high) 
{
	//max�֐��Fv �� low ��菬������� low ���A�傫����� v ��Ԃ�
	//min�֐��F�A���Ă����l�� v �� high ���傫����� high

	//���F low <= v <= high �͈̔͂ɂ���

	return std::min(std::max(v, low), high);
}