
/*

��������ģʽ
GOOD�������˼򵥹���ģʽ�в����ؿ��ţ����ԭ�򡣹�������ģʽ��ѡ����
���Ƶ��˿ͻ���ȥʵ�֣����������¹��ܾͲ����޸�ԭ�����ֱ࣬���޸Ŀͻ��˼��ɡ�

*/


#include<iostream>
#include "LeiFengFactory.h"
#include "StudentLeiFengFactory.h"
#include "VolenterFactory.h"

using namespace std;


int main(int argc, char **argv)
{
	LeiFengFactory * lfFactory = new VolenterFactory();
	LeiFengFactory * lfFactory2 = new StudentFactory();
	LeiFeng* lf = lfFactory->CreateLeiFeng();
	lf->Sweep();
	delete lf;

	lf = lfFactory2->CreateLeiFeng();
	lf->Sweep();

	delete lf;
	delete lfFactory;
	delete lfFactory2;

	system("pause");
	return 0;
}