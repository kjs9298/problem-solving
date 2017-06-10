#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// (x좌표, (왼쪽/오른쪽, 사각형번호))
typedef pair<int, pair<int, int> > Event;

struct Rectangle {
	int x1, y1, x2, y2;
	Rectangle() {}
	Rectangle(int _x1, int _y1, int _x2, int _y2) :
		x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

int unionArea(vector<Rectangle>& rects) {
	if (rects.empty()) {
		return 0;
	}

	vector<Event> events;
	vector<int> ys;

	for (int i = 0; i < rects.size(); ++i) {
		Rectangle rect = rects[i];

		ys.push_back(rect.y1);
		ys.push_back(rect.y2);
		events.push_back(Event(rect.x1, make_pair(1, i)));
		events.push_back(Event(rect.x2, make_pair(-1, i)));
	}

	sort(events.begin(), events.end());
	
	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());

	vector<int> counts(ys.size() - 1, 0);
	
	int ret = 0;
	
	for (int i = 0; i < events.size() - 1; ++i) {
		int x = events[i].first;
		int delta = events[i].second.first;
		int rect_no = events[i].second.second;

		int y1 = rects[rect_no].y1, y2 = rects[rect_no].y2;

		for (int j = 0; j<ys.size(); ++j) {
			if (y1 <= ys[j] && ys[j] < y2) {
				counts[j] += delta;
			}
		}

		int cutLength = 0;
		for (int j = 0; j < ys.size() -1; ++j) {
			if (counts[j] > 0) {
				cutLength += ys[j+1] - ys[j];
			}
		}

		ret += cutLength * (events[i + 1].first - x);
	}
	
	return ret;
}


int main() {
	int N; cin >> N; 
	int x1, y1, x2, y2;
	vector<Rectangle> rects;

	while (N--) {
		cin >> x1 >> y1 >> x2 >> y2;
		rects.push_back(Rectangle(x1, y1, x2, y2));
	}

	cout << unionArea(rects) << endl;
}