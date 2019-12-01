#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> scores;
	int i;
	int sum = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	int max = 0;
	int min = 100;
	
	while(true){
		int score;
		cin >> score;
		if(score == -1)
			break;
		scores.push_back(score);
	}
	
	for(auto& value : scores){
		sum += value;
	}
	
	double avg = (double)sum / scores.size();
	cout << "성적 평균=" << avg << endl;
	
	for(auto& value : scores){
		sum1 += value;
	}
	
	double avg1 = (double)sum1 / scores.size();
	cout << "성적 평균=" << avg1 << endl;
	
	for(i=0;i<scores.size();i++){
		sum2 += scores[i];
	}
	
	double avg2 = (double)sum2 / scores.size();
	cout << "성적 평균=" << avg2 << endl;
	
	vector<int>::iterator it;
	
	for(it = scores.begin();it != scores.end();it++){
		sum3 += *it;
	}
	
	double avg3 = (double)sum3 / scores.size();
	cout << "성적 평균=" << avg3 << endl;
	
	for(auto it2 = scores.begin();it2 !=scores.end();it2++){
		sum4 += *it2;
	}
	
	double avg4 = (double)sum4 / scores.size();
	cout << "성적 평균=" << avg4 << endl;
	
	for(i=0;i<scores.size();i++){
		if(max < scores[i])
			max = scores[i];
		if(min > scores[i])
			min = scores[i];
	}
	
	cout << "최대=" << max << endl;
	cout << "최소=" << min << endl;
	
	return 0;
}