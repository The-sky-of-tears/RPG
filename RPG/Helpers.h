#pragma once
#include <utility>
#include <iostream>

namespace Helpers
{
	inline int normalize_int(int int_to_norm, int norm_max) {
		if (int_to_norm >= norm_max)
		{
			return int_to_norm % norm_max;
		}
		else if (int_to_norm < 0)
		{
			return  norm_max + int_to_norm % norm_max;
		}
		else
		{
			return int_to_norm;
		}
	}
	
	inline std::pair<int, int> normalize_pair(std::pair<int, int> pair_to_norm, std::pair<int, int> pair_norm_max) { //Normalizing shake Fred
		return { normalize_int(pair_to_norm.first, pair_norm_max.first),normalize_int(pair_to_norm.second, pair_norm_max.second) };
	}
}

