#include <iostream>
using namespace std;

// left upper -> left lower

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
const int path_len = 48;
int p[path_len];
bool onpath[9][9]; // add border to 7x7 -> 9x9

int tryPath(int pathIdx, int curR, int curC) {
    if((onpath[curR][curC-1] && onpath[curR][curC+1]) &&
        (!onpath[curR-1][curC] && !onpath[curR+1][curC]))
        return 0;
    if((onpath[curR-1][curC] && onpath[curR+1][curC]) &&
        (!onpath[curR][curC-1] && !onpath[curR][curC+1]))
        return 0;

    if (curR == 7 && curC == 1) {  // reached endpoint before visiting all
		if (pathIdx == path_len) return 1;
		return 0;
	}

	if (pathIdx == path_len) return 0;

    int ret = 0;
    onpath[curR][curC] = true;

    if (p[pathIdx] < 4) {
		int nxtR = curR + dr[p[pathIdx]];
		int nxtC = curC + dc[p[pathIdx]];
		if (!onpath[nxtR][nxtC]) ret += tryPath(pathIdx + 1, nxtR, nxtC);
	}
	// see Java solution for optimization 4 implementation
	else {  // iterate through all four possible turns
		for (int i = 0; i < 4; i++) {
			int nxtR = curR + dr[i];
			int nxtC = curC + dc[i];
			if (onpath[nxtR][nxtC]) continue;
			ret += tryPath(pathIdx + 1, nxtR, nxtC);
		}
	}
	// reset and return
	onpath[curR][curC] = false;
	return ret;
}

int main() {
    string line; getline(cin , line);

    for(int i=0; i<path_len; i++) {
        char c = line[i];
        if(c=='U') p[i]=0;
        else if(c=='R') p[i]=1;
        else if(c=='D') p[i]=2;
        else if(c=='L') p[i]=3;
        else p[i]=4;
    }
    for(int i=0; i<9; i++) {
        onpath[0][i]=true;
        onpath[8][i]=true;
        onpath[i][0]=true;
        onpath[i][8]=true;
    }
    
    int startIdx = 0, startR = 1, startC = 1;
    int ans = tryPath(startIdx, startR, startC);
    cout << ans << "\n";
}