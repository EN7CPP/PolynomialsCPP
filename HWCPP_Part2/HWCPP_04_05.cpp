// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "math.h"
using namespace std;
class Polynomial{
private:
	int arrLength;
	int * arrPtr;
public:
	
	Polynomial(int length){
		this->arrLength=length;
		arrPtr=new int[length];
		this->setCoefficients();
	}
	Polynomial(){
		this->arrPtr=nullptr;
	}
	
	~Polynomial(){
		this->arrPtr=nullptr;
	}
	
	double calculateValue(double x){
		double sum=0;
		for(int i=0;i<arrLength;i++){
			sum+= pow(x,i)*this->arrPtr[i];
		}
		return sum;
	}
	void setCoefficients(){
		for(int i=0;i<arrLength;i++){
			cout<<"Enter coefficient number "<<i+1<<":";
			cin>>this->arrPtr[i];
		}
		
	}
	void setCoefficient(int ind,int val){
		this->arrPtr[ind-1]=val;
	}
	void getCoefficients(){
		for(int i=0;i<arrLength;i++){
			cout<<this->arrPtr[i]<<"  ";
		}
		cout<<endl;
	}
	int getCoefficient(int ind){
		return this->arrPtr[ind-1];
	}
	void setArrLength(int l){
		this->arrLength=l;
	}
	void ArrayInitialization(int length){
		this->arrPtr=new int[length];
	}
	int getArrayLength(){
		return this->arrLength;
	}
	//Operator overloading
	Polynomial operator+(Polynomial const &toBeAdded){
		Polynomial toBeReturned;
		if(toBeAdded.arrLength>=this->arrLength){
			
			toBeReturned.setArrLength(toBeAdded.arrLength);
			toBeReturned.ArrayInitialization(toBeAdded.arrLength);
			for(int i=0;i<toBeReturned.arrLength;i++){
				if(i>this->arrLength-1){
					toBeReturned.arrPtr[i]=toBeAdded.arrPtr[i];
				}
				else {
					toBeReturned.arrPtr[i]=toBeAdded.arrPtr[i]+this->arrPtr[i];
				}
			}
			
		}
		else {
			
			toBeReturned.setArrLength(this->arrLength);
			toBeReturned.ArrayInitialization(this->arrLength);
			
			for(int i=0;i<this->getArrayLength();i++){
				
				if(i>toBeAdded.arrLength-1){
				
					toBeReturned.arrPtr[i]=this->arrPtr[i];
																			
				}
				else {
					
					toBeReturned.arrPtr[i]=toBeAdded.arrPtr[i]+this->arrPtr[i];

				}
				cout<<i<<endl;
			}
			
			
		}
		return toBeReturned;
	}
	
	Polynomial operator-(Polynomial const &toBeSubtracted){
		Polynomial toBeReturned;
		if(toBeSubtracted.arrLength>=this->arrLength){
			
			toBeReturned.setArrLength(toBeSubtracted.arrLength);
			toBeReturned.ArrayInitialization(toBeSubtracted.arrLength);
			for(int i=0;i<toBeReturned.arrLength;i++){
				if(i>this->arrLength-1){
					toBeReturned.arrPtr[i]=-toBeSubtracted.arrPtr[i];
				}
				else {
					toBeReturned.arrPtr[i]=this->arrPtr[i]-toBeSubtracted.arrPtr[i];
				}
			}
			
		}
		else {
			
			toBeReturned.setArrLength(this->arrLength);
			toBeReturned.ArrayInitialization(this->arrLength);
			
			for(int i=0;i<this->getArrayLength();i++){
				
				if(i>toBeSubtracted.arrLength-1){
				
					toBeReturned.arrPtr[i]=this->arrPtr[i];
																			
				}
				else {
					
					toBeReturned.arrPtr[i]=this->arrPtr[i]-toBeSubtracted.arrPtr[i];

				}
				
			}
			
			
		}
		return toBeReturned;
	}

	int* multiplyByPolynomial(int ind,int coef,int fullLength,int arrLength,int arr[]){
		int*ptrToArr=new int[fullLength];
		for(int i=0;i<ind;i++){
			ptrToArr[i]=0;
		}
		for(int i=arrLength+ind;i<fullLength;i++){
			ptrToArr[i]=0;
		}
		for(int i=ind;i<ind+arrLength;i++){
			ptrToArr[i]=arr[i-ind]*coef;
		}
		return ptrToArr;
	}

