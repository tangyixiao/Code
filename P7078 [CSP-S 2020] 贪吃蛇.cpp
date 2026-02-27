#include <iostream>
#include <cstdio>
#include <set>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1000005;

struct Snake {
    int id;
    ll val;
    Snake() {}
    Snake(int _id, ll _val) : id(_id), val(_val) {}
    bool operator<(const Snake& other) const {
        if (val != other.val) return val < other.val;
        return id < other.id;
    }
};

struct Event {
    int id_max, id_min;
    ll val_max, val_min, new_val;
    Event() {}
    Event(int _id_max, int _id_min, ll _val_max, ll _val_min, ll _new_val) :
        id_max(_id_max), id_min(_id_min), val_max(_val_max), val_min(_val_min), new_val(_new_val) {}
};

int n;
ll a[MAXN];
vector<Event> events;

bool weaker(const Snake& a, const Snake& b) {
    if (a.val != b.val) return a.val < b.val;
    return a.id < b.id;
}

bool is_weaker_or_equal(const Snake& a, const Snake& b) {
    return weaker(a, b) || (a.val == b.val && a.id == b.id);
}

void simulate_events() {
    events.clear();
    set<Snake> S;
    for (int i = 1; i <= n; i++) {
        S.insert(Snake(i, a[i]));
    }
    
    while (S.size() > 1) {
        Snake weak = *S.begin();
        Snake strong = *S.rbegin();
        S.erase(weak);
        S.erase(strong);
        
        events.push_back(Event(strong.id, weak.id, strong.val, weak.val, strong.val - weak.val));
        S.insert(Snake(strong.id, strong.val - weak.val));
    }
}

int solve() {
    if (n == 1) return 1;
    
    simulate_events();
    int m = events.size();
    if (m == 0) return n;
    
    set<Snake> S;
    // 最后一条蛇
    Event last = events.back();
    S.insert(Snake(last.id_max, last.new_val));
    
    vector<bool> choice(m, true);
    bool next_safe = true;
    
    for (int i = m - 1; i >= 0; i--) {
        Event e = events[i];
        Snake C(e.id_max, e.new_val);
        
        Snake weak = *S.begin();
        bool is_weakest = is_weaker_or_equal(C, weak);
        int S_size = S.size();
        
        bool will_be_eaten = false;
        if (is_weakest && S_size > 1 && next_safe) {
            will_be_eaten = true;
        }
        
        choice[i] = !will_be_eaten;
        bool curr_safe = !will_be_eaten;
        next_safe = curr_safe;
        
        // 更新集合
        S.erase(C);
        S.insert(Snake(e.id_max, e.val_max));
        S.insert(Snake(e.id_min, e.val_min));
    }
    
    // 找到第一个不吃的蛇
    for (int i = 0; i < m; i++) {
        if (!choice[i]) {
            return n - i;
        }
    }
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        if (t == 0) {
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) {
                scanf("%lld", &a[i]);
            }
        } else {
            int k;
            scanf("%d", &k);
            for (int i = 0; i < k; i++) {
                int x;
                ll y;
                scanf("%d%lld", &x, &y);
                a[x] = y;
            }
        }
        
        printf("%d\n", solve());
    }
    
    return 0;
}