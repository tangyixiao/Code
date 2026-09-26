#include "testlib.h"

#include <algorithm>
#include <bitset>
#include <vector>

constexpr int MAX_N = 1000;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const int n = inf.readInt(1, MAX_N, "n");
    const int m = inf.readInt(n - 1, n * (n - 1) / 2, "m");

    std::vector<std::bitset<MAX_N + 1>> adjacent(n + 1);
    std::vector<std::vector<int>> graph(n + 1);
    for (int edge = 0; edge < m; ++edge) {
        const int u = inf.readInt(1, n, "u");
        const int v = inf.readInt(1, n, "v");
        adjacent[u].set(v);
        adjacent[v].set(u);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // The first pass computes vertices at distance at most two.
    std::vector<std::bitset<MAX_N + 1>> within_two(n + 1);
    for (int u = 1; u <= n; ++u) {
        within_two[u] = adjacent[u];
        within_two[u].set(u);
        for (int v : graph[u]) {
            within_two[u] |= adjacent[v];
        }
    }

    // A neighbor followed by a path of length at most two has length at most three.
    std::vector<std::bitset<MAX_N + 1>> within_three = within_two;
    for (int u = 1; u <= n; ++u) {
        for (int v : graph[u]) {
            within_three[u] |= within_two[v];
        }
    }

    std::vector<int> path(n + 1);
    std::vector<int> seen(n + 1);
    for (int start = 1; start <= n; ++start) {
        const int first = ouf.readInt(-1, n, format("a_%d,1", start));
        if (first == -1) {
            // The cube of every connected undirected graph is Hamiltonian.
            quitf(_wa, "a valid route exists for start vertex %d, but -1 was printed", start);
        }

        path[0] = first;
        for (int position = 1; position <= n; ++position) {
            path[position] = ouf.readInt(1, n, format("a_%d,%d", start, position + 1));
        }

        if (path[0] != start) {
            quitf(_wa, "route %d starts at %d instead of %d", start, path[0], start);
        }
        if (path[n] != start) {
            quitf(_wa, "route %d ends at %d instead of %d", start, path[n], start);
        }

        std::fill(seen.begin(), seen.end(), 0);
        for (int position = 0; position < n; ++position) {
            const int vertex = path[position];
            if (seen[vertex]++) {
                quitf(_wa, "route %d visits vertex %d more than once", start, vertex);
            }
            if (!within_three[path[position]].test(path[position + 1])) {
                quitf(_wa, "route %d moves from %d to %d, whose distance exceeds 3",
                      start, path[position], path[position + 1]);
            }
        }
    }

    if (!ouf.seekEof()) {
        quitf(_wa, "extra data after the %d required routes", n);
    }

    quitf(_ok, "all routes are valid");
}
