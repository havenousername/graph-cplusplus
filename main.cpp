#include <iostream>
#include "graph/Graph.h"
#include "enums/GraphTypeEnum.h"
#include "exception"
#include <vector>

using std::cout;
using std::endl;

int main() {
    Graph graph(GraphTypeEnum::ARRAY_BASED);
    graph.add(802);
    graph.add(302);
    graph.add(1002);
    graph.add(101);
    cout << "Empty adj. matrix" << endl;
    graph.print();
    try
    {
        graph.connect(101, 302, 2);
        graph.connect(101, 802, 6);
        graph.connect(302, 802, 3);
        graph.connect(302, 1002, 5);
        graph.connect(802, 1002, 1);
        cout << "Not empty adj. matrix" << endl;
        graph.print();

//        graph.empty();
//        cout << "Empty graph:" << endl;
//        graph.print();
        int dj = graph.shortestPath<int>(802, 302);
        std::vector<int> djs = graph.shortestPath<std::vector<int>>(802, 302);

        cout << "--------" << endl;
        cout << "Shortaest path graph: " <<  dj << endl;
        cout << "--------" << endl;
        cout << "Shortest path tree from A = 101 to D = 1002: " << endl;
        for (auto j : djs) {
            cout << j << " ";
        }
        cout << endl;
    }
    catch (std::exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
