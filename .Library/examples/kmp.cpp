

i32 main() {
    fastio;
    in64(n); str t = readline();
    in64(m); str p = readline();
    vl pi(m, 0);
    for(i64 j=0, i=1; i<m; i++) {
        while(j && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j;
    }
    vl ans;
    // t 위치, p 위치
    for(i64 i=0, j=0; i<n; i++) {
        while(j && t[i] != p[j]) j = pi[j-1];
        if(t[i] == p[j]) {
            if(j == m-1) ans.eb(i-m+1), j=pi[j];
            else j++;
        }
    }
    for(i64 &i : ans) ++i;
    println(Size(ans));
    printfln()(ans);
}
