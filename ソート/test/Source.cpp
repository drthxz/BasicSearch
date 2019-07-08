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

//学生リスト
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
	cout << "5B 許" << endl;

	//int sort_data[11];
	//int no[11];
	//wstring name[11];

	////データをポインターで示す
	//for (int i=0;i<10;i++) p[i]=&a[i];
	////for文で10人分の並び替え
	//for(int j=0;j<10-1;j++){
	//	//初期化と設定
	//	int k2=0;

	//	for(int k=1;k<10;k++){
	//		//大きい？小さい？
	//			k2=k;
	//	}
	//	//交換
	//	t=p[j];//避難
	//	p[j]=p[k2];//set
	//	p[k2]=t;
	//}

	////結果表示
	//for (int h=0;h<10;h++){
	//	cout<<p[h]->name<<p[h]->age<<endl;
	//
	//}
	
	//chikuji_search();//前から順番に探索
	//binary_search();//2分探索
	//Merge();//昇順に並んだ2組のデータ列を併合する
	//Hash();

	//ソート-------------------------------------------

	
	int sort_data[] = { 50,80,45,31,45,51,2,96,45,200,-1 };//得点  11番目作ると入力数値を入れれる
	int no[] = { 0, 1, 2, 3, 4, 5,6, 7, 8,  9,-1 };//クリア面数
	wstring name[] = { L"あ",L"い",L"う",L"え",L"お",L"か",L"き",L"く",L"け",L"こ",L"" };

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

	//ランキングBubble-------------
	int Now_data, Now_stage;
	wstring Now_name;

	Show2(sort_data, no, name, 10);
	cout << "得点は？"; cin >> Now_data;
	cout << "面数は？"; cin >> Now_stage;
	wcout << L"名前は？"; wcin >> Now_name;

	//ランキングOK?
	sort_data[10] = Now_data;
	no[10] = Now_stage;
	name[10] = Now_name;
	
	Bubble_tset(sort_data, no, name, 11);
	Show2(sort_data, no, name, 10);
	
	//ランキングBubbleEnd------------

	//------------------------------------------------------


	int i;
	cin >> i;

}

//ハッシュ
void Hash(){
		//データ作成
		const int TableSize=1000;
		const int ModSize=1000;

		struct tel{
				char name[20];
				char telnum[20];
				int enpty;//使用中??
		}dat[TableSize];
		//tel*dat[TableSize];
		int n;
		char a[20],b[20];
		cout<<"入力終了は9999	"<<endl;
		//データ作成
		while(true){
				cout<<"名前を入力---->";
				cin>>a;
				if(strcmp(a,"9999")==0)break;
				cout<<"電話番号を入力--->";
				cin>>b;
				if(strcmp(b,"9999")==0)break;
				n=hash_make(a);

				while(dat[n].enpty==1 && n<TableSize) n++;//次の場所
				if(n<TableSize){
					strcpy_s(dat[n].name,a);
					strcpy_s(dat[n].telnum,b);
					dat[n].enpty=1;
				}else{
					cout<<"容量を超えました"<<endl;
				}
		}

		while(true){//存在しない名前の時のエラー処理なし！！
			cout<<endl;
			cout<<"探す名前を入力----->";
			cin>>a;
			if(strcmp(a,"9999")==0)break;
			n=hash_make(a);
			//suzuki とsizukiを探せ---------	
			//nに入っているデータの表示
			cout<<"ハッシュ番号＝"<<n;
			cout<<"[名前]"<<dat[n].name<<"[TEL]"<<dat[n].telnum<<endl;
		}
}
int hash_make(char *s){
		const int modSize=1000;
		int n=strlen(s);//文字列の長さを求める
		int result=0;
		result=(s[0] - 'A' + (s[n/2-1]-'A') *26  + (s[n-2]-'A') *26 *26 ) %modSize;
		return result;
}

//昇順に並んだ2組のデータ列を併合する
void Merge(){
		int a[]={1,3,5,6,9,14,17,23,46,57};//10
		int b[]={7,13,36,51,100};//5
		int c[15];
		int i,j,p;
		//マージ作業
		i=j=p=0;
		while(i<10&&j<5){//a[],b[]とも終わりでないときのループ
				if(a[i]<=b[j]) c[p++]=a[i++];
				else c[p++]=b[j++];
		}
		while(i<10) c[p++]=a[i++];//a[]が終わるまで
		while(j<5) c[p++]=b[j++];//b[]が終わるまで

		//結果表示
		for(int i=0;i<15;i++){
			cout<<c[i]<<" ,";
		}
		cout<<endl;

}

//2分探索(binary search)
//データがソートされているのが条件
void binary_search(){
		int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		int  key,low,hight,mid,flag;//low=下限0　hight=上限20-1
		int cnt;//発見したカウント
		cout<<"検索する数を入力してください"<<endl;
		cin>>key;

		low=0;hight=20-1;flag=0;cnt=0;
		while(low<=hight){
				cnt++;
				mid=(low+hight)/2;
				if(key==a[mid]){//発見!!
						//配列の何番目にあったか
						//cntを表示
						cout<<mid+1<<"番目にありました"<<a[mid]<<endl;
						flag=1;//発見したflag set
						break;
				}
				//発見できない!!
				if(a[mid]<key){//
						low=mid+1;
				}else{
						hight=mid-1;
				}	
		}
		if(flag!=1)cout<<"データはありませんでした。"<<endl;
		cout<<cnt<<"　回の検索ループでした"<<endl;

}

//前から順番に探索
void chikuji_search(){
	char n[20];//入力用
	cout<<"検索する人名を入力してください"<<endl;
	cout<<"例)    tanaka----->"; cin>>n;

	cout<<n<<endl;

	//最後の構造体に検索データと同じデータをset
	strcpy_s(a[10].name,n);

	int i=0;
	while(strcmp(n,a[i].name)  !=0) i++;
	if(i<10){
	cout<<i+1<<"番目にいました!"<<endl<<a[i].age<<"歳"<<endl;
	}else{
	cout<<"検索する人名のデータはありませんでした"<<endl;
	}

}

//------------
//選択ソート:
//一番小さいものと先頭を入れ替える
//------------

void Sort_Select(int data[],int length){

	
	int i, j, min;

	for(i=0;i<length;i++){
		

		for(int j=0;j<length;j++){
		
			if(data[i]<data[j]){

				//データの交換
				min = data[i];//cope
				data[i] = data[j];
				data[j] = min;
				
			}//for2 end
		
		

		}//for1 end
	}

}


//------------
//バブルソート:
//後ろから入れ替える
//------------
void Bubble_Sort(int data[], int length){

	int i, j, min;
	for(i=0;i<length-1;i++){
	
		for(j=length -1;j>i;j--){
			//lengthは1から10まで、jは0から9まで
		
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
//挿入ソート:
//トランプみたい替え方
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
//安定なソート:
//同じ値を持つデータが二つ以上存在していると、
//------------
void Stable_Sort(int data[], int no[], int length) {

	int i, j, min, temp;

	for (i = 0; i < length; i++) {


		for (int j = 0; j < length; j++) {

			if (data[i] < data[j]) {

				//データの交換
				min = data[i];//cope
				data[i] = data[j];
				data[j] = min;

				//noの入れ替え
				temp = no[i];
				no[i] = no[j];
				no[j] = temp;

			}//for2 end



		}//for1 end

	}
}

void Stable_Show(int data[], int no[], int length) {

	cout << "点数  ";
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

	cout << "点数　"<<endl;
	for (int i = 0; i < length; i++) {

		cout << data[i] << " ";

	}

	cout << endl;

}

//---------------------
//ランキングソート用表示
//---------------------
void Show2(int data[], int no[], wstring name[], int length) {

	for (int i = 0; i < length; i++) {

		cout << i + 1 << "位　" << data[i] << "点　-　";
		wcout << name[i];
		cout << " - " << no[i] << "面" << endl;

	}
	cout << " " << endl;

}





