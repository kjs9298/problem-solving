#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// (position x, (left/right, rect_no))
typedef pair<int, pair<int, int> > Event;

struct Rect {
	int x1, y1, x2, y2;
	Rect(int _x1, int _y1, int _x2, int _y2) :
		x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

int unionArea(vector<Rect>& rects) {
	if (rects.empty()) {
		return 0;
	}

	vector<Event> events;
	vector<int> pos_ys;

	for (int i = 0; i < rects.size(); ++i) {
		Rect rect = rects[i];

		pos_ys.push_back(rect.y1);
		pos_ys.push_back(rect.y2);
		events.push_back(Event(rect.x1, make_pair(1, i)));
		events.push_back(Event(rect.x2, make_pair(-1, i)));
	}

	sort(events.begin(), events.end());

	sort(pos_ys.begin(), pos_ys.end());
	pos_ys.erase(unique(pos_ys.begin(), pos_ys.end()), pos_ys.end());

	vector<int> counts(pos_ys.size() - 1, 0);

	long long ret = 0;

	for (int i = 0; i < events.size() - 1; ++i) {
		int x = events[i].first;
		int cnt = events[i].second.first;
		int rect_no = events[i].second.second;

		int y1 = rects[rect_no].y1, y2 = rects[rect_no].y2;

		for (int j = 0; j<pos_ys.size(); ++j) {
			if (y1 <= pos_ys[j] && pos_ys[j] < y2) {
				counts[j] += cnt;
			}
		}

		long long cut_len = 0;
		for (int j = 0; j < pos_ys.size() - 1; ++j) {
			if (counts[j] > 0) {
				cut_len += pos_ys[j + 1] - pos_ys[j];
			}
		}
		ret += cut_len * (events[i + 1].first - x);
	}

	if (ret > 2147483647) {
		return -1;
	}
	else {
		return ret;
	}
}

int solution(int K, int L, int M, int N, int P, int Q, int R, int S) {

	vector<Rect> rects;
	rects.push_back(Rect(K, L, M, N));
	rects.push_back(Rect(P, Q, R, S));

	return unionArea(rects);
}

int main() {
	
	int K, L, M, N, P, Q, R, S;
	cin >> K >> L >> M >> N >> P >> Q >> R >> S;
	cout << solution(K, L, M, N, P, Q, R, S) << endl;

}