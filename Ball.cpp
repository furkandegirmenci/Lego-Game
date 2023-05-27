/*
 * calcMinEnergy algorithm :
     *  If we look at the calculations for newEnergy, both equals to "(2 * ballEnergy) - height"
     *  We can make use of this by starting from the end of lego array
     *  Every node we go, our energy calculation change will be :
     *          (endEnergy + height) / 2
     *  From here, when we go to next node we will add that lego's "height * 2^j"
     *  in here, j will slowly go towards n(number of legos)
     *  At the end of the calculation, we will have heights added to a calculation. If we call this heightValue, Our result will be :
     *          (endEnergy + heightValue) / 2^n
     *  We do not know what our endEnergy is, but what we know is (endEnergy + heightValue) must be multitude of 2^n
     *  By checking if (heightValue % 2^n == 0) we can see if our endEnergy is 0 or not. If this is true,
     *      Our end energy will be 0. And our calculation will be heightValue / 2^n
     *   if this is false,
     *      Out endEnergy must be a number. We can divide heightValue by 2^n, then add +1 due to how int division works in C++.
     *  The lowest value of this calculation will be our minEnergy
 */

#include "Ball.h"
#include <cmath>

int Ball::getBallEnergy() const {
    return ballEnergy;
}


void Ball::calcMinEnergy(const int *arr, int size) {
    int heightValue {};
    int j {0};

    for (int i = size - 1; i >= 0 ; i--) {
        heightValue += arr[i] * static_cast<int>(pow(2, j));
        j++;
    }

    if(heightValue % static_cast<int>(pow(2, size)) == 0) {
        minEnergy = heightValue / static_cast<int>(pow(2, size));
    } else {
        minEnergy = (heightValue / static_cast<int>(pow(2, size))) + 1;
    }
}



int Ball::getMinEnergy() const {
    return minEnergy;
}


Ball::~Ball() {}