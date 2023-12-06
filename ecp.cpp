#include <fstream>
#define LGMAX 1001
using namespace std;
char pd[]={'(','[','{'},
     pi[]={')',']','}'},
     s[LGMAX];
int c[]={2,3,5}, p[6];
void evalexp(int);
int main()
{
	ifstream f("ecp.in");
	f >> s; 
	f.close();
	evalexp(0);
	ofstream g("ecp.out");
	g << p[2] << ' ' << p[3] << ' ' << p[5];
	g.close();
	return 0;
}
void evalexp(int i)
{
	if (s[i])
	{
		int j;
		for (j = 0; j < 3 && pd[j] != s[i]; j++);
		if (j == 3) evalexp(i+1);
		else
		{
			int k;
			for (k = 0; k < 3 && pi[k] != s[i+1]; k++);
			if (k == j)
			{
				p[c[j]]++;
				evalexp(i+2);
			}
			else
			{
				p[c[j]] += c[j];
				evalexp(i+1);
			}
		}
	}
}
