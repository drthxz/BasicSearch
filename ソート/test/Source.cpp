#include <iostream>
#include <string>

#include <fstream>
#include <sstream>
#include <locale>
using namespace std;

void Sort_Select(int data[], int length);
void Show2(int data[], int no[], wstring name[], int length);
void Show(int data[], int length);
void Bubble_Sort(int data[], int length);
void Insertion_Sort(int data[], int length);
void Stable_Sort(int data[], int no[], int length);
void Stable_Show(int data[], int no[], int length);
void Bubble_tset(int data[], int no[], wstring name[], int length);

void chikuji_search();
void binary_search();
void Merge();

void Hash();
int hash_make(char *s);

//�w�����X�g
struct Seito
{
	char name[20];
	int age;
}*t,*p[11],a[]={
	"tanaka",8,"kato",18,"kojima",28,"suzuki",38,"takahashi",48,
	"tanaka",58,"sato",68,"maeda",78,"ooshima",88,"kobayasi",98,
	"aaaa",9999
};



int main()
{
	//Seito* t;
	wcout.imbue(locale(""));
	wcin.imbue(locale(""));
	cout << "5B ��" << endl;

	//int sort_data[11];
	//int no[11];
	//wstring name[11];

	////�f�[�^���|�C���^�[�Ŏ���
	//for (int i=0;i<10;i++) p[i]=&a[i];
	////for����10�l���̕��ёւ�
	//for(int j=0;j<10-1;j++){
	//	//�������Ɛݒ�
	//	int k2=0;

	//	for(int k=1;k<10;k++){
	//		//�傫���H�������H
	//			k2=k;
	//	}
	//	//����
	//	t=p[j];//���
	//	p[j]=p[k2];//set
	//	p[k2]=t;
	//}

	////���ʕ\��
	//for (int h=0;h<10;h++){
	//	cout<<p[h]->name<<p[h]->age<<endl;
	//
	//}
	
	//chikuji_search();//�O���珇�ԂɒT��
	//binary_search();//2���T��
	//Merge();//�����ɕ���2�g�̃f�[�^��𕹍�����
	//Hash();

	//�\�[�g-------------------------------------------

	
	int sort_data[] = { 50,80,45,31,45,51,2,96,45,200,-1 };//���_  11�Ԗڍ��Ɠ��͐��l�������
	int no[] = { 0, 1, 2, 3, 4, 5,6, 7, 8,  9,-1 };//�N���A�ʐ�
	wstring name[] = { L"��",L"��",L"��",L"��",L"��",L"��",L"��",L"��",L"��",L"��",L"" };

	//Sort_Select------------
	Show(sort_data, 10);
	Sort_Select(sort_data, 10);
	Show(sort_data, 10);
	//Sort_Select------------

	//Stable-------------
	//Stable_Show(sort_data, no, 10);
	//Stable_Sort(sort_data, no, 10);
	//Stable_Show(sort_data, no, 10);
	//Stable_Sort(sort_data, no, 10);
	//StableEnd----------
	
	//Insertion_Sort-----------
	//Show(sort_data, 10);
	//Insertion_Sort(sort_data, 10);
	//Show(sort_data, 10);
	//Insertion_Sort-----------

	//�����L���OBubble-------------
	int Now_data, Now_stage;
	wstring Now_name;

	Show2(sort_data, no, name, 10);
	cout << "���_�́H"; cin >> Now_data;
	cout << "�ʐ��́H"; cin >> Now_stage;
	wcout << L"���O�́H"; wcin >> Now_name;

	//�����L���OOK?
	sort_data[10] = Now_data;
	no[10] = Now_stage;
	name[10] = Now_name;
	
	Bubble_tset(sort_data, no, name, 11);
	Show2(sort_data, no, name, 10);
	
	//�����L���OBubbleEnd------------

	//------------------------------------------------------


	int i;
	cin >> i;

}

