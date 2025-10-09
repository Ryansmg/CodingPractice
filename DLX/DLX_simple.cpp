#include <bits/stdc++.h>

class DLX {
    struct node {
        signed row;
        node *u, *d, *l, *r;
        bool required;
        union {
            node* h;
            signed size;
        };
        void cover() {
            this->r->l = this->l; this->l->r = this->r;
            for(node* i = this->d; i != this; i = i->d) {
                for(node* j = i->r; j != i; j = j->r) {
                    j->d->u = j->u; j->u->d = j->d;
                    j->h->size--;
                }
            }
        }
        void uncover() {
            for(node* i = this->u; i != this; i = i->u) {
                for(node* j = i->l; j != i; j = j->l) {
                    j->d->u = j; j->u->d = j;
                    j->h->size++;
                }
            }
            this->r->l = this; this->l->r = this;
        }
        bool search(DLX& dlx) {
            node* ptr = nullptr;
            signed low = 2147483647;
            for(node* i = r; i != this; i = i->r) {
                if(i->size < low && i->required) {
                    if(!(i->size)) return false;
                    low = i->size; ptr = i;
                }
            }
            if(ptr == nullptr) return true;
            ptr->cover();
            for(node* i = ptr->d; i != ptr; i = i->d) {
                dlx.solution.push_back(i->row);
                for(node* j = i->r; j != i; j = j->r) j->h->cover();
                if(search(dlx)) return true;

                dlx.solution.pop_back();
                for(node* j = i->l; j != i; j = j->l) j->h->uncover();
            }
            ptr->uncover();
            return false;
        }
    };
    std::vector<node> nodes, heads; node hd{};
    std::vector<bool> required;
public:
    std::vector<signed> solution;
    [[maybe_unused]] bool possible = false;
    DLX() = default;
    explicit DLX(const std::vector<std::vector<bool>>& matrix)
        : DLX(matrix, std::vector<bool>(matrix[0].size(), true)) {}
    DLX(const std::vector<std::vector<bool>>& matrix, const std::vector<bool>& required) {
        auto n = static_cast<signed>(matrix[0].size()),
             m = static_cast<signed>(matrix.size());
        assert(n == static_cast<signed>(required.size()));
        heads.resize(n, {});
        hd.r = &heads[0]; hd.l = &heads[n-1];
        for(signed i = 0; i < n; i++) {
            heads[i].size = 0;
            heads[i].required = required[i];
            heads[i].u = heads[i].d = &heads[i];
            heads[i].l = i ? &heads[i-1] : &hd;
            heads[i].r = i < n-1 ? &heads[i+1] : &hd;
        }
        signed vsz = 0, cnt = 0;
        for(signed i = 0; i < m; i++) for(signed j = 0; j < n; j++) vsz += matrix[i][j];
        nodes.resize(vsz);
        for(signed i = 0; i < m; i++) {
            node* prv = nullptr;
            for(signed j = 0; j < n; j++) {
                if(!matrix[i][j]) continue;
                node& cur = nodes[cnt++];
                cur.row = i; cur.u = heads[j].u;
                cur.h = cur.d = &heads[j];
                if(prv) cur.l = prv, cur.r = prv->r, prv->r->l = &cur, prv->r = &cur;
                else cur.l = cur.r = &cur;
                heads[j].u->d = &cur; heads[j].u = &cur;
                heads[j].size++;
                prv = &cur;
            }
        }
        possible = hd.search(*this);
    }
};

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    

}
