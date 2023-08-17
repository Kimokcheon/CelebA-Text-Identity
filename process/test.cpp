#include <bits/stdc++.h>
using namespace std;

string removeWords(const std::string& input) {
    // 要过滤的单词列表
    static const std::string filterWords[] = {"processed_tokens", "The", "the", "picture", "is", "has", "wears", "captions", "train", "test", "val", "with","person","in","this","wearing","open","slightly"};

    // 将输入字符串拆分为单词
    std::vector<std::string> words;
    std::string word;
    for (char c : input) {
        if (isspace(c)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    // 删除要过滤的单词
    auto end_it = std::remove_if(words.begin(), words.end(), [&](const std::string& w){
        return std::find(std::begin(filterWords), std::end(filterWords), w) != std::end(filterWords);
    });
    words.erase(end_it, words.end());

    // 重新构建过滤后的字符串
    std::string result;
    for (const auto& w : words) {
        result += w + " ";
    }
    if (!result.empty()) {
        // 删除末尾空格
        result.pop_back();
    }
    return result;
}

string removePunctuations(string str)
{
    string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (!ispunct(str[i]))
            result += str[i];
    }
    return result;
}


int main(){
    freopen("./1.txt","r",stdin);
    freopen("./cap.txt","w",stdout);
    int flag=0;
    string x;

    for(int i=0;i<1439347;i++){
        getline(cin,x);
        //cout<<x;
        if(flag==1){
            cout<<removeWords(removePunctuations(x))<<endl;
            flag=0;
        }
        if(x=="\"captions\": ["){
            flag=1;
        }
    }

}