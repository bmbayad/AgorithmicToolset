#include <iostream>


int get_change(int n) {

	int money_left = n;
	int coin_num =0;
	while (money_left > 0)
	{
		if (money_left >= 10) {
			int  remainder = money_left % 10;
			if (remainder == 0) {
				coin_num += 1;
				money_left -=10;

			}else{
			coin_num += (money_left- remainder)/10;
			money_left = remainder;
			}

		}
		else if (money_left >= 5) {
			coin_num ++;
			money_left -=5;

		}
		else {
			coin_num += money_left;
			money_left =0;
		}
	}
	return coin_num;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << get_change(n) << '\n';
}
