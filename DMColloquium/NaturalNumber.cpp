//
//  NaturalNumber.cpp
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#include "NaturalNumber.h"

// put definitions for all methods over here.

/// This is just an example of how to get going. Doesn't make any sense
NaturalNumber NaturalNumber::greatestCommonFactor(NaturalNumber secondNumber){
    return *this;
}

NaturalNumber NaturalNumber::ADD_NN_N(NaturalNumber nat_num_2)
{
	//
	//  ADD_NN_N
	//  DMColloquium
	//
	//  Created by Dmitry Konstantinov, Dmitry Azarov & Tuyaara Fedorova on 5/7/15.
	//
	unsigned int length, min, flag;
	switch (this->COM_NN_D(nat_num_2))
	{
	case 2:
		length = this->digitBlocks.size() + 1;
		min = nat_num_2.digitBlocks.size();
		flag = 2;
		break;
	case 1:
		length = nat_num_2.digitBlocks.size() + 1;
		min = this->digitBlocks.size();
		flag = 1;
		break;
	case 0:
		length = this->digitBlocks.size() + 1;
		min = this->digitBlocks.size();
		break;
	default:
		break;
	}
	NaturalNumber result_of_sum;
	result_of_sum.digitBlocks = std::vector<unsigned int>(length);
	for (int j = 0; j < min; j++) {
		result_of_sum.digitBlocks[j] += (nat_num_2.digitBlocks[j] + this->digitBlocks[j]); // суммируем последние разряды чисел
		result_of_sum.digitBlocks[j + 1] += result_of_sum.digitBlocks[j] / 1000000000; 
		result_of_sum.digitBlocks[j] = result_of_sum.digitBlocks[j] % 1000000000;
	}
	switch (flag)
	{
	case 2:
		for (int i = nat_num_2.digitBlocks.size(); i < length - 1; i++) {
			result_of_sum.digitBlocks[i] += this->digitBlocks[i];
			result_of_sum.digitBlocks[i + 1] += result_of_sum.digitBlocks[i] / 1000000000; // если есть разряд для переноса, переносим его в следующий разряд
			result_of_sum.digitBlocks[i] = result_of_sum.digitBlocks[i] % 1000000000; // если есть разряд для переноса он отсекается
		}
		break;
	case 1:
		for (int i = this->digitBlocks.size(); i < length - 1; i++) {
			result_of_sum.digitBlocks[i] += nat_num_2.digitBlocks[i];
			result_of_sum.digitBlocks[i + 1] += (result_of_sum.digitBlocks[i] / 1000000000); // если есть разряд для переноса, переносим его в следующий разряд
			result_of_sum.digitBlocks[i] = result_of_sum.digitBlocks[i] % 1000000000; // если есть разряд для переноса он отсекается
		}
		break;
	default:
		break;
	}
	if (result_of_sum.digitBlocks[length - 1] == 0) {
		length--;
	}
	return result_of_sum;
}
