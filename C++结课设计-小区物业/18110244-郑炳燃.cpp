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
	cout<<"\t\t��                     ��ӭ����               ��"<<endl;
	cout<<"\t\t��                                            ��"<<endl;
	cout<<"\t\t��               С����ҵ�ѹ���ϵͳ           ��"<<endl;
	cout<<"\t\t------------------------------------------------"<<endl;
	system("pause");//����
	system("cls");//��ͣ
	menu();
}

class family//������family
{
	public:
		char name[20];//��������
		char xingbie[4];//
		char shenfenzhenghao[20];//
		char number[20];//��ϵ��ʽ
		int louhao;  // ¥��          
		int danyuan;//��Ԫ��
		int huhao;//����
		int pingfang;//���
		int danjia;//ÿƽ����ҵ�۸�
		int yingjiaona;//Ӧ���ɵ���ҵ��
		char beizhu[20];//��ע
		family()//���캯��
		{}
		~family()
		{}
		void input();
};

void family::input()//���ⶨ���ຯ��
{
	cout<<"\t\t�����뻧������:";
	char nam[20];
	cin>>nam;
	strcpy(name,nam);
	cout<<"\t\t�����뻧���Ա�:";
	char xb[20];
	cin>>xb;
	strcpy(xingbie,xb);//strcpy�����ݸ��Ƹ����Ա
	cout<<"\t\t�����뻧�����֤��:";
	char sfzh[20];
	cin>>sfzh;
	strcpy(shenfenzhenghao,sfzh);
	cout<<"\t\t��������ϵ�绰:";
	char num[20];
	cin>>num;
	strcpy(number,num);
	cout<<"\t\t������ס��¥��:";
	int lou;cin>>lou;louhao=lou;
	cout<<"\t\t�����뵥Ԫ��:";
	int dan;cin>>dan;danyuan=dan;
	cout<<"\t\t�����뻧��:";
	int hu;cin>>hu;huhao=hu;
	cout<<"\t\t������ƽ����:";
	int pf;cin>>pf;
	pingfang=pf;
	cout<<"\t\t������ÿƽ����ҵ��:";
	int pfwyf;cin>>pfwyf;
	danjia=pfwyf;
	int yjnwyf = pf*pfwyf;
	yingjiaona=yjnwyf;
	cout<<"\t\t�����뱸ע:";
	char bz[20];
	cin>>bz;
	strcpy(beizhu,bz);
}