//�n�b�V��
void Hash(){
		//�f�[�^�쐬
		const int TableSize=1000;
		const int ModSize=1000;

		struct tel{
				char name[20];
				char telnum[20];
				int enpty;//�g�p��??
		}dat[TableSize];
		//tel*dat[TableSize];
		int n;
		char a[20],b[20];
		cout<<"���͏I����9999	"<<endl;
		//�f�[�^�쐬
		while(true){
				cout<<"���O�����---->";
				cin>>a;
				if(strcmp(a,"9999")==0)break;
				cout<<"�d�b�ԍ������--->";
				cin>>b;
				if(strcmp(b,"9999")==0)break;
				n=hash_make(a);

				while(dat[n].enpty==1 && n<TableSize) n++;//���̏ꏊ
				if(n<TableSize){
					strcpy_s(dat[n].name,a);
					strcpy_s(dat[n].telnum,b);
					dat[n].enpty=1;
				}else{
					cout<<"�e�ʂ𒴂��܂���"<<endl;
				}
		}

		while(true){//���݂��Ȃ����O�̎��̃G���[�����Ȃ��I�I
			cout<<endl;
			cout<<"�T�����O�����----->";
			cin>>a;
			if(strcmp(a,"9999")==0)break;
			n=hash_make(a);
			//suzuki ��sizuki��T��---------	
			//n�ɓ����Ă���f�[�^�̕\��
			cout<<"�n�b�V���ԍ���"<<n;
			cout<<"[���O]"<<dat[n].name<<"[TEL]"<<dat[n].telnum<<endl;
		}
}
int hash_make(char *s){
		const int modSize=1000;
		int n=strlen(s);//������̒��������߂�
		int result=0;
		result=(s[0] - 'A' + (s[n/2-1]-'A') *26  + (s[n-2]-'A') *26 *26 ) %modSize;
		return result;
}

//�����ɕ���2�g�̃f�[�^��𕹍�����
void Merge(){
		int a[]={1,3,5,6,9,14,17,23,46,57};//10
		int b[]={7,13,36,51,100};//5
		int c[15];
		int i,j,p;
		//�}�[�W���
		i=j=p=0;
		while(i<10&&j<5){//a[],b[]�Ƃ��I���łȂ��Ƃ��̃��[�v
				if(a[i]<=b[j]) c[p++]=a[i++];
				else c[p++]=b[j++];
		}
		while(i<10) c[p++]=a[i++];//a[]���I���܂�
		while(j<5) c[p++]=b[j++];//b[]���I���܂�

		//���ʕ\��
		for(int i=0;i<15;i++){
			cout<<c[i]<<" ,";
		}
		cout<<endl;

}

//2���T��(binary search)
//�f�[�^���\�[�g����Ă���̂�����
void binary_search(){
		int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		int  key,low,hight,mid,flag;//low=����0�@hight=���20-1
		int cnt;//���������J�E���g
		cout<<"�������鐔����͂��Ă�������"<<endl;
		cin>>key;

		low=0;hight=20-1;flag=0;cnt=0;
		while(low<=hight){
				cnt++;
				mid=(low+hight)/2;
				if(key==a[mid]){//����!!
						//�z��̉��Ԗڂɂ�������
						//cnt��\��
						cout<<mid+1<<"�Ԗڂɂ���܂���"<<a[mid]<<endl;
						flag=1;//��������flag set
						break;
				}
				//�����ł��Ȃ�!!
				if(a[mid]<key){//
						low=mid+1;
				}else{
						hight=mid-1;
				}	
		}
		if(flag!=1)cout<<"�f�[�^�͂���܂���ł����B"<<endl;
		cout<<cnt<<"�@��̌������[�v�ł���"<<endl;

}

