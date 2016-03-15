#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
	int start, end;
	bool operator<(const Segment &rhs) const { return end < rhs.end;}
};

vector<int> optimal_points(vector<Segment> &segments) {

	std::sort(segments.begin(), segments.end());
	vector<int> points;
	points.push_back(segments[0].end);
	//write your code here
	for (size_t i = 1; i < segments.size(); ++i) {
		if ((points.back() != segments[i].end) &&  ( (segments[i].end - points.back()) > (segments[i].end - segments[i].start))  ) {
			points.push_back(segments[i].end);
		}
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
