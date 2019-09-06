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

//動的ツリー用の構造体
struct tnode{
	tnode *left;//左用のポインター
	char name[12];//nameの長さ　　charは長さが入れる
	tnode *right;//右用のポインター
};
struct tnode *talloc(void){//記憶領域の獲得
	return (struct tnode *)malloc(sizeof(struct tnode));
}

//配列ツリー用の構造体
int sp=9;
struct tnode2{
	int left;//左用のポインター
	string name;//stringは長さが設定必要ない
	int right;//右用のポインター
};
//構造体の配列
struct  tnode2 a[20]=	{
	//-1=null leftの数=何個の分岐
	{2,"miyagi",1},//root 
	{-1,"saitama",5},
	{-1,"chiba",3},
	{4,"kanagawa",-1},
	{6,"ibaraki",2},
	{-1,"tochigi",7},
	{-1,"gunma",-1},
	{-1,"tokyo",8},
	{-1,"yamanashi",-1},
	//追加データ-----
	//{-1,"yamaguchi",-1}//追加
};
int main()
{
	cout<<"許"<<endl<<endl;
	//配列ツリー-----
	//Tree_find();
	//Tree_Add();
	//-----------------
	//動的メモリ
	//Tree_Meory();

	//動的メモリ確保の再帰処理
	char dat[20];//入力データ保存
	struct tnode *root, *p, *old;
	root=NULL;
	while(true){
		cout << "次のデータは--->" << flush;
		cin >> dat;
		if (strcmp(dat, "9999") == 0) { cout << "お疲れ様" << endl; break; }
		root=gentree(root,dat);
	}
	Tree_Level(root);
	//Tree_preorder(root);

	////検索---
	//cout<<"探すデータは---->"<<flush;
	//cin>>dat;
	//if((p=search(root,dat))!=NULL){
	//	printf("%sが見つかりました\n",dat);
	//}else{
	//	printf("見つかりません\n");
	//}

	int in_key;
	cin>>in_key;
}
//走査(レベルごと)
void Tree_Level(struct tnode *p){
	struct tnode *q[128],//ポインター。テーブル
						*w[128];//作業用
	int i,child,n ,level;
	child=1; q[0]= p; level=0;//初期設定
	do{
		n=0;
		printf("level    %d  :",level);
		for(i=0;i<child;i++){
			printf("%12s",q[i]->name);//ノードの表示
			//1つ下のレベルの子へのポインターをスタックに積む
			if(q[i]->left!=NULL){
				w[n++]=q[i]->left;
			}
			if(q[i]->right!=NULL){
				w[n++]=q[i]->right;
			}
		}
		printf("\n");
		child=n;//1つ下のレベルの子の数
		for(i=0;i<child;i++){
			q[i]=w[i];
		}
		level++;
	}
	while(child!=0);
}
//行きがけ順走査
void Tree_preorder(tnode * tnode){
	if(tnode==NULL){
		return;
	}else{
		printf("%s\n",tnode->name);
		Tree_preorder(tnode->left);
		Tree_preorder(tnode->right);
	}
}
//通りがけ順走査
void Tree_inorder(tnode * tnode){
	if(tnode==NULL){
		return;
	}else{
		Tree_inorder(tnode->left);
		printf("%s\n",tnode->name);
		Tree_inorder(tnode->right);
	}
}
//帰りがけ順走査
void Tree_postorder(tnode * tnode){
	if(tnode==NULL){
		return;
	}else{
		Tree_postorder(tnode->left);
		Tree_postorder(tnode->right);
		printf("%s\n",tnode->name);
	}
}

//木のサーチ
struct tnode *search(struct tnode *p,char *key){
	if(p==NULL || strcmp(key,p->name)==0){return p;}
	if(strcmp(key,p->name)<0){return search(p->left,key);}
	else{return search(p->right,key);}
}

//動的メモリ確保の再帰処理で
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
	//動的メモリ確保---------
	char dat[20];//入力データ保存
	struct tnode *root, *p, *old;
	//loop node 制作
	root = talloc();//メモリ確保
	cout << "loop note は-----＞" << flush;
	cin >> root->name;
	root->left = NULL;
	root->right = NULL;
	old = NULL;
	while (true) {
		cout << "次のデータは--->" << flush;
		cin >> dat;
		p = root;
		if (strcmp(dat, "9999") == 0) { cout << "お疲れ様" << endl; break; }
		//終わりは？
		while (p != NULL) {
			old = p;
			if (strcmp(dat, p->name) <= 0) { p = p->left; }
			//strcmp(datと p->name)=第1引数 < 第2引数　の場合はマイナスの値
													//第1引数 > 第2引数　の場合はプラスの値
													//第1引数 = 第2引数　の場合は0
			else { p = p->right; }
		}
		//結果を見つけたら繋げる
		p = talloc();//新しいデータ用の動的メモリ確保
		strcpy_s(p->name, dat);//名前set      strcpy_s(コピー先のアドレス, コピー元のアドレス)
		p->left = NULL;
		p->right = NULL;
		if (strcmp(dat, old->name) <= 0) {
			old->left = p;
		}
		else {
			old->right = p;
		}
	}
	//最小ノードの探索
	p = root;
	while (p->left != NULL) { p = p->left; }
	cout << "最小ノード=" << p->name << endl;
	while (p->right != NULL) { p = p->right; }
	cout << "最大ノード=" << p->name << endl;
}


//---------------関数-----------
//-----------------
//検索
//-----------------
string key;
	int old;
	int poin;//ポインターと同じ
	int flag;//発見フラグ
void Tree_find(){

	Node_Disp(sp);
	
	Tree_Add();


	//ツリーデータの検索
	cout<<"探すテータは？"<<endl<<endl;
	cin>>key;
	poin=0; flag=0;
	while(poin!=-1){
		if(key==a[poin].name){//同じ？？
			cout<<"配列の"<<poin<<"番目に見つかりました"<<endl;
			flag=1;
			break;
		}
		//次のデータ配列に移動
		else	if(key>a[poin].name){
				//右部分木へ移動
				poin=a[poin].right;
		}else{
				//左部分木へ移動
				poin=a[poin].left;
		}
		

	}
	if(flag==0){cout<<"データなし"<<endl;}
}

void Tree_Add(){
	cout<<"追加するデータは---->";
	cin>>key;
	poin=0;flag=0;
	while(poin!=-1){
	//最後の場所保存
	//最後の-1の場所を探す！
		old=poin;
		//次のデータ配列に移動
		if(key>a[old].name){
				//右部分木へ移動
				poin=a[poin].right;
		}else{
				//左部分木へ移動
				poin=a[poin].left;
		}
	}
	//新ノードを追加し、接続
	a[sp].left=a[sp].right=-1;
	a[sp].name=key;
	if(key<=a[old].name){
		a[old].left=sp;
	}else{
		a[old].right=sp;
	}

	//配列の最後に県名を作成
	//大データーー＞右側に9
	//小データーー＞左側に9
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