void menu()//�˵�
{
	int choice;
	do
	{
		cout<<endl;
		cout<<"\t\t\t--------  ��ӭ����  ------"<<endl;
		cout<<"\t\t\t|                          ������      |"<<endl;
		cout<<"\t\t\t|           С����ҵ����ϵͳ       ��  |"<<endl;
		cout<<"\t\t\t|                         ������       |"<<endl;
		cout<<"\t\t\t|      ***     1-¼����Ϣ     ***������|"<<endl;
		cout<<"\t\t\t|      ***     2-�����Ϣ     ***������|"<<endl;
		cout<<"\t\t\t|      ***     3-�޸���Ϣ     ***������|"<<endl;
		cout<<"\t\t\t|      ***     4-��ѯ��Ϣ     ***������|"<<endl;
		cout<<"\t\t\t|      ***     5-ɾ����Ϣ     ***������|"<<endl;
		cout<<"\t\t\t|      ***     6-�˳�ϵͳ     ***������|"<<endl;
		cout<<"\t\t\t|                                  ����|"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"ѡ���������(1-6):";       
		cin>>choice;
		system("cls");
		if(choice>6||choice<1) 
			cout<<"**�������Ӧ����1-6֮��!!!\n"<<endl;
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
family home[50];//����������

void read()//���
{
	cout<<"��С������ס����Ϣ����:"<<endl;
	cout<<"***************************************************************************************************************************\n";
	for(int j=0;home[j].huhao>0;j++)
	{
		cout.setf(ios::left);
		cout<<"��������:"<<setw(6)<<home[j].name;
		cout.setf(ios::left);
		cout<<"�����Ա�:"<<setw(6)<<home[j].xingbie;
		cout.setf(ios::left);
		cout<<"���֤��:"<<setw(6)<<home[j].shenfenzhenghao;
		cout.setf(ios::left);
		cout<<"  ��ϵ�绰:"<<setw(15)<<home[j].number;
		cout.setf(ios::left);
		cout<<"  ¥��:"<<setw(5)<<home[j].louhao;
		cout.setf(ios::left);
		cout<<"  ��Ԫ:"<<setw(5)<<home[j].danyuan;
		cout.setf(ios::left);
		cout<<"  ����:"<<setw(5)<<home[j].huhao;
		cout<<"  ƽ��:"<<setw(5)<<home[j].pingfang;
		cout.setf(ios::left);
		cout<<"  ����:"<<setw(5)<<home[j].danjia;
		cout.setf(ios::left);
		cout<<" Ӧ����:"<<setw(5)<<home[j].yingjiaona;
		cout.setf(ios::left);
		cout<<"  ��ע:"<<setw(5)<<home[j].beizhu;//
		cout<<endl;
	}
	cout<<"***************************************************************************************************************************\n";
	cout<<"��ʾ���!"<<endl;

	system("pause");
	system("cls");
	menu();
}

void write()
{
	bool zzr = true;//��������Ϊ1
	while(zzr)
	{
		int sdf =home[0].huhao;//home[i].huhao>0
		for(int i=0;i<=50;i++)
		{
			home[i].input();
			cout<<"\n\t<y>-����¼�� <������>-����˵�"<<endl;
			cout<<"\t��ѡ��:";
			char b;
			cin>>b;
			if(b=='y') 
				continue;//ֻ��������ѭ��
			if(b!='y')
			{
				zzr = false;//������0
				break;
			}
		}
	}

	system("cls");
	menu();
}

void modify()//�޸�
{
	int d;
	do
	{
		cout<<"��������Ҫ�޸ĵ��û�����,�Իس�����"<<endl;
		char y[20];
		cin>>y;
		for(int j=0;j<50;j++)
		{
			if(strcmp(home[j].name,y)==0)
			{
				cout<<"����������:";
				cin>>home[j].name;
				cout<<"�������Ա�:";
				cin>>home[j].xingbie;
				cout<<"���������֤��:";
				cin>>home[j].shenfenzhenghao;
				cout<<"��������ϵ��ʽ:";
				cin>>home[j].number;
				cout<<"������¥��:";
				cin>>home[j].louhao;
				cout<<"�����뵥Ԫ:";
				cin>>home[j].danyuan;
				cout<<"�����뻧��:";
				cin>>home[j].huhao;
				cout<<"������ƽ��:";
				cin>>home[j].pingfang;
				cout<<"�����뵥��:";
				cin>>home[j].danjia;
				cout<<"�����뱸ע:";
				cin>>home[j].beizhu;
				break;
			}
			if(j==50) 
			{
				system("cls");
				cout<<"�Բ���û�и�ס��,������ѡ�����蹦��"<<endl;
				system("pause");
				menu();
			}
		}
		cout<<"�޸���ɣ������޸�<y>----����˵�<n>"<<endl;
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

void del()//ɾ��
{
	int e;
	do{
		cout<<"��������Ҫɾ���Ļ�������:";
		char z[20];
		cin>>z;
		for(int j=0;j<50;j++)
		{
			if(j==50)
			{
				cout<<"û�и�ס��!!�޷�ɾ��!"<<endl;
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
		cout<<"ɾ���ɹ�!~\n"<<endl;
		cout<<"*******************"<<endl;
		cout<<"*  <y>-����ɾ��   *"<<endl;
		cout<<"*  <n>-����˵�   *"<<endl;
		cout<<"*******************"<<endl;
		cout<<"��ѡ��:";
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

void find()//��ѯ
{
	cout<<"------------------------"<<endl;
	cout<<"��   1-���������ֲ�ѯ   ��"<<endl;
	cout<<"��   2-��ס��¥�Ų�ѯ   ��"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"��ѡ�� 1��2:";
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
				cout<<"�������ѯ�Ļ�������:";
				cin>>y;
				for(int j=0;j<50;j++)
					if(strcmp(home[j].name,y)==0)
					{
						cout<<"��ѯ�����û���Ϣ����\n"
							<<"��������:"<<home[j].name
							<<" �Ա�:"<<home[j].xingbie
							<<" ���֤��:"<<home[j].shenfenzhenghao
							<<" ¥��:"<<home[j].louhao
							<<" ��Ԫ:"<<home[j].danyuan
							<<" ����:"<<home[j].huhao<<"  "
							<<" ƽ��:"<<home[j].pingfang
							<<" ����:"<<home[j].danjia
							<<" Ӧ��:"<<home[j].yingjiaona
							<<" �绰:"<<home[j].number<<endl;
						cout<<"*********************************************************************"<<endl;
						flag=1;
					}
					if(flag==0) 
					{
						cout<<"�Բ���!��Ҫ��ѯ��ס��������!"<<endl;
						cout<<"�Ƿ�������˵�<y>-- ������ѯ<n>"<<endl;
					}
					else 
					{

						cout<<"��ѯ���!~���Ƿ�������˵�<y>-- ������ѯ<n>"<<endl;
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
				cout<<"�������ѯ��¥��:";
				cin>>z;	

				for(i=0;i<50;i++)
					if(home[i].louhao==z) 	
					{
						cout<<z<<"��¥���û���Ϣ����"<<endl;
						
							cout<<"��ѯ�����û���Ϣ����\n"
							<<"��������:"<<home[i].name
							<<" �Ա�:"<<home[i].xingbie
							<<" ���֤��:"<<home[i].shenfenzhenghao
							<<" ¥��:"<<home[i].louhao
							<<" ��Ԫ:"<<home[i].danyuan
							<<" ����:"<<home[i].huhao<<"  "
							<<" ƽ��:"<<home[i].pingfang
							<<" ����:"<<home[i].danjia
							<<" Ӧ��:"<<home[i].yingjiaona
							<<" �绰:"<<home[i].number<<endl;
						cout<<"*********************************************************************"<<endl;
						flag=1;
					}	
					if(flag==0) 
					{
						cout<<"�Բ���!��Ҫ��ѯ��ס��������!"<<endl;
						cout<<"�Ƿ�������˵�<y>-- ������ѯ<n>"<<endl;
					}
					else 
					{

						cout<<"��ѯ���!~���������˵�<y>-- ������ѯ<n>"<<endl;
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
