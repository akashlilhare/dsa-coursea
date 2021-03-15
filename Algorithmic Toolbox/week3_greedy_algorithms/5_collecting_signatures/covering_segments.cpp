#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

<<<<<<< HEAD
using namespace std;

struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
    sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b) -> bool {
        return a.end < b.end;
    });

    vector<int> points; 
    int point = segments[0].end; 
    points.push_back(point);

    for (int i = 1; i < segments.size(); ++i) {
        if (point < segments[i].start || point > segments[i].end) { 
            point = segments[i].end; 
            points.push_back(point);
        }
    }

    return points;
}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        cin >> segments[i].start >> segments[i].end;
    }

    vector<int> points = optimal_points(segments);

    cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        cout << points[i] << " ";
    }
    return 0;
}
=======
using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
>>>>>>> eecc4387e852d46461d27b9fddba0c632269b313
