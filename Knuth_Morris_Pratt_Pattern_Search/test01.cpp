#include <iostream>
#include <string>


void kmp_search(std::string s, std::string p){
	
}


void lps(std::string s, std::string p){
	int len = 0;
	std::vector<int> lps(p.length());
	int i =1;
	while(i < p.length()){
		if(p.at(i)==p.at(len)){
			len++;
			lps[i] = len;
			i++;
		}else{
			if(len != 0){
				len = lps[len - 1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main(int argc, char *argv[]){
	std::string s, p;
	std::cin >> s; 
	std::cin >> p;
	kmp_search(s, p);
	return 0;
}
