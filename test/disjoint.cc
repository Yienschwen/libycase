#include <iostream>

#include "include/ds.h"

using namespace std;
using namespace ycpp;

int main() {
	char cmd;
	disjoint<int> dsMain;
	while (cin >> cmd) {
		if (cmd == 'm') {
			int x;
			cin >> x;
			dsMain.make_set(x);
		}
		else if (cmd == 'u') {
			int x, y;
			cin >> x >> y;
			dsMain.merge_val(x, y);
		}
		else if (cmd == 'f') {
			int x;
			cin >> x;
			cout << dsMain.find_set(x) << '\n';
		}
	}
	return 0;
}
