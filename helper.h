#include <cstdlib>
#include <vector>
using namespace std;

#define pdd pair<double,double>
#define INF 999999999

int pnpoly(vector<pdd>& poly, pdd pt) {
  int i, j, c = 0;
  for (i = 0, j = poly.size()-1; i < poly.size(); j = i++) {
    if ( ((poly[i].second>pt.second) != (poly[j].second>pt.second)) &&
     (pt.first < (poly[j].first-poly[i].first) * (pt.second-poly[i].second) / (poly[j].second-poly[i].second) + poly[i].first) )
       c = !c;
  }
  return c;
}

// Adapted from: https://stackoverflow.com/questions/11716268/point-in-polygon-algorithm

pdd genpt_in(vector<pdd>&poly, double inc, double pad) {
    double minx = INF;
    double miny = INF;
    double maxx = -INF;
    double maxy = -INF;
    for (pdd& pt: poly) {
        minx = min(minx, pt.first);
        miny = min(miny, pt.second);
        maxx = max(maxx, pt.first);
        maxy = max(maxy, pt.second);
    }
    minx = inc * ((int) ((minx+inc-1) / inc));
    miny = inc * ((int) ((miny+inc-1) / inc));
    maxx = inc * ((int) (maxx / inc));
    maxy = inc * ((int) (maxy / inc));
    int xnum = (maxx-minx)/inc;
    int ynum = (maxy-miny)/inc;
    int ts = 0;
    while (true) {
        ts++;
        pdd pt = make_pair(minx+pad+inc*(rand()%xnum), miny+pad+inc*(rand()%ynum));
        if (pnpoly(poly, pt)) return pt;
        if (ts == 100) return make_pair(-INF,-INF);
    }
}