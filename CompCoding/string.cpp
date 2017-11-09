#include <sstream>

// load vector from string
istringstream is(s);
int temp;
while(is >> temp)
  vec.push_back(temp);
