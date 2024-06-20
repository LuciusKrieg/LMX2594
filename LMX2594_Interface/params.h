#include <iostream>
#include <map>

using namespace std;

#define ParamInfo(width, shift, regnumber) ((width << 10) + (shift << 5) + (regnumber))

void GetParamsList();