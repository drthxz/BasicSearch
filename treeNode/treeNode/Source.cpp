#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void Tree_find();
void Node_Disp(int n);

int sp=9;
struct tnode{
	int left;//���p�̃|�C���^�[
	string name;
	int right;//�E�p�̃|�C���^�[
};

struct  tnode a[20]=	{
	{2,"miyagi",1},//root 
	{-1,"saitama",5},
	{-1,"chiba",3},
	{4,"kanagawa",-1},
	{6,"ibaraki",2},
	{-1,"tochigi",7},
	{-1,"gunma",-1},
	{-1,"tokyo",8},
	{-1,"yamanashi",-1},
	//�ǉ��f�[�^-----
	//{-1,"yamaguchi",-1}//�ǉ�
};
int main()
{
	cout<<"��"<<endl<<endl;
	Tree_find();
	int in_key;
	cin>>in_key;
}

//---------------�֐�-----------
//-----------------
//����
//-----------------
void Tree_find(){

	Node_Disp(sp);
	string key;
	int old;
	int poin;//�|�C���^�[�Ɠ���
	int flag;//�����t���O
	cout<<"�ǉ�����f�[�^��---->";
	cin>>key;
	poin=0;flag=0;
	while(poin!=-1){
	//�Ō�̏ꏊ�ۑ�
	//�Ō��-1�̏ꏊ��T���I
		old=poin;
		//���̃f�[�^�z��Ɉړ�
		if(key>a[old].name){
				//�E�����؂ֈړ�
				poin=a[poin].right;
		}else{
				//�������؂ֈړ�
				poin=a[poin].left;
		}
	}
	//�V�m�[�h��ǉ����A�ڑ�
	a[sp].left=a[sp].right=-1;
	a[sp].name=key;
	if(key<=a[old].name){
		a[old].left=sp;
	}else{
		a[old].right=sp;
	}

	//�z��̍Ō�Ɍ������쐬
	//��f�[�^�[�[���E����9
	//���f�[�^�[�[��������9
	Node_Disp(sp);


	//�c���[�f�[�^�̌���
	cout<<"�T���e�[�^�́H"<<endl<<endl;
	cin>>key;
	poin=0; flag=0;
	while(poin!=-1){
		if(key==a[poin].name){//�����H�H
			cout<<"�z���"<<poin<<"�ԖڂɌ�����܂���"<<endl;
			flag=1;
			break;
		}
		//���̃f�[�^�z��Ɉړ�
		else	if(key>a[poin].name){
				//�E�����؂ֈړ�
				poin=a[poin].right;
		}else{
				//�������؂ֈړ�
				poin=a[poin].left;
		}
		

	}
	if(flag==0){cout<<"�f�[�^�Ȃ�"<<endl;}
}

//display
void Node_Disp(int n){
	for(int i=0; i<n;i++){
		cout<<setw(4)<<a[i].left<<"-";
		cout<<setw(12)<<a[i].name<<"-";
		cout<<setw(4)<<a[i].right<<":"<<endl;
	}
}