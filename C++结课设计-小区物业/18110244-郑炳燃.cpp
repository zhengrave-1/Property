#include<iostream> 
#include<string> 
#include<fstream> 
#include<stdlib.h>
#include<iomanip>
using namespace std;
void write();
void read();
void modify();
void del();
void find();
void menu();

void main()
{
	cout<<"\t\t------------------------------------------------"<<endl;
	cout<<"\t\t◆                     欢迎进入               ◆"<<endl;
	cout<<"\t\t◆                                            ◆"<<endl;
	cout<<"\t\t◆               小区物业费管理系统           ◆"<<endl;
	cout<<"\t\t------------------------------------------------"<<endl;
	system("pause");//清屏
	system("cls");//暂停
	menu();
}

class family//声明类family
{
	public:
		char name[20];//户主姓名
		char xingbie[4];//
		char shenfenzhenghao[20];//
		char number[20];//联系方式
		int louhao;  // 楼号          
		int danyuan;//单元号
		int huhao;//房号
		int pingfang;//面积
		int danjia;//每平米物业价格
		int yingjiaona;//应缴纳的物业费
		char beizhu[20];//备注
		family()//构造函数
		{}
		~family()
		{}
		void input();
};

void family::input()//类外定义类函数
{
	cout<<"\t\t请输入户主名字:";
	char nam[20];
	cin>>nam;
	strcpy(name,nam);
	cout<<"\t\t请输入户主性别:";
	char xb[20];
	cin>>xb;
	strcpy(xingbie,xb);//strcpy把数据复制给类成员
	cout<<"\t\t请输入户主身份证号:";
	char sfzh[20];
	cin>>sfzh;
	strcpy(shenfenzhenghao,sfzh);
	cout<<"\t\t请输入联系电话:";
	char num[20];
	cin>>num;
	strcpy(number,num);
	cout<<"\t\t请输入住户楼号:";
	int lou;cin>>lou;louhao=lou;
	cout<<"\t\t请输入单元号:";
	int dan;cin>>dan;danyuan=dan;
	cout<<"\t\t请输入户号:";
	int hu;cin>>hu;huhao=hu;
	cout<<"\t\t请输入平方数:";
	int pf;cin>>pf;
	pingfang=pf;
	cout<<"\t\t请输入每平方物业费:";
	int pfwyf;cin>>pfwyf;
	danjia=pfwyf;
	int yjnwyf = pf*pfwyf;
	yingjiaona=yjnwyf;
	cout<<"\t\t请输入备注:";
	char bz[20];
	cin>>bz;
	strcpy(beizhu,bz);
}

void menu()//菜单
{
	int choice;
	do
	{
		cout<<endl;
		cout<<"\t\t\t--------  欢迎进入  ------"<<endl;
		cout<<"\t\t\t|                          　　　      |"<<endl;
		cout<<"\t\t\t|           小区物业管理系统       　  |"<<endl;
		cout<<"\t\t\t|                         　　　       |"<<endl;
		cout<<"\t\t\t|      ***     1-录入信息     ***　　　|"<<endl;
		cout<<"\t\t\t|      ***     2-浏览信息     ***　　　|"<<endl;
		cout<<"\t\t\t|      ***     3-修改信息     ***　　　|"<<endl;
		cout<<"\t\t\t|      ***     4-查询信息     ***　　　|"<<endl;
		cout<<"\t\t\t|      ***     5-删除信息     ***　　　|"<<endl;
		cout<<"\t\t\t|      ***     6-退出系统     ***　　　|"<<endl;
		cout<<"\t\t\t|                                  　　|"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"选择所需操作(1-6):";       
		cin>>choice;
		system("cls");
		if(choice>6||choice<1) 
			cout<<"**输入错误，应该在1-6之间!!!\n"<<endl;
	}while(choice>6||choice<1);
	switch(choice)
	{
		case 1:write();break;
		case 2:read();break;
		case 3:modify();break;
		case 4:find();break;
		case 5:del();break;
		case 6:exit(0);break;
	}

}
family home[50];//定义类数组