	Polynomial operator * (Polynomial const &toBeMultiplied){
		Polynomial toBeReturned;
		int**arrptrs=new int*[this->arrLength];
		int fullLength=toBeMultiplied.arrLength+this->arrLength-1;
		toBeReturned.setArrLength(fullLength);
		int * ptrToFinalArray=new  int [fullLength];
		for(int i=0;i<this->arrLength;i++){
			arrptrs[i]=new int[toBeMultiplied.arrLength+this->arrLength-1];
		}
		for(int i=0;i<this->arrLength;i++){
			arrptrs[i]=multiplyByPolynomial(i,this->arrPtr[i],fullLength,toBeMultiplied.arrLength,toBeMultiplied.arrPtr);
		}
		for(int i=0;i<fullLength;i++){
			int sum=0;
			for(int z=0;z<this->arrLength;z++){
				sum+=arrptrs[z][i];
			}
			ptrToFinalArray[i]=sum;
			sum=0;
		}
		toBeReturned.arrPtr=ptrToFinalArray;
		return toBeReturned;
		
	}
	Polynomial operator += (Polynomial const &toBeAdded){
	int * toBeAssigned;
	if(toBeAdded.arrLength>=this->arrLength){
		toBeAssigned=new int [toBeAdded.arrLength];
			
			for(int i=0;i<toBeAdded.arrLength;i++){
				if(i>this->arrLength-1){
					toBeAssigned[i]=toBeAdded.arrPtr[i];
				}
				else {
					toBeAssigned[i]=toBeAdded.arrPtr[i]+this->arrPtr[i];
				}
			}
			this->setArrLength(toBeAdded.arrLength);
			this->arrPtr=toBeAssigned;
			
		}
		else {
			toBeAssigned=new int [this->arrLength];
			
			
			for(int i=0;i<this->getArrayLength();i++){
				
				if(i>toBeAdded.arrLength-1){
				
					toBeAssigned[i]=this->arrPtr[i];
																			
				}
				else {
					
					toBeAssigned[i]=toBeAdded.arrPtr[i]+this->arrPtr[i];

				}
				
			}
			this->setArrLength(this->arrLength);
			this->arrPtr=toBeAssigned;
			
		}
	return *this;
	
	}

	Polynomial operator -= (Polynomial const &toBeSubtracted){
		int * toBeAssigned;
		if(toBeSubtracted.arrLength>=this->arrLength){
			toBeAssigned = new int[toBeSubtracted.arrLength];
			
			for(int i=0;i<toBeSubtracted.arrLength;i++){
				if(i>this->arrLength-1){
					toBeAssigned[i]=-toBeSubtracted.arrPtr[i];
				}
				else {
					toBeAssigned[i]=this->arrPtr[i]-toBeSubtracted.arrPtr[i];
				}
			}
			this->setArrLength(toBeSubtracted.arrLength);
			this->arrPtr=toBeAssigned;
		}
		else {
			
			toBeAssigned = new int[this->arrLength];
			
			for(int i=0;i<this->arrLength;i++){
				
				if(i>toBeSubtracted.arrLength-1){
				
					toBeAssigned[i]=this->arrPtr[i];
																			
				}
				else {
					
					toBeAssigned[i]=this->arrPtr[i]-toBeSubtracted.arrPtr[i];

				}
				
			}
			this->setArrLength(this->arrLength);
			this->arrPtr=toBeAssigned;
			
		}
		
		return *this;
			
	
	}

	Polynomial operator *= (Polynomial const &toBeMultiplied) {
	
		
		int**arrptrs = new int*[this->arrLength];
		int fullLength = toBeMultiplied.arrLength + this->arrLength - 1;
		int * ptrToFinalArray = new  int[fullLength];
		for (int i = 0; i<this->arrLength; i++) {
			arrptrs[i] = new int[toBeMultiplied.arrLength + this->arrLength - 1];
		}
		for (int i = 0; i<this->arrLength; i++) {
			arrptrs[i] = multiplyByPolynomial(i, this->arrPtr[i], fullLength, toBeMultiplied.arrLength, toBeMultiplied.arrPtr);
		}
		for (int i = 0; i<fullLength; i++) {
			int sum = 0;
			for (int z = 0; z<this->arrLength; z++) {
				sum += arrptrs[z][i];
			}
			ptrToFinalArray[i] = sum;
			sum = 0;
		}
		this->arrLength=fullLength;
		this->arrPtr=ptrToFinalArray;
		return *this;
	
	}


	Polynomial operator = (Polynomial toBeAssigned){
		this->arrLength=toBeAssigned.arrLength;
		copy(this->arrPtr,this->arrPtr+this->arrLength,toBeAssigned.arrPtr);
		return *this;
	}
	

};

int main()
{
	Polynomial one(3),two(3);
	(two*one).getCoefficients();
	cout << endl;
	two*=one;
	two.getCoefficients();
	
	Polynomial three = one + two;
	two -= one;
	
	cout << "PolyNomial three:  "; three.getCoefficients();
	cout << endl;
	cout << "Polynomial one:   "; one.getCoefficients();
	cout << endl;
	cout << "Polynomial two:   "; two.getCoefficients();					//Just try any operation you want 
	cout << endl;
	cout << "PolyNomial three:  "; three.getCoefficients();
	
	return 0;
}

