#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("ILP.in","w",stdout);
	srand((unsigned)time(NULL));
	int n=100, m=100;
	int x[1000],c[200];
	int ab[1000][200];
	int z=0;
	int r=1000;//range
	
	for(int t=1;t<=1;t++)
	{
		for(int i=1;i<=n;i++) 
		{
			x[i]=rand()%r; //随机一个解，解范围在0~r之内
			c[i]=r-rand()%(2*r);//c，范围在-r~r内
			z+=c[i]*x[i];
		} 
		for(int j=1;j<=m;j++)//按行生成符合的a和b 
		{
			int value=0;
			for(int i=1;i<=n;i++)
			{
				ab[j][i]=2*r-rand()%(3*r);
				value+=ab[j][i]*x[i];
			}
			ab[j][n+1]=value+rand()%(3);
		}
		
		//cout<<"第"<<t<<"组"<<endl; 
		cout<<n<<" "<<m<<endl;
		for(int i=1;i<=n;i++)
			cout<<c[i]<<" ";
		cout<<endl;
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n+1;i++)
			{
				cout<<ab[j][i]<<" ";
			}
			cout<<endl;
		}
		
		cout<<endl<<z<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