void read()//浏览
{
	cout<<"该小区所有住户信息如下:"<<endl;
	cout<<"***************************************************************************************************************************\n";
	for(int j=0;home[j].huhao>0;j++)
	{
		cout.setf(ios::left);
		cout<<"户主名字:"<<setw(6)<<home[j].name;
		cout.setf(ios::left);
		cout<<"户主性别:"<<setw(6)<<home[j].xingbie;
		cout.setf(ios::left);
		cout<<"身份证号:"<<setw(6)<<home[j].shenfenzhenghao;
		cout.setf(ios::left);
		cout<<"  联系电话:"<<setw(15)<<home[j].number;
		cout.setf(ios::left);
		cout<<"  楼号:"<<setw(5)<<home[j].louhao;
		cout.setf(ios::left);
		cout<<"  单元:"<<setw(5)<<home[j].danyuan;
		cout.setf(ios::left);
		cout<<"  户号:"<<setw(5)<<home[j].huhao;
		cout<<"  平方:"<<setw(5)<<home[j].pingfang;
		cout.setf(ios::left);
		cout<<"  单价:"<<setw(5)<<home[j].danjia;
		cout.setf(ios::left);
		cout<<" 应缴纳:"<<setw(5)<<home[j].yingjiaona;
		cout.setf(ios::left);
		cout<<"  备注:"<<setw(5)<<home[j].beizhu;//
		cout<<endl;
	}
	cout<<"***************************************************************************************************************************\n";
	cout<<"显示完成!"<<endl;

	system("pause");
	system("cls");
	menu();
}

void write()
{
	bool zzr = true;//布尔类型为1
	while(zzr)
	{
		int sdf =home[0].huhao;//home[i].huhao>0
		for(int i=0;i<=50;i++)
		{
			home[i].input();
			cout<<"\n\t<y>-继续录入 <其他键>-进入菜单"<<endl;
			cout<<"\t请选择:";
			char b;
			cin>>b;
			if(b=='y') 
				continue;//只结束本次循环
			if(b!='y')
			{
				zzr = false;//布尔变0
				break;
			}
		}
	}

	system("cls");
	menu();
}

void modify()//修改
{
	int d;
	do
	{
		cout<<"请输入需要修改的用户名字,以回车结束"<<endl;
		char y[20];
		cin>>y;
		for(int j=0;j<50;j++)
		{
			if(strcmp(home[j].name,y)==0)
			{
				cout<<"请输入名字:";
				cin>>home[j].name;
				cout<<"请输入性别:";
				cin>>home[j].xingbie;
				cout<<"请输入身份证号:";
				cin>>home[j].shenfenzhenghao;
				cout<<"请输入联系方式:";
				cin>>home[j].number;
				cout<<"请输入楼号:";
				cin>>home[j].louhao;
				cout<<"请输入单元:";
				cin>>home[j].danyuan;
				cout<<"请输入户号:";
				cin>>home[j].huhao;
				cout<<"请输入平方:";
				cin>>home[j].pingfang;
				cout<<"请输入单价:";
				cin>>home[j].danjia;
				cout<<"请输入备注:";
				cin>>home[j].beizhu;
				break;
			}
			if(j==50) 
			{
				system("cls");
				cout<<"对不起，没有该住户,请重新选择所需功能"<<endl;
				system("pause");
				menu();
			}
		}
		cout<<"修改完成，继续修改<y>----进入菜单<n>"<<endl;
		char x;
		cin>>x;
		if(x=='n') 
		{
			system("cls");
			menu();
		}

		if(x=='y')
			d=1;
	}while(d==1);
}

