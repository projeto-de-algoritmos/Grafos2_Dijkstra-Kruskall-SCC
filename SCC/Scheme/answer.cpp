#include <iostream>
#include <vector>

using namespace std;

#define llint long long int

using ii = pair<llint, llint>;

const llint N = 100005;

bool check = false, vis[N];

llint g[N], in[N];

vector<llint> from, to;

llint n, cnt;

llint dfs(llint u)
{
    vis[u] = 1;

    if (!vis[g[u]]){
        return dfs(g[u]);
    }

    return u;
}

int main(){
    cin >> n;

    for (llint i = 1; i <= n; i++){
        cin >> g[i];
        in[g[i]]++;
    }

    for (llint i = 1; i <= n; i++){
        if (in[i] == 0)
        {
            check = true;
            cnt++;
            from.push_back(i);
            to.push_back(dfs(i));
        }
    }

    for (llint i = 1; i <= n; i++){
        if (!vis[i])
        {
            cnt++;
            from.push_back(i);
            to.push_back(dfs(i));
        }
    }

    if (!check and cnt == 1){
        cout << 0;
        return 0;
    }

    for (llint i = 0; i < from.size(); i++){
    }

    cout << cnt << "\n";

    for (llint i = 0; i < cnt; i++){
        cout << to[i] << " " << from[(i + 1) % cnt] << "\n";
    }

    return 0;
}
