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
	tnode *left;//左用のポインター
	char name[12];//nameの長さ　　charは長さが入れる
	tnode *right;//右用のポインター
};
struct tnode *talloc(void) {//記憶領域の獲得
	return (struct tnode *)malloc(sizeof(struct tnode));
}


wchar_t msg2[] = L"ぢぴゐつぃじねれはれぃぶけぅぼて>";
int main()
{	
	locale::global(locale("japanese"));
	cout << "08_許巧穎" << endl;

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

	cout << "[素数の1515項目目から5個の一の位は順番に]" << endl;
	for (i = 1514; i < 1519; i++) {
		cout << to_string(key[i]).substr(4, 1)+", ";
	}
	cout << endl << "[暗号文は]"<<msg2[1] << endl;
	cout << "[暗号を解読した文章は]" << endl;

}

string key="y";
void EX_02() {
	string monster[] = {"大魔王ゾーマ","竜王","おにこんぼう" ,"ギガンテス" ,"キラーパンサー","スライム" };
	float count[] = { 1,2,15,30,50 };
	float kakuri[5];
	random_device rnd;
	mt19937 mt(rnd());
	
	while (key == "y") {
		cout << "---モンスター名--------------確率--------------1万回中に出た回数" << endl;
		for (int i = 0; i < 5; i++) {
			normal_distribution<> norm(count[i], 0.3f);
			kakuri[i] = norm(mt);
			cout << "   " << monster[i] << "            : ";
			printf("%.1f", kakuri[i]);
			cout<< "[%]               " << round(kakuri[i] * 100) << "/10000" << endl;
		}
		
		cout <<endl << "[上記の確立で呼び出されたモンスターは]" << endl;
		//cout<< <<endl;
		cout << "続けますか？[y/n]---->" << endl;
		cin >> key;
	}
	
}

void EX_03() {

	Tree_Meory();
	
}
int i=0;
void Tree_Meory()
{
	//動的メモリ確保---------
	char dat[20];//入力データ保存
	struct tnode *root, *p, *old;
	string name[128];
	//loop node 制作
	root = talloc();//メモリ確保
	cout << "県名は？　----＞" << flush;
	cin >> root->name;
	name[i]= root->name;
	root->left = NULL;
	root->right = NULL;
	old = NULL;
	while (true) {
		i++;
		cout << "県名は？　----＞" << flush;
		cin >> dat;
		name[i] = dat;
		p = root;
		if (strcmp(dat, "9999") == 0) { break; }
		//終わりは？
		while (p != NULL) {
			old = p;
			if (strcmp(dat, p->name) <= 0) { p = p->left;}
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
	while (p->right != NULL) { p = p->right; }
	cout << "--------------大きい順に表示-----------" << endl;
	/*for (int i = 0; i < name->length, i++;) {
		cout << name[i] << endl;
	}*/
	
	cout << "--------------レベル表示-----------" << endl;
	Tree_Level(root);
}

void Tree_Level(struct tnode *p) {
	struct tnode *q[128],//ポインター。テーブル
		*w[128];//作業用
	int i, child, n, level;
	child = 1; q[0] = p; level = 0;//初期設定
	do {
		n = 0;
		printf("level    %d  :", level);
		for (i = 0; i < child; i++) {
			printf("%12s", q[i]->name);//ノードの表示
			//1つ下のレベルの子へのポインターをスタックに積む
			if (q[i]->left != NULL) {
				w[n++] = q[i]->left;
			}
			if (q[i]->right != NULL) {
				w[n++] = q[i]->right;
			}
		}
		printf("\n");
		child = n;//1つ下のレベルの子の数
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
