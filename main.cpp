#include <iostream>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include "elevator.h"
using namespace std;
int mf=9;
building A(mf);//������
void display()
{
    system("cls");
    A.dis_b();
    A.dis_vew();
}
int main()
{
    int i,j;
    int flag1;
    int flag2;
    int flag=1;
    int cnt;
    int cur;//��ǰ��������¥��
    cur=1;
    display();
    cout<<"����ͣ��"<<cur<<"�㣬��˿ͽ������"<<endl;
    A.E.inoperate(1);//����������
    A.E.set_status(1);//����������
    while(1)
    {
        display();
        if(A.E.get_status()==0)
        {
            cout<<"����������Ҳû�����󣬵��ݽ���"<<endl;
            break;
        }
        if(A.E.get_status()==1)//����
        {
            if(flag=0)//���ݴ���תΪ��
            {
                cur=cur+1;
                A.E.set_now(cur);
            }
            flag=1;
            display();
            cout<<"�����������У���Ҫ����"<<cur+1<<"�㣡"<<endl<<endl;
            cur=cur+1;
            A.E.set_now(cur);
            A.E.outoperate();//����������
            while(1)
            {
                if(A.E.get_floor(cur)==0)//û������Ҫ�µ���
                {
                    if(A.E.get_out(cur)==1||A.E.get_out(cur)==3)//���˴��ⲿ����������
                    {
                        display();
                        cout<<"����ͣ��"<<cur<<"�㣬��˿ͽ������"<<endl;
                        if(A.E.get_out(cur)==3)//��������ϵ����󣬻�ʣ�����µ�����
                        {
                            A.E.set_out(cur,2);
                        }
                        else
                        {
                            A.E.set_out(cur,0);//������ɣ��ϵ��ݣ���������
                        }
                        A.E.inoperate(cur);//����������
                    }
                    if(cur<=mf)//����û���ϵ���߲�
                    {
                        display();
                        cout<<"û�г˿���"<<cur<<"�����£����ݼ�����������!"<<endl<<endl;
                        A.E.outoperate();//����������
                        cur=cur+1;
                        A.E.set_now(cur);
                        A.E.set_status(1);//����״̬
                    }
                }
                else if(A.E.get_floor(cur)==1)//���˵�������Ҫ��¥�㣬Ҫ�µ���
                {

                    display();
                    cout<<"����ͣ��"<<cur<<"�㣬��˿��µ���"<<endl;
                    for(i=1; i<=A.E.counts; i++)
                    {
                        if((A.E.p[i].to_floor==cur)&&(A.E.p[i].in_floor==1))
                        {
                            cout<<"��A�����еĵ�"<<i<<"λ�˿��µ���"<<endl;
                            A.E.p[i].in_floor=0;//�µ���
                        }
                    }
                    A.E.set_button(cur,0);//�����i�㣬��i��ָʾ��Ϩ��
                    A.E.set_floor(cur,0);//�ʹ����Ϣ�б����Ƴ�
                    A.E.outoperate();//����������
                    cur=cur+1;
                    A.E.set_now(cur);
                }
                if(A.E.get_out(cur)==1||A.E.get_out(cur)==3)//���˴��ⲿ����������
                {
                    display();
                    cout<<"����ͣ��"<<cur<<"�㣬��˿ͽ������"<<endl;
                    if(A.E.get_out(cur)==3)//��������ϵ����󣬻�ʣ�����µ�����
                    {
                        A.E.set_out(cur,2);
                    }
                    else
                    {
                        A.E.set_out(cur,0);//������ɣ��ϵ��ݣ���������
                    }
                    A.E.inoperate(cur);//����������
                }
                flag1=0;
                flag2=0;
                for(i=cur; i<=mf; i++)
                {

                    if(A.E.get_floor(i)==1||A.E.get_out(i)!=0)//�Ϸ�������
                    {
                        flag1=1;
                        break;
                    }
                }
                for(j=1; j<=cur; j++)
                {
                    if(A.E.get_floor(j)==1||A.E.get_out(j)!=0)//�·�������
                    {
                        flag2=1;
                        break;
                    }
                }
                cnt=0;//������
                for(i=1; i<=mf; i++)
                {
                    if(A.E.get_floor(i)==0&&A.E.get_out(i)==0)
                    {
                        cnt++;
                    }
                }
                if(cnt==mf)
                {
                    A.E.set_status(0);
                    break;
                }
                if(flag1==1)
                {
                    A.E.set_status(1);//��������
                }
                else if(flag2==1)//��������
                {
                    A.E.set_status(2);//��������
                    if(A.E.get_out(cur-1)==2||A.E.get_out(cur-1)==3)
                    {
                        display();
                        cur=cur-1;
                        cout<<"����ͣ��"<<cur<<"�㣬��˿ͽ������"<<endl;
                        if(A.E.get_out(cur)==3)//��������ϵ����󣬻�ʣ�����µ�����
                        {
                            A.E.set_out(cur,1);
                        }
                        else
                        {
                            A.E.set_out(cur,0);//������ɣ��ϵ��ݣ���������
                        }
                        A.E.inoperate(cur);//����������
                    }
                    break;
                }
            }
        }
        else if(A.E.get_status()==2)//��������
        {
            if(flag=1)//���ݴ���תΪ��
            {
                cur=cur-1;
                A.E.set_now(cur);
            }
            flag=0;
            display();
            cout<<"�����������У���Ҫ����"<<cur-1<<"�㣡"<<endl<<endl;
            cur=cur-1;
            A.E.set_now(cur);
            A.E.outoperate();//����������
            while(1)
            {
                if(A.E.get_floor(cur)==0)//û������Ҫ�µ���
                {
                    if(A.E.get_out(cur)==2||A.E.get_out(cur)==3)//���˴��ⲿ����������
                    {
                        system("cls");
                        A.dis_b();
                        A.dis_vew();
                        cout<<"����ͣ��"<<cur<<"�㣬��˿ͽ������"<<endl;
                        if(A.E.get_out(cur)==3)//��������µ����󣬻�ʣ�����ϵ�����
                        {
                            A.E.set_out(cur,1);
                        }
                        else
                        {
                            A.E.set_out(cur,0);//������ɣ��ϵ��ݣ���������
                        }
                        A.E.inoperate(cur);//����������
                    }
                    if(cur>=1)
                    {
                        display();
                        cout<<"û�г˿���"<<cur<<"�����£����ݼ�����������!"<<endl<<endl;
                        A.E.outoperate();//����������
                        cur=cur-1;
                        A.E.set_now(cur);
                        A.E.set_status(2);//����״̬��
                    }

                }
                else if(A.E.get_floor(cur)==1)//����Ҫ��¥
                {
                    display();
                    cout<<"����ͣ��"<<cur<<"�㣬��˿��µ���"<<endl;
                    for(i=1; i<=A.E.counts; i++)
                    {
                        if((A.E.p[i].to_floor==cur)&&(A.E.p[i].in_floor==1))
                        {
                            cout<<"��A�����еĵ�"<<i<<"λ�˿��µ���"<<endl;
                            A.E.p[i].in_floor=0;//�µ���
                        }
                    }
                    A.E.set_button(cur,0);//�����i�㣬��i��ָʾ��Ϩ��
                    A.E.set_floor(cur,0);
                    cur=cur-1;
                    A.E.set_now(cur);
                    A.E.outoperate();//����������
                }
                if(A.E.get_out(cur)==2||A.E.get_out(cur)==3)//���˴��ⲿ����������
                {
                    display();
                    cout<<"����ͣ��"<<cur<<"�㣬��˿ͽ������"<<endl;
                    if(A.E.get_out(cur)==3)//��������µ����󣬻�ʣ�����ϵ�����
                    {
                        A.E.set_out(cur,1);
                    }
                    else
                    {
                        A.E.set_out(cur,0);//������ɣ��ϵ��ݣ���������
                    }
                    A.E.inoperate(cur);//����������
                }
                flag1=0;
                flag2=0;
                for(i=cur; i<=mf; i++)
                {

                    if(A.E.get_floor(i)==1||A.E.get_out(i)!=0)//�Ϸ�������
                    {
                        flag1=1;
                        break;
                    }
                }
                for(j=1; j<=cur; j++)
                {
                    if(A.E.get_floor(j)==1||A.E.get_out(j)!=0)//�·�������
                    {
                        flag2=1;
                        break;
                    }
                }
                cnt=0;//������
                for(i=1; i<=mf; i++)
                {
                    if(A.E.get_floor(i)==0&&A.E.get_out(i)==0)
                    {
                        cnt++;
                    }
                }
                if(cnt==mf)
                {
                    A.E.set_status(0);
                    break;
                }
                if(flag2==1)
                {
                    A.E.set_status(2);//��������
                }
                else if(flag1==1)
                {
                    A.E.set_status(1);//��������
                    break;
                }
            }
        }
    }
    return 0;
}
