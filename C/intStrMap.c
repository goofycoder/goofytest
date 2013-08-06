/*
     mimic the C++ STL::map
          - useful when mapping the function returns to statuses.
          - enum use
     
     Date: 08/06/2013
*/

#include <stdio.h>

typedef enum {
     ONE = 1,
     TWO,
     THREE
} KEY;

typedef struct _intToStrMap {
     KEY key;
     const char* value;
} intStrMap;

static intStrMap str_map[] = {
     {ONE, "one"},
     {TWO, "two"},
     {THREE, "three"},
}; 

void traverseMap() 
{
     unsigned numItems = sizeof(str_map)/sizeof(intStrMap);
     unsigned i = 0;

     for (; i < numItems; i++) {
          printf("Item %d: %s\n", i, str_map[i].value); 
     }
}

int main()
{
     traverseMap();    
     return 0;
}
