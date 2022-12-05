    #include<iostream>
    #include<vector>
    #include<queue>

    using namespace std;

    const int MAXN=1e5+5;
    int n,m,k;
    int a[MAXN];
    int nxt[MAXN];
    struct node{
    	int v,w,nt;
    }e[MAXN<<3];
    int tmp=0;
    int cnt[MAXN],dis[MAXN];
    priority_queue<pair<int,int> >q;
    
    void add_edge(int u,int v,int w) {
    	tmp++;
    	e[tmp].v=v;
    	e[tmp].w=w;
    	e[tmp].nt=nxt[u];
    	nxt[u]=tmp;
    }

    void dijkstra() {
    	q.push(make_pair(0,1));
    	while(!q.empty()){
    		int d=-q.top().first,p=q.top().second;
    		q.pop();
    		if(!dis[p]) {
                dis[p]=d,cnt[p]=1;
            }
    		else if(dis[p]==d){
                cnt[p]++;
                continue;
            }
    		else {
                continue;
            }
    		
            dis[p]=d;
    		
            for(int i=nxt[p];i;i=e[i].nt) {
    			int v=e[i].v,w=e[i].w;
    			q.push(make_pair(-d-w,v));
    		}
    	}
    	return;
    }
    int main(){
    	int u,v,w;
    	cin>>n>>m>>k;
    	for(int i=1;i<=m;i++) {
    		cin>>u>>v>>w;
    		add_edge(u,v,w);
    		add_edge(v,u,w);
    	}
    	for(int i=1;i<=k;i++) {
    		cin>>v>>w;
    		add_edge(1,v,w);
    		add_edge(v,1,w);
    	}
    	
        dijkstra();
    	
        int ans=0;
    	for(int i=2*m+1;i<=tmp;i+=2)
    		if(e[i].w>dis[e[i].v]){
                ans++;
            }
    		else if(cnt[e[i].v]>1) {
                ans++;
                cnt[e[i].v]--;
            }
    	cout<<ans<<endl;
    	return 0;
    } 