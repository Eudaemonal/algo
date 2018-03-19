#include <iostream>
#include <string>
#include <vector>


std::vector<int> get_lps(std::string s, std::string p){
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
	return lps;
}

void kmp_search(std::string s, std::string p){
	std::vector<int> lps;
	lps = get_lps(s, p);
	int i = 0;
	int j = 0;
	while(i < s.length()){
		if(p.at(j)==s.at(i)){
			j++;
			i++;
		}
		if(j==p.length()){
			std::cout << "Found pattern at index " << i-j << "\n";
			j = lps[j-1];
		}
		else if(i < s.length() && p[j]!=s[i]){
			if(j!=0){
				j = lps[j-1];
			}else{
				i = i + 1;
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
