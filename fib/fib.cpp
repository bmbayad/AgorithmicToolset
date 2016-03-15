#include <iostream>
#include <cstdlib>

using namespace std;

int calc_fib(int n) {
	if (n <= 1)
		return n;

	return calc_fib(n - 1) + calc_fib(n - 2);
}



int calc_fib_fast(int n) {

	if (n < 2)
		return n;

	int *arr = new int[n + 1]();
	arr[0] = 0;
	arr[1] = 1;


	for (size_t i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		//cout << i << ' ' <<arr[i-1] << ' ' <<arr[i-2]<< ' '<< arr[i]  <<endl;
		cout<<arr[i]<<"  ";
	}

	int res = arr[n];
	cout<<endl;
	cout << res<<" ";

	delete[] arr;
	return res;

}

long long calc_fib_fast1(int n) {

	if (n < 2)
		return n;

	long long *arr = new long long[n + 1]();
	arr[0] = 0;
	arr[1] = 1;


	for (size_t i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		//cout << i << ' ' <<arr[i-1] << ' ' <<arr[i-2]<< ' '<< arr[i]  <<endl;
	}

	long long res = arr[n];
   //cout << "fib res: " <<res <<endl;

	delete[] arr;
	return res;

}


void fib_mod_m(int m) {

	int trial = 0;
	long long prev_val = 0;
	for (size_t i = 0; i <= 20; i++)
	{
		cout << i << " ";
		long long val = calc_fib_fast1(i);
		cout << val << ' ';
	}
	cout<<endl<<endl;
	for (size_t i = 0; i <= 70; i++)
	{
		cout <<i<<" ";
		long long val = calc_fib_fast1(i) % m;
		cout << val << ' ';
	}
	cout << endl;
}

void fib_mod_m2(int m) {
	//int repition =0;
	//int trial = 0;
	//long long prev_val = 0;

	int counter = 2;
	int val = 0;
	int prev_val = 0;
	do
	{

		if (0 == calc_fib_fast(counter) % m && 1 == calc_fib_fast(counter + 1) % m) {
			cout << "found sequence with repition: " << counter;
			break;
		}
		counter++;
	} while (true);



	//for (size_t i = 0; i <= 90; i++)
	//{		
	//	int val = calc_fib_fast(i) % m;
	//	if (val == 1 && prev_val == 0) {
	//		if(trial == 1){
	//			cout<<"found sequence with repition: " << repition  <<endl;
	//			break;
	//		}
	//		else {
	//			trial = 1;
	//			
	//		}
	//	}
	//	++repition;
	//	prev_val = val;	
	//	cout << val << ' ';
	//}
	//cout <<endl;
}

int fib_mod_m1(int m) {
	int counter = 2;
	do
	{		
		if (0 == calc_fib_fast1(counter) % m && 1 == calc_fib_fast1(counter+1) % m) {
			return counter;
		}
		counter++;
	} while (true);
}

int get_fibonacci_last_digit(int n) {

	if(n < 2)
		return n;
	
	int *arr = new int[n + 1]();
	arr[0] = 0;
	arr[1] = 1;


	for (size_t i = 2; i <=n; i++)
	{
		arr[i] = (arr[i-1] + arr[i-2]) % 10;		
		//cout << i << ' ' <<arr[i-1] << ' ' <<arr[i-2]<< ' '<< arr[i]  <<endl;
	}

	int res = arr[n];
	//cout << "fib res: " <<res <<endl;
	
	delete[] arr;
	return res;

}

unsigned int gcd_fast(unsigned int a, unsigned int b) {
	//write your code here
	if(b == 0)
		return a;

	unsigned int remainder  = a % b;
	gcd_fast(b, remainder);

}

int gcd_trivial(int a, int b) {
	//write your code here
	int current_gcd = 1;
	for (int d = 2; d <= a && d <= b; d++) {
		if (a % d == 0 && b % d == 0) {
			if (d > current_gcd) {
				current_gcd = d;
			}
		}
	}
	return current_gcd;
}


long long lcm(long a, long long b) {
	long long res = gcd_fast(a,b);
	return (a*b)/res;
}

