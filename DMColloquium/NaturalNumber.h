//
//  NaturalNumber.h
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#ifndef __DMColloquium__NaturalNumber__
#define __DMColloquium__NaturalNumber__

#include <vector>

#endif /* defined(__DMColloquium__NaturalNumber__) */

class NaturalNumber {
protected:
    // you must only use first 9 digits of each int.
    // So, if a number is: 12345678901234 than
    // digitBlocks[1] = 12345
    // digitBlocks[0] = 678901234
    std::vector<unsigned int> digitBlocks;
public:
    NaturalNumber greatestCommonFactor(NaturalNumber secondNumber);
    // put declarations-ONLY for each method below
	NaturalNumber ADD_NN_N(NaturalNumber nat_num_2);
};
