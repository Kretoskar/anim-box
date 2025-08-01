#pragma once

namespace Wrum
{
	class MathCore
	{
	public:
		static inline float DegToRad(float Deg) { return Deg * 0.0174532925f; }
		static inline float RadToDeg(float Rad) { return Rad * 57.2957795f; }
		static inline float Max(float lhs, float rhs) { return lhs > rhs ? lhs : rhs; }
		static inline float Min(float lhs, float rhs) { return lhs < rhs ? lhs : rhs; }
		static inline float Abs(float f) { return std::abs(f); }
		static inline bool NearlyEqual(float lhs, float rhs) { return Abs(lhs - rhs) <= FloatEpsilon; }
		static inline float Lerp(float lhs, float rhs, float a) { return (lhs * (1.0 - a)) + (rhs * a); }
		static inline float Clamp(float value, float minValue, float maxValue) 
		{
			if (value < minValue) {
				return minValue;
			}
			else if (value > maxValue) {
				return maxValue;
			}
			else {
				return value;
			}
		}


		 static float PI;
		 static float FloatEpsilon;
	};
}