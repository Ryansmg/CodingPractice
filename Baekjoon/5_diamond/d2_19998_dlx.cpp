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
            solution_count = 1;
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

class DLX_Helper {
    std::map<std::string, signed> condition; signed oc = 0;
    std::map<std::string, signed> selection; signed ac = 0;
    std::vector<std::vector<signed>> s2c;
public:
    void add(const std::string& sele, const std::vector<std::string>& conds) {
        signed s;
        if(auto iter = selection.find(sele); iter == selection.end()) {
            s = ac;
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
    
    DLX run(int mode = DLX::SINGLE) const {
        std::vector matrix(ac, std::vector<bool>(oc));
        for(signed i = 0; i < static_cast<signed>(s2c.size()); i++)
            for(const signed& j : s2c[i]) matrix[i][j] = true;
        return DLX(matrix, mode);
    }
};

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // 1 ~ 81열 : 각 행(i/9)에 숫자 i%9이 들어가 있는가?
    // 82 ~ 162열 : 각 열(i/9)에 숫자 i%9이 들어가 있는가?
    // 162 + i*9 + j열 = 163 ~ 243열 : i번째 3x3 정사각형에 숫자 j가 들어가 있는가?
    // 244 + i*9 + j열 = 244 ~ 324열 : i행 j열에 숫자가 있는가?
    // 총 열 개수 == 325

    // 0행 : 이미 채워져 있는 칸들
    // i*81+j+1 = k행 : (k-1)/81==i 행 (k-1)%81/9==j열에 (k-1)%9+1 숫자가 들어감
    // 총 행 개수 == 9*81+1 = 730행

    vector board(9, vector<int>(9));
    vector matrix(730, vector<bool>(325));
    matrix[0][0] = true;
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            cin >> board[r][c];
            int squareN = r/3*3 + c/3;
            if(board[r][c]) {
                matrix[0][r * 9 + board[r][c]] = true;
                matrix[0][81 + c * 9 + board[r][c]] = true;
                matrix[0][162 + squareN * 9 + board[r][c]] = true;
                matrix[0][244 + r * 9 + c] = true;
            } else {
                int t = r * 81 + c * 9;
                for(int i = 1; i <= 9; i++) {
                    matrix[t + i][r * 9 + i] = true;
                    matrix[t + i][81 + c * 9 + i] = true;
                    matrix[t + i][162 + squareN * 9 + i] = true;
                    matrix[t + i][244 + r * 9 + c] = true;
                }
            }
        }
    }
    // 81 + 18 + 9 : 1행 2열에 9
    DLX dlx(matrix, DLX::COUNT);
    cout << dlx.solution_count << "\n";
    for(const int& i : dlx.solution) {
        if(!i) continue;
        board[(i - 1) / 81][(i - 1) % 81 / 9] = (i - 1) % 9 + 1;
    }
    for(const auto& l : board) {
        for(const int& i : l) cout << i << " ";
        cout << "\n";
    }
}
