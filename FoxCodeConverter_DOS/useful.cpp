#include "useful.hpp"

void upCharArray(char* input)
{
    unsigned int x=0;
    while(input[x])
    {
        input[x]=toupper(input[x]);
        ++x;
    }
    return;
}
