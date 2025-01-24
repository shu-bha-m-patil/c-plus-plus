#include <iostream>

int main()
{
    int petrol[4] = {50,10,60,100};
    int petrolPumpDistance[4] = {30,20,100,10};
    int start = 0;
    int remainingPetrol = 0;
    int prevPetrol = 0;
    for (size_t i = 0; i < 4; i++)
    {
        remainingPetrol = remainingPetrol + petrol[i] - petrolPumpDistance[i];
        if(remainingPetrol < 0)
        {
            start = i + 1;
            prevPetrol = prevPetrol + remainingPetrol;
            remainingPetrol = 0;
        }
    }
    remainingPetrol = remainingPetrol + prevPetrol;
    std::cout << "The starting petrol pump is " << (remainingPetrol > 0 ? start + 1 : -1) << std::endl;
    return 0;
}