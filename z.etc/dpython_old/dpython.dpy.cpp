#include "dpython.cpp"
load_all

start

 forin(i, range(input()))
     def(in, input())
     print(tern("True", isPrime(ull(in)), "False"))
 endfor
//expdef(vector<var>, in, split(input(), " "))
//print(vgcd(in[0], in[1]))

endprogram

/*
mapint test

expdef(vector<int>, in)
expdef(vector<string>, in2)
set(in2, split(input(), " "))
mapint(in, in2)
print(in[0] + in[1] + in[2])
print(str(in[0]) + str(in[1]))
*/

/*
q2317
expdef(vector<string>, in, split(input(), " "))
def(a, in[0])
def(b, in[1])

if(int(a)>int(b))
    swap(a,b)
endif

defa(ans, 0)

forin(i, range(int(b)-int(a)+1))
    defa(v, int(i)+int(a))
    defa(now, 1)
    while(int(v)!=1)
        seta(now, int(now) + 1)
        if(int(v)&1)
            seta(v, int(v)*3+1)
        else
            seta(v, int(v)/2)
        endif
    endwhile
    seta(ans, max(ans, now))
endfor
print(ans)
*/