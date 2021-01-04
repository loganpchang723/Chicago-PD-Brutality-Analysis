/*
USAGE: Currently converts a series of percentages to population counts



*/

#include <fstream>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;

#define RES 10000
#define dtct 1
#define ppct 1

ifstream btmp ("beatmap.txt");
ifstream fin ("Data/hhdlist.txt");
// ifstream fin0 ("Data/poplist.txt");
ifstream fin2 ("Data/hilist.txt");
ifstream bgmp ("bgmap.txt");
ofstream cout ("coutput.out");

map<string,double> bgdata;
// map<string,double> pctdata;
map<string,vector<double>> racedata;
map<string,vector<double>> btdata;

int main() {
    double factor = 0.00000680800288898972273;
    int N, M, K;
    string name, a, b;
    double dens;
    fin >> N;
    cout << fixed << showpoint << setprecision(10);
    for (int i = 0; i < N; i++) {
        fin >> name;
        bgdata[name] = 0;
        for (int j = 0; j < ppct; j++) {
            fin >> dens;
            if (j >= 15) continue;
            // dens *= factor;
            bgdata[name] += dens*factor;
        }
        //  >> dens;
        // dens *= factor;
        // bgdata[name] = dens;
    }
    // fin0 >> K;
    // for (int i = 0; i < K; i++) {
    //     fin0 >> name >> dens;
    //     pctdata[name] = dens/100.;
    // }
    fin2 >> M;
    for (int i = 0; i < M; i++) {
        fin2 >> name;
        
        for (int j = 0; j < dtct; j++) {
            fin2 >> dens;
            racedata[name].emplace_back(dens); // /100.
            // racedata[name].emplace_back(1.);
        }
    }
    for (int i = 0; i < RES; i++) {
        for (int j = 0; j < RES; j++) {
            btmp >> a;
            bgmp >> b;
            if (a == "----" || b == "-------") continue;
            if (bgdata.find(b) == bgdata.end()
                || racedata.find(b) == racedata.end()
                /*|| pctdata.find(b) == pctdata.end()*/) continue;
            if (btdata.find(a) == btdata.end()) {
                for (int k = 0; k < dtct; k++) btdata[a].emplace_back(0);
            }
            for (int k = 0; k < dtct; k++) {
                btdata[a][k] += racedata[b][k]*bgdata[b]/**pctdata[b]*/;
            }
        }
    }
    cout << btdata.size() << '\n';
    for (auto it = btdata.begin(); it != btdata.end(); it++) {
        name = (*it).first;
        cout << name << ' ';
        for (int i = 0; i < dtct; i++) {
            cout << (*it).second[i];
            if (i != dtct-1) cout << ' ';
        }
        cout << '\n';
    }

}