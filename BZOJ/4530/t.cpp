// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 3e5, max_node = maxn;
int n, m, a[maxn];

struct Node {
  Node *ch[2], *fa;
  int sum;
  bool rev;

  inline int dir(void) const {
    return fa->ch[1] == this;
  }

  inline bool is_root(void) const {
    return fa->ch[0] != this && fa->ch[1] != this;
  }

  inline int id(void) const ;

} node[max_node], _null = {&_null, &_null, &_null, 0, false}, *null = &_null;

inline int Node::id(void) const {
  return this - node;
}

const char* S(Node *p) {
  if (p == null) return "null";
  if (p >= node && p < node + n) {
    static char s[10][20];
    static int id = 0;
    id = (id + 1) % 10;
    sprintf(s[id], "%d", (int)(p - node) + 1);
    return s[id];
  }
  return "wild";
}

int cnt_node;

Node* NewNode(void) {
  Node *x = node + cnt_node++;
  x->ch[0] = x->ch[1] = x->fa = null;
  // x->sum = 0;
  x->rev = false;
  return x;
}

void SetFa(Node *x, Node *p, int d) {
  x->fa = p;
  p->ch[d] = x;
}

void Update(Node *x) {
  x->sum = x->ch[0]->sum ^ x->ch[1]->sum ^ a[x->id()];
}

void Reverse(Node *x) {
  // printf("    reverse %s\n", S(x));
  swap(x->ch[0], x->ch[1]);
  // x->ch[0]->rev ^= 1;
  // x->ch[1]->rev ^= 1;
  x->rev ^= 1;
}

void PushDown(Node *x) {
  // printf("    pushdown %s\n", S(x));
  if (x->rev) {
    Reverse(x->ch[0]);
    Reverse(x->ch[1]);
    x->rev = 0;
  }
}

void Rotate(Node *x) {
  //printf("    rotate %s\n", S(x));
  Node *y = x->fa;
  int dx = x->dir();
  if (!y->is_root()) {
    SetFa(x, y->fa, y->dir());
  } else {
    x->fa = y->fa;
  }
  SetFa(x->ch[!dx], y, dx);
  SetFa(y, x, !dx);
  Update(y);
  Update(x);
  // puts("ROT END");
  // void PrintAll();
  // PrintAll();
}

void PushAll(Node *x) {
  if (!x->is_root()) {
    PushAll(x->fa);
  }
  PushDown(x);
}

void Splay(Node *x) {
  // printf("  splay %s\n", S(x));
  PushAll(x);
  while (!x->is_root()) {
    if (x->fa->is_root()) {
      Rotate(x);
    } else if (x->fa->dir() == x->dir()) {
      Rotate(x->fa);
      Rotate(x);
    } else {
      Rotate(x);
      Rotate(x);
    }
  }
  // puts("SPLAY END");
  // void PrintAll();
  // PrintAll();
}

void Access(Node *x) {
  // printf("access %s\n", S(x));
  // void PrintAll();
  // PrintAll();
  for (Node *y = null; x != null; y = x, x = x->fa) {
    Splay(x);
    x->ch[1] = y;
    Update(x);
  }
  // printf("access %s end\n", S(x));
  // PrintAll();
  // puts("");
}

void MakeRoot(Node *x) {
  // printf("makeroot %s\n", S(x));
  Access(x);
  // printf("\nSTAGE 1\n");
  // void PrintAll();
  // PrintAll();
  Splay(x);
  // printf("\nSTAGE 2\n");
  // PrintAll();
  Reverse(x);
}

void Link(Node *x, Node *y) {
  // printf("link %s %s\n", S(x), S(y));
  MakeRoot(x);
  Access(y);
  Splay(y);
  x->fa = y;
  Update(y);
}

void Cut(Node *x, Node *y) {
  MakeRoot(x);
  Access(y);
  Splay(y);
  y->ch[0] = x->fa = null;
  Update(y);
}

int Query(Node *x, Node *y) {
  // printf("query %s %s\n", S(x), S(y));
  MakeRoot(x);
  Access(y);
  Splay(y);
  return y->sum;
}

void Modify(Node *x) {
  MakeRoot(x);
  Splay(x);
  Update(x);
}

void PrintAll(void) {
  for (int i = 0; i < n; ++i) {
    printf("node %d: lc(%s), rc(%s), fa(%s), sum(%d), rev(%d)\n",
           i + 1, S(node[i].ch[0]), S(node[i].ch[1]), S(node[i].fa),
           node[i].sum, node[i].rev);
  }
}

int main(void) {
  // printf("%s %s\n", S(null->ch[0]), S(null->ch[1]));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    NewNode();
    scanf("%d", a + i);
    node[i].sum = a[i];
  }
  for (int i = 0; i < m; ++i) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 0) {
      --x; --y;
      printf("%d\n", Query(node + x, node + y));
    } else if (t == 1) {
      --x; --y;
      MakeRoot(node + x);
      MakeRoot(node + y);
      if (node[x].is_root()) {
        Link(node + x, node + y);
      }
    } else if (t == 2) {
      --x; --y;
      MakeRoot(node + x);
      MakeRoot(node + y);
      if (!node[x].is_root()) {
        Access(node + x);
        Splay(node + x);
        if (node[x].ch[0] == node + y && node[y].ch[1] == null) {
          Cut(node + x, node + y);
        }
      }
    } else {
      --x;
      a[x] = y;
      Modify(node + x);
    }
    // PrintAll();
  }
  return 0;
}
