#include <iostream>

int main()
{
    int left[] = {1,2,4};
    int right[] = {4,5,7};
    int freq[100] = {0};
    int size = sizeof(left) / sizeof(int);

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = left[i]; j <= right[i]; j++)
        {
            freq[j]++;
        }
    }

    int maxfreq = 0;
    int freqIndex = 0;
    for (size_t i = 0; i < 100; i++)
    {
        if(freq[i] > maxfreq)
        {
            maxfreq = freq[i];
            freqIndex = i;
        }
    }
    std::cout << "The maximum time occuring value is : " << freqIndex << std::endl;
}