//�O���珇�ԂɒT��
void chikuji_search(){
	char n[20];//���͗p
	cout<<"��������l������͂��Ă�������"<<endl;
	cout<<"��)    tanaka----->"; cin>>n;

	cout<<n<<endl;

	//�Ō�̍\���̂Ɍ����f�[�^�Ɠ����f�[�^��set
	strcpy_s(a[10].name,n);

	int i=0;
	while(strcmp(n,a[i].name)  !=0) i++;
	if(i<10){
	cout<<i+1<<"�Ԗڂɂ��܂���!"<<endl<<a[i].age<<"��"<<endl;
	}else{
	cout<<"��������l���̃f�[�^�͂���܂���ł���"<<endl;
	}

}

//------------
//�I���\�[�g:
//��ԏ��������̂Ɛ擪�����ւ���
//------------

void Sort_Select(int data[],int length){

	
	int i, j, min;

	for(i=0;i<length;i++){
		

		for(int j=0;j<length;j++){
		
			if(data[i]<data[j]){

				//�f�[�^�̌���
				min = data[i];//cope
				data[i] = data[j];
				data[j] = min;
				
			}//for2 end
		
		

		}//for1 end
	}

}


//------------
//�o�u���\�[�g:
//��납�����ւ���
//------------
void Bubble_Sort(int data[], int length){

	int i, j, min;
	for(i=0;i<length-1;i++){
	
		for(j=length -1;j>i;j--){
			//length��1����10�܂ŁAj��0����9�܂�
		
			if(data[j-1]>data[j]){
				
				min = data[j];
				data[j] = data[j - 1];
				data[j - 1] = min;
			
			}
		
		}
	
	}

}

void Bubble_tset(int data[], int no[], wstring name[], int length){

	int i, j, max, no_max;
	wstring name_max;
	for(i=0;i<length;i++){
		
		for(j=length-1;j>i;j--){
			
			if(data[j-1]<data[j]){
				
				max = data[j];
				data[j] = data[j - 1];
				data[j - 1] = max;

				no_max = no[j];
				no[j] = no[j - 1];
				no[j - 1] = no_max;

				name_max = name[j];
				name[j] = name[j - 1];
				name[j - 1] = name_max;
				
			}
		}
	}
}


//------------
//�}���\�[�g:
//�g�����v�݂����ւ���
//------------
void Insertion_Sort(int data[], int length){

	int i, j, min;
	for(i=0;i< length;i++){
		j = i;
		while ((j >= 1)&&(data[j-1]>data[j])){
		
			min = data[j];
			data[j] = data[j - 1];
			data[j - 1] = min;
			j--;

		}
	
	}

}

//------------
//����ȃ\�[�g:
//�����l�����f�[�^����ȏ㑶�݂��Ă���ƁA
//------------
void Stable_Sort(int data[], int no[], int length) {

	int i, j, min, temp;

	for (i = 0; i < length; i++) {


		for (int j = 0; j < length; j++) {

			if (data[i] < data[j]) {

				//�f�[�^�̌���
				min = data[i];//cope
				data[i] = data[j];
				data[j] = min;

				//no�̓���ւ�
				temp = no[i];
				no[i] = no[j];
				no[j] = temp;

			}//for2 end



		}//for1 end

	}
}

void Stable_Show(int data[], int no[], int length) {

	cout << "�_��  ";
	for (int i = 0; i < length; i++) {

		cout << data[i] << " ";


	}

	cout << endl;
	cout << "no    ";
	for (int i = 0; i < length; i++) {

		cout << no[i] << "  ";


	}

	cout << endl;


}





void Show(int data[], int length) {

	cout << "�_���@"<<endl;
	for (int i = 0; i < length; i++) {

		cout << data[i] << " ";

	}

	cout << endl;

}

//---------------------
//�����L���O�\�[�g�p�\��
//---------------------
void Show2(int data[], int no[], wstring name[], int length) {

	for (int i = 0; i < length; i++) {

		cout << i + 1 << "�ʁ@" << data[i] << "�_�@-�@";
		wcout << name[i];
		cout << " - " << no[i] << "��" << endl;

	}
	cout << " " << endl;

}





