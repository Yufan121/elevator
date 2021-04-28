#include <iostream>
#include <string>
#include "elevator.h"
using namespace std;

elevator::elevator(int mf)
{
    int i;
    maxfloor=mf;
    run_status=0;//���ݳ�ʼ״̬�ڵ�һ��
    now_floor=1;
    counts=1;
    for(i=1; i<=mf; i++)
    {
        button[i]=0;
        floor[i]=0;
        eout[i]=0;
    }
}
elevator::~elevator()
{
}
void elevator::set_status(int flag)
{
    run_status=flag;
}
void elevator::set_now(int fl)
{
    now_floor=fl;
}
void elevator::set_button(int i,int flag)
{
    button[i]=flag;
}
void elevator::set_out(int i,int flag)//1�����ߣ�2������
{
    elevator::eout[i]=flag;
}
void elevator::set_floor(int i,int flag)
{
    elevator::floor[i]=flag;
}
int elevator::get_status()
{
    return run_status;
}
int elevator::get_now()
{
    return now_floor;
}
int elevator::get_out(int i)
{
    return elevator::eout[i];
}

int elevator::get_button(int i)
{
    return button[i];
}
int elevator::get_floor(int i)
{
    return elevator::floor[i];
}

void elevator::inoperate(int i)
{
    int fl;
    cout<<"����������ڳ˿Ͱ�����Ҫ�����¥�㣡"<<endl;
    cout<<"���¥���м��ÿո���������������밴0��";
    while(1)
    {
        cin>>fl;
        if(fl==0)
        {
            break;
        }
        p[counts].from_floor=i;
        p[counts].to_floor=fl;
        p[counts].in_floor=1;
        p[counts].id='A'+counts-1;
        counts++;
        elevator::set_floor(fl,1);//Ҫ�����¥��
        set_button(fl,1);//���õ����ڵ���ʾ��ť
    }

}


void elevator::outoperate()//�ڵ����ⲿ��������ʱ����û�г˿��ϵ���
{
    int fl;
    cout<<"������ⲿ�˿Ͱ�������¥�����¥�źţ�"<<endl;
    cout<<"���¥���ÿո���������������밴0��";
    while(1)
    {
        cin>>fl;
        if(fl==0)
        {
            break;
        }
        if(elevator::get_out(fl)==2)//���Ѿ��������µ��ź�
        {
            elevator::set_out(fl,3);
        }
        else
        {
            elevator::set_out(fl,1);//1������
        }
    }
    cout<<"������ⲿ�˿Ͱ�������¥�����¥�źţ�"<<endl;
    cout<<"���¥���ÿո���������������밴0��";
    while(1)
    {
        cin>>fl;
        if(fl==0)
        {
            break;
        }
        if(elevator::get_out(fl)==1)//���Ѿ��������ϵ��ź�
        {
            elevator::set_out(fl,3);
        }
        else
        {
            elevator::set_out(fl,2);//2������
        }
    }
}

