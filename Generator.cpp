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
			x[i]=rand()%r; //���һ���⣬�ⷶΧ��0~r֮��
			c[i]=r-rand()%(2*r);//c����Χ��-r~r��
			z+=c[i]*x[i];
		} 
		for(int j=1;j<=m;j++)//�������ɷ��ϵ�a��b 
		{
			int value=0;
			for(int i=1;i<=n;i++)
			{
				ab[j][i]=2*r-rand()%(3*r);
				value+=ab[j][i]*x[i];
			}
			ab[j][n+1]=value+rand()%(3);
		}
		
		//cout<<"��"<<t<<"��"<<endl; 
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
