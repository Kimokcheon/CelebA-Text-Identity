#include <bits/stdc++.h>
using namespace std;

void puttoken(string sentence){
    std::vector<std::string> words;
    std::string word;
    for (auto c : sentence) {
        if (c == ' ' || std::ispunct(c)) { // 当遇到空格或标点符号时，把之前的单词加入到 vector 中
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
            if (std::ispunct(c)) { // 如果当前字符是标点符号，则把它也作为一个新的单词加入到 vector 中
                words.push_back(std::string(1, c));
            }
        } else { // 否则继续构造当前单词
            word += c;
        }
    }
    if (!word.empty()) { // 最后一个单词没有空格或标点符号，需要额外添加到 vector 中
        words.push_back(word);
    }
    for (const auto& w : words) {
        if(& w == &words.back()){std::cout <<"\""<< w <<"\""<<std::endl; }
        else{
            std::cout <<"\""<< w <<"\""<<"," <<std::endl;
        }

    }
}

struct pic{
    int id=-1;
    int select=-1;
    string captions;
    string picpath;
    string annopath;
    int split;
    bool operator<(const pic& tmp ){
        if(id == tmp.id){
            return split<tmp.split;
        }
        else{return id < tmp.id;}
    }
} p[205600];

void putspit(int split){
    if(split==0){
        cout<<"\"split\": \"train\","<<endl;
    }
    if(split==1){
        cout<<"\"split\": \"val\","<<endl;
    }
    if(split==2){
        cout<<"\"split\": \"test\","<<endl;
    }
}

int extractNumberFromFilename(const std::string& filename) {
    // 找到文件名中第一个数字的位置
    size_t pos = filename.find_first_of("0123456789");
    if (pos == std::string::npos) {
        // 如果文件名中没有数字，则返回0或抛出异常
        return 0;
    }

    // 读取数字直到结束或遇到非数字字符
    int num = 0;
    while (pos < filename.length() && isdigit(filename[pos])) {
        num = num * 10 + (filename[pos] - '0');
        ++pos;
    }

    return num;
}

int main() {
    int N=202599;
    freopen("./list_eval_partition.txt","r",stdin);
    for(int i=1;i<=N;i++){
        string tmp;
        cin>>tmp>>p[i].split;
    }

    

    freopen("./identity_CelebA.txt","r",stdin);
    for(int i=1;i<=N;i++){
        int id;

        string fijpg;

        cin>>fijpg>>id;
        if(id==10177){
            id=0;
        }
//        if(p[i].id== -1){
//            p[i].split=1;
//        }
        p[i].id=id;
        p[i].picpath=fijpg;
        p[i].annopath="./celeba_caption/"+to_string(i) + ".txt";

    }
    freopen("./CelebA-HQ-to-CelebA-mapping.txt","r",stdin);
    int a[30000];
    for(int i=0;i<30000;i++){
        int idx,orig_idx;string orig_file;
        cin>>idx>>orig_idx>>orig_file;
        a[i]=orig_idx;
    }
    sort(a,a+30000);



    for(int i=1;i<=N;i++){
        string filename=p[i].annopath;
        ifstream file(filename);  // 打开文件

        if (!file.is_open()) {  // 检查文件是否成功打开
            cerr << "Failed to open file: " << filename << endl;

            return 1;
        }

        string line;
        while (getline(file, line)) {  // 遍历文件行
            p[i].captions=line;
            //cout<<p[i].captions<<endl;
        }
        file.close();  // 关闭文
    }
    sort(p,p+N);


    int repeat[10177];

    freopen("./ICFG-PEDES.json","w",stdout);
    cout<<'['<<endl;
    int idcore=0;
    int id_tmp=0;
    for(int i=1;i<N;i++){
        if(p[i].split==0){
            cout<<"{"<<endl;
            putspit(p[i].split);
            cout<<"\"file_path\": "<<"\""<<p[i].picpath<<"\","<<endl;
            if(p[i].id==id_tmp){
                cout<<"\"id\":"<<idcore<<","<<endl;
            }else{
                id_tmp = p[i].id;
                idcore++;
                cout<<"\"id\":"<<idcore<<","<<endl;
            }
            
            cout<<"\"processed_tokens\": ["<<endl;
            cout<<"["<<endl;
            puttoken(p[i].captions);
            cout<<"]"<<endl;
            cout<<"],"<<endl;
            cout<<"\"captions\": ["<<endl;
            cout<<"\""<<p[i].captions<<"\""<<endl;
            cout<<"]"<<endl;
            cout<<"},"<<endl;
        }
     
    }
    for(int i=1;i<N;i++){
        if(p[i].split==1){
            cout<<"{"<<endl;
            putspit(p[i].split);
            cout<<"\"file_path\": "<<"\""<<p[i].picpath<<"\","<<endl;
            if(p[i].id==id_tmp){
                cout<<"\"id\":"<<idcore<<","<<endl;
            }else{
                id_tmp = p[i].id;
                idcore++;
                cout<<"\"id\":"<<idcore<<","<<endl;
            }
            
            cout<<"\"processed_tokens\": ["<<endl;
            cout<<"["<<endl;
            puttoken(p[i].captions);
            cout<<"]"<<endl;
            cout<<"],"<<endl;
            cout<<"\"captions\": ["<<endl;
            cout<<"\""<<p[i].captions<<"\""<<endl;
            cout<<"]"<<endl;
            cout<<"},"<<endl;
        }
     
    }
    for(int i=1;i<N;i++){
        if(p[i].split==2){
            cout<<"{"<<endl;
            putspit(p[i].split);
            cout<<"\"file_path\": "<<"\""<<p[i].picpath<<"\","<<endl;
            if(p[i].id==id_tmp){
                cout<<"\"id\":"<<idcore<<","<<endl;
            }else{
                id_tmp = p[i].id;
                idcore++;
                cout<<"\"id\":"<<idcore<<","<<endl;
            }
            
            cout<<"\"processed_tokens\": ["<<endl;
            cout<<"["<<endl;
            puttoken(p[i].captions);
            cout<<"]"<<endl;
            cout<<"],"<<endl;
            cout<<"\"captions\": ["<<endl;
            cout<<"\""<<p[i].captions<<"\""<<endl;
            cout<<"]"<<endl;
            cout<<"},"<<endl;
        }
     
    }
    cout<<"{"<<endl;
    putspit(p[N].split);
    cout<<"\"file_path\": "<<"\""<<p[N].picpath<<"\","<<endl;
    cout<<"\"id\":"<<(idcore+1)<<","<<endl;
    cout<<"\"processed_tokens\": ["<<endl;
    cout<<"["<<endl;
    puttoken(p[N].captions);
    cout<<"]"<<endl;
    cout<<"],"<<endl;
    cout<<"\"captions\": ["<<endl;
    cout<<"\""<<p[N-1].captions<<"\""<<endl;
    cout<<"]"<<endl;
    cout<<"}"<<endl;
    cout<<']'<<endl;
}