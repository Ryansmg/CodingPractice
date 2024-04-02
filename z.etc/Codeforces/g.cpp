#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findP(vector<int> &parent, int n) {
    if(n == parent[n]) return n;
    return parent[n] = findP(parent, parent[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for(int ti=0; ti<t; ti++) {
        int n; cin >> n;
        vector<int> parent;
        vector<int> cnt(n, 0);
        vector<int> grsize(n, 1);
        for(int i=0; i<n; i++) parent.push_back(i);

        vector<string> genre, writer;
        vector<pair<string, string>> in;
        for(int i=0; i<n; i++) {
            string a, b;
            cin >> a >> b;
            in.emplace_back(a, b);
            genre.push_back(a);
            writer.push_back(b);
        }
        sort(genre.begin(), genre.end());
        sort(writer.begin(), writer.end());
        genre.erase(unique(genre.begin(), genre.end()), genre.end());
        writer.erase(unique(writer.begin(), writer.end()), writer.end());

        vector<int> genrepar, writerpar;
        int gl = genre.size(), wl = writer.size();
        for(int i=0; i<gl; i++) genrepar.push_back(i);
        for(int i=0; i<wl; i++) writerpar.push_back(i);

        for(int i=0; i<n; i++) {
            int geni = lower_bound(genre.begin(), genre.end(), in[i].first) - genre.begin();
            int wri = lower_bound(writer.begin(), writer.end(), in[i].second) - writer.begin();
            for(int j=i+1; j<n; j++) {
                if(findP(parent, i) == findP(parent, j)) continue;
                int geni2 = lower_bound(genre.begin(), genre.end(), in[j].first) - genre.begin();
                int wri2 = lower_bound(writer.begin(), writer.end(), in[j].second) - writer.begin();
                if(geni==geni2 || wri==wri2) {
                    // writerpar[findP(writerpar, wri)] = findP(writerpar, wri2);
                    // genrepar[findP(genrepar, geni)] = findP(genrepar, geni2);
                    grsize[findP(parent, j)] += grsize[findP(parent, i)];
                    parent[findP(parent, i)] = findP(parent, j);
                }
            }
        }
        int m = grsize[0];
        for(int i : grsize) m = max(m, i);
        cout << n - m << "\n";
    }
}
