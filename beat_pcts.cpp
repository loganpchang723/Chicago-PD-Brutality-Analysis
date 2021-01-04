#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

ifstream fin1 ("Data/Beat Stuff/beathh_new.txt");
ifstream fin2 ("Data/Beat Stuff/beathi_raw.txt");
ofstream fout ("coutput.out");
string name;
double stat, jk;

map<string,double> pop;
map<string,double> hi;

vector<pair<string,double>> output;

int main() {
    int N, M;
    fout << fixed << showpoint << setprecision(10);
    fin1 >> N;
    for (int i = 0; i < N; i++) {
        fin1 >> name >> stat;
        pop[name] = stat;
    }
    fin2 >> M;
    for (int i = 0; i < M; i++) {
        fin2 >> name >> stat;
        hi[name] = stat;
    }
    for (auto it = hi.begin(); it != hi.end(); it++) {
        if (!pop.count(it->first)) continue;
        name = it->first;
        stat = it->second/pop[it->first];
        output.emplace_back(make_pair(it->first, stat));
    }
    fout << output.size() << '\n';
    for (int i = 0; i < output.size(); i++) {
        fout << output[i].first << ' ' << output[i].second << '\n';
    }
}