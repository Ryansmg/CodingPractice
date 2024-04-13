#include "dpython.cpp"

start

expdef(vector<int>, in, {})
mapint(in, split(input(), " "))
print(in[0]*in[1])

end