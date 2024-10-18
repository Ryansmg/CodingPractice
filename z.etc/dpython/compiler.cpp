#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

void print_init_dpp() {
    std::ifstream is(R"(C:\Users\ryans\Desktop\Coding\z.etc\dpython\init.cpp)");
    while(!is.eof()) {
        std::string s;
        std::getline(is, s);
        std::cout << s << '\n';
    }
}

// for string delimiter
std::vector<std::string> split(const std::string& s, const std::string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;
    
    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    
    res.push_back (s.substr (pos_start));
    return res;
}

struct codeLine {
    long long indent;
    std::string data;
    std::vector<std::string> tokens;
    explicit codeLine(std::string raw) {
        indent = 0;
        while(raw[indent] == ' ') indent++;
        std::string tempData = raw.substr(indent);
        for(char &c : tempData) {
            if(c == '\'') data += '"';
            else if(c == '\t') data += "    ";
            else data += c;
        }
        while(data.back() == ' ') data.pop_back();
        tokens = split(data, " ");
    }
    std::string to_dpy_format() {
        if(data.empty()) return "";
        std::string result(indent, ' ');
        bool isAssign = false;
        for(auto &a : tokens) if(a == "=") isAssign = true;
        if(isAssign) {
            result += "auto " + tokens[0] + " = dpy_construct_(";
            assert(tokens[1] == "=");
            for(int i = 2; i < tokens.size(); i++) {
                result += tokens[i] + " ";
            }
            result += ");";
        }
        else if(tokens[0]=="for") {
            assert(tokens[2] == "in");
            assert(tokens[3].back() == ':');
            tokens[3].pop_back();
            result += "for(auto &" + tokens[1] + ":" + tokens[3] + ")";
        }
        else result += data + ";";
        return result;
    }
};

int main() {
    fastio
    freopen(R"(C:\Users\ryans\Desktop\Coding\z.etc\dpython\result.cpp)", "w", stdout);
    print_init_dpp();
    
    std::string code;
    std::ifstream is(R"(C:\Users\ryans\Desktop\Coding\z.etc\dpython\tar.dpy)");
    while(!is.eof()) {
        std::string s;
        std::getline(is, s);
        code += s + '\n';
    }
    
    std::vector<std::string> rawLines = split(code, "\n");
    std::vector<codeLine> lines; for(const auto& raw : rawLines) lines.emplace_back(raw);
    
    //   init functions
    
    std::cout << "signed main() {\n";
    
    for(long long i=0; i<lines.size(); i++) {
        if(i > 0 && lines[i].indent < lines[i-1].indent) std::cout << "    " << std::string(lines[i].indent, ' ') << "}\n";
        std::cout << "    " << lines[i].to_dpy_format();
        if(i < lines.size()-1 && lines[i].indent < lines[i+1].indent) std::cout << " {";
        std::cout << "\n";
    }
    if(lines.back().indent > 0) std::cout << "    }\n";
    
    std::cout << "}\n";
}
