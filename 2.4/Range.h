#include <iostream>
#include <sstream>
#include <ostream>
#include <iostream>

template <class T> 
class Range;

template <class T> 
std::ostream &operator<<(std::ostream &out, const Range<T> &r);

template <class T> 
class Range {
    private: 
        T start;
        T end;
        T step;
    public:
        Range(T start, T end);
        Range(T start, T end, T step);
        int length();
        T sum();
        T average();
        T min();
        T max();
        friend std::ostream &operator<< <>(std::ostream &out, const Range<T> &r);
    
};

//Constructor for if I am not given the Step
template <class T> 
Range<T>::Range(T start, T end) {
    this->start = start;
    this->end = end;
    this->step = 1;
}//end of constructor

//Constructor for if I am given the Step
template <class T> 
Range<T>::Range(T start, T end, T step) {
    this->start = start;
    this->end = end;
    this->step = step;
}//end of constructor


template <class T> 
int Range<T>::length(){ //returns the number of values in the range
    T leng = 0;
    if(start < end){
        for(T i = start; i <= end; i += step){
            leng++;
        }
    }
     if(start > end){
        for(T i = start; i >= end; i += step){
            leng++;
        }
     }
   

    return leng;
} //end of length

template <class T> 
 T Range<T>::sum(){  //returns the sum of all the values in the range
        T sum = start; 
          if(start < end){
            T i = start + step;
            while(i <= end){ //we keep adding step to i and then add i to sum
                sum += i; 
                i += step;
            }
            return sum;
        } else {
            T i = start + step;
            while(i >= end){  
                sum += i;
                i += step;
            }
        }
        return sum;
    } 

 
    

template <class T> 
T Range<T>::average(){ //returns the average of all the values in the range
    T avg = 0;
//Find the average
   avg = sum() / length(); //You are able to divide funtions
    return avg;
} //end of average



template <class T> 
T Range<T>:: min() { //should return the minimum value

    if (start < end){
    return start;
    } else {
        T i = start + step * (length() -1); //A tutor assisted with this. We are using summation
    
        return i;
    }
    
}//end of min 


template <class T> 
T Range<T>::max()  { //should return the maximum value
  
    if (end < start){
    return start;
    } else {
        T i = start + step * (length() -1);    
        return i;
    }

}//end of max

template <class T> 
std::ostream &operator<<(std::ostream &out, const Range<T> &r) {
    std::stringstream S; //convert strings into nums and vice versa
    S << r.start << "- " << r.end;
    out << S.str();
  return out;
}

