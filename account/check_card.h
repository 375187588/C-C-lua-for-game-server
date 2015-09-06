#include <iostream>
#include <string>
using namespace std;

int IsRight(string card);
bool BirthdayIsRight(string cardId);
bool NameIsRight(string name);
int GetDay(int year,int month);

int IsRight(string card)
{
	int error=0;
	int length=(int)card.length();
	int index=card.find_first_not_of("1234567890X");
	if(index!=(int)card.npos)
	{
		error=-1;  //�������з������ַ�
	}else
	{
		if(!BirthdayIsRight(card))
		{
			error=-4; //�������´���
		}else
		{
			if(length==18)     //��֤18λ���֤����
			{
				int no[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
				char id[]={'1','0','X','9','8','7','6','5','4','3','2'};

				const char *p=card.c_str();
				int i=0,wi=0,sum=0;
				for(;i<length-1;i++)
				{
					wi=(*(p+i)-'0')*no[i];
					sum+=wi;
				}
				if(*(p+i)<'0'||*(p+i)>'9')
				{
					if (*(p+i)!='X'&&*(p+i)!='x')
					{
						error=-2;//���֤���һλ�������
						return error;
					}
				}
				wi=sum%11;
				if(*(p+17)=='x'||*(p+17)=='X')            //���һλΪ'x'��'X';
				{
					if(id[wi]!='x'&&id[wi]!='X')
						error=-3;
				}
				else if(id[wi]!=*(p+17))     //�жϼ���������֤У�����������Ƿ����
				{
					error=-3;
				}
			}
		}
	}
	return error;
}
//�ж����֤�����е��������Ƿ���ȷ
bool BirthdayIsRight(string cardId)
{
	string year,month,day;
	time_t tt = time(nullptr);
	tm * p_tm = gmtime(&tt);

	bool flag=false;
	int length=cardId.length();
	if(length==18)
	{
		year=cardId.substr(6,4);//ȡ18λ���֤�е���
		if( (1900+p_tm->tm_year)-atoi(year.c_str())<18 )	//����18��
			return false;
		month=cardId.substr(10,2); // ��
		day=cardId.substr(12,2);   //��
	}
	else
	{
		year=cardId.substr(6,2);//ȡ15λ���֤�е���
		if( p_tm->tm_year-atoi(year.c_str())<18 )	//����18��
			return false;
		month=cardId.substr(8,2); // ��
		day=cardId.substr(10,2);   //��
		year="19"+year;
	}
	//
	if(atoi(year.c_str())==0||atoi(month.c_str())==0||atoi(day.c_str())==0)
	{
		flag=false;
	}
	else if(GetDay(atoi(year.c_str()),atoi(month.c_str()))>=atoi(day.c_str()))
	{
		flag=true;
	}
	return flag;
}
//�õ�ָ������µ�����
int GetDay(int year, int month)
{
	int day=0;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		{
			day=31;
			break;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		{
			day=30;
			break;
		}
	case 2:
		{
			if( (year%4==0&&year%100!=0) || year%400==0 )
				day=29;
			else
				day=28;
			break;
		}
	default:
		{
			day=-1;
			break;
		}
	}
	return day;
}
bool NameIsRight(string name)
{
	// utf8
	int name_len = name.length();
	if( name_len%3 != 0 )
		return false;
	for(int i=0; i<name_len; i+=3 )
	{
		if( name.at(i) > 0 )
			return false;
	}
	return true;
}
