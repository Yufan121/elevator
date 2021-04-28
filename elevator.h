#ifndef ELEVATOR_H_INCLUDED
#define ELEVATOR_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;
class cpassenger
{
public:
    int from_floor;//����¥��
    int to_floor;//Ҫȥ¥��
    int in_floor;//�Ƿ��ڵ�����,1�ڣ�0����
    char id;//���
};


class elevator
{
public:
    elevator(int mf=9);//���캯����Ĭ��9��
    ~elevator();
    void set_status(int flag);//���õ��ݵ�ǰ������״̬
    void set_now(int flag);//���õ�ǰ�������ڵ�¥��
    void set_button(int i,int flag);//���õ����ڰ�ť������
    void set_floor(int i,int flag);//1�У�0û��
    void set_out(int i,int flag);//1�����ߣ�2������.3����������������
    int get_floor(int i);//��õ�i���Ƿ��г˿͵������Ϣ
    int get_out(int i);//��õ�i���������Ϣ
    int get_status();//��õ��ݵ�ǰ��״̬
    int get_now();//��õ��ݵ�ǰ��λ��
    int get_button(int i);
    void inoperate(int i);//�����ڲ�����
    void outoperate();
    cpassenger p[100];//Ҫ�������ݵĳ˿�
    int counts;//�����õ��ݳ˿���
private:
    int maxfloor;//����maxfloor��
    int run_status;//��������״̬��1���ϣ�2����,0ֹͣ
    int now_floor;//���ݵ�ǰ����¥��
    int button[10];//¥�㰴ť��1���£�0δ��
    int floor[10];//��Ϣ����,��̬���ݳ�Ա
    int eout[10];//������Ե��������ڵ�¥��
};

class building
{
public:
    building(int mf=9);
    ~building();
    elevator E;
    void dis_b();//��ӡģ��ĵ���ʱ������
    void dis_vew();//��ӡ�����ڲ��Լ������ڲ��İ�ť
    int get_mf();
private:
    int MF;//9��¥
};

#endif // ELEVATOR_H_INCLUDED