void del()//删除
{
	int e;
	do{
		cout<<"请输入需要删除的户主名字:";
		char z[20];
		cin>>z;
		for(int j=0;j<50;j++)
		{
			if(j==50)
			{
				cout<<"没有该住户!!无法删除!"<<endl;
				system("pause");
				menu();
			}
			if(strcmp(home[j].name,z)==0) 
			{	
				int i;
				for(i=j;i<50;i++)
				{
					home[i]=home[i+1];
				}
				break;
			}
		
		}
		cout<<"删除成功!~\n"<<endl;
		cout<<"*******************"<<endl;
		cout<<"*  <y>-继续删除   *"<<endl;
		cout<<"*  <n>-进入菜单   *"<<endl;
		cout<<"*******************"<<endl;
		cout<<"请选择:";
		char x;
		cin>>x;
		if(x=='n') 
		{
			system("cls");
			menu();
		}
		if(x=='y')
			e=1;

	}while(e==1);
}

void find()//查询
{
	cout<<"------------------------"<<endl;
	cout<<"●   1-按户主名字查询   ●"<<endl;
	cout<<"●   2-按住户楼号查询   ●"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"请选择 1或2:";
	int m;
	cin>>m;
	switch(m)
	{
	case 1:
		{
			int e;
			do
			{
				int flag=0;
				char y[20];
				cout<<"请输入查询的户主名字:";
				cin>>y;
				for(int j=0;j<50;j++)
					if(strcmp(home[j].name,y)==0)
					{
						cout<<"查询到的用户信息如下\n"
							<<"户主名字:"<<home[j].name
							<<" 性别:"<<home[j].xingbie
							<<" 身份证号:"<<home[j].shenfenzhenghao
							<<" 楼号:"<<home[j].louhao
							<<" 单元:"<<home[j].danyuan
							<<" 户号:"<<home[j].huhao<<"  "
							<<" 平方:"<<home[j].pingfang
							<<" 单价:"<<home[j].danjia
							<<" 应交:"<<home[j].yingjiaona
							<<" 电话:"<<home[j].number<<endl;
						cout<<"*********************************************************************"<<endl;
						flag=1;
					}
					if(flag==0) 
					{
						cout<<"对不起!您要查询的住户不存在!"<<endl;
						cout<<"是否进入主菜单<y>-- 继续查询<n>"<<endl;
					}
					else 
					{

						cout<<"查询完成!~，是否进入主菜单<y>-- 继续查询<n>"<<endl;
					}
					char x;
					cin>>x;
					if(x=='y') 
					{
						system("cls");
						menu();
					}
					if(x=='n')
						e=1;
			}while(e==1);	
		}break;

	case 2:
		{
			int f;int i;
			do{
				int z;int flag=0;
				cout<<"请输入查询的楼号:";
				cin>>z;	

				for(i=0;i<50;i++)
					if(home[i].louhao==z) 	
					{
						cout<<z<<"号楼的用户信息如下"<<endl;
						
							cout<<"查询到的用户信息如下\n"
							<<"户主名字:"<<home[i].name
							<<" 性别:"<<home[i].xingbie
							<<" 身份证号:"<<home[i].shenfenzhenghao
							<<" 楼号:"<<home[i].louhao
							<<" 单元:"<<home[i].danyuan
							<<" 户号:"<<home[i].huhao<<"  "
							<<" 平方:"<<home[i].pingfang
							<<" 单价:"<<home[i].danjia
							<<" 应交:"<<home[i].yingjiaona
							<<" 电话:"<<home[i].number<<endl;
						cout<<"*********************************************************************"<<endl;
						flag=1;
					}	
					if(flag==0) 
					{
						cout<<"对不起!您要查询的住户不存在!"<<endl;
						cout<<"是否进入主菜单<y>-- 继续查询<n>"<<endl;
					}
					else 
					{

						cout<<"查询完成!~，进入主菜单<y>-- 继续查询<n>"<<endl;
					}
					char x;
					cin>>x;
					if(x=='y')
					{
						system("cls");
						menu();
					}
					if(x=='n')
						f=1;
			}while(f==1);
		}
	}
}
