#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 10;
const int MAX_DEPTH = 18;
const int INF = 0x3f3f3f3f;

template<typename T>
T read() {
	T result = 0;int f = 1;int c = getchar();
	while(c > '9' || c < '0') {if(c == '-') f *= -1;c = getchar();}
	while(c <= '9' && c >= '0') {result = result * 10 + c - '0';c = getchar();}
	return result * f;
}

struct Graph {
	struct Edge {
		int next,to;
	};
	Edge edges[MAXN * 2];
	int tot,heads[MAXN];

	Graph() : tot(0) {
		memset(heads,-1,sizeof(heads));
	}

	void addEdge(int u,int v) {
		edges[tot].next = heads[u];
		edges[tot].to = v;
		heads[u] = tot++;
	}
} graph;

int depth[MAXN];

namespace TreapSpace {
	const int MAX_NODE_SIZE = 2e6 + 10;
	int ch[MAX_NODE_SIZE][2],val[MAX_NODE_SIZE],pri[MAX_NODE_SIZE],siz[MAX_NODE_SIZE],sZ;

	struct Treap {
		typedef pair<int,int> DRoot;

		int root;

		Treap() : root(0) { }

		void clear() {
			root = 0;
		}

		int newNode(int v) {
			int sign = ++sZ;
			val[sign] = v;
			pri[sign] = rand();
			siz[sign] = 1;
			ch[sign][0] = 0;
			ch[sign][1] = 0;
			return sign;
		}

		void upd(int now) {
			siz[now] = siz[ch[now][0]] + siz[ch[now][1]] + 1;
		}

		int merge(int a,int b) {
			if(a == 0) return b;
			if(b == 0) return a;
			if(pri[a] > pri[b]) {
				ch[a][1] = merge(ch[a][1],b);
				upd(a);
				return a;
			}else {
				ch[b][0] = merge(a,ch[b][0]);
				upd(b);
				return b;
			}
		}

		DRoot split(int now,int k) {
			DRoot result(0,0);
			if(now == 0) return result;
			if(k <= siz[ch[now][0]]) {
				result = split(ch[now][0],k);
				ch[now][0] = result.second;
				upd(now);
				result.second = now;
			}else {
				result = split(ch[now][1],k - siz[ch[now][0]] - 1);
				ch[now][1] = result.first;
				upd(now);
				result.first = now;
			}
			return result;
		}

		int lowCnt(int v) {
			int now = root,result = 0;
			while(now != 0) {
				if(val[now] < v) {
					result += siz[ch[now][0]] + 1;
					now = ch[now][1];
				}else {
					now = ch[now][0];
				}
			}
			return result;
		}

		void insert(int v) {
			int cnt = lowCnt(v),newNodeSign = newNode(v);
			DRoot tmp = split(root,cnt);
			root = merge(tmp.first,merge(newNodeSign,tmp.second));
		}

		int getResult(int k) {
			if(siz[root] < k) return INF;
			DRoot tmp = split(root,k - 1),tmp1 = split(tmp.second,1);
			int result = val[tmp1.first];
			root = merge(tmp.first,merge(tmp1.first,tmp1.second));
			return result;
		}

		void travel(int now) {
			if(now == 0) return;
			travel(ch[now][0]);
			insert(val[now]);
			travel(ch[now][1]);
		}

		int size() {
			return siz[root];
		}

		static Treap merge(Treap a,Treap b) {
			if(a.size() < b.size()) {
				b.travel(a.root);
				a.clear();
				return b;
			}else {
				a.travel(b.root);
				b.clear();
				return a;
			}
		}

	};
}

int n,m,fathers[MAXN][MAX_DEPTH + 1];

void getInfo(int now,int father) {
	depth[now] = depth[father] + 1;
	fathers[now][0] = father;
	for(int i = 1;i <= MAX_DEPTH;i++) {
		fathers[now][i] = fathers[fathers[now][i - 1]][i - 1];
	}
	for(int i = graph.heads[now];i != -1;i = graph.edges[i].next) {
		Graph::Edge &tmpEdge = graph.edges[i];
		if(tmpEdge.to == father) continue;
		getInfo(tmpEdge.to,now);
	}
}

int getLCA(int u,int v) {
	if(u == v) return u;
	if(depth[u] > depth[v]) {
		swap(u,v);
	}
	for(int i = MAX_DEPTH;i >= 0;i--) {
		if(depth[fathers[v][i]] >= depth[u]) {
			v = fathers[v][i];
		}
	}
	if(u == v) return u;
	for(int i = MAX_DEPTH;i >= 0;i--) {
		if(fathers[v][i] != fathers[u][i]) {
			v = fathers[v][i];
			u = fathers[u][i];
		}
	}
	return fathers[v][0];
}

struct Info {
	int type,node;

	Info() : type(0) , node(0) { }

	Info(int type,int node) : type(type) , node(node) { }
};

struct Query {
	int v,k,sign;

	Query() { }

	Query(int v,int k,int sign) : v(v) , k(k) , sign(sign) { }
};

vector<Info> infos[MAXN];
vector<Query> querys[MAXN];

void addQuery(int v,int k,int i) {
	querys[v].push_back(Query(v,k,i));
}

int results[MAXN];

using TreapSpace::Treap;

Treap treaps[MAXN];

void getResult(int now,int father) {
	treaps[now] = Treap();
	for(int i = graph.heads[now];i != -1;i = graph.edges[i].next) {
		Graph::Edge &tmpEdge = graph.edges[i];
		if(tmpEdge.to == father) continue;
		getResult(tmpEdge.to,now);
		treaps[now] = Treap::merge(treaps[now],treaps[tmpEdge.to]);
	}
	for(vector<Info>::iterator it = infos[now].begin();it != infos[now].end();it++) {
		Info &tmpInfo = *it;
		treaps[now].insert(tmpInfo.node);
	}
	for(vector<Query>::iterator it = querys[now].begin();it != querys[now].end();it++) {
		Query &tmpQuery = *it;
		results[tmpQuery.sign] = max(0,depth[now] - treaps[now].getResult(tmpQuery.k));
	}
}

int main() {
	n = read<int>(),m = read<int>();
	for(int i = 0;i < n - 1;i++) {
		int u = read<int>(),v = read<int>();
		graph.addEdge(u,v);
		graph.addEdge(v,u);
	}
	getInfo(1,0);
	for(int i = 1;i <= m;i++) {
		int x = read<int>(),y = read<int>();
		int lca = getLCA(x,y);
		if(lca == y)swap(x,y);
		infos[y].push_back(Info(0,depth[lca]));
		if(lca != x) infos[x].push_back(Info(0,depth[lca]));
	}
	int q = read<int>();
	for(int i = 1;i <= q;i++) {
		int v = read<int>(),k = read<int>();
		addQuery(v,k,i);
	}
	getResult(1,0);
	for(int i =1;i <= q;i++) {
		printf("%d\n",results[i]);
	}
	return 0;
}
