#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int N = 210;
struct P {
	double x, y, z;
	P(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}
	void Print() {
		printf("%d %d %d\n", int(x), int(y), int(z));
	}
} p[N];
inline P operator-(P u, P v) { return P(u.x - v.x, u.y - v.y, u.z - v.z); }
inline P Cross(P u, P v) {
	return P(u.y * v.z - u.z * v.y,
			u.z * v.x - u.x * v.z,
			u.x * v.y - u.y * v.x );
}
inline double Dot(P u, P v) {
	return u.x * v.x + u.y * v.y + u.z * v.z;
}
int main() {
	srand(486);
	int n = 0, st = 0;
	while (scanf("%lf%lf%lf", &p[n].x, &p[n].y, &p[n].z) == 3) {
		//p[n].x += eps * (double(rand()) / RAND_MAX);
		//p[n].y += eps * (double(rand()) / RAND_MAX);
		//p[n].z += eps * (double(rand()) / RAND_MAX);
		++n;
	}
	random_shuffle(p, p + n);
	double ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			for (int k = j + 1; k < n; ++k) {
				int sgn = 0;
				P f = Cross(p[k] - p[i], p[j] - p[i]);
				for (int l = 0; l < n; ++l) if (l != i && l != j && l != k) {
					int no = Dot(f, p[l] - p[i]) > 0 ? 1 : -1;
					if (!sgn) {
						sgn = no;
					} else if (sgn != no) {
						sgn = 233;
						break;
					}
				}
				if (sgn != 233) {
					if (!st) st = k;
					ans += abs(Dot(Cross(p[i] - p[st], p[j] - p[st]), p[k] - p[st]));
					cout<<abs(Dot(Cross(p[i] - p[st], p[j] - p[st]), p[k] - p[st]))<<endl;
				}
			}
	printf("%.2lf\n", abs(ans) / 6);
	return 0;
}
