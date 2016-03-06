//此程序用来实现四则运算自动出题，范围包括整数、真分数
//王永维，2016、3、5

#include<iostream>
using namespace std;
void main()
{
	int fenshuRand;//真分数或整数
	int numRand1,numRand2;   //运算数
	int fuhaoRand; //运算符号
	int count;     //产生的式子个数
	for(count=0;count<30;count++)
	{
		//输出题号
		cout<<"\t("<<count+1<<")\t";
			
		//选择运算数是真分数或者整数
		fenshuRand=rand()%2+1;

		//产生第一个数
		if(fenshuRand==1)// fenshuRand 为1 为整数
		{
			numRand1=rand()%100+1;
			cout<<numRand1;
		}
		if(fenshuRand==2)// fenshuRand 为2 为真分数
		{
			numRand1=rand()%100+1;
			numRand2=rand()%100+1;
			if(numRand1<numRand2)
				cout<<"("<<numRand1<<"/"<<numRand2<<")";
			else
				cout<<"("<<numRand2<<"/"<<numRand1<<")";
		}
		//产生运算符号
		fuhaoRand=rand()%4+1;
		if(fuhaoRand==1)
			cout<<" ＋ ";
		else if(fuhaoRand==2)
			cout<<" － ";
		else if(fuhaoRand==3)
			cout<<" × ";
		else
			cout<<" ÷ ";

		//产生第二个数
		fenshuRand=rand()%2+1;
		if(fenshuRand==1)// fenshuRand 为1 为整数
		{
			numRand1=rand()%100+1;
			cout<<numRand1;
		}
		if(fenshuRand==2)// fenshuRand 为2 为真分数
		{
			numRand1=rand()%100+1;
			numRand2=rand()%100+1;
			if(numRand1<numRand2)
				cout<<"("<<numRand1<<"/"<<numRand2<<")";
			else
				cout<<"("<<numRand2<<"/"<<numRand1<<")";

		}
		cout<<"="<<endl;
	}
}