#include <iostream>
using namespace std;

string int_to_roman(int num)
{
	string ones[]={"","I","II","III","IV","IV","V","V","VI","VII","VIII","IX"};
	string tens[]={"","X","XX","XXX","XV","L","LX","LXX","LXXX","XC"};
	string hrnd[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	string thsnd[]={"","M","MM","MMM"};
	
	return thsnd[num/1000]+hrnd[(num%1000)/100]+tens[(num%100)/10]+ones[(num%10)];
}
int main(int argc, char** argv) {
	int num=1994;
	cout<<int_to_roman(num);
}
