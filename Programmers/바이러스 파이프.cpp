#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> make_graph(vector<vector<int>>& edges, int n) {

    const int edges_size = static_cast<int>(edges.size());
    vector<vector<pair<int, int>>> graph(n);

    for (auto edge : edges) {
        int node_a = edge.at(0);
        int node_b = edge.at(1);
        int type = edge.at(2);

        graph.at(node_a - 1).push_back(make_pair(node_b - 1, type));
        graph.at(node_b - 1).push_back(make_pair(node_a - 1, type));
    }

    return graph;
}

void pipe(int k, vector<bool>& infection_node, vector<vector<pair<int, int>>>& graph, int& answer) {

    if (k == 0) {
        int result = 0;
        for (auto is_infection : infection_node) {
            if (is_infection) {
                result++;
            }
        }

        answer = max(answer, result);
        return;
    }


    vector<int> cur_infection_node;
    auto infection = [&](int type){
        const int infection_node_size = static_cast<int>(infection_node.size());
        for (int idx = 0; idx < infection_node_size; idx++) {
            bool is_infection = false;
            if (infection_node.at(idx)) {
                vector<pair<int,int>> edges = graph.at(idx);
                for (auto edge : edges) {
                    if (edge.second == type) {
                        if (infection_node.at(edge.first)) continue;
                        cur_infection_node.push_back(edge.first);
                        infection_node.at(edge.first) = true;
                        is_infection = true;
                    }
                }
            }

            if (is_infection) idx = -1;
        }
    };

    auto immunity = [&](int type){
        for (auto node : cur_infection_node) {
            infection_node.at(node) = false;
        }
        cur_infection_node.clear();
    };

    // A
    infection(1);
    pipe(k - 1, infection_node, graph, answer);
    immunity(1);

    // B
    infection(2);
    pipe(k - 1, infection_node, graph, answer);
    immunity(2);

    // C
    infection(3);
    pipe(k - 1, infection_node, graph, answer);
    immunity(3);
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;

    vector<bool> infection_node(n, false);
    infection_node.at(infection - 1) = true;

    vector<vector<pair<int, int>>> graph = make_graph(edges, n);

    pipe(k, infection_node, graph, answer);

    return answer;
}