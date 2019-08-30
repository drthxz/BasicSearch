#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void Tree_find();
void Node_Disp(int n);

int sp=9;
struct tnode{
	int left;//左用のポインター
	string name;
	int right;//右用のポインター
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
	//追加データ-----
	//{-1,"yamaguchi",-1}//追加
};
int main()
{
	cout<<"許"<<endl<<endl;
	Tree_find();
	int in_key;
	cin>>in_key;
}

//---------------関数-----------
//-----------------
//検索
//-----------------
void Tree_find(){

	Node_Disp(sp);
	string key;
	int old;
	int poin;//ポインターと同じ
	int flag;//発見フラグ
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
	Node_Disp(sp);


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

//display
void Node_Disp(int n){
	for(int i=0; i<n;i++){
		cout<<setw(4)<<a[i].left<<"-";
		cout<<setw(12)<<a[i].name<<"-";
		cout<<setw(4)<<a[i].right<<":"<<endl;
	}
}