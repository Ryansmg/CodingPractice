#include <bits/stdc++.h>

class DLX {
    struct node {
        signed row;
        node *u, *d, *l, *r;
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
            if(r == this) {
                if(dlx.all) {
                    if(dlx.sol) dlx.all_solutions.push_back(dlx.solution);
                    else dlx.solution_count++;
                }
                return true;
            }
            node* ptr = nullptr;
            signed low = 2147483647;
            for(node* i = r; i != this; i = i->r) {
                if(i->size < low) {
                    if(!(i->size)) return false;
                    low = i->size; ptr = i;
                }
            }
            assert(ptr);
            ptr->cover();
            for(node* i = ptr->d; i != ptr; i = i->d) {
                dlx.solution.push_back(i->row);
                for(node* j = i->r; j != i; j = j->r) j->h->cover();
                if(search(dlx) && !dlx.all) return true;
                else {
                    dlx.solution.pop_back();
                    for(node* j = i->l; j != i; j = j->l) j->h->uncover();
                }
            }
            ptr->uncover();
            return false;
        }
    };
    bool all = false, sol = false;
    std::vector<node> nodes, heads; node hd{};
public:
    enum { SINGLE, ALL, COUNT };
    std::vector<signed> solution;
    std::vector<std::vector<signed>> all_solutions;
    std::size_t solution_count = 0;
    [[maybe_unused]] bool possible = false;
    DLX() = default;
    explicit DLX(const std::vector<std::vector<bool>>& matrix, int mode = SINGLE) {
        all = mode == ALL || mode == COUNT;
        sol = mode == SINGLE || mode == ALL;
        auto n = static_cast<signed>(matrix[0].size()),
             m = static_cast<signed>(matrix.size());
        heads.resize(n, {});
        hd.r = &heads[0]; hd.l = &heads[n-1];
        for(signed i = 0; i < n; i++) {
            heads[i].size = 0;
            heads[i].u = heads[i].d = &heads[i];
            heads[i].l = (i ? &heads[i-1] : &hd);
            heads[i].r = (i < n-1 ? &heads[i+1] : &hd);
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
        if(mode == SINGLE) {
            solution_count = possible;
        }
        if(mode == ALL) {
            possible = !all_solutions.empty();
            solution_count = all_solutions.size();
            if(possible) solution = all_solutions[0];
        }
        if(mode == COUNT) {
            possible = solution_count;
        }
    }
};

class DLXHelper {
    std::map<std::string, signed> condition; signed oc = 0;
    std::map<std::string, signed> selection; signed ac = 0;
    std::vector<std::string> selectionName;
    std::vector<std::vector<signed>> s2c;
public:
    void addCond(const std::vector<std::string>& conds) {
        for(const std::string& s : conds) if(!condition.contains(s)) condition.insert({s, oc++});
    }
    void addCond(const std::string& cond) { addCond(std::vector{cond}); }
    void add(const std::string& sele, const std::vector<std::string>& conds) {
        signed s;
        if(auto iter = selection.find(sele); iter == selection.end()) {
            s = ac;
            selectionName.push_back(sele);
            selection.insert({sele, ac++});
            s2c.emplace_back();
        }
        else s = iter->second;

        for(const std::string& cond : conds) {
            signed c;
            if(auto iter = condition.find(cond); iter == condition.end())
                c = oc, condition.insert({cond, oc++});
            else
                c = iter->second;
            s2c[s].push_back(c);
        }
    }
    void add(const std::string& sele, const std::string& cond) { add(sele, std::vector{cond}); }

    std::string seleName(signed sele) { return selectionName[sele]; }

    DLX run(int mode = DLX::SINGLE) const {
        std::vector matrix(ac, std::vector<bool>(oc));
        for(signed i = 0; i < static_cast<signed>(s2c.size()); i++)
            for(const signed& j : s2c[i]) matrix[i][j] = true;
        return DLX(matrix, mode);
    }

    std::vector<std::string> toName(const std::vector<signed>& solution) const {
        std::vector<std::string> ret(solution.size());
        for(size_t i = 0; i < solution.size(); i++) ret[i] = selectionName[solution[i]];
        return ret;
    }
};

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(true) {
        vector board(9, vector<int>(9));
        string s; cin >> s;
        if(s == "end") break;
        DLXHelper dlx;
        dlx.add("p", "0"); // precondition, "0" 조건은 "p" 선택만 만족하는 조건으로, 이미 놓아져 있는 숫자들에 대한 선택을 강제하기 위해서 추가
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                int squareN = r / 3 * 3 + c / 3;
                board[r][c] = (s[r*9+c] == '.') ? 0 : s[r*9+c]-'0';
                if(board[r][c]) {
                    dlx.add("p", format("row{}_{}", r, board[r][c])); // 각 행에 모든 수가 있는가?
                    dlx.add("p", format("col{}_{}", c, board[r][c])); // 각 열에 모든 수가 있는가?
                    dlx.add("p", format("sq{}_{}", squareN, board[r][c])); // 각 3x3에 모든 수가 있는가?
                    dlx.add("p", format("ex{}_{}", r, c)); // (r, c) 자리에 수가 있는가?
                } else {
                    for(int i = 1; i <= 9; i++) {
                        string name = format("s{}_{}_{}", r, c, i); // (r, c) 자리에 수 i를 놓는 선택
                        dlx.add(name, format("row{}_{}", r, i));
                        dlx.add(name, format("col{}_{}", c, i));
                        dlx.add(name, format("sq{}_{}", squareN, i));
                        dlx.add(name, format("ex{}_{}", r, c));
                    }
                }
            }
        }
        for(const auto &name: dlx.toName(dlx.run().solution)) {
            if(name == "p") continue;
            int r = name[1] - '0', c = name[3] - '0', v = name[5] - '0';
            board[r][c] = v;
        }
        for(const auto &l: board) {
            for(const int &i: l) cout << i;
        }
        cout << "\n";
    }
}