void stress_test() {
	
	while (true)
	{
		int n = rand() % 5 + 2;
		cout << n << endl;
		
		long long res1 = calc_fib(n);
		long long res2 = calc_fib_fast(n);

		if (res1 != res2) {
			cout << "Wrong answer: " << res1 << ' ' <<res2 <<endl;
			break;
		}
		else {
			cout <<"OK\n";
		}
	}
}


int main() {


	/*input for:
		calc_fib
		calc_fib_fast
		get_fibonacci_last_digit
	*/

	//int n = 0;
	//std::cin >> n;

	//std::cout << calc_fib(n) << '\n';
	//std::cout << calc_fib_fast(n) << '\n';
	//std::cout << get_fibonacci_last_digit(n) << '\n';
	//stress_test();

	/*input for gcd_fast & gcd_trivial function*/

	//int a, b;
	//std::cin >> a >> b;
	//std::cout << gcd_fast(a, b) << std::endl;
	//

	/*input for lcm*/

	//int a, b;
	//std::cin >> a >> b;
	//std::cout << lcm(a, b) << std::endl;





	//fib_mod_m(7);
	//fib_mod_m(30524);
	
	
	//cout << "rep for 2: " << fib_mod_m1(2) << endl;
	//cout <<"rep for 3: "<< fib_mod_m1(3)<<endl;
	//cout << "rep for 4: " << fib_mod_m1(4) << endl;

	//fib_mod_m(5);
	//cout << "rep for 5: " << fib_mod_m1(5) << endl;

	//fib_mod_m(20);
	//cout << "rep for 20: " << fib_mod_m1(20) << endl;

	//fib_mod_m(30524);
	//cout << "rep for 30524: " << fib_mod_m1(30524) << endl;



	cout << "rep for 2: " << fib_mod_m1(2) << endl;
	cout <<"rep for 3: "<< fib_mod_m1(3)<<endl;
	//cout << "rep for 4: " << fib_mod_m1(4) << endl;
	//fib_mod_m(4);
	cout << "rep for 5: " << fib_mod_m1(5) << endl;
	//fib_mod_m(5);
	//cout << "rep for 6: " << fib_mod_m1(6) << endl;
	cout << "rep for 7: " << fib_mod_m1(7) << endl;
	//cout << "rep for 8: " << fib_mod_m1(8) << endl;
	cout << "rep for 9: " << fib_mod_m1(9) << endl;
	
	//cout << "rep for 10: " << fib_mod_m1(10) << endl;
	cout << "rep for 11: " << fib_mod_m1(11) << endl;
	//cout << "rep for 12: " << fib_mod_m1(12) << endl;
	cout << "rep for 13: " << fib_mod_m1(13) << endl;
	cout << "rep for 17: " << fib_mod_m1(17) << endl;
	cout << "rep for 19: " << fib_mod_m1(19) << endl;
	cout << "rep for 23: " << fib_mod_m1(23) << endl;
	cout << "rep for 29: " << fib_mod_m1(29) << endl;
	cout << "rep for 27: " << fib_mod_m1(27) << endl;
	cout << "rep for 31: " << fib_mod_m1(31) << endl;
	cout << "rep for 37: " << fib_mod_m1(37) << endl;
	cout << "rep for 41: " << fib_mod_m1(41) << endl;
	//calc_fib_fast(43);
	cout << "rep for 43: " << fib_mod_m1(43) << endl;
	cout << "rep for 33: " << fib_mod_m1(33) << endl;
	cout << "rep for 30: " << fib_mod_m1(30) << endl;
	cout << "rep for 21: " << fib_mod_m1(21) << endl;
	cout << "rep for 15: " << fib_mod_m1(15) << endl;
	cout << "rep for 25: " << fib_mod_m1(25) << endl;
	cout << "rep for 35: " << fib_mod_m1(35) << endl;




	//long long val1 = 281621358815590;
	//int mod1 = val1%30524;
	//

	//cout <<val1<<" "<<mod1<<" "<< calc_fib_fast(mod1)% 30524 <<endl;



	//long long val1 = 2015;
	//int mod = 8;
	//int mod1 = val1 % mod;
	//cout << val1 << " " << mod1 << " " << calc_fib_fast(mod1) % 3 << endl;
	return 0;
}
