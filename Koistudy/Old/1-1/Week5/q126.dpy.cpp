#include "dpython.cpp"

start

expdef(int, n, int(input()))
expdef(int, m, n)
defa(maxn, -1)
defa(maxind, -1)
defa(minn, VAR_MAX)
defa(minind, -1)

while(m--)
    defa(ind, n-m)
    defa(in, cin())
    if(int(maxn) < int(in))
        seta(maxn, in)
        seta(maxind, ind)
    endif
    if(int(minn) > int(in))
        seta(minn, in)
        seta(minind, ind)
    endif
whileend

print(maxind + " : " + maxn)
print(minind + " : " + minn)

endprogram
