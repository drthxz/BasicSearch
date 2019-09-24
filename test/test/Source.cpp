#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <random>

using namespace std;

void EX_01();
void EX_02();
void EX_03();
void Tree_Meory();
struct tnode *gentree(struct tnode *p, char *w);
void Tree_Level(struct tnode *p);

struct tnode {
	tnode *left;//���p�̃|�C���^�[
	char name[12];//name�̒����@�@char�͒����������
	tnode *right;//�E�p�̃|�C���^�[
};
struct tnode *talloc(void) {//�L���̈�̊l��
	return (struct tnode *)malloc(sizeof(struct tnode));
}


wchar_t msg2[] = L"���҂�����˂�͂ꂡ�Ԃ����ڂ�>";
int main()
{	
	locale::global(locale("japanese"));
	cout << "08_���I�n" << endl;

	//EX_01();
	//EX_02();
	EX_03();

	int key;
	cin >> key;

}
int k = 0;

void EX_01() {
	int i, j;
	int key[1519];
	int flag;

	for (i = 2; i <= 100000; ++i) {
		flag = 0;
		for (j = 2; j < i; ++j) {
			if (i%j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			key[k] = i;
			
			
			printf("%d , ", i);
			k++;
			if (k == 1519) {
				cout << endl;
				break;
			}
		}
		
	}

	cout << "[�f����1515���ږڂ���5�̈�̈ʂ͏��Ԃ�]" << endl;
	for (i = 1514; i < 1519; i++) {
		cout << to_string(key[i]).substr(4, 1)+", ";
	}
	cout << endl << "[�Í�����]"<<msg2[1] << endl;
	cout << "[�Í�����ǂ������͂�]" << endl;

}

string key="y";
void EX_02() {
	string monster[] = {"�喂���]�[�}","����","���ɂ���ڂ�" ,"�M�K���e�X" ,"�L���[�p���T�[","�X���C��" };
	float count[] = { 1,2,15,30,50 };
	float kakuri[5];
	random_device rnd;
	mt19937 mt(rnd());
	
	while (key == "y") {
		cout << "---�����X�^�[��--------------�m��--------------1���񒆂ɏo����" << endl;
		for (int i = 0; i < 5; i++) {
			normal_distribution<> norm(count[i], 0.3f);
			kakuri[i] = norm(mt);
			cout << "   " << monster[i] << "            : ";
			printf("%.1f", kakuri[i]);
			cout<< "[%]               " << round(kakuri[i] * 100) << "/10000" << endl;
		}
		
		cout <<endl << "[��L�̊m���ŌĂяo���ꂽ�����X�^�[��]" << endl;
		//cout<< <<endl;
		cout << "�����܂����H[y/n]---->" << endl;
		cin >> key;
	}
	
}

void EX_03() {

	Tree_Meory();
	
}
int i=0;
void Tree_Meory()
{
	//���I�������m��---------
	char dat[20];//���̓f�[�^�ۑ�
	struct tnode *root, *p, *old;
	string name[128];
	//loop node ����
	root = talloc();//�������m��
	cout << "�����́H�@----��" << flush;
	cin >> root->name;
	name[i]= root->name;
	root->left = NULL;
	root->right = NULL;
	old = NULL;
	while (true) {
		i++;
		cout << "�����́H�@----��" << flush;
		cin >> dat;
		name[i] = dat;
		p = root;
		if (strcmp(dat, "9999") == 0) { break; }
		//�I���́H
		while (p != NULL) {
			old = p;
			if (strcmp(dat, p->name) <= 0) { p = p->left;}
			//strcmp(dat�� p->name)=��1���� < ��2�����@�̏ꍇ�̓}�C�i�X�̒l
													//��1���� > ��2�����@�̏ꍇ�̓v���X�̒l
													//��1���� = ��2�����@�̏ꍇ��0
			else { p = p->right; }
		}
		//���ʂ���������q����
		p = talloc();//�V�����f�[�^�p�̓��I�������m��
		strcpy_s(p->name, dat);//���Oset      strcpy_s(�R�s�[��̃A�h���X, �R�s�[���̃A�h���X)
		p->left = NULL;
		p->right = NULL;
		if (strcmp(dat, old->name) <= 0) {
			old->left = p;
		}
		else {
			old->right = p;
		}
	}
	//�ŏ��m�[�h�̒T��
	p = root;
	while (p->right != NULL) { p = p->right; }
	cout << "--------------�傫�����ɕ\��-----------" << endl;
	/*for (int i = 0; i < name->length, i++;) {
		cout << name[i] << endl;
	}*/
	
	cout << "--------------���x���\��-----------" << endl;
	Tree_Level(root);
}

void Tree_Level(struct tnode *p) {
	struct tnode *q[128],//�|�C���^�[�B�e�[�u��
		*w[128];//��Ɨp
	int i, child, n, level;
	child = 1; q[0] = p; level = 0;//�����ݒ�
	do {
		n = 0;
		printf("level    %d  :", level);
		for (i = 0; i < child; i++) {
			printf("%12s", q[i]->name);//�m�[�h�̕\��
			//1���̃��x���̎q�ւ̃|�C���^�[���X�^�b�N�ɐς�
			if (q[i]->left != NULL) {
				w[n++] = q[i]->left;
			}
			if (q[i]->right != NULL) {
				w[n++] = q[i]->right;
			}
		}
		printf("\n");
		child = n;//1���̃��x���̎q�̐�
		for (i = 0; i < child; i++) {
			q[i] = w[i];
		}
		level++;
	} while (child != 0);
}

struct tnode *gentree(struct tnode *p, char *w){
	if(p==NULL){
		p=talloc();
		strcpy_s(p->name,w);
		p->left=p->right=NULL;
	}else if(strcmp(w,p->name)<0){
		p->left=gentree(p->left,w);
	}else{
		p->right=gentree(p->right,w);
	}
	return p;
}
