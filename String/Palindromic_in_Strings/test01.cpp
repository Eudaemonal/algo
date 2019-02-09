#include <iostream>
#include <string>

int count_palindromic(std::string s){
    int n = s.length();
    int count = 0;

    // double the size of center, which stands for half step
    // each time of left and right
    for(int center = 0; center <= n*2-1; center++){
        int left = center / 2;
        int right = left + center % 2; // different when center is even or odd
        while(left >=0 && right <n && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
    }
    return count;
}

int main(int argc, char *argv[]){
    std::string s;
    std::cin >> s;

    std::cout << count_palindromic(s) << "\n";
}
