#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

struct Member {
    string name;
    string type;
    long long offset;
};

struct TypeInfo {
    long long size;
    long long align;
    bool is_basic;
    vector<Member> members;
};

struct Var {
    string name;
    string type;
    long long addr;
};

unordered_map<string, TypeInfo> types; 
vector<Var> vars;                      
long long cur_end = 0;                 


long long align_addr(long long prev_end, long long align) {
    if (prev_end % align == 0)
        return prev_end;
    return prev_end + align - (prev_end % align);
}



string find_leaf(const string &type, long long base, const string &prefix, long long addr) {
    TypeInfo &info = types[type];
    if (info.is_basic) {
        
        if (base <= addr && addr < base + info.size)
            return prefix;
        else
            return "";
    } else {
        for (const Member &m : info.members) {
            long long child_base = base + m.offset;
            string res = find_leaf(m.type, child_base, prefix + "." + m.name, addr);
            if (!res.empty())
                return res;
        }
        return "";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    types["byte"] = {1, 1, true, {}};
    types["short"] = {2, 2, true, {}};
    types["int"] = {4, 4, true, {}};
    types["long"] = {8, 8, true, {}};

    int n;
    cin >> n;

    while (n--) {
        int op;
        cin >> op;

        if (op == 1) {
            string s;
            int k;
            cin >> s >> k;
            vector<Member> members(k);
            long long max_align = 1;
            long long prev_end = 0;

            for (int i = 0; i < k; ++i) {
                string t, mname;
                cin >> t >> mname;
                TypeInfo &ti = types[t];
                long long al = ti.align;
                long long off = align_addr(prev_end, al);
                members[i] = {mname, t, off};
                prev_end = off + ti.size;
                max_align = max(max_align, al);
            }

            long long last_end = members.back().offset + types[members.back().type].size;
            last_end = align_addr(last_end, max_align);

            types[s] = {last_end, max_align, false, members};
            cout << last_end << " " << max_align << "\n";
        } else if (op == 2) {
            string t, vname;
            cin >> t >> vname;
            TypeInfo &ti = types[t];
            long long al = ti.align;
            long long sz = ti.size;
            long long addr = align_addr(cur_end, al);
            vars.push_back({vname, t, addr});
            cur_end = addr + sz;
            cout << addr << "\n";
        } else if (op == 3) {
            string path;
            cin >> path;
            stringstream ss(path);
            string part;
            vector<string> parts;
            while (getline(ss, part, '.'))
                parts.push_back(part);

            
            long long addr = 0;
            string cur_type;
            for (const Var &v : vars) {
                if (v.name == parts[0]) {
                    addr = v.addr;
                    cur_type = v.type;
                    break;
                }
            }

            
            for (size_t i = 1; i < parts.size(); ++i) {
                const TypeInfo &info = types[cur_type];
                for (const Member &m : info.members) {
                    if (m.name == parts[i]) {
                        addr += m.offset;
                        cur_type = m.type;
                        break;
                    }
                }
            }
            cout << addr << "\n";
        } else { 
            long long addr;
            cin >> addr;
            string result;
            for (const Var &v : vars) {
                result = find_leaf(v.type, v.addr, v.name, addr);
                if (!result.empty()) {
                    cout << result << "\n";
                    break;
                }
            }
            if (result.empty())
                cout << "ERR\n";
        }
    }
    return 0;
}