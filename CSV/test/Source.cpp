#include <iostream>
#include <string>

#include <fstream>
#include <sstream>

#include <locale>
#include <cstdlib>

using namespace std;

void Show2(int data[], int no[], string name[], int length);
void Bubble_tset(int data[], int no[], string name[], int length);
bool file_load(wstring F_name, int sort_data[], int no[], string name[]);


int main()
{
	//Seito* t;
	wcout.imbue(locale(""));
	wcin.imbue(locale(""));
	cout << "5B ��" << endl;

	int sort_data[11];
	int no[11];
	string name[11];


	//CSV�t�@�C���̓ǂݍ���
	file_load(L"Book1.csv", sort_data,no,name);
	Bubble_tset(sort_data, no, name, 11);
	Show2(sort_data, no, name, 10);


	int i;
	cin >> i;

}



void Bubble_tset(int data[], int no[], string name[], int length){

	int i, j, max, no_max;
	string name_max;
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



//---------------------
//�����L���O�\�[�g�p�\��
//---------------------
void Show2(int data[], int no[], string name[], int length) {

	for (int i = 0; i < length; i++) {

		cout << i + 1 << "�ʁ@" << data[i] << "�_�@-�@";
		cout << name[i];
		cout << " - " << no[i] << "��" << endl;

	}
	cout << " " << endl;

}

//---------------
//CSV�t�@�C���̓ǂݍ���
//�����F�F�ǂݍ��ރt�@�C����
//�߂�l::false�ǂݍ��݃G���[
//�@�@�@::true�ǂݍ��ݐ���
//---------------
bool file_load(wstring F_name,int sort_data[],int no[],string name[]){
	ifstream ifs(F_name);//�t�@�C���p�X����t�@�C���I�u�W�F�N�g���쐬
	if(!ifs){
		cout << "�t�@�C���ǂݍ��݃G���[" << endl;
		return false;
	}
	int j=0;
	string str = "";
	while (getline(ifs, str)) {//�t�@�C������1�s�ǂݍ���
		
		string tmp = "";
		istringstream stream(str);
		cout << str <<"---------------"<< endl;
		
		int i= 0;
		while(getline(stream,tmp,',')){//3���ڂ�','�ŋ�؂�Ȃ���ǂݍ���
			//�����f�[�^���t�@�C���̒��g�Ɠ���ւ���<<<<
			
			if(i==0){
			//cout << atoi(tmp.c_str());//�����f�[�^�𐮐��^�ɕϊ�  789,12,�c��

			cout << tmp << endl;
			sort_data[j] = atoi(tmp.c_str());
			}

			if(i==1){
				//cout << atoi(tmp.c_str());//�����f�[�^�𐮐��^�ɕϊ�  789,12,�c��

				cout << tmp << endl;
				no[j]=atoi(tmp.c_str());
			}

			if(i==2){
				//cout << atoi(tmp.c_str());//�����f�[�^�𐮐��^�ɕϊ�  789,12,�c��

				cout << tmp << endl;
				name[j] = tmp;
			}
			i++;
			
		}
		j++;
	}
	

	return true;

}





