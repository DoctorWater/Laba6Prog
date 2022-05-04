#include <iostream>
#include "vector"

using namespace std;
template <typename T>
bool predicate(T a){
    return a>3;
}
template<typename T>
bool palindromPredicate(T a){
    return a % 2 == 0;
}

template <typename Iter, typename Fun>
bool anyOf(Iter begin, Iter end, Fun comparator){
    bool checker=false;
    auto iterator=begin;
    while(iterator!=end)
    {
        if (comparator(*iterator)){
            return true;
        }
        iterator++;
    }
    return checker;
}
template <typename Iter, typename Fun>
bool isPartitioned(Iter begin, Iter end, Fun comparator){
    bool checker=false;
    int counter=0;
    auto iterator=begin;
    while(iterator!=end)
    {
       if(comparator(*iterator)!=checker) {
           counter++;
           checker=!checker;
       }
    }
    if(counter==1)
        return true;
    else
        return false;
}
template<typename Iter, typename Fun>
bool isPalindtome(Iter begin, Iter end, Fun predicate){
    int a=begin-end;
    if (!predicate(a))
        return false;
    else{
        bool checker = true;
        for (int i=0;i<a/2;i++){
            if(*begin!=*end){
                checker= false;
            }
            begin++;
            end--;
        }
        return checker;
    }
}

int main() {
    std::vector<int> vec;
    vec.resize(6);
    vec={1,2,3,3,2,1};
    std::cout << "Any_Of result: " << anyOf<vector<int>::iterator>(vec.begin(),vec.end(), predicate<int>) << " is_Partitioned result: " << isPartitioned<vector<int>::iterator>(vec.begin(),vec.end(), predicate<int>) << std::endl;
    cout << isPalindtome<vector<int>::iterator>(vec.begin(), vec.end(), palindromPredicate<int>);
    return 0;
}
