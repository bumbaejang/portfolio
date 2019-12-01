#include <iostream>
using namespace std;

class family{
	private:
	int parent[1000] = {0};
	public:
	int level(int p); //사람 p에서 가장 위의 조상까지 가는 경로의 길이(촌수)
	int distance(int p1, int p2); //두 사람 p1과 p2에 대하여, p1과 p2의 거리(촌수)
	int LowestAncestor(int p1, int p2); ///두 사람 p1과 p2에 대하여, p1과 p2의 가장 가까운 공통조상
	
	void setparent(int n1, int n2){ //접근자(변경 목적)
		parent[n1] = n2;
	}
	
	int getparent(int i){ //접근자(반환목적)
		return parent[i];
	}
};

int family::level(int p){
	int count = 0;
	int i;
	i = p;
	while(true){ //최고 조상까지 갈 때까지 무한반복
		if(parent[i] == -1) //최고 조상을 만나면 탈출
			break;
		else{
			count++;
			i = parent[i];
		}
	}
	return count;
}

int family::distance(int p1, int p2){
	int ancestor;
	int count = 0;
	int a, b;
	a = p1;
	b = p2;
	ancestor = LowestAncestor(p1, p2);
	while(true){ //p1와 p2의 공통조상을 만날 때까지 거리를 더하며 무한반복
		if(a == ancestor) //공통조상을 만나면 탈출
			break;
		count++;
		a = parent[a];
	}
	while(true){ //p1와 p2의 공통조상을 만날 때까지 거리를 더하며 무한반복
		if(b == ancestor) //공통조상을 만나면 탈출
			break;
		count++;
		b = parent[b];
	}
	if(ancestor == -1)
		count = -1;
	return count;
}

int family::LowestAncestor(int p1, int p2){
	int f1[1000] = {0};
	int f2[1000] = {0};
	int a, b, i, j;
	int ca = 0;
	int cb = 0;
	int anc = -1;
	a = p1;
	b = p2;
	for(i=0;;i++){ //p1의 모든 조상들을 저장할 때 까지 무한반복
		if(a == -1){
			f1[i] = a;
			ca++;
			break;
		}
		f1[i] = a;
		a = parent[a];
		ca++;
	}
	for(i=0;;i++){ //p2의 모든 조상들을 저장할 때 까지 무한반복
		if(b == -1){
			f2[i] = b;
			cb++;
			break;
		}
		f2[i] = b;
		b = parent[b];
		cb++;
	}
	for(i=0;i<ca;i++){ //p1과 p2의 제일가까운 공통 조상을 찾을때 까지 반복
		for(j=0;j<cb;j++){
			if(f1[i] == f2[j]){ //내부 반복문 탈출
				anc = f1[i];
				break;
			}
		}
		if(anc != -1) //외부 반복문 탈출
			break;
	}

	return anc;
}

int main(){
	int i, k;
	int num;
	int relative;
	int son, father;
	int p1, p2;
	family f;
	cin >> num >> relative;
	
	for(i=0;i<num+1;i++){ //입력받은 num인덱스 까지 -1로 초기화
		f.setparent(i, -1);
	}
	
	for(i=0;i<relative;i++){
		cin >> son >> father;
		f.setparent(son, father);
	}
	
	for(i=0;i<num;i++){
		cout << f.level(i) << " ";
	}
 	return 0;
}