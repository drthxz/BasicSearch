#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void Tree_find();
void Tree_Meory();
void Tree_Add();
void Node_Disp(int n);
void Tree_Meory();
struct tnode *gentree(struct tnode *p, char *w);
struct tnode *search(struct tnode *p,char *key);
void Tree_preorder(tnode * tnode);
void Tree_inorder(tnode * tnode);
void Tree_postorder(tnode * tnode);
void Tree_Level(struct tnode *p);

//���I�c���[�p�̍\����
struct tnode{
	tnode *left;//���p�̃|�C���^�[
	char name[12];//name�̒����@�@char�͒����������
	tnode *right;//�E�p�̃|�C���^�[
};
struct tnode *talloc(void){//�L���̈�̊l��
	return (struct tnode *)malloc(sizeof(struct tnode));
}

//�z��c���[�p�̍\����
int sp=9;
struct tnode2{
	int left;//���p�̃|�C���^�[
	string name;//string�͒������ݒ�K�v�Ȃ�
	int right;//�E�p�̃|�C���^�[
};
//�\���̂̔z��
struct  tnode2 a[20]=	{
	//-1=null left�̐�=���̕���
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
	//�z��c���[-----
	//Tree_find();
	//Tree_Add();
	//-----------------
	//���I������
	//Tree_Meory();

	//���I�������m�ۂ̍ċA����
	char dat[20];//���̓f�[�^�ۑ�
	struct tnode *root, *p, *old;
	root=NULL;
	while(true){
		cout << "���̃f�[�^��--->" << flush;
		cin >> dat;
		if (strcmp(dat, "9999") == 0) { cout << "�����l" << endl; break; }
		root=gentree(root,dat);
	}
	Tree_Level(root);
	//Tree_preorder(root);

	////����---
	//cout<<"�T���f�[�^��---->"<<flush;
	//cin>>dat;
	//if((p=search(root,dat))!=NULL){
	//	printf("%s��������܂���\n",dat);
	//}else{
	//	printf("������܂���\n");
	//}

	int in_key;
	cin>>in_key;
}
//����(���x������)
void Tree_Level(struct tnode *p){
	struct tnode *q[128],//�|�C���^�[�B�e�[�u��
						*w[128];//��Ɨp
	int i,child,n ,level;
	child=1; q[0]= p; level=0;//�����ݒ�
	do{
		n=0;
		printf("level    %d  :",level);
		for(i=0;i<child;i++){
			printf("%12s",q[i]->name);//�m�[�h�̕\��
			//1���̃��x���̎q�ւ̃|�C���^�[���X�^�b�N�ɐς�
			if(q[i]->left!=NULL){
				w[n++]=q[i]->left;
			}
			if(q[i]->right!=NULL){
				w[n++]=q[i]->right;
			}
		}
		printf("\n");
		child=n;//1���̃��x���̎q�̐�
		for(i=0;i<child;i++){
			q[i]=w[i];
		}
		level++;
	}
	while(child!=0);
}
//�s������������
void Tree_preorder(tnode * tnode){
	if(tnode==NULL){
		return;
	}else{
		printf("%s\n",tnode->name);
		Tree_preorder(tnode->left);
		Tree_preorder(tnode->right);
	}
}
//�ʂ肪��������
void Tree_inorder(tnode * tnode){
	if(tnode==NULL){
		return;
	}else{
		Tree_inorder(tnode->left);
		printf("%s\n",tnode->name);
		Tree_inorder(tnode->right);
	}
}
//�A�肪��������
void Tree_postorder(tnode * tnode){
	if(tnode==NULL){
		return;
	}else{
		Tree_postorder(tnode->left);
		Tree_postorder(tnode->right);
		printf("%s\n",tnode->name);
	}
}

//�؂̃T�[�`
struct tnode *search(struct tnode *p,char *key){
	if(p==NULL || strcmp(key,p->name)==0){return p;}
	if(strcmp(key,p->name)<0){return search(p->left,key);}
	else{return search(p->right,key);}
}

//���I�������m�ۂ̍ċA������
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

void Tree_Meory()
{
	//���I�������m��---------
	char dat[20];//���̓f�[�^�ۑ�
	struct tnode *root, *p, *old;
	//loop node ����
	root = talloc();//�������m��
	cout << "loop note ��-----��" << flush;
	cin >> root->name;
	root->left = NULL;
	root->right = NULL;
	old = NULL;
	while (true) {
		cout << "���̃f�[�^��--->" << flush;
		cin >> dat;
		p = root;
		if (strcmp(dat, "9999") == 0) { cout << "�����l" << endl; break; }
		//�I���́H
		while (p != NULL) {
			old = p;
			if (strcmp(dat, p->name) <= 0) { p = p->left; }
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
	while (p->left != NULL) { p = p->left; }
	cout << "�ŏ��m�[�h=" << p->name << endl;
	while (p->right != NULL) { p = p->right; }
	cout << "�ő�m�[�h=" << p->name << endl;
}


//---------------�֐�-----------
//-----------------
//����
//-----------------
string key;
	int old;
	int poin;//�|�C���^�[�Ɠ���
	int flag;//�����t���O
void Tree_find(){

	Node_Disp(sp);
	
	Tree_Add();


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

void Tree_Add(){
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
	Node_Disp(sp+1);
}

//display
void Node_Disp(int n){
	for(int i=0; i<n;i++){
		cout<<setw(4)<<a[i].left<<"-";
		cout<<setw(12)<<a[i].name<<"-";
		cout<<setw(4)<<a[i].right<<":"<<endl;
	}
}