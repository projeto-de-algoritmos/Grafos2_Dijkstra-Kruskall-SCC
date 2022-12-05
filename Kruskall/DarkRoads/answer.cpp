#include <iostream>
#include <vector>
#include <algorithm>

#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
using namespace std;
typedef long long ll;

struct UnionFind{
  vector<int> f, setSize;
  int cantSets;
  void init(int n){
    f.clear();
    setSize.clear();
    cantSets = n;
    f.resize(n, -1);
    setSize.resize(n, 1);
  }
  int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }
  bool join(int i, int j){
    bool con = comp(i) == comp(j);
    if (!con){
      cantSets--;
      setSize[comp(j)] += setSize[comp(i)];
      setSize[comp(i)] = setSize[comp(j)];
      f[comp(i)] = comp(j);
    }
    return con;
  }
} uf;

struct Edge
{
  int a, b, w;
};
bool operator<(const Edge &a, const Edge &b) { return a.w < b.w; }
vector<Edge> E;
int n;

ll kruskal(){
  ll cost = 0;
  sort(E.begin(), E.end());
  uf.init(n);
  forall(it, E)
  {
    if (uf.comp(it->a) != uf.comp(it->b))
    {
      uf.join(it->a, it->b);
      cost += it->w;
    }
  }
  return cost;
}

int main(){
  unsigned qtdCruzamentos, qtdRuas;
  cin >> qtdCruzamentos >> qtdRuas;
  unsigned long total = 0;

  while (qtdCruzamentos != 0 && qtdRuas != 0){
    total = 0;
    n = qtdCruzamentos;
    E.clear();
    for (unsigned i = 0; i < qtdRuas; i++){
      int x, y, z;
      cin >> x >> y >> z;
      Edge edge;
      edge.a = x;
      edge.b = y;
      edge.w = z;
      E.push_back(edge);
      total += z;
    }

    ll econ;
    econ = kruskal();
    cout << total - econ << endl;
    cin >> qtdCruzamentos >> qtdRuas;
  }
  return 0;
}
