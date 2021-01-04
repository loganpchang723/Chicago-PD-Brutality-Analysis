#include <fstream>
// #include <iostream>
#include <limits>
#include <cmath>

typedef std::numeric_limits< double > dbl;
#include "helper.h"

#define RES 10000
#define cv(x) ((int) ((x) - 0.5))

// ifstream fin ("beatclean.txt");
ifstream fin ("bgclean.txt");
// ofstream fout ("beatmap.txt");
ofstream fout ("bgmap.txt");
ofstream cout ("coutput.out");

string grid [RES][RES];
vector<pair<string, vector<vector<pdd>>>> stor;

bool is_valid(pdd pt) {
    int a = cv(pt.first);
    int b = cv(pt.second);
    return (0 <= a && a < RES && 0 <= b && b < RES);
}

void floodfill (pdd pt, int stind) {
    double mv [4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    vector<pdd> stack;
    stack.emplace_back(pt);
    grid[cv(pt.second)][cv(pt.first)] = (stor[stind].first).substr(5);
    while (!stack.empty()) {
        pdd cur = stack[stack.size()-1];
        stack.pop_back();
        for (int i = 0; i < 4; i++) {
            pdd neigh = make_pair(cur.first+mv[i][0], cur.second+mv[i][1]);
            if (!is_valid(neigh) || grid[cv(neigh.second)][cv(neigh.first)].size()
                || !pnpoly((stor[stind].second)[0], neigh)) continue;
            bool good = true;
            for (int j = 1; j < (stor[stind].second).size(); j++)
                if (pnpoly((stor[stind].second)[j], neigh)) {good = false; break;}
            if (good) {
                stack.emplace_back(neigh);
                grid[cv(neigh.second)][cv(neigh.first)] = (stor[stind].first).substr(5);
            }
        }
    }
}

int main() {
    // this should be good
    int N, M, K;
    double x, y, minx = INF, miny = INF, maxx = -INF, maxy = -INF;
    double scal_x = cos(41.866101999807483*M_PI/180.); // 1 representative point
    string nm;
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> nm >> M;
        vector<vector<pdd>> cur;
        for (int j = 0; j < M; j++) {
            cur.emplace_back(vector<pdd>());
            fin >> K;
            for (int k = 0; k < K-1; k++) { // K-1, assuming start pt repeats
                fin >> x >> y;
                x *= scal_x;
                y = -y;
                cur[j].emplace_back(make_pair(x,y));
                minx = min(minx, x);
                miny = min(miny, y);
                maxx = max(maxx, x);
                maxy = max(maxy, y);
            }
            fin >> x >> y;
        }
        stor.emplace_back(make_pair(nm, cur));
    }
    // double scale = RES/max(maxy-miny, maxx-minx);
    // double xtran = -minx*scale;
    // double ytran = -miny*scale;

    // 26421.739924803642 1730348.5694561952 1110321.5995987393

    double scale = 26421.739924803642;
    double xtran = 1730348.5694561952;
    double ytran = 1110321.5995987393;

    cout.precision(dbl::max_digits10);
    cout << scale << ' ' << xtran << ' ' << ytran << '\n';
    // actual algorithm
    int ct = 0;
    for (int i = 0; i < N; i++) {
        // converting
        double minx = INF, miny = INF, maxx = -INF, maxy = -INF;

        for (int j = 0; j < (stor[i].second).size(); j++) for (int k = 0; k < (stor[i].second)[j].size(); k++) {
            (stor[i].second)[j][k].first = scale * (stor[i].second)[j][k].first + xtran;
            minx = min(minx, (stor[i].second)[j][k].first);
            maxx = max(maxx, (stor[i].second)[j][k].first);
            (stor[i].second)[j][k].second = scale * (stor[i].second)[j][k].second + ytran;
            miny = min(miny, (stor[i].second)[j][k].second);
            maxy = max(maxy, (stor[i].second)[j][k].second);
        }

        // heuristic for if inside
        if ((maxx < 0) || (minx > RES)
            || (maxy < 0) || (miny > RES)) continue;

        // finding a valid inner pt
        int trials = 0;
        pdd pt;
        while (true) {
            trials++;
            if (trials == 100) break;
            pt = genpt_in((stor[i].second)[0], 1, 0.5);
            if (!is_valid(pt) || grid[cv(pt.second)][cv(pt.first)].size()) continue;
            bool good = true;
            for (int j = 1; j < (stor[i].second).size(); j++) 
                if (pnpoly((stor[i].second)[j], pt)) {good = false; break;}
            if (good) break;
        }
        if (trials == 100) continue;
        floodfill(pt, i);
    }

    // print to file
    for (int i = 0; i < RES; i++) {
        for (int j = 0; j < RES; j++) {
            if (grid[i][j].size()) fout << grid[i][j];
            else fout << "-------";
            if (j != RES-1) fout << ' ';
        }
        fout << '\n';
    }
}


// Quick test:

    // vector<pdd> poly;
    // poly.emplace_back(make_pair(1,1));
    // poly.emplace_back(make_pair(0,4));
    // poly.emplace_back(make_pair(1,3));
    // poly.emplace_back(make_pair(6,2));
    // poly.emplace_back(make_pair(1,2));
    // for (int i = 0; i < 10; i++) {
    //     pdd ans = genpt_in(poly, 1, 0);
    //     cout << ans.first << ' ' << ans.second << '\n';
    // }

        // vector<pdd> poly;
    // poly.emplace_back(make_pair(0,2));
    // poly.emplace_back(make_pair(1,0));
    // poly.emplace_back(make_pair(1,2));
    // poly.emplace_back(make_pair(6,2));
    // poly.emplace_back(make_pair(1,3));
    // poly.emplace_back(make_pair(0,4));
    // poly.emplace_back(make_pair(-2,3));
    // for (int i = 0; i < 5; i++) {
    //     pdd ans = genpt_in(poly, 1, 0.5);
    //     cout << ans.first << ' ' << ans.second << '\n';
    // }