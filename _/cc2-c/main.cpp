#include <iostream>
#include <vector>

using namespace std;

class Module{
  private:
  int m;
  public:
  Module(int _m){
    m=_m;
  }
  bool operator()(int x){
    if(x%m==0){
      return true;
    }
    return false;
  }
};


template<typename T, class M>
vector<T> find_matching_numbers2(vector<T> vec, M module){
  vector<int>::iterator itr= vec.begin() ;
  vector<int>::iterator end= vec.end() ;
  vector<T> res;
  while(itr!=end){
    if(module(*itr)){
      res.push_back(*itr);
    }
    itr++;
  }
  return res;
}

int main() {
  Module M(2);
  vector<int> vec;
  vec.push_back(5);
  vec.push_back(4);
  vec.push_back(2);
  vec.push_back(6);
  vector<int> vec_res = find_matching_numbers2(vec,M);
  vector<int>::iterator itr = vec_res.begin();
  vector<int>::iterator end = vec_res.end();
  while(itr != end)
    {
     cout<<*itr<<"\n";
      ++itr;
    }
